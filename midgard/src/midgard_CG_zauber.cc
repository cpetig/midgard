// $Id: midgard_CG_zauber.cc,v 1.31 2001/10/08 12:53:01 thoma Exp $
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
#include "Zauber_auswahl.hh"
#include <Gtk_OStream.h>

void midgard_CG::on_zauber_wahl_clicked()
{
  zauber_clist->clear();
  if (Werte.Spezial2()=="" && Typ[0]->Short()=="eBe")
   {
      std::string strinfo="Erst Prim�r- und Sekund�relement w�hlen\n";
      manage(new WindowInfo(strinfo));
      return;
   }
  manage(new Zauber_auswahl(this,Werte,vec_Beruf,Typ,lernpunkte.Zauber()));
}

void midgard_CG::show_zauber()
{
   zauber_clist->clear();
   Gtk::OStream os(zauber_clist);
   for(std::list<cH_Zauber>::const_iterator i=list_Zauber.begin();i!=list_Zauber.end();++i)
      {
         os << (*i)->Name()<<"\t"<<(*i)->Erfolgswert(Typ,Werte)<<"\n";
      }
   for (unsigned int i=0;i<zauber_clist->columns().size();++i)
      zauber_clist->set_column_auto_resize(i,true);
   zauber_clist->set_reorderable(true);
}

void midgard_CG::zauber_uebernehmen(const std::list<cH_Zauber>& saz)
{
   list_Zauber=saz;
   angeborene_zauber();
/*
   for(std::list<cH_Zauber>::const_iterator i=list_Zauber.begin();i!=list_Zauber.end();++i)
      {
         int erf = get_erfolgswert_zaubern(Typ,Typ2,(*i)->Name());
         (*i)->set_Erfolgswert(erf);
      }
*/
   show_zauber();
}

void midgard_CG::angeborene_zauber()
{
 if (Typ[0]->Short()=="eBe" || Typ[1]->Short()=="eBe" || Typ[0]->Short()=="dBe" || Typ[1]->Short()=="dBe" ) 
    list_Zauber.push_back(cH_Zauber("Lehrersuche",Typ,Ausnahmen(Werte,Typ,vec_Beruf)));
 if (Werte.Spezies()=="Elf") 
    list_Zauber.push_back(cH_Zauber("Erkennen der Aura",Typ,Ausnahmen(Werte,Typ,vec_Beruf)));
}
