/*  Midgard Character Generator
 *  Copyright (C) 2001-2002 Malte Thoma
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
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, U
 */

#include "midgard_CG.hh"
#include <cstring>

void midgard_CG::wizard_do_nothing()
{
}

void midgard_CG::wizard_do_something()
{
  if(!wizard) return;
  Wizard_window::esteps e=wizard->ActualStep();
  GdkEventButton button;
  memset(&button,0,sizeof button);
  button.button=1;
  switch (e) {
      case Wizard_window::SPEZIES : notebook_main->set_sensitive(true);break;
      case Wizard_window::GRUNDWERTE : grundwerte_wuerfeln(); break;
      case Wizard_window::GESCHLECHT : notebook_main->set_sensitive(true);break;
      case Wizard_window::TYP : notebook_main->set_sensitive(true);break;
      case Wizard_window::STADTLAND : notebook_main->set_sensitive(true);break;
      case Wizard_window::ABGELEITETEWERTE : on_abge_werte_setzen_clicked(); break;
      case Wizard_window::HERKUNFT : on_herkunftsland_clicked(); break;
      case Wizard_window::ANGEBORENEFERTIGKEITEN : on_angeborene_fertigkeit_clicked(); break;
      case Wizard_window::LERNPUNKTE : on_lernpunkte_wuerfeln_clicked(); break;
      case Wizard_window::WAEHLEN : notebook_main->set_sensitive(true); break;
      case Wizard_window::BERUF: beruf_gewuerfelt(random.integer(1,100)); break;
      case Wizard_window::SPEZIALWAFFE :
         if(Typ[0]->Spezialwaffe() || Typ[1]->Spezialwaffe() )
             togglebutton_spezialwaffe->set_active(true); 
         break;
      case Wizard_window::SPEZIALGEBIET : notebook_main->set_sensitive(true); break;
      case Wizard_window::GELD : on_button_lernschema_geld_button_release_event(&button); break;
      case Wizard_window::WAFFEN : on_button_lernschema_waffen_button_release_event(&button); break;
      case Wizard_window::RUESTUNG : on_button_ruestung_button_release_event(&button); break;
      case Wizard_window::SPEICHERN : on_speichern_release_event(&button); break;
      case Wizard_window::FERTIG : on_button_close_wizard_clicked(); break;
      default: regnot("Nicht impelmentiert");break;
   }
}

void midgard_CG::wizard_starten_clicked()
{
 on_neuer_charakter_clicked();
 wizard = manage(new class Wizard_window(this));
 notebook_main->set_sensitive(false);
 wizard->restart();
}

void midgard_CG::on_button_close_wizard_clicked()
{
 wizard=0;
 notebook_main->set_sensitive(true);
}