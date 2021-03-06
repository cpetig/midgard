/*  Midgard Character Generator
 *  Copyright (C) 2001 Malte Thoma
 *  Copyright (C) 2006 Christof Petig
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
#include <Gtk_OStream.h>
#include <SelectMatching.h>
#include "LernListen.hh"
#include <Misc/Trace.h>
#include "MagusDialog.hh"
#include <libmagus/Datenbank.hh>
#include <libmagus/NotFound.h>
#include <Misc/TemporaryValue.h>

void table_grundwerte::fill_typauswahl()
{
  ManuProC::Trace _t(table_grundwerte::trace_channel,__FUNCTION__);
  if(!hauptfenster) return;
  fill_typauswahl_fill(1);
  if (!hauptfenster->getAben().getVTyp().empty()) 
   {
     combo_typ->get_entry()->set_text(hauptfenster->getAben().Typ1()->Name(hauptfenster->getAben().Geschlecht()));
   }
}

void table_grundwerte::fill_typauswahl_2()
{
  ManuProC::Trace _t(table_grundwerte::trace_channel,__FUNCTION__);
  if(!hauptfenster) return;
  fill_typauswahl_fill(2);
  combo_typ2->get_entry()->set_text(hauptfenster->getAben().Typ2()->Name(hauptfenster->getAben().Geschlecht()));
}

void table_grundwerte::fill_typauswahl_fill(int typ_1_2)
{
  ManuProC::Trace _t(table_grundwerte::trace_channel,__FUNCTION__);
  const std::vector<std::pair<cH_Typen,bool> > T=LernListen::getTypen(hauptfenster->getAben());
  std::list<std::string> L;
  for(std::vector<std::pair<cH_Typen,bool> >::const_iterator i=T.begin();i!=T.end();++i)
   {
// diese Logik scheint mir etwas unvollständig, CP
// erste Combo: Kämpfer, zweite Combo: Zauberer
#warning Zauberer wird zum Kämpfer fehlt!
     if(combo_typ2->is_visible() && typ_1_2==1 && i->first->Zaubern()=="z") continue;
     if(typ_1_2==2 && i->first->Zaubern()!="z") continue;
         {
           if(i->second)
              L.push_back(i->first->Name(hauptfenster->getAben().Geschlecht()));
           else
              L.push_back("("+i->first->Name(hauptfenster->getAben().Geschlecht())+")");
         }
   }
 TemporaryValue<bool> tv(block_changed,true);
 if(typ_1_2==1) combo_typ->set_popdown_strings(L);
 else           combo_typ2->set_popdown_strings(L);
}

void table_grundwerte::on_combo_typ_activate()
{
//  button_abg_werte->set_sensitive(true);
  button_abg_werte->grab_focus();
}

void table_grundwerte::on_combo_typ__changed()
{
 if(!block_changed) typauswahl_button();
}

bool table_grundwerte::on_combo_typ__focus_out_event(GdkEventFocus *ev)
{
  typauswahl_button();
  return false;
}

enum { Button_Stadt, Button_Land };

void table_grundwerte::typauswahl_button()
{
 ManuProC::Trace _t(table_grundwerte::trace_channel,__FUNCTION__);
 hauptfenster->getChar()->begin_undo();
 std::string typ=combo_typ->get_entry()->get_text();
 try
 { if (typ.size()>2 && typ[0]=='(' && typ[typ.size()-1]==')')
     typ=typ.substr(1,typ.size()-2);
   hauptfenster->getAben().setTyp1(Typen::getTyp(typ));
 } catch (NotFound &n) { return; }
 hauptfenster->getChar()->name_undo("Typ auf " + typ + " geändert");

 hauptfenster->getChar().getWizard().done(Wizard::TYP,hauptfenster->getAben());
// if (Typ[0]->Short()=="dBe" || Typ[0]->Short()=="eBe") angeborene_zauber();

 if(hauptfenster->getAben().Spezies()->Land()) 
   {
     button_stadt_land->set_sensitive(false);
     button_stadt_land->set_index(Button_Land);
   }
 else if(!hauptfenster->getAben().Typ1()->Stadt())
   {
     button_stadt_land->set_sensitive(false);
     button_stadt_land->set_index(Button_Land);
   }
 else if(!hauptfenster->getAben().Typ1()->Land())
   {
     button_stadt_land->set_sensitive(false);
     button_stadt_land->set_index(Button_Stadt);
   }
 else
   { button_stadt_land->set_sensitive(true);
   }
}


void table_grundwerte::on_combo_typ2_activate()
{
  button_abg_werte->grab_focus();
}

void table_grundwerte::on_combo_typ2__changed()
{
 if(!block_changed)typauswahl_2_button();
}

bool table_grundwerte::on_combo_typ2_focus_out_event(GdkEventFocus *ev)
{
  typauswahl_2_button();
  return false;
}

void table_grundwerte::typauswahl_2_button()
{
 ManuProC::Trace _t(table_grundwerte::trace_channel,__FUNCTION__);
 hauptfenster->getChar()->begin_undo();
 std::string typ=combo_typ2->get_entry()->get_text();
 try
 { hauptfenster->getAben().setTyp2(Typen::getTyp(typ));
   hauptfenster->getChar()->name_undo("2. Typ auf " + typ + " geändert");
 } catch (NotFound &n) 
 { hauptfenster->getChar()->cancel_undo(); 
   return; 
 }
}


void table_grundwerte::fill_spezies()
{
  ManuProC::Trace _t(table_grundwerte::trace_channel,__FUNCTION__);
  std::vector<std::string> L;
  bool nsc_allowed = hauptfenster?bool(hauptfenster->getAben().getOptionen().OptionenCheck(Optionen::NSC_only).active):false;
  std::vector<cH_Spezies>V=LernListen::getSpezies(nsc_allowed);
  for(std::vector<cH_Spezies>::const_iterator i=V.begin();i!=V.end();++i)
   {
     L.push_back((*i)->Name());
   }
 TemporaryValue<bool> tv(block_changed,true);
 combo_spezies->set_popdown_strings(L);
}

void table_grundwerte::on_combo_spezies_activate()
{
 button_grundwerte->grab_focus();
}

void table_grundwerte::on_combo_spezies_changed()
{
 if(!block_changed) spezieswahl_button();
}


bool table_grundwerte::on_combo_spezies_focus_out_event(GdkEventFocus *ev)
{
//cout << "Fokus out\n";
//  spezieswahl_button();
  return false;
}

void table_grundwerte::spezieswahl_button()
{
 ManuProC::Trace _t(table_grundwerte::trace_channel,__FUNCTION__);
 std::string spezies=combo_spezies->get_entry()->get_text();
 if(!Spezies::get_Spezies_from_long(spezies))
   return;
 hauptfenster->getChar()->begin_undo();
 hauptfenster->getAben().getWerte().reset(); // = Grundwerte(true);
 hauptfenster->getAben().setSpezies(Spezies::getSpezies(spezies));
 hauptfenster->getChar()->name_undo("Spezies gewählt");
 fill_typauswahl();

 if (hauptfenster->getAben().Spezies()->Name()=="Elf")
 { MagusDialog d(hauptfenster);
   d.set_text("Soll dieser Elf ein Doppeltyp-Abenteurer sein?");
   if (d.run()==Gtk::RESPONSE_OK) doppelcharaktere();
 }  
 hauptfenster->getChar().getWizard().done(Wizard::SPEZIES,hauptfenster->getAben());
}

void table_grundwerte::on_radiobutton_stadt_land_toggled()
{
  ManuProC::Trace _t(table_grundwerte::trace_channel,__FUNCTION__);
  if(block_changed) return;
  hauptfenster->getChar().getWizard().done(Wizard::STADTLAND,hauptfenster->getAben());

  if(button_stadt_land->get_index()==Button_Land) hauptfenster->getAben().setStadtLand(Enums::Land);
  else                                hauptfenster->getAben().setStadtLand(Enums::Stadt);
}


void table_grundwerte::doppelcharaktere()
{
  ManuProC::Trace _t(table_grundwerte::trace_channel,__FUNCTION__);
   if(!hauptfenster) return;
   combo_typ2->show();
   fill_typauswahl();
   fill_typauswahl_2();
}

void table_grundwerte::on_radiobutton_mann_toggled()
{
  ManuProC::Trace _t(table_grundwerte::trace_channel,__FUNCTION__);
  if(block_changed) return;
  hauptfenster->getChar()->begin_undo();
  hauptfenster->getChar().getWizard().done(Wizard::GESCHLECHT,hauptfenster->getAben());
  Enums::geschlecht oldG=hauptfenster->getAben().Geschlecht();
  hauptfenster->getAben().setGeschlecht(button_geschlecht->get_index() ? Enums::Frau : Enums::Mann);
  if(oldG!=hauptfenster->getAben(). Geschlecht() && hauptfenster->getAben(). Groesse() && hauptfenster->getAben(). Spezies()->Name()=="Mensch")
   {
     if( hauptfenster->getAben(). Geschlecht()==Enums::Frau) hauptfenster->getAben(). setGroesse(hauptfenster->getAben(). Groesse()-10);
     else hauptfenster->getAben(). setGroesse(hauptfenster->getAben(). Groesse()+10);
   }
  if(oldG!=hauptfenster->getAben().Geschlecht() && hauptfenster->getAben().Gewicht() && hauptfenster->getAben().Spezies()->Name()=="Mensch")
   {
     if( hauptfenster->getAben().Geschlecht()==Enums::Frau) hauptfenster->getAben().setGewicht(hauptfenster->getAben().Gewicht()-4);
     else hauptfenster->getAben().setGewicht(hauptfenster->getAben().Gewicht()+4);
   }
  fill_typauswahl();
  fill_typauswahl_2();
  hauptfenster->getChar()->name_undo("Geschlecht gewählt");
}

/*
void table_grundwerte::kaempfer_lernt_zaubern()
{
  ManuProC::Trace _t(table_grundwerte::trace_channel,__FUNCTION__);
  if(!hauptfenster) return;
  hauptfenster->notebook_main->set_current_page(midgard_CG::PAGE_GRUNDWERTE);
  doppelcharaktere();
  hauptfenster->InfoFenster->AppendShow("Jetzt unter 'Grundwerte' die zweite Charkakterklasse wählen\n",WindowInfo::None);
  if (hauptfenster->getAben().Zaubern_wert()==2) 
      hauptfenster->getAben().setZaubern_wert(10);
}
*/
