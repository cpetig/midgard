// generated 2001/4/12 9:43:50 CEST by thoma@ig23.
// using glademm V0.5_11f_cvs
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- /home/thoma/rollenspiel/midgard/programme/gra_mygen/midgard.glade
// for gtk 1.2.8 and gtkmm 1.2.4
//
// Please modify the corresponding derived classes in ./src/Window_herkunft.cc

#include "config.h"
#include "Window_herkunft.hh"
#include <gtk--/pixmap.h>
#include "../pixmaps/CountrChar-trans-50.xpm"
#include <gtk--/label.h>
#include <gtk--/box.h>

Window_herkunft_glade::Window_herkunft_glade(
) : Gtk::Window(GTK_WINDOW_TOPLEVEL)
{   
   
   Gtk::Window *Window_herkunft = this;
   Gtk::Pixmap *pixmap17 = manage(new class Gtk::Pixmap(CountrChar_trans_50_xpm));
   clist_herkunftsland = manage(new class Gtk::CList(2));
   scrolledwindow19 = manage(new class Gtk::ScrolledWindow());
   
   Gtk::VBox *vbox12 = manage(new class Gtk::VBox(false, 0));
   pixmap17->set_alignment(0.5, 0.5);
   pixmap17->set_padding(0, 0);
   clist_herkunftsland->set_usize(274, 360);
   clist_herkunftsland->set_column_title(0, "Kontinent");
   clist_herkunftsland->set_column_width(0, 80);
   clist_herkunftsland->set_column_title(1, "Land");
   clist_herkunftsland->set_column_width(1, 80);
   clist_herkunftsland->column_titles_show();
   scrolledwindow19->set_policy(GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
   scrolledwindow19->add(*clist_herkunftsland);
   vbox12->pack_start(*pixmap17);
   vbox12->pack_start(*scrolledwindow19);
   Window_herkunft->set_title("Herkunft");
   Window_herkunft->add(*vbox12);
   pixmap17->show();
   clist_herkunftsland->show();
   scrolledwindow19->show();
   vbox12->show();
   Window_herkunft->show();
   clist_herkunftsland->select_row.connect(SigC::slot(static_cast<class Window_herkunft*>(this), &Window_herkunft::on_clist_herkunftsland_select_row));
}

Window_herkunft_glade::~Window_herkunft_glade()
{   
}
