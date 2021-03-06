// $Id: table_lernschema_kido.cc,v 1.21 2006/02/20 08:08:54 christof Exp $
/*  Midgard Character Generator
 *  Copyright (C) 2001 Malte Thoma
 *  Copyright (C) 2004 Christof Petig
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

#include "table_grundwerte.hh"
//#include "KiDo_auswahl.hh"
#include <Gtk_OStream.h>
#include "KiDo.hh"
#include "class_SimpleTree.hh"
#include <Misc/itos.h>
#include "midgard_CG.hh"
#include <libmagus/Ausgabe.hh>
#include <libmagus/Datenbank.hh>

void table_lernschema::on_kido_wahl_clicked()
{
   if(!button_kido_auswahl->get_active()) return;
   KiDo_Stile kido_stil;
   if(!kido_stil.ist_gelernt(vabenteurer->getAbenteurer().Spezialisierung()))
    {
      Ausgabe(Ausgabe::Error,"Erst eine Technik wählen");
      return;
    }
   vabenteurer->getAbenteurer().List_Kido().clear();
   fill_kido_lernschema();
}

void table_lernschema::fill_kido_lernschema()
{
  clean_lernschema_trees();
  scrolledwindow_lernen->remove();
  if(!vabenteurer->getLernpunkte().MaxKido()) return;
  else if(vabenteurer->getLernpunkte().MaxKido()==1) label_lernschma_titel->set_text(itos(vabenteurer->getLernpunkte().MaxKido())+" KiDo-Technik auswählen");
  else label_lernschma_titel->set_text(itos(vabenteurer->getLernpunkte().MaxKido())+" KiDo-Techniken auswählen");
  tree_kido_lernschema = manage(new MidgardBasicTree(MidgardBasicTree::KIDO_NEU));
  tree_kido_lernschema->signal_leaf_selected().connect(SigC::slot(*static_cast<class table_lernschema*>(this), &table_lernschema::on_tree_kido_lernschema_leaf_selected));

  std::list<MBEmlt> newlist;
  KiDo_Stile kido_stil;
  for(std::list<cH_MidgardBasicElement>::const_iterator i=Datenbank.Kido.begin();i!=Datenbank.Kido.end();++i)
   {
     cH_KiDo kd(*i);
     if(kd->Stufe()!="Schüler") continue;
     if (kido_stil.ist_hart(vabenteurer->getAbenteurer().Spezialisierung()))
         if(kido_stil.ist_sanft(kd->Stil())) continue;
     if (kido_stil.ist_sanft(vabenteurer->getAbenteurer().Spezialisierung()))
         if(kido_stil.ist_hart(kd->Stil())) continue;
     if (MBEmlt(&*kd)->ist_gelernt(vabenteurer->getAbenteurer().List_Kido())) continue ;
     newlist.push_back(MBEmlt(*i));                                     
   }

  MidgardBasicTree::show_list_in_tree(newlist,tree_kido_lernschema,vabenteurer->actualIterator());
  scrolledwindow_lernen->show();
  tree_kido_lernschema->show();
  scrolledwindow_lernen->add(*tree_kido_lernschema);
}

void table_lernschema::on_tree_kido_lernschema_leaf_selected(cH_RowDataBase d)
{
  const Data_SimpleTree *dt=dynamic_cast<const Data_SimpleTree*>(&*d);
  cH_MidgardBasicElement MBE = dt->getMBE()->getMBE();
  vabenteurer->actualIterator()->begin_undo();
  vabenteurer->getAbenteurer().List_Kido().push_back(MBE);
  --vabenteurer->actualIterator()->getLernpunkte().MaxKido();
  vabenteurer->actualIterator()->name_undo(MBE->Name()+" gelernt");
  fill_kido_lernschema();
  show_gelerntes();      
}

void table_lernschema::on_combo_kido_stil_activate()
{
  button_kido_auswahl->grab_focus();
}

bool table_lernschema::on_combo_kido_stil_focus_out_event(GdkEventFocus *ev)
{
  KiDo_Stile ks;
  std::vector<std::string> V=ks.getVStile();
  for(std::vector<std::string>::const_iterator i=V.begin();i!=V.end();++i)
   {
     if(*i==combo_kido_stil->get_entry()->get_text())
      {
        vabenteurer->getAbenteurer().setSpezialisierung(*i);                
        if(vabenteurer->getAbenteurer().Grad()==1) button_kido_auswahl->set_sensitive(true);
        break;
      }
   }
  return false;
}

        

void table_lernschema::on_combo_kido_stil_changed()
{
}
