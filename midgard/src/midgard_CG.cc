// $Id: midgard_CG.cc,v 1.111 2002/01/12 09:23:30 thoma Exp $
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

// generated 2001/2/2 11:29:18 CET by thoma@ig23.
// using glademm V0.5_11c
//
// newer (non customized) versions of this file go to midgard_CG.cc_glade

// This file is for your program, I won't touch it again!

#include "midgard_CG.hh"
#include "Window_charakter_beschreibung.hh"
#include "Window_hilfe.hh"
#include "Window_Geld_eingeben.hh"
#include "Window_ruestung.hh"
#include "Window_waffe.hh"
#include "Window_Waffenbesitz.hh"
#include <gtk--/notebook.h>

//midgard_CG::midgard_CG(int argc,char **argv)
midgard_CG::midgard_CG(Datenbank& _Database)
: menu(0),Database(_Database)
{
  srand(time(0));
  on_neuer_charakter_clicked();
  set_tree_titles();
}

gint midgard_CG::on_eventbox_MCG_button_press_event(GdkEventButton *event) 
{ 
   if (event->button == 3) 
   {  menu->popup(event->button,event->time);
      return true;
   }
   return false;
}

gint midgard_CG::on_button_menu_button_release_event(GdkEventButton *event)
{
  menu->popup(event->button,event->time);
  return true;
}
 

void midgard_CG::set_tree_titles()
{
 std::vector<string> preis;
 preis.push_back("Art");
 preis.push_back("");
 preis.push_back("Kategorie");
 preis.push_back("Eigenschaft");
 preis.push_back("Kostenfaktor");
 preise_tree->setTitles(preis);
}

void midgard_CG::on_radiobutton_frau_toggled()
{   
  if (radiobutton_frau->get_active()) Werte.Geschlecht()="w";
   else Werte.set_Geschlecht("m");
  fill_typauswahl();
  fill_typauswahl_2();
  typauswahl->set_history(Typ[0]->Nr());
  typauswahl_2->set_history(Typ[1]->Nr());
}

void midgard_CG::on_radiobutton_mann_toggled()
{
  if (radiobutton_mann->get_active()) Werte.Geschlecht()="m";
   else Werte.set_Geschlecht("w");
  fill_typauswahl();
  fill_typauswahl_2();
  typauswahl->set_history(Typ[0]->Nr());
  typauswahl_2->set_history(Typ[1]->Nr());
}

void midgard_CG::show_gtk()
{
  typauswahl->set_history(Typ[0]->Nr());
  if (Typ[1]->Short()=="") typauswahl_2->hide();
  else
   { typauswahl_2->show(); 
     typauswahl_2->set_history(Typ[1]->Nr());
   }
//cout << "Geschlecht = " <<Werte.Geschlecht()<<'\n';
 fertig_typ->set_text(Typ[0]->Name(Werte.Geschlecht()));     // Charakterklasse im Lernfenster
 if (Typ[1]->Name(Werte.Geschlecht())!="") 
   fertig_typ->set_text(Typ[0]->Name(Werte.Geschlecht())+"/"+Typ[1]->Name(Werte.Geschlecht()));
 steigern_typ->set_text(Typ[0]->Name(Werte.Geschlecht()));     // Charakterklasse im Lernfenster
 if (Typ[1]->Name(Werte.Geschlecht())!="") 
   steigern_typ->set_text(Typ[0]->Name(Werte.Geschlecht())+"/"+Typ[1]->Name(Werte.Geschlecht()));
 
 zeige_werte(Werte);
 show_berufe();
 show_fertigkeiten();
 show_waffen();
 show_zauber();

 EP_uebernehmen();
 Geld_uebernehmen();
 steigern_gtk();

 // Spezialwaffe anzeigen?
 if (Typ[0]->Zaubern()=="n" || Typ[0]->Short() == "Ord") label_spezialwaffe->set_text("Spezialwaffe durch \nSelektieren ausw�hlen");
 else label_spezialwaffe->set_text("");

 // Magie anzeigen?
 if (Typ[0]->Zaubern()=="j" || Typ[0]->Zaubern() == "z" || magie_bool) 
   { if (Typ[0]->Short()=="Ma" || Typ[0]->Short() == "eBe") magier_spezialgebiet("show");
     else magier_spezialgebiet("hide");
     table_magier_lernen->show();
     table_magier_steigern->show();
   }
 else 
   { table_magier_lernen->hide();
     table_magier_steigern->hide();
   }
 // KiDo anzeigen?
 if (kido_bool) 
   { optionmenu_KiDo_Stile->show();
     table_kido_lernen->show();
     table_kido_steigern->show();
   }
 else 
   { optionmenu_KiDo_Stile->hide();
     table_kido_lernen->hide();
     table_kido_steigern->hide();
   }
 // KiDo Stil setzen
 int kido_stil_nr=0;
 if (Werte.Spezialisierung()=="Harte Techniken") kido_stil_nr = 1;
 if (Werte.Spezialisierung()=="Sanfte Techniken") kido_stil_nr = 2;
 if (Werte.Spezialisierung()=="Gemischte Techniken") kido_stil_nr = 3;
 if (kido_stil_nr!=0)
  {   
    optionmenu_KiDo_Stile->set_history(kido_stil_nr);
//    checkbutton_KanThaiPan->set_active(true);
//    KanThaiPanbool=true;
  }
}


void midgard_CG::on_charakter_beschreibung_clicked()
{   
  manage(new Window_charakter_beschreibung(this,Werte.Beschreibung())); 
}   
void midgard_CG::charakter_beschreibung_uebernehmen(const std::string& b)
{
  Werte.set_Beschreibung(b);
  on_speichern_clicked();
}
void midgard_CG::charakter_beschreibung_drucken(const std::string& b)
{
  Werte.set_Beschreibung(b);
  on_speichern_clicked();
  midgard_CG::latex_beschreibung_drucken();
}

void midgard_CG::on_button_hilfe_clicked()
{
  manage(new Window_hilfe()); 
}
void midgard_CG::on_button_info_clicked()
{   
  manage(new Midgard_Info());
}


void midgard_CG::on_button_geld_s_clicked()
{
  manage (new  Window_Geld_eingeben(this, Werte));
}
void midgard_CG::on_button_ruestung_s_clicked()
{
  manage (new Window_ruestung(Werte,this,Database));
}
void midgard_CG::on_button_waffen_s_clicked()
{
  manage (new Window_Waffenbesitz(this,Database,list_Waffen,list_Waffen_besitz,Werte,Typ));
}



/*****************************************************************/

void midgard_CG::clear_listen()
{
   list_Fertigkeit.clear();
   list_Fertigkeit_neu.clear();
   list_Fertigkeit_ang.clear();
   list_Waffen.clear();
   list_Waffen_neu.clear();
   list_WaffenGrund.clear();
   list_WaffenGrund_neu.clear();
   list_Waffen_besitz.clear();
   list_Kido.clear();
   list_Kido_neu.clear();
   list_Beruf.clear();
   list_Sprache.clear();
   list_Schrift.clear();
   list_Sprache_neu.clear();
   list_Schrift_neu.clear();
   list_Zauber.clear();
   list_Zauberwerk.clear();
   list_Zauber_neu.clear();
   list_Zauberwerk_neu.clear();
   besitz.clear();
}

void midgard_CG::clear_gtk()
{
   berufe_clist->clear();
   waffen_clist->clear();
   fertigkeiten_clist->clear();
   zauber_clist->clear();
   clist_kido->clear();
   alte_fert_tree->clear();
   neue_fert_tree->clear();
   alte_waffen_tree->clear();
   neue_waffen_tree->clear();
   alte_grund_tree->clear();
   neue_grund_tree->clear();
   alte_zauber_tree->clear();
   neue_zauber_tree->clear();
   alte_zaubermittel_tree->clear();
   neue_zaubermittel_tree->clear();
   alte_kido_tree->clear();
   neue_kido_tree->clear();
   alte_sprache_tree->clear();
   neue_sprache_tree->clear();
   alte_schrift_tree->clear();
   neue_schrift_tree->clear();
}

void midgard_CG::on_neuer_charakter_clicked()
{

   button_abg_werte->set_sensitive(false);
   button_herkunft->set_sensitive(false);
//   button_sprache->set_sensitive(false);
   button_beschreibung->set_sensitive(false);
   frame_steigern->set_sensitive(false);
   frame_lernschema->set_sensitive(false);

   button_lernpunkte->set_sensitive(false);
   button_lernpunkte_edit->set_sensitive(false);
   button_geld_waffen->set_sensitive(false);
   button_ruestung->set_sensitive(false);

   vbox_beruferfolgswert->hide();
   hbox_beruf->set_sensitive(false);
   table_beruf->set_sensitive(false);
   hbox_fertigkeit->set_sensitive(false);
   table_fertigkeit->set_sensitive(false);
   hbox_waffen->set_sensitive(false);
   table_waffen->set_sensitive(false);
   hbox_zauber->set_sensitive(false);
//XXX   table_magier_lernen->set_sensitive(false);
   hbox_kido->set_sensitive(false);
   table_kido_lernen->set_sensitive(false);
   scrolledwindow_landauswahl->hide();
   table_werte_wuerfeln->hide();
   table_bw_wurf->hide();
   spinbutton_pp_eingeben->hide();
   table_gruppe->hide();
   table_artikel->hide();
   togglebutton_gruppe_neu->hide(); // nicht implementiert

//   button_beruf_erfolgswert->set_sensitive(false);
   button_beruf_erfolgswert->hide();
   button_fertigkeiten->set_sensitive(false);
   button_kido_auswahl->set_sensitive(false);       

   Werte.clear();
   lernpunkte.clear();
   Typ.clear();
   Typ.resize(2);
   zeige_lernpunkte();
   zeige_werte(Werte);
   Originalbool=true; // checkbutton_original->set_active(true);
   Infobool=true;      //checkbutton_original->set_active(true);
   for(std::vector<cH_Region>::const_iterator i=Database.Regionen.begin();i!=Database.Regionen.end();++i)
      (*i)->setActive(false);
   menu_init();

   steigern_bool=true; checkbutton_EP_Geld->set_active(steigern_bool);

   Database.GradAnstieg.set_Grad_Basiswerte(1);
//   vscale_EP_Gold->set_digits(Database.GradAnstieg.get_Steigern_EP_Prozent());
   label_EP->set_text("50%");
   label_Gold->set_text("50%");

//  on_checkbutton_original_toggled();
  kido_bool=false;
  magie_bool=false;
  fill_typauswahl();
  fill_spezies();
  spezieswahl_button();
  typauswahl_button(); // ruft clear_listen() und clear_gtk() auf
  show_gtk();
}

void midgard_CG::on_schliessen_CG_clicked()
{
  system("rm midgard_tmp_*");
  Gtk::Main::instance()->quit();
}

