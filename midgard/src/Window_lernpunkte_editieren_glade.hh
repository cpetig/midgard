// $Id: Window_lernpunkte_editieren_glade.hh,v 1.14 2001/04/19 11:45:35 christof Exp $
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
// Please modify the corresponding derived classes in ./src/Window_lernpunkte_editieren.hh and./src/Window_lernpunkte_editieren.cc

#ifndef _WINDOW_LERNPUNKTE_EDITIEREN_GLADE_HH
#  define _WINDOW_LERNPUNKTE_EDITIEREN_GLADE_HH

#include <gtk--/window.h>
#include <gtk--/spinbutton.h>

class Window_lernpunkte_editieren_glade : public Gtk::Window
{   
protected:
        
        class Gtk::SpinButton *lernpunkte_b_ein;
        class Gtk::SpinButton *lernpunkte_f_ein;
        class Gtk::SpinButton *lernpunkte_w_ein;
        class Gtk::SpinButton *lernpunkte_z_ein;
        
        Window_lernpunkte_editieren_glade();
        
        ~Window_lernpunkte_editieren_glade();
};
#endif
