// $Id: midgard_CG.cc,v 1.263 2002/09/19 08:16:21 thoma Exp $
/*  Midgard Character Generator
 *  Copyright (C) 2001 Malte Thoma
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#include "midgard_CG.hh"
#include <gtk--/notebook.h>
#include <gtk--/main.h>
#include "Midgard_Info.hh"
#include "Fertigkeiten.hh"
#include <unistd.h>
//#include <stdlib.h>
#ifdef __MINGW32__
#include <time.h>
#endif
#include "Windows_Linux.hh"

midgard_CG::midgard_CG(const string &_argv0,const string &_magus_verzeichnis,
                       const string &datei)
: argv0(_argv0),magus_verzeichnis(_magus_verzeichnis),in_dtor(false),
	InfoFenster(0),MOptionen(0),wizard(0),menu_kontext(0)
{
  InfoFenster = manage(new WindowInfo(this));

  // Optionen laden
  fill_IconVec();
  MOptionen = new Midgard_Optionen(this); 
  table_optionen->set_Hauptfenster(this);
  MOptionen->load_options(with_path("magus_optionen.xml",false,true));
  
  srand(time(0));
  Database.load(Midgard_Info,this);

  set_sensitive(true);

  if (!datei.empty()) xml_import(datei); // Charakter laden
  else if(MOptionen->OptionenCheck(Midgard_Optionen::Wizard_immer_starten).active) 
       on_wizard_starten_activate();
  else on_neuer_charakter_clicked();
  if(MOptionen->OptionenCheck(Midgard_Optionen::Notebook_start).wert!=-1) 
     notebook_main->set_page(MOptionen->OptionenCheck(Midgard_Optionen::Notebook_start).wert);


  init_statusbar();
  // f�r die NEWS
  Gtk::OStream os(list_news);
  os << 
#include"NEWS.h" 
   <<'\n';
}

midgard_CG::~midgard_CG()
{  //cout << "~midgard_CG()\n\n\n\n";
   in_dtor=true;
   delete MOptionen;
//   if (menu) delete menu;
//   if (table_steigern->menu_gradanstieg) table_steigern->delete menu_gradanstieg;
//   InfoFenster->destroy(); 
   if(wizard) delete wizard;
}

void midgard_CG::init_statusbar()
{
  frame_regionen_status->remove();
  vec_region_status.clear();
  Gtk::HBox *hb_regionen_status=manage(new class Gtk::HBox(false, 0));
  Midgard_Optionen::IconIndex II=MOptionen->getIconIndex();
  for(std::vector<cH_Region>::const_iterator i=Database.Regionen.begin();i!=Database.Regionen.end();++i)
   {
     Gtk::Pixmap *p=RegionenPic::Pic((*i)->Pic(),II,true);
     hb_regionen_status->pack_start(*p);
     if((*i)->Active()) p->show();
     vec_region_status.push_back(st_reg_status((*i)->Pic(),p));
   }
  hb_regionen_status->show();
  frame_regionen_status->add(*hb_regionen_status);
}

void midgard_CG::set_region_statusbar(RegionenPic::epic pic,bool active)
{
  for(std::vector<st_reg_status>::const_iterator i=vec_region_status.begin();i!=vec_region_status.end();++i)
   {
     if(i->name==pic)
      {
        if(active) i->pix->show();
        else i->pix->hide();
        return;
      }
   }
}


std::string midgard_CG::with_path(const std::string &name,bool path_only,bool noexit) const
{
  std::vector<std::string> V;
#ifndef __MINGW32__ // IMHO macht das unter Win32 keinen Sinn
  // vielleicht sollten wir das aktuelle Verzeichnis beim 
  // Programmstart einmal ermitteln und nicht immer
  char currentwd[10240];
  *currentwd=0;
  getcwd(currentwd,sizeof currentwd);
  
  V.push_back(std::string(currentwd)+"/");
#endif  
  V.push_back(magus_verzeichnis);
#ifndef __MINGW32__
  V.push_back(PACKAGE_DATA_DIR);
  V.push_back(std::string(PACKAGE_DATA_DIR)+"/docs/");
  V.push_back(std::string(currentwd)+"/../xml/");
  V.push_back(std::string(currentwd)+"/../docs/");
#else
  V.push_back(BinaryVerzeichnis());
  V.push_back(BinaryVerzeichnis()+"Daten\\");
  V.push_back(BinaryVerzeichnis()+"Hilfe\\");
#endif  
  std::string ntmp;
  for(std::vector<std::string>::const_iterator i=V.begin();i!=V.end();++i)
   {
     std::string n=*i+name;
cout <<"Suche nach "<< n<<'\n';
     if(!access(n.c_str(),R_OK)) 
      { if(path_only) return *i;
        else return n;
      }
   }
  cout << "File "+name+" nowhere found\n";
  if(!noexit) exit(1);
  return("");
}

std::string midgard_CG::BinaryVerzeichnis() const
{  
   if (argv0.rfind(WinLux::dirsep)!=std::string::npos) 
      return argv0.substr(0,argv0.rfind(WinLux::dirsep)+1);
   else return "";
}

void midgard_CG::fill_IconVec()
{
  // InfoFenster
  IconVec.push_back(st_buttons(InfoFenster->button_bestaetigen,iJa));
  IconVec.push_back(st_buttons(InfoFenster->button_abbrechen,iNein));
  // Grundwerte
  IconVec.push_back(st_buttons(table_grundwerte->button_grundwerte,iEigenschaften));
  IconVec.push_back(st_buttons(table_grundwerte->button_abg_werte,iAbgeleitet));
  IconVec.push_back(st_buttons(table_grundwerte->togglebutton_edit_werte,iEditGrund));
  // Lernschema
  IconVec.push_back(st_buttons(table_lernschema->button_lernpunkte,iLernpunkte));
  IconVec.push_back(st_buttons(table_lernschema->togglebutton_lernpunkte_edit,iLernEdit));
  IconVec.push_back(st_buttons(table_lernschema->button_beruf,iBeruf));
  IconVec.push_back(st_buttons(table_lernschema->button_lernschema_geld,iGeld));
  IconVec.push_back(st_buttons(table_lernschema->button_lernschema_waffen,iWaffen));
  IconVec.push_back(st_buttons(table_lernschema->button_ruestung,iRuestung));
  IconVec.push_back(st_buttons(table_lernschema->button_ausruestung,iAusruestung));
  // Steigern
  IconVec.push_back(st_buttons(table_steigern->button_grad_basiswerte,iEigenschaft));
  // Beschreibung
  IconVec.push_back(st_buttons(table_beschreibung->button_grafik,iBildeinfuegen));
  IconVec.push_back(st_buttons(table_beschreibung->button_beschreibung_drucken,iPrint));

  //////////////////////////////////////////////////////////////////////////
  IconVecBin.push_back(st_buttons(eventbox_wizard_aktiv,iStatusWizard));
}

