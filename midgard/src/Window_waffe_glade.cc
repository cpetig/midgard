// generated 2001/3/23 9:13:54 CET by thoma@ig23.
// using glademm V0.5_11f_cvs
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- /home/thoma/rollenspiel/midgard/programme/gra_mygen/midgard.glade
// for gtk 1.2.8 and gtkmm 1.2.4
//
// Please modify the corresponding derived classes in ./src/Window_waffe.cc

#include "config.h"
#include "Window_waffe.hh"
#include <gtk--/label.h>
#include <gtk--/scrolledwindow.h>
#include <gtk--/table.h>

Window_waffe_glade::Window_waffe_glade(
) : Gtk::Window(GTK_WINDOW_TOPLEVEL)
{   
   
   Gtk::Window *Window_waffe = this;
   clist_waffe = manage(new class Gtk::CList(3));
   
   Gtk::ScrolledWindow *scrolledwindow37 = manage(new class Gtk::ScrolledWindow());
   Gtk::Label *label303 = manage(new class Gtk::Label("Waffe w�hlen"));
   Gtk::Table *table40 = manage(new class Gtk::Table(2, 3, false));
   clist_waffe->set_column_title(0, "Waffe");
   clist_waffe->set_column_width(0, 78);
   clist_waffe->set_column_title(1, "Grundkenntnisse");
   clist_waffe->set_column_width(1, 91);
   clist_waffe->set_column_title(2, "Schaden");
   clist_waffe->set_column_width(2, 80);
   clist_waffe->column_titles_show();
   scrolledwindow37->set_usize(414, 282);
   scrolledwindow37->set_policy(GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
   scrolledwindow37->add(*clist_waffe);
   label303->set_alignment(0, 0.5);
   label303->set_padding(0, 0);
   table40->attach(*scrolledwindow37, 0, 3, 1, 2, GTK_FILL, GTK_FILL, 0, 0);
   table40->attach(*label303, 0, 3, 0, 1, 0, 0, 3, 4);
   Window_waffe->set_title("Waffe");
   Window_waffe->add(*table40);
   clist_waffe->show();
   scrolledwindow37->show();
   label303->show();
   table40->show();
   Window_waffe->show();
   clist_waffe->select_row.connect(SigC::slot(static_cast<class Window_waffe*>(this), &Window_waffe::on_clist_waffe_select_row));
}

Window_waffe_glade::~Window_waffe_glade()
{   
}
