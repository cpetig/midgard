// generated 2002/10/14 9:40:12 CEST by thoma@Tiger.(none)
// using glademm V1.1.1c_cvs
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- /home/thoma/rollenspiel/midgard/programme/gcc_3.0/midgard/midgard.glade
// for gtk 1.2.10 and gtkmm 1.2.10
//
// Please modify the corresponding derived classes in ./src/Window_hilfe.cc

#include "config.h"
#include "Window_hilfe.hh"
#include <gdk/gdkkeysyms.h>
#include <gtk--/accelgroup.h>
#include <gtk--/scrolledwindow.h>
#include <gtk--/button.h>
#include <gtk--/pixmap.h>
#include "../pixmaps/SchliessenIII-50.xpm"
#include <gtk--/toolbar.h>
#include <gtk--/table.h>

Window_hilfe_glade::Window_hilfe_glade(
) : Gtk::Window(GTK_WINDOW_TOPLEVEL)
{  
   
   Gtk::Window *Window_hilfe = this;
   Gtk::AccelGroup *Window_hilfe_accgrp = Gtk::AccelGroup::create();
   _data = new GlademmData(Window_hilfe_accgrp);
   text_hilfe = manage(new class Gtk::Text());
   
   Gtk::ScrolledWindow *scrolledwindow25 = manage(new class Gtk::ScrolledWindow());
   Gtk::Toolbar *toolbar27 = manage(new class Gtk::Toolbar(GTK_ORIENTATION_HORIZONTAL, GTK_TOOLBAR_ICONS));
   Gtk::Table *table35 = manage(new class Gtk::Table(2, 4, false));
   
   toolbar27->tools().push_back(Gtk::Toolbar_Helpers::ButtonElem("", *manage(new Gtk::Pixmap(SchliessenIII_50_xpm)), 0));
   Gtk::Button *button56 = static_cast<Gtk::Button *>(toolbar27->tools().back()->get_widget());
   text_hilfe->set_usize(700,348);
   text_hilfe->set_flags(GTK_CAN_FOCUS);
   text_hilfe->set_editable(false);
   scrolledwindow25->set_policy(GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
   scrolledwindow25->add(*text_hilfe);
   toolbar27->set_border_width(5);
   toolbar27->set_space_size(5);
   toolbar27->set_tooltips(true);
   toolbar27->set_space_style(GTK_TOOLBAR_SPACE_EMPTY);
   table35->set_row_spacings(0);
   table35->set_col_spacings(0);
   table35->attach(*scrolledwindow25, 0, 4, 0, 1, GTK_EXPAND|GTK_SHRINK|GTK_FILL, GTK_EXPAND|GTK_SHRINK|GTK_FILL, 0, 0);
   table35->attach(*toolbar27, 3, 4, 1, 2, 0, 0, 0, 0);
   Window_hilfe->set_title("Hilfe");
   Window_hilfe->set_modal(false);
   Window_hilfe->set_position(GTK_WIN_POS_NONE);
   Window_hilfe->add_accel_group(*(_data->getAccelGroup()));
   Window_hilfe->add(*table35);
   text_hilfe->show();
   scrolledwindow25->show();
   toolbar27->show();
   table35->show();
   Window_hilfe->show();
   button56->clicked.connect(SigC::slot(static_cast<class Window_hilfe*>(this), &Window_hilfe::on_button_hilfe_schliessen_clicked));
}

Window_hilfe_glade::~Window_hilfe_glade()
{  delete _data;
}
