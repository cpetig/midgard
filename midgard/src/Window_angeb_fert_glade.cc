// generated 2002/1/30 12:02:59 CET by thoma@Tiger.
// using glademm V0.6.2c_cvs
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- /home/thoma/rollenspiel/midgard/programme/gcc_3.0/midgard/midgard.glade
// for gtk 1.2.10 and gtkmm 1.2.5
//
// Please modify the corresponding derived classes in ./src/Window_angeb_fert.cc

#include "config.h"
#include "Window_angeb_fert.hh"
#include <gtk--/label.h>
#include <gtk--/scrolledwindow.h>
#include <gtk--/button.h>
#include <gtk--/pixmap.h>
#include "../pixmaps/SchliessenIII-50.xpm"
#include <gtk--/toolbar.h>
#include "../pixmaps/Angeb_Sicht-32.xpm"
#include "../pixmaps/Angeb_Nase-32.xpm"
#include "../pixmaps/Angeb_Richtung-32.xpm"
#include "../pixmaps/Angeb_Ohr-32.xpm"
#include "../pixmaps/Angeb_Reflex-32.xpm"
#include "../pixmaps/Angeb_Tast-32.xpm"
#include <gtk--/box.h>
#include <gtk--/table.h>

Window_angeb_fert_glade::Window_angeb_fert_glade(
) : Gtk::Window(GTK_WINDOW_TOPLEVEL)
{   
   
   Gtk::Window *Window_angeb_fert = this;
   clist_ang_fert_alt = manage(new class Gtk::CList(2));
   
   Gtk::ScrolledWindow *scrolledwindow44 = manage(new class Gtk::ScrolledWindow());
   clist_ang_fert_neu = manage(new class Gtk::CList(3));
   
   Gtk::ScrolledWindow *scrolledwindow45 = manage(new class Gtk::ScrolledWindow());
   label_ang_fert = manage(new class Gtk::Label("label325"));
   
   Gtk::Toolbar *toolbar31 = manage(new class Gtk::Toolbar(GTK_ORIENTATION_HORIZONTAL, GTK_TOOLBAR_ICONS));
   Gtk::Button *button60 = Gtk::wrap((GtkButton*)gtk_toolbar_append_element(GTK_TOOLBAR(toolbar31->gtkobj()), GTK_TOOLBAR_CHILD_BUTTON, 0, "", 0, 0, GTK_WIDGET(manage(new Gtk::Pixmap(SchliessenIII_50_xpm))->gtkobj()), 0, 0));
   Gtk::Pixmap *pixmap108 = manage(new class Gtk::Pixmap(Angeb_Sicht_32_xpm));
   Gtk::Pixmap *pixmap109 = manage(new class Gtk::Pixmap(Angeb_Nase_32_xpm));
   Gtk::Pixmap *pixmap110 = manage(new class Gtk::Pixmap(Angeb_Richtung_32_xpm));
   Gtk::Pixmap *pixmap111 = manage(new class Gtk::Pixmap(Angeb_Ohr_32_xpm));
   Gtk::Pixmap *pixmap112 = manage(new class Gtk::Pixmap(Angeb_Reflex_32_xpm));
   Gtk::Pixmap *pixmap113 = manage(new class Gtk::Pixmap(Angeb_Tast_32_xpm));
   Gtk::VBox *vbox32 = manage(new class Gtk::VBox(false, 0));
   Gtk::Table *table48 = manage(new class Gtk::Table(3, 3, false));
   clist_ang_fert_alt->set_usize(179, -1);
   clist_ang_fert_alt->set_column_title(0, "Fertigkeit");
   clist_ang_fert_alt->set_column_width(0, 80);
   clist_ang_fert_alt->set_column_title(1, "Wert");
   clist_ang_fert_alt->set_column_justification(1, GTK_JUSTIFY_RIGHT);
   clist_ang_fert_alt->set_column_width(1, 80);
   clist_ang_fert_alt->column_titles_show();
   scrolledwindow44->set_policy(GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
   scrolledwindow44->add(*clist_ang_fert_alt);
   clist_ang_fert_neu->set_usize(266, 400);
   clist_ang_fert_neu->set_column_title(0, "Würfelwurf");
   clist_ang_fert_neu->set_column_justification(0, GTK_JUSTIFY_CENTER);
   clist_ang_fert_neu->set_column_width(0, 80);
   clist_ang_fert_neu->set_column_title(1, "Fertigkeit");
   clist_ang_fert_neu->set_column_width(1, 80);
   clist_ang_fert_neu->set_column_title(2, "Wert");
   clist_ang_fert_neu->set_column_justification(2, GTK_JUSTIFY_RIGHT);
   clist_ang_fert_neu->set_column_width(2, 80);
   clist_ang_fert_neu->column_titles_show();
   scrolledwindow45->set_policy(GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
   scrolledwindow45->add(*clist_ang_fert_neu);
   label_ang_fert->set_alignment(0, 0.5);
   label_ang_fert->set_padding(0, 0);
   toolbar31->set_border_width(5);
   toolbar31->set_space_size(5);
   toolbar31->set_tooltips(true);
   pixmap108->set_alignment(0.5, 0.5);
   pixmap108->set_padding(0, 0);
   pixmap109->set_alignment(0.5, 0.5);
   pixmap109->set_padding(0, 0);
   pixmap110->set_alignment(0.5, 0.5);
   pixmap110->set_padding(0, 0);
   pixmap111->set_alignment(0.5, 0.5);
   pixmap111->set_padding(0, 0);
   pixmap112->set_alignment(0.5, 0.5);
   pixmap112->set_padding(0, 0);
   pixmap113->set_alignment(0.5, 0.5);
   pixmap113->set_padding(0, 0);
   vbox32->pack_start(*pixmap108);
   vbox32->pack_start(*pixmap109);
   vbox32->pack_start(*pixmap110);
   vbox32->pack_start(*pixmap111);
   vbox32->pack_start(*pixmap112);
   vbox32->pack_start(*pixmap113);
   table48->attach(*scrolledwindow44, 0, 1, 1, 2, GTK_EXPAND|GTK_FILL, GTK_EXPAND|GTK_FILL, 0, 0);
   table48->attach(*scrolledwindow45, 2, 3, 1, 2, GTK_FILL, GTK_FILL, 0, 0);
   table48->attach(*label_ang_fert, 0, 3, 0, 1, 0, 0, 3, 5);
   table48->attach(*toolbar31, 1, 2, 2, 3, GTK_FILL, 0, 0, 0);
   table48->attach(*vbox32, 1, 2, 1, 2, GTK_FILL, GTK_FILL, 0, 0);
   Window_angeb_fert->set_title("Angeborene Fertigkeiten");
   Window_angeb_fert->set_modal(true);
   Window_angeb_fert->add(*table48);
   clist_ang_fert_alt->show();
   scrolledwindow44->show();
   clist_ang_fert_neu->show();
   scrolledwindow45->show();
   label_ang_fert->show();
   toolbar31->show();
   pixmap108->show();
   pixmap109->show();
   pixmap110->show();
   pixmap111->show();
   pixmap112->show();
   pixmap113->show();
   vbox32->show();
   table48->show();
   Window_angeb_fert->show();
   clist_ang_fert_alt->select_row.connect(SigC::slot(static_cast<class Window_angeb_fert*>(this), &Window_angeb_fert::on_clist_ang_fert_alt_select_row));
   clist_ang_fert_neu->select_row.connect(SigC::slot(static_cast<class Window_angeb_fert*>(this), &Window_angeb_fert::on_clist_ang_fert_neu_select_row));
   button60->clicked.connect(SigC::slot(static_cast<class Window_angeb_fert*>(this), &Window_angeb_fert::on_button_close_clicked));
}

Window_angeb_fert_glade::~Window_angeb_fert_glade()
{   
}
