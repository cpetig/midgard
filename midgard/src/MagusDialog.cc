// $Id: MagusDialog.cc,v 1.5 2004/12/21 07:24:14 christof Exp $
/*  Midgard Character Generator
 *  Copyright (C) 2001 Malte Thoma
 *  Copyright (C) 2003 Christof Petig
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

#include "config.h"
#include <gtkmm/main.h>
#include "midgard_CG.hh"
#include "Fertigkeiten.hh"
#include <gtkmm/button.h>
#include <gtkmm/table.h>   
#include <gtkmm/label.h>
#include <gtkmm/box.h>
#include <Misc/itos.h>
extern Glib::RefPtr<Gdk::Pixbuf> MagusImage(const std::string &name);
#include "MagusDialog.hh"

#if 0
void MagusDialog::on_button_abbrechen_clicked()
{   delete this;
}
#endif

bool MagusDialog::on_WindowInfo_delete_event(GdkEventAny *ev)
{ hide();
  return false; // verhindert das zerstören des Objektes
}

MagusDialog::MagusDialog(Gtk::Window *w)
{ set_transient_for(*w);
  show();
}

void MagusDialog::set_text(const std::string& s)
{  text->set_text(s);
}

void MagusDialog::set_yes_no(const std::string& y,const std::string& n)
{  text_yes->set_text(y);
   text_no->set_text(n);
}

int MagusDialog::run()
{  return Gtk::Dialog::run();
}

void MagusDialog::set_style(const bitmask<style_bits> &st)
{  if (st & b_Nein) cancelbutton->show();
   else cancelbutton->hide();
   if (st & b_Ja) okbutton->show();
   else okbutton->hide();
   if (st & b_Close) closebutton->show();
   else closebutton->hide();
}
