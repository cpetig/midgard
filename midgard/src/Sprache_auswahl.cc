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

// generated 2001/3/7 7:55:50 CET by thoma@ig23.
// using glademm V0.5_11f_cvs
//
// newer (non customized) versions of this file go to Sprache_auswahl.cc_new

// This file is for your program, I won't touch it again!

#include "config.h"
#include "Sprache_auswahl.hh"
#include "midgard_CG.hh"
#include <Gtk_OStream.h>
//exec sql include sqlca;
//#include <Aux/Transaction.h>
//#include <Aux/SQLerror.h>
#include "Schrift.hh"
#include "Sprache.hh"

void Sprache_auswahl::on_clist_sp_sc_select_row(gint row, gint column, GdkEvent *event)
{   
  cH_MidgardBasicElement *s=static_cast<cH_MidgardBasicElement*>(clist_sp_sc->selection().begin()->get_data());
  cH_Sprache(*s)->set_Erfolgswert(cH_Sprache(*s)->Maxwert());
  hauptfenster->MidgardBasicElement_uebernehmen(*s);

/*
//   std::string fert = clist_sp_sc->get_text(row,0);
   if (modus =="Sprache")
    {
//       int wert = atoi(clist_sp_sc->get_text(row,2).c_str());
//       hauptfenster->sprache_uebernehmen(fert,wert);
//       cH_Sprache *s=static_cast<cH_Sprache*>(clist_sp_sc->selection().begin()->get_data());
       cH_MidgardBasicElement *s=static_cast<cH_MidgardBasicElement*>(clist_sp_sc->selection().begin()->get_data());
//       cH_MidgardBasicElement s(new Sprache(fert));
//       cH_Sprache(s)->set_Erfolgswert(wert);
//       hauptfenster->MidgardBasicElement_uebernehmen(s);
       hauptfenster->MidgardBasicElement_uebernehmen(*s);
    }
   if (modus =="Lesen/Schreiben") 
    {
//      std::string typ  = clist_sp_sc->get_text(row,1);
//      hauptfenster->schrift_uebernehmen(fert,typ);
      cH_Schrift *s=static_cast<cH_Schrift*>(clist_sp_sc->selection().begin()->get_data());
//      hauptfenster->MidgardBasicElement_uebernehmen(new Schrift(fert));
//XXX       hauptfenster->MidgardBasicElement_uebernehmen(*s);
    }
*/
   destroy();
}


Sprache_auswahl::Sprache_auswahl(midgard_CG* h, const midgard_CG::st_Database& Database, const std::string& mod)
 : hauptfenster(h),modus(mod)
{
//   Grundwerte Werte;
   Gtk::OStream os(clist_sp_sc);
/*
   exec sql begin declare section;
      char db_1[50], db_2[50];
      char db_cname[50],db_version[50];
      int  db_3;
   exec sql end declare section;
  strncpy(db_cname,(Werte.Name_Charakter()).c_str(),sizeof(db_cname));
  strncpy(db_version,(Werte.Version()).c_str(),sizeof(db_version));
*/  
   if (mod == "Sprache")
      {
         sp_sc_label->set_text("Sprache w�hlen");
//         label_clist_sp_1->set_text("Sprache");
//         label_clist_sp_2->set_text("Urschrift");
         for (std::list<cH_MidgardBasicElement>::const_iterator i=Database.Sprache.begin();i!=Database.Sprache.end();++i)
          { 
            cH_Sprache s(*i);
            os << s->Name()<<'\t'<<s->Maxwert()<<'\n';
            os.flush(&const_cast<cH_MidgardBasicElement&>(*i));
          }
/*
         Transaction tr;
         exec sql declare ein cursor for
            SELECT DISTINCT  name, land, max_wert from sprachen
            WHERE name NOT IN (SELECT fertigkeit FROM charaktere_fertigkeiten
            WHERE art = 'Sprache' 
            AND charakter_name = :db_cname AND version = :db_version) order by name;
         exec sql open ein;
         SQLerror::test(__FILELINE__);
         while (true)
            {
               exec sql fetch ein into :db_1, :db_2, :db_3;
               SQLerror::test(__FILELINE__,100);
               if (sqlca.sqlcode) break;
               os << db_1<<"\t("<<db_2<<")\t"<<db_3<<"\n";
            }   
         tr.close();
         exec sql close ein;
*/
      }
   if (mod == "Lesen/Schreiben")
      {
         sp_sc_label->set_text("Schrift w�hlen");
//         label_clist_sp_1->set_text("Schrift");
//         label_clist_sp_2->set_text("Typ");
         for (std::list<cH_MidgardBasicElement>::const_iterator i=Database.Schrift.begin();i!=Database.Schrift.end();++i)
          { 
            cH_Schrift s(*i);
            os << s->Name()<<s->Art_der_Schrift()<<'\n';
            os.flush(&const_cast<cH_MidgardBasicElement&>(*i));
          }
/*
         Transaction tr;
         exec sql declare ein2 cursor for
            SELECT DISTINCT  name, typ from schrift WHERE  name 
            NOT IN (SELECT fertigkeit FROM charaktere_fertigkeiten
            WHERE art = 'Urschrift' 
            AND charakter_name = :db_cname AND version = :db_version) 
            order by name;
         exec sql open ein2;
         SQLerror::test(__FILELINE__);
         while (true)
            {
               exec sql fetch ein2 into :db_1, :db_2;
               SQLerror::test(__FILELINE__,100);
               if (sqlca.sqlcode) break;
               os << db_1<<"\t("<<db_2<<")\n";
            }   
         tr.close();
         exec sql close ein2;
*/
      }
   for (unsigned int i=0;i<clist_sp_sc->columns().size();++i)
      clist_sp_sc->set_column_auto_resize(i,true);
}
