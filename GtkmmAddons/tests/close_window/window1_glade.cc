/*  Gtk--addons: a collection of gtk-- addons
 *  Copyright (C) 2001 Adolf Petig GmbH & Co. KG, written by Christof Petig
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

// generated 2001/2/8 23:09:38 CET by christof@puck.(none)
// using glademm V0.5_11c
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- close_window.glade
// for gtk 1.2.8 and gtkmm 1.2.4
//
// Please modify the corresponding derived classes in ./src/window1.cc

#include "window1.hh"
#include <gtk--/button.h>

window1_glade::window1_glade(
) : Gtk::Window(GTK_WINDOW_TOPLEVEL)
{   
   
   Gtk::Window *window1 = this;
   Gtk::Button *button1 = manage(new Gtk::Button("spawn a new Window"));
   button1->set_name("button1");
   window1->set_name("window1");
   window1->set_title("Parent Window");
   window1->add(*button1);
   button1->show();
   window1->show();
   button1->clicked.connect(SigC::slot(static_cast<class window1*>(this), &window1::on_button1_clicked));
   window1->delete_event.connect(SigC::slot(static_cast<class window1*>(this), &window1::on_window1_delete_event));
}

window1_glade::~window1_glade()
{   
}