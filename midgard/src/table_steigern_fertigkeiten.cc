/*  Copyright (C) 2001 Malte Thoma
 *  Copyright (C) 2004-2005 Christof Petig
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

#include <Gtk_OStream.h>
#include <Misc/create_parse.h>
#include <libmagus/Ausgabe.hh>
#include <libmagus/Datenbank.hh>
#include <libmagus/NotFound.h>
#include <libmagus/Fertigkeiten.hh>
#include <libmagus/Waffe.hh>
#include <libmagus/LernListen.hh>
#include "midgard_CG.hh"
#include "table_steigern.hh"
#include "class_SimpleTree.hh"

void table_steigern::fertigkeiten_zeigen()
{ if (notebook_lernen->get_current_page()!=PAGE_FERTIGKEITEN) return;
  alte_fertigkeiten_zeigen();
  neue_fertigkeiten_zeigen();
  zeige_werte();
}

void table_steigern::neue_fertigkeiten_zeigen()
{
  Abenteurer &A=hauptfenster->getAben();
  list_Fertigkeit_neu=LernListen::get_steigern_MBEm(A,MidgardBasicElement::FERTIGKEIT);
  MidgardBasicTree::show_list_in_tree(list_Fertigkeit_neu,neue_fert_tree,hauptfenster->getChar().actualIterator());
}

void table_steigern::alte_fertigkeiten_zeigen()
{
 MidgardBasicTree::show_list_in_tree(hauptfenster->getAben().List_Fertigkeit(),alte_fert_tree,hauptfenster->getChar().actualIterator());
}

void table_steigern::on_leaf_selected_alte_fert(cH_RowDataBase d)
{
#warning wozu das?
  // CP: das unselektiert die Zeile - ist aber harmlos IIRC
//  if (button_was_tun->get_index()==Button_PP_eingeben)
//    alte_fert_tree->get_selection()->unselect_all();
}

#warning !1-click
void table_steigern::on_leaf_selected_alte_fert2(cH_RowDataBase rdb, bool &handled)
{ if (button_was_tun->get_index()!=Button_PP_eingeben)
  { MidgardBasicElement_leaf_alt(rdb);
    handled=true;
  }
}

void table_steigern::on_alte_fert_reorder()
{
  std::deque<guint> seq = alte_fert_tree->get_seq();
  switch((Data_SimpleTree::Spalten_LONG_ALT)seq[0]) {
      case Data_SimpleTree::NAMEa : hauptfenster->getAben().List_Fertigkeit().sort(MBEmlt::sort(MBEmlt::sort::NAME)); ;break;
      case Data_SimpleTree::WERTa : hauptfenster->getAben().List_Fertigkeit().sort(MBEmlt::sort(MBEmlt::sort::ERFOLGSWERT)); ;break;
      default : Ausgabe(Ausgabe::Error,"Sortieren nach diesem Parameter ist nicht möglich");
   }
}

#warning das sollte vereinheitlicht werden!
// vielleicht in table_steigern::neu_lernen tun
void table_steigern::on_neue_fert_clicked(cH_RowDataBase rdb, bool &handled)
{ if (button_was_tun->get_index()!=Button_PP_eingeben)
  { // MidgardBasicElement_leaf_neu(rdb);
    MBEmlt MBE = rdb.cast_dynamic<const Data_SimpleTree>()->getMBE();
    if ((*MBE)->Name()=="KiDo") 
      { zeige_werte();
        Ausgabe(Ausgabe::ActionNeeded,"Jetzt muss ein Stil unter 'Lernschema' -> 'KiDo' gewählt werden !!!");
#warning Kido Stil mit Wizard realisieren!
  //      hauptfenster->load_for_mainpage(midgard_CG::PAGE_LERNEN);
  //          Wizard::KIDO_STIL
        MidgardBasicElement_leaf_neu(rdb);
      }
    else if ((*MBE)->Name()=="Zaubern") 
      {  
        kaempfer_lernt_zaubern();
      }
    else 
    {  
       MidgardBasicElement_leaf_neu(rdb);
       return;
    }
    handled=true;
  }
}

void table_steigern::on_leaf_selected_neue_fert(cH_RowDataBase d)
{  
//  fertigkeiten_zeigen();
}



void table_steigern::kaempfer_lernt_zaubern() 
{
  hauptfenster->getChar().getWizard().set(Wizard::ZWEITER_TYP);
#if 0
// Wizard::ZWEITER_TYP
 Gtk::HBox *_b=manage(new Gtk::HBox());

 Gtk::Button *_button=manage(new Gtk::Button("Abbrechen"));
 _button->signal_clicked().connect(SigC::slot(*this, &table_steigern::zaubern_klasse_gewaehlt_abbrechen));
 _b->pack_start(*_button,false, false, 0);

 Gtk::Combo *_ct = manage(new class Gtk::Combo());
 _ct->get_entry()->set_editable(false); 
 const std::vector<std::pair<cH_Typen,bool> > T=LernListen::getTypen(hauptfenster->getAben());
 std::list<std::string> L;
 for(std::vector<std::pair<cH_Typen,bool> >::const_iterator i=T.begin();i!=T.end();++i)
  {
    if( i->first->Zaubern()!="z") continue;
    if(i->second)
      L.push_back(i->first->Name(hauptfenster->getAben().Geschlecht()));
    else
      L.push_back("("+i->first->Name(hauptfenster->getAben().Geschlecht())+")");
  }
 _ct->set_popdown_strings(L);
 _ct->get_entry()->signal_changed().connect(SigC::slot(*this, &table_steigern::zaubern_klasse_gewaehlt));
 _b->pack_start(*_ct,false, false, 0);
 frame_spezielles->set_label("Zweite Abenteurerklasse auswählen");
 frame_spezielles->add(*_b);
 frame_spezielles->show_all();
#endif
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
   try
   {  hauptfenster->getAben().setTyp2(Typen::getTyp(typ));
   } catch (NotFound &n) { return; }
   break;    
  }

 if (hauptfenster->getAben().Zaubern_wert()==2) 
     hauptfenster->getAben().setZaubern_wert(10);
 frame_spezielles->remove();
 frame_spezielles->hide();
 fertigkeiten_zeigen();
}

void table_steigern::zaubern_klasse_gewaehlt_abbrechen()
{
  frame_spezielles->remove();
  frame_spezielles->hide();
}
