// $Id: table_lernschema_kido.cc,v 1.2 2002/05/22 17:00:45 thoma Exp $
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

#include "table_grundwerte.hh"
//#include "KiDo_auswahl.hh"
#include <Gtk_OStream.h>
#include "KiDo.hh"
#include "class_SimpleTree.hh"
#include <Aux/itos.h>
#include "midgard_CG.hh"

void table_lernschema::on_kido_wahl_clicked()
{
   if(!button_kido_auswahl->get_active()) return;
   KiDo_Stile kido_stil;
   if(!kido_stil.ist_gelernt(hauptfenster->getCWerte().Spezialisierung()))
    {
      hauptfenster->set_status("Erst eine Technik w�hlen\n");
      return;
    }
   hauptfenster->getChar().List_Kido().clear();
   fill_kido_lernschema();

//   manage(new KiDo_auswahl(this,maxkido,Werte,Database,hauptfenster->Typ,Vkido));
}

void table_lernschema::fill_kido_lernschema()
{
  clean_lernschema_trees();
  viewport_lernen->remove();
  if(maxkido==0) return;
  else if(maxkido==1) label_lernschma_titel->set_text(itos(maxkido)+" KiDo-Technik ausw�hlen");
  else label_lernschma_titel->set_text(itos(maxkido)+" KiDo-Techniken ausw�hlen");
  tree_kido_lernschema = manage(new MidgardBasicTree(MidgardBasicTree::KIDO));
  tree_kido_lernschema->leaf_selected.connect(SigC::slot(static_cast<class table_lernschema*>(this), &table_lernschema::on_tree_kido_lernschema_leaf_selected));

  std::list<cH_MidgardBasicElement> newlist;
  KiDo_Stile kido_stil;
  for(std::list<cH_MidgardBasicElement>::const_iterator i=hauptfenster->getDatabase().Kido.begin();i!=hauptfenster->getDatabase().Kido.end();++i)
   {
     cH_KiDo kd(*i);
     if(kd->Stufe()!="Sch�ler") continue;
     if (kido_stil.ist_hart(hauptfenster->getCWerte().Spezialisierung()))
         if(kido_stil.ist_sanft(kd->Stil())) continue;
     if (kido_stil.ist_sanft(hauptfenster->getCWerte().Spezialisierung()))
         if(kido_stil.ist_hart(kd->Stil())) continue;
     if ((*i)->ist_gelernt(hauptfenster->getCChar().CList_Kido())) continue ;
     newlist.push_back(*i);                                     
   }

  MidgardBasicElement::show_list_in_tree(newlist,tree_kido_lernschema,hauptfenster);
  scrolledwindow_lernen->show();
  tree_kido_lernschema->show();
  viewport_lernen->add(*tree_kido_lernschema);
}

void table_lernschema::on_tree_kido_lernschema_leaf_selected(cH_RowDataBase d)
{
  const Data_SimpleTree *dt=dynamic_cast<const Data_SimpleTree*>(&*d);
  cH_MidgardBasicElement MBE = dt->getMBE();
  hauptfenster->getChar().List_Kido().push_back(MBE);
  --maxkido;
  hauptfenster->undosave(MBE->Name()+" gelernt");
  fill_kido_lernschema();
  show_gelerntes();      
}


/*
void table_lernschema::show_kido()
{
   clist_kido->clear();
   Gtk::OStream os(clist_kido);
   for (std::list<cH_MidgardBasicElement>::const_iterator i=list_Kido.begin();i!=list_Kido.end();++i)
    {
      cH_KiDo kd(*i);
      os << kd->HoHo()<<"\t"<<kd->Deutsch()<<"\t"<<kd->Ap()<<"\t"<<kd->Kosten(Werte,hauptfenster->Typ)<<"\n";
    }
   for (unsigned int i=0;i<clist_kido->columns().size();++i)
      clist_kido->set_column_auto_resize(i,true);
}
*/

void table_lernschema::kido_stil_optionmenue()
{
//  static bool block=false;
//  if (block==true) return;
  KiDo_Stile kido_stil;
  int ityp = int(optionmenu_KiDo_Stile->get_menu()->get_active()->get_user_data());
  if (ityp==optionmenu_KiDo_Stile::sanft) hauptfenster->getWerte().setSpezialisierung(kido_stil.sanft());
  if (ityp==optionmenu_KiDo_Stile::hart) hauptfenster->getWerte().setSpezialisierung(kido_stil.hart());
  if (ityp==optionmenu_KiDo_Stile::gemischt) hauptfenster->getWerte().setSpezialisierung(kido_stil.gemischt());
  // NUR sensetiv setzen, wenn Abenteurerrschaffung also Grad=1
  if(hauptfenster->getCWerte().Grad()==1) button_kido_auswahl->set_sensitive(true);
}