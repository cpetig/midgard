// $Id: Window_lernpunkte_editieren.cc,v 1.16 2001/07/29 20:29:59 thoma Exp $
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

// generated 2001/2/7 8:11:20 CET by thoma@ig23.
// using glademm V0.5_11c
//
// newer (non customized) versions of this file go to lernpunkte_editieren.cc_glade

// This file is for your program, I won't touch it again!

#include "Window_lernpunkte_editieren.hh"
#include "midgard_CG.hh"

void Window_lernpunkte_editieren::on_close_clicked()
{   
#warning Christof: Warum funktioniert das nicht so ?
  lernpunkte->set_Beruf(lernpunkte_b_ein->get_value_as_int());
  lernpunkte->set_Fertigkeit (lernpunkte_f_ein->get_value_as_int());
  lernpunkte->set_Waffen       (lernpunkte_w_ein->get_value_as_int());
  lernpunkte->set_Zauber       (lernpunkte_z_ein->get_value_as_int());
# warning sondern nur so?
  lernpunkte->set_Beruf      (atoi(lernpunkte_b_ein->get_text().c_str()));
  lernpunkte->set_Fertigkeit (atoi(lernpunkte_f_ein->get_text().c_str()));
  lernpunkte->set_Waffen     (atoi(lernpunkte_w_ein->get_text().c_str()));
  lernpunkte->set_Zauber     (atoi(lernpunkte_z_ein->get_text().c_str()));

  hauptfenster->setze_lernpunkte(*lernpunkte);
  destroy();
}

Window_lernpunkte_editieren::Window_lernpunkte_editieren(midgard_CG* h, Lernpunkte* l)
: lernpunkte(l)
{
  hauptfenster=h;
  lernpunkte_b_ein->set_text(itos(lernpunkte->Beruf()));
  lernpunkte_f_ein->set_text(itos(lernpunkte->Fertigkeiten()));
  lernpunkte_w_ein->set_text(itos(lernpunkte->Waffen()));
  lernpunkte_z_ein->set_text(itos(lernpunkte->Zauber()));
}
