// $Id: WindowInfo_glade.cc,v 1.14 2001/04/19 11:45:35 christof Exp $
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

// generated 2001/4/19 8:46:44 CEST by thoma@ig23.
// using glademm V0.5_11f_cvs
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- /home/thoma/rollenspiel/midgard/programme/gra_mygen/midgard.glade
// for gtk 1.2.8 and gtkmm 1.2.4
//
// Please modify the corresponding derived classes in ./src/WindowInfo.cc

#include "config.h"
#include "WindowInfo.hh"
#include <gtk--/box.h>

WindowInfo_glade::WindowInfo_glade(
) : Gtk::Window(GTK_WINDOW_DIALOG)
{   
   
   Gtk::Window *WindowInfo = this;
   infotext = manage(new class Gtk::Label("infotext"));
   button_info_ok = manage(new class Gtk::Button("OK"));
   
   Gtk::VBox *vbox4 = manage(new class Gtk::VBox(false, 0));
   infotext->set_usize(400, 300);
   infotext->set_alignment(0.5, 0.5);
   infotext->set_padding(0, 0);
   vbox4->pack_start(*infotext);
   vbox4->pack_start(*button_info_ok, false, false, 0);
   WindowInfo->set_title("Info");
   WindowInfo->set_policy(true, true, true);
   WindowInfo->add(*vbox4);
   infotext->show();
   button_info_ok->show();
   vbox4->show();
   WindowInfo->show();
   button_info_ok->clicked.connect(SigC::slot(static_cast<class WindowInfo*>(this), &WindowInfo::on_button_info_ok_clicked));
}

WindowInfo_glade::~WindowInfo_glade()
{   
}
