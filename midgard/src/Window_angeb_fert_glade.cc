// generated 2001/4/12 9:43:51 CEST by thoma@ig23.
// using glademm V0.5_11f_cvs
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- /home/thoma/rollenspiel/midgard/programme/gra_mygen/midgard.glade
// for gtk 1.2.8 and gtkmm 1.2.4
//
// Please modify the corresponding derived classes in ./src/Window_angeb_fert.cc

#include "config.h"
#include "Window_angeb_fert.hh"
#include <gtk--/label.h>
#include <gtk--/scrolledwindow.h>
#include <gtk--/pixmap.h>
#include "../pixmaps/AngebSkills-trans-50.xpm"
#include <gtk--/button.h>
#include "../pixmaps/SchliessenIII-50.xpm"
#include <gtk--/toolbar.h>
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
   
   Gtk::Pixmap *pixmap15 = manage(new class Gtk::Pixmap(AngebSkills_trans_50_xpm));
   Gtk::Toolbar *toolbar31 = manage(new class Gtk::Toolbar(GTK_ORIENTATION_HORIZONTAL, GTK_TOOLBAR_ICONS));
   Gtk::Button *button60 = Gtk::wrap((GtkButton*)gtk_toolbar_append_element(GTK_TOOLBAR(toolbar31->gtkobj()), GTK_TOOLBAR_CHILD_BUTTON, 0, "", 0, 0, GTK_WIDGET(manage(new Gtk::Pixmap(SchliessenIII_50_xpm))->gtkobj()), 0, 0));
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
   clist_ang_fert_neu->set_usize(266, 218);
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
   pixmap15->set_alignment(0.5, 0.5);
   pixmap15->set_padding(0, 0);
   toolbar31->set_border_width(5);
   toolbar31->set_space_size(5);
   toolbar31->set_tooltips(true);
   table48->attach(*scrolledwindow44, 0, 1, 1, 2, GTK_EXPAND|GTK_FILL, GTK_EXPAND|GTK_FILL, 0, 0);
   table48->attach(*scrolledwindow45, 2, 3, 1, 2, GTK_FILL, GTK_FILL, 0, 0);
   table48->attach(*label_ang_fert, 0, 3, 0, 1, 0, 0, 3, 5);
   table48->attach(*pixmap15, 1, 2, 1, 2, GTK_FILL, GTK_FILL, 0, 0);
   table48->attach(*toolbar31, 1, 2, 2, 3, GTK_FILL, 0, 0, 0);
   Window_angeb_fert->set_title("Angeborene Fertigkeiten");
   Window_angeb_fert->add(*table48);
   clist_ang_fert_alt->show();
   scrolledwindow44->show();
   clist_ang_fert_neu->show();
   scrolledwindow45->show();
   label_ang_fert->show();
   pixmap15->show();
   toolbar31->show();
   table48->show();
   Window_angeb_fert->show();
   clist_ang_fert_alt->select_row.connect(SigC::slot(static_cast<class Window_angeb_fert*>(this), &Window_angeb_fert::on_clist_ang_fert_alt_select_row));
   clist_ang_fert_neu->select_row.connect(SigC::slot(static_cast<class Window_angeb_fert*>(this), &Window_angeb_fert::on_clist_ang_fert_neu_select_row));
   button60->clicked.connect(SigC::slot(static_cast<class Window_angeb_fert*>(this), &Window_angeb_fert::on_button_close_clicked));
}

Window_angeb_fert_glade::~Window_angeb_fert_glade()
{   
}
