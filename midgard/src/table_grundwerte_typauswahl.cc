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
#include <Gtk_OStream.h>
#include <SelectMatching.h>
#include "LernListen.hh"
#include <Misc/Trace.h>

void table_grundwerte::fill_typauswahl()
{
  ManuProC::Trace _t(table_grundwerte::trace_channel,__FUNCTION__);
  if(!hauptfenster) return;
  fill_typauswahl_fill(1);
  if (!hauptfenster->getChar()->getVTyp().empty()) 
   {
     combo_typ->get_entry()->set_text(hauptfenster->getChar()->Typ1()->Name(hauptfenster->Geschlecht()));
   }
}

void table_grundwerte::fill_typauswahl_2()
{
  ManuProC::Trace _t(table_grundwerte::trace_channel,__FUNCTION__);
  if(!hauptfenster) return;
  fill_typauswahl_fill(2);
  combo_typ2->get_entry()->set_text(hauptfenster->getChar()->Typ2()->Name(hauptfenster->Geschlecht()));
}

void table_grundwerte::fill_typauswahl_fill(int typ_1_2)
{
  ManuProC::Trace _t(table_grundwerte::trace_channel,__FUNCTION__);
  const std::vector<std::pair<cH_Typen,bool> > T=LernListen().getTypen(hauptfenster->getChar().getAbenteurer());
  std::list<std::string> L;
  for(std::vector<std::pair<cH_Typen,bool> >::const_iterator i=T.begin();i!=T.end();++i)
   {
     if(combo_typ2->is_visible() && typ_1_2==1 && i->first->Zaubern()=="z") continue;
     if(typ_1_2==2 && i->first->Zaubern()!="z") continue;
         {
           if(i->second)
              L.push_back(i->first->Name(hauptfenster->Geschlecht()));
           else
              L.push_back("("+i->first->Name(hauptfenster->Geschlecht())+")");
         }
   }
 block_changed=true;
 if(typ_1_2==1) combo_typ->set_popdown_strings(L);
 else           combo_typ2->set_popdown_strings(L);
 block_changed=false;
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
  hauptfenster->getChar().undosave("Typ gewählt");
  typauswahl_button();
  return false;
}

void table_grundwerte::typauswahl_button()
{
 ManuProC::Trace _t(table_grundwerte::trace_channel,__FUNCTION__);
 std::string typ=combo_typ->get_entry()->get_text();
 if(!Typen::get_Typ_from_long(Datenbank.Typen,typ))
   return;

 hauptfenster->getChar().getWizard().done(Wizard::TYP);
 hauptfenster->getChar()->setTyp1(cH_Typen(typ));

// if (Typ[0]->Short()=="dBe" || Typ[0]->Short()=="eBe") angeborene_zauber();

 if(hauptfenster->Spezies()->Land()) 
   {
     radiobutton_land->set_active(true);
     radiobutton_stadt->set_sensitive(false);
     radiobutton_land->set_sensitive(true);
   }
 else if(!hauptfenster->getChar()->Typ1()->Stadt())
   {
     radiobutton_land->set_active(true);
     radiobutton_land->set_sensitive(true);
     radiobutton_stadt->set_sensitive(false);
   }
 else if(!hauptfenster->getChar()->Typ1()->Land())
   {
     radiobutton_stadt->set_active(true);
     radiobutton_stadt->set_sensitive(true);
     radiobutton_land->set_sensitive(false);
   }
 else
   {
     radiobutton_stadt->set_sensitive(true);
     radiobutton_land->set_sensitive(true);
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
  hauptfenster->getChar().undosave("zweiter Typ gewählt");
  typauswahl_2_button();
  return false;
}

void table_grundwerte::typauswahl_2_button()
{
 ManuProC::Trace _t(table_grundwerte::trace_channel,__FUNCTION__);
 std::string typ=combo_typ2->get_entry()->get_text();
 if(!Typen::get_Typ_from_long(Datenbank.Typen,typ))
   return;

 hauptfenster->getChar()->setTyp2(cH_Typen(typ));

// if (Typ[1]->Short()=="dBe" || Typ[1]->Short()=="eBe") angeborene_zauber();
}


void table_grundwerte::fill_spezies()
{
 ManuProC::Trace _t(table_grundwerte::trace_channel,__FUNCTION__);
  std::vector<std::string> L;
  bool nsc_allowed = hauptfenster->getOptionen()->OptionenCheck(Optionen::NSC_only).active;
  std::vector<cH_Spezies>V=LernListen().getSpezies(nsc_allowed);
  for(std::vector<cH_Spezies>::const_iterator i=V.begin();i!=V.end();++i)
   {
     L.push_back((*i)->Name());
   }
 block_changed=true;
 combo_spezies->set_popdown_strings(L);
 block_changed=false;
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
 if(!Spezies::get_Spezies_from_long(Datenbank.Spezies,spezies))
   return;
 hauptfenster->getWerte() = Grundwerte();
 hauptfenster->setSpezies(Spezies::getSpezies(spezies,Datenbank.Spezies));

// hauptfenster->getChar().undosave("Spezies gewählt");
 fill_typauswahl();

 if (hauptfenster->Spezies()->Name()=="Elf")
   hauptfenster->InfoFenster->AppendShow("Soll dieser Elf ein Doppeltyp-Abenteurer sein?",WindowInfo::Elf_doppel);
   
 hauptfenster->getChar().getWizard().done(Wizard::SPEZIES);
}

void table_grundwerte::on_radiobutton_stadt_land_toggled()
{
  ManuProC::Trace _t(table_grundwerte::trace_channel,__FUNCTION__);
  if(block_changed) return;
  hauptfenster->getChar().getWizard().done(Wizard::STADTLAND);

  if(radiobutton_stadt->get_active()) hauptfenster->setStadtLand(Enums::Stadt);   
  else                                hauptfenster->setStadtLand(Enums::Land);   
}


void table_grundwerte::doppelcharaktere()
{
  ManuProC::Trace _t(table_grundwerte::trace_channel,__FUNCTION__);
   if(!hauptfenster) return;
   combo_typ2->show();
   fill_typauswahl();
   fill_typauswahl_2();
}

void table_grundwerte::on_radiobutton_frau_toggled()
{ on_radiobutton_mann_toggled(); }
void table_grundwerte::on_radiobutton_mann_toggled()
{
  ManuProC::Trace _t(table_grundwerte::trace_channel,__FUNCTION__);
  if(block_changed) return;
  hauptfenster->getChar().getWizard().done(Wizard::GESCHLECHT);
  Enums::geschlecht oldG=hauptfenster->Geschlecht();
  if (radiobutton_mann->get_active()) hauptfenster->setGeschlecht(Enums::Mann);
  else hauptfenster->setGeschlecht(Enums::Frau);
  if(oldG!=hauptfenster->Geschlecht() && hauptfenster->Groesse() && hauptfenster->Spezies()->Name()=="Mensch")
   {
     if( hauptfenster->Geschlecht()==Enums::Frau) hauptfenster->setGroesse(hauptfenster->Groesse()-10);
     if( hauptfenster->Geschlecht()==Enums::Mann) hauptfenster->setGroesse(hauptfenster->Groesse()+10);
   }
  if(oldG!=hauptfenster->Geschlecht() && hauptfenster->Gewicht() && hauptfenster->Spezies()->Name()=="Mensch")
   {
     if( hauptfenster->Geschlecht()==Enums::Frau) hauptfenster->setGewicht(hauptfenster->Gewicht()-4);
     if( hauptfenster->Geschlecht()==Enums::Mann) hauptfenster->setGewicht(hauptfenster->Gewicht()+4);
   }
  fill_typauswahl();
  fill_typauswahl_2();
//  hauptfenster->getChar().undosave("Geschlecht gewählt");
}

/*
void table_grundwerte::kaempfer_lernt_zaubern()
{
  ManuProC::Trace _t(table_grundwerte::trace_channel,__FUNCTION__);
  if(!hauptfenster) return;
  hauptfenster->notebook_main->set_current_page(midgard_CG::PAGE_GRUNDWERTE);
  doppelcharaktere();
  hauptfenster->InfoFenster->AppendShow("Jetzt unter 'Grundwerte' die zweite Charkakterklasse wählen\n",WindowInfo::None);
  if (hauptfenster->Zaubern_wert()==2) 
      hauptfenster->setZaubern_wert(10);
}
*/