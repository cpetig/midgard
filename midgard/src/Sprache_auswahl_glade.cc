// generated 2001/5/8 15:14:14 CEST by thoma@Tiger.
// using glademm V0.6.2_cvs
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- /home/thoma/rollenspiel/midgard/programme/gra_mygen/midgard.glade
// for gtk 1.2.8 and gtkmm 1.2.5
//
// Please modify the corresponding derived classes in ./src/Sprache_auswahl.cc

#include "config.h"
#include "Sprache_auswahl.hh"
#include <gtk--/pixmap.h>
#include "../pixmaps/Lang_Script-trans-50.xpm"
#include <gtk--/scrolledwindow.h>
#include <gtk--/box.h>

Sprache_auswahl_glade::Sprache_auswahl_glade(
) : Gtk::Window(GTK_WINDOW_TOPLEVEL)
{   
   
   Gtk::Window *Sprache_auswahl = this;
   Gtk::Pixmap *pixmap18 = manage(new class Gtk::Pixmap(Lang_Script_trans_50_xpm));
   sp_sc_label = manage(new class Gtk::Label("label"));
   clist_sp_sc = manage(new class Gtk::CList(3));
   
   Gtk::ScrolledWindow *scrolledwindow18 = manage(new class Gtk::ScrolledWindow());
   Gtk::VBox *vbox11 = manage(new class Gtk::VBox(false, 0));
   pixmap18->set_alignment(0.5, 0.5);
   pixmap18->set_padding(0, 0);
   sp_sc_label->set_alignment(0.5, 0.5);
   sp_sc_label->set_padding(0, 0);
   clist_sp_sc->set_column_title(0, "label");
   clist_sp_sc->set_column_width(0, 80);
   clist_sp_sc->set_column_title(1, "label271");
   clist_sp_sc->set_column_width(1, 80);
   clist_sp_sc->set_column_title(2, "wert");
   clist_sp_sc->set_column_width(2, 80);
   scrolledwindow18->set_policy(GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
   scrolledwindow18->add(*clist_sp_sc);
   vbox11->pack_start(*pixmap18, false, true, 0);
   vbox11->pack_start(*sp_sc_label, false, false, 0);
   vbox11->pack_start(*scrolledwindow18);
   Sprache_auswahl->set_usize(270, 539);
   Sprache_auswahl->set_title("Sprache & Schrift");
   Sprache_auswahl->add(*vbox11);
   pixmap18->show();
   sp_sc_label->show();
   clist_sp_sc->show();
   scrolledwindow18->show();
   vbox11->show();
   Sprache_auswahl->show();
   clist_sp_sc->select_row.connect(SigC::slot(static_cast<class Sprache_auswahl*>(this), &Sprache_auswahl::on_clist_sp_sc_select_row));
}

Sprache_auswahl_glade::~Sprache_auswahl_glade()
{   
}
