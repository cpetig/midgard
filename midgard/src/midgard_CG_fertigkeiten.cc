// $Id: midgard_CG_fertigkeiten.cc,v 1.59 2002/03/01 18:56:12 thoma Exp $
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
//#include "Fertigkeiten_auswahl.hh"
#include <Gtk_OStream.h>
#include "Window_angeb_fert.hh"
#include "Fertigkeiten.hh"
#include "Fertigkeiten_angeboren.hh"
#include <Aux/itos.h>

gint midgard_CG::on_angeborene_fertigkeit_button_release_event(GdkEventButton *event)
{
  list_Fertigkeit_ang.clear();
  Werte.resetSinne();
  checkAngeboreneSinne();
//  if (Werte.Spezies()->Name()=="Zwerg" || Werte.Spezies()->Name()=="Elf") 
//      list_Fertigkeit_ang.push_back(&*cH_Fertigkeit_angeborene("Nachtsicht"));
  
  if (event->button==1) on_angeborene_fertigkeit_clicked() ;
  if (event->button==3) on_angeborene_fertigkeit_right_clicked() ;
  zeige_werte(Werte);
  show_gelerntes();

  button_lernpunkte->set_sensitive(true);
  togglebutton_lernpunkte_edit->set_sensitive(true);
  button_angeborene_fert->set_sensitive(false);

  return false;
}

void midgard_CG::on_angeborene_fertigkeit_clicked()
{
  int wurf = random.integer(1,100);
//wurf = 100; /*debug*/
  while (wurf==100)
   {
      manage (new Window_angeb_fert(this,Database,list_Fertigkeit_ang,Werte,wurf));
      wurf = random.integer(1,100);
   }
  Window_angeb_fert *W = manage (new Window_angeb_fert(this,Database,list_Fertigkeit_ang,Werte,wurf));
  std::string stinfo="F�r die Angeborene Fertigkeit\n wurde eine ";
  stinfo+=itos(wurf);stinfo+=" gew�rfelt: "+W->Name()+"\n";
  InfoFenster->AppendShow(stinfo);
}


void midgard_CG::on_angeborene_fertigkeit_right_clicked()
{
  manage (new Window_angeb_fert(this,Database,list_Fertigkeit_ang,Werte,-1));
}


void midgard_CG::universal_Fertigkeiten()
{
  list_Fertigkeit_universal.clear();
  for(std::list<cH_MidgardBasicElement>::const_iterator i=Database.Fertigkeit.begin();i!=Database.Fertigkeit.end();++i)
   {
//     if((*i)->ist_gelernt(list_Fertigkeit)) continue ;
     if(cH_Fertigkeit(*i)->Voraussetzungen(Werte) && cH_Fertigkeit(*i)->Ungelernt()!=-1)
       list_Fertigkeit_universal.push_back(*i);
   }
}


/*
void midgard_CG::angeborene_fertigkeiten()
{
 if (Werte.Spezies()->Name()=="Zwerg" ||
     Werte.Spezies()->Name()=="Waldgnom" ||
     Werte.Spezies()->Name()=="Berggnom")
   {
     cH_MidgardBasicElement fert_an(&*cH_Fertigkeit_angeborene("Robustheit"));
     cH_Fertigkeit_angeborene(fert_an)->set_Erfolgswert(9);
     list_Fertigkeit_ang.push_back(fert_an);
   }
}
*/

void midgard_CG::checkAngeboreneSinne()
{
  std::list<pair<std::string,int> > L=Werte.Spezies()->getSinne();
  for(std::list<pair<std::string,int> >::const_iterator i=L.begin();i!=L.end();++i)
     Werte.setSinn(i->first,i->second);
}
