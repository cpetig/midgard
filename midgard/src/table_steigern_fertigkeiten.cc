/*  Copyright (C) 2001 Malte Thoma
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
#include "table_steigern.hh"
#include "class_SimpleTree.hh"
#include <Gtk_OStream.h>
#include "Fertigkeiten.hh"
#include "Waffe.hh"       
#include "LernListen.hh"
#include <libmagus/Ausgabe.hh>

void table_steigern::fertigkeiten_zeigen()
{
  alte_fertigkeiten_zeigen();
  neue_fertigkeiten_zeigen();
  zeige_werte();
}

void table_steigern::neue_fertigkeiten_zeigen()
{
  Abenteurer &A=hauptfenster->getChar().getAbenteurer();
  list_Fertigkeit_neu=LL->get_steigern_MBEm(A,Enums::sFert);
 MidgardBasicTree::show_list_in_tree(list_Fertigkeit_neu,neue_fert_tree,&hauptfenster->getChar().getAbenteurer());
}

void table_steigern::alte_fertigkeiten_zeigen()
{
 MidgardBasicTree::show_list_in_tree(hauptfenster->getChar()->List_Fertigkeit(),alte_fert_tree,&hauptfenster->getChar().getAbenteurer());
}


void table_steigern::on_leaf_selected_alte_fert(cH_RowDataBase d)
{  
 if (MidgardBasicElement_leaf_alt(d)) 
   {  
      dynamic_cast<const Data_SimpleTree*>(&*d)->redisplay(alte_fert_tree);
      neue_fertigkeiten_zeigen();
      zeige_werte();
      if(radiobutton_verlernen->get_active()) alte_fertigkeiten_zeigen();
   }
 if(!spinbutton_pp_eingeben->is_visible())
    alte_fert_tree->get_selection()->unselect_all();
}

void table_steigern::on_alte_fert_reorder()
{
  std::deque<guint> seq = alte_fert_tree->get_seq();
  switch((Data_SimpleTree::Spalten_LONG_ALT)seq[0]) {
      case Data_SimpleTree::NAMEa : hauptfenster->getChar()->List_Fertigkeit().sort(MBEmlt::sort(MBEmlt::sort::NAME)); ;break;
      case Data_SimpleTree::WERTa : hauptfenster->getChar()->List_Fertigkeit().sort(MBEmlt::sort(MBEmlt::sort::ERFOLGSWERT)); ;break;
      default : Ausgabe(Ausgabe::Error,"Sortieren nach diesem Parameter ist nicht möglich");
   }
}



void table_steigern::on_leaf_selected_neue_fert(cH_RowDataBase d)
{  
  const Data_SimpleTree *dt=dynamic_cast<const Data_SimpleTree*>(&*d);
  MBEmlt MBE = dt->getMBE();
  if ((*MBE)->Name()=="KiDo") 
    { zeige_werte();
      Ausgabe(Ausgabe::ActionNeeded,"Jetzt muß ein Stil unter 'Lernschema' -> 'KiDo' gewählt werden !!!");
      hauptfenster->load_for_mainpage(midgard_CG::PAGE_LERNEN);
      MidgardBasicElement_leaf_neu(d);      
    }
  else if ((*MBE)->Name()=="Zaubern") 
    {  
      kaempfer_lernt_zaubern();
    }
  else 
     MidgardBasicElement_leaf_neu(d);
  fertigkeiten_zeigen();
}



void table_steigern::kaempfer_lernt_zaubern() 
{
 Gtk::HBox *_b=manage(new Gtk::HBox());

 Gtk::Button *_button=manage(new Gtk::Button("Abbrechen"));
 _button->signal_clicked().connect(SigC::slot(*this, &table_steigern::zaubern_klasse_gewaehlt_abbrechen));
 _b->pack_start(*_button,false, false, 0);

 Gtk::Combo *_ct = manage(new class Gtk::Combo());
 _ct->get_entry()->set_editable(false); 
 bool nsc_allowed = hauptfenster->getChar().getAbenteurer().getOptionen().OptionenCheck(Optionen::NSC_only).active;
 const std::vector<std::pair<cH_Typen,bool> > T=LL->getTypen(hauptfenster->getChar().getAbenteurer());
 std::list<std::string> L;
 for(std::vector<std::pair<cH_Typen,bool> >::const_iterator i=T.begin();i!=T.end();++i)
  {
    if( i->first->Zaubern()!="z") continue;
    if(i->second)
      L.push_back(i->first->Name(hauptfenster->getChar().getAbenteurer().Geschlecht()));
    else
      L.push_back("("+i->first->Name(hauptfenster->getChar().getAbenteurer().Geschlecht())+")");
  }
 _ct->set_popdown_strings(L);
 _ct->get_entry()->signal_changed().connect(SigC::slot(*this, &table_steigern::zaubern_klasse_gewaehlt));
 _b->pack_start(*_ct,false, false, 0);
 frame_spezielles->set_label("Zweite Abenteurerklasse auswählen");
 frame_spezielles->add(*_b);
 frame_spezielles->show_all();
// _ct->set_use_arrows(true);
// _ct->set_use_arrows_always(false);
}

void table_steigern::zaubern_klasse_gewaehlt()
{
 Gtk::Widget *child=frame_spezielles->get_child();
 Gtk::Box_Helpers::BoxList &ch=dynamic_cast<Gtk::Box*>(child)->children();

 for(Gtk::Box_Helpers::BoxList::iterator i=ch.begin();i!=ch.end();++i)
  {
   if(!dynamic_cast<Gtk::Combo*>((*i).get_widget())) continue;
   Gtk::Combo *C=dynamic_cast<Gtk::Combo*>((*i).get_widget());
   std::string typ=C->get_entry()->get_text();
   if(!Typen::get_Typ_from_long(Datenbank.Typen,typ))
     return;
   hauptfenster->getChar()->setTyp2(cH_Typen(typ));
   break;    
  }

 if (hauptfenster->getChar().getAbenteurer().Zaubern_wert()==2) 
     hauptfenster->getChar().getAbenteurer().setZaubern_wert(10);
 frame_spezielles->remove();
 frame_spezielles->hide();
 fertigkeiten_zeigen();
}

void table_steigern::zaubern_klasse_gewaehlt_abbrechen()
{
  frame_spezielles->remove();
  frame_spezielles->hide();
}


