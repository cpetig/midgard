// $Id: midgard_CG_fertigkeiten.cc,v 1.20 2001/06/24 13:24:52 thoma Exp $
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
#include "Fertigkeiten_auswahl.hh"
#include <Gtk_OStream.h>
#include "Window_angeb_fert.hh"
//#include <algorithm>

void midgard_CG::on_fertigkeiten_wahl_clicked()
{   
//  manage(new Fertigkeiten_auswahl(this,typ.s,werte,lernpunkte,vec_beruf));
  manage(new Fertigkeiten_auswahl(this,typ.s,typ_2.s,lernpunkte,werte));
}

void midgard_CG::show_fertigkeiten()
{
   fertigkeiten_clist->clear();
   Gtk::OStream os(fertigkeiten_clist);
   for(vector<H_Data_fert>::iterator i=vec_Fertigkeiten.begin();
         i!=vec_Fertigkeiten.end();++i)
      {
         os << (*i)->Name();
         if ((*i)->Erfolgswert()!=0) os <<"\t" <<(*i)->Erfolgswert();
         os << "\n";
      }
   for(vector<H_Data_fert>::iterator i=vec_an_Fertigkeit.begin();
         i!=vec_an_Fertigkeit.end();++i)
      {
         os << (*i)->Name();
         if ((*i)->Erfolgswert()!=0) os <<"\t" <<(*i)->Erfolgswert();
         os << "\n";
      }
   for (unsigned int i=0;i<fertigkeiten_clist->columns().size();++i)
      fertigkeiten_clist->set_column_auto_resize(i,true);
   fertigkeiten_clist->set_reorderable(true);
}

void midgard_CG::fertigkeiten_uebernehmen(const vector<H_Data_fert>& saf)
{
   vec_Fertigkeiten = saf;
   maxkido=0;
   if (typ.s=="Kd") maxkido=2;
//XXX   vector<vector<st_ausgewaehlte_fertigkeiten>::iterator>  vi;
   int KD_tech=0; //XXX
   for(vector<H_Data_fert>::iterator i=vec_Fertigkeiten.begin();
         i!=vec_Fertigkeiten.end();++i)
      {
         int bonus = midgard_CG::attribut_check((*i)->Attribut());
         (*i)->set_Erfolgswert( (*i)->Erfolgswert() + bonus);
         if ((*i)->Name()=="KiDo") {kido_bool=true; show_gtk(get_typ_nr());}
         if ((*i)->Name()=="KiDo-Technik") { ++KD_tech;++maxkido;}
      }

   for (int j=0;j<KD_tech;++j)
     for(vector<H_Data_fert>::iterator i=vec_Fertigkeiten.begin();
         i!=vec_Fertigkeiten.end();++i)
       if ((*i)->Name()=="KiDo-Technik") {vec_Fertigkeiten.erase(i);break;}
      
   midgard_CG::show_fertigkeiten();

   hbox_waffen->set_sensitive(true);
   table_waffen->set_sensitive(true);
}

gint midgard_CG::on_angeborene_fertigkeit_button_release_event(GdkEventButton *event)
{
  vec_an_Fertigkeit.clear();
  if (werte.spezies=="Zwerg" || werte.spezies=="Elf") 
      vec_an_Fertigkeit.push_back(new Data_fert("Nachtsicht",0));
  if (event->button==1) midgard_CG::on_angeborene_fertigkeit_clicked() ;
  if (event->button==3) midgard_CG::on_angeborene_fertigkeit_right_clicked() ;
  button_fertigkeiten->set_sensitive(true);
  return false;
}

void midgard_CG::on_angeborene_fertigkeit_clicked()
{
  Random random;
  int wurf = random.integer(1,100);
//wurf = 100; /*debug*/
  while (wurf==100)
   {
      manage (new Window_angeb_fert(this,vec_an_Fertigkeit,werte,wurf));
      wurf = random.integer(1,100);
   }
  manage (new Window_angeb_fert(this,vec_an_Fertigkeit,werte,wurf));
  string stinfo="F�r die Angeborene Fertigkeit\n wurde eine ";stinfo+=itos(wurf);stinfo+=" gew�rfelt.\n";
  manage(new WindowInfo(stinfo));
  midgard_CG::show_fertigkeiten();
}

void midgard_CG::on_angeborene_fertigkeit_right_clicked()
{
  manage (new Window_angeb_fert(this,vec_an_Fertigkeit,werte,-1));
  midgard_CG::show_fertigkeiten();
}

