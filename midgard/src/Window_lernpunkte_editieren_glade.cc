// generated 2001/4/12 9:43:50 CEST by thoma@ig23.
// using glademm V0.5_11f_cvs
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- /home/thoma/rollenspiel/midgard/programme/gra_mygen/midgard.glade
// for gtk 1.2.8 and gtkmm 1.2.4
//
// Please modify the corresponding derived classes in ./src/Window_lernpunkte_editieren.cc

#include "config.h"
#include "Window_lernpunkte_editieren.hh"
#include <gtk--/label.h>
#include <gtk--/adjustment.h>
#include <gtk--/pixmap.h>
#include "../pixmaps/Edit-2W6-trans-50.xpm"
#include <gtk--/button.h>
#include "../pixmaps/SchliessenIII-50.xpm"
#include <gtk--/toolbar.h>
#include <gtk--/table.h>
#include <gtk--/frame.h>

Window_lernpunkte_editieren_glade::Window_lernpunkte_editieren_glade(
) : Gtk::Window(GTK_WINDOW_TOPLEVEL)
{   
   
   Gtk::Window *Window_lernpunkte_editieren = this;
   Gtk::Label *label107 = manage(new class Gtk::Label("Beruf"));
   Gtk::Label *label108 = manage(new class Gtk::Label("Fertigkeiten"));
   Gtk::Label *label109 = manage(new class Gtk::Label("Waffen"));
   Gtk::Label *label110 = manage(new class Gtk::Label("Zauber"));
   Gtk::Adjustment *lernpunkte_b_ein_adj = manage(new class Gtk::Adjustment(1, 0, 100, 1, 10, 10));
   lernpunkte_b_ein = manage(new class Gtk::SpinButton(*lernpunkte_b_ein_adj, 1, 0));
   
   Gtk::Adjustment *lernpunkte_f_ein_adj = manage(new class Gtk::Adjustment(1, 0, 100, 1, 10, 10));
   lernpunkte_f_ein = manage(new class Gtk::SpinButton(*lernpunkte_f_ein_adj, 1, 0));
   
   Gtk::Adjustment *lernpunkte_w_ein_adj = manage(new class Gtk::Adjustment(1, 0, 100, 1, 10, 10));
   lernpunkte_w_ein = manage(new class Gtk::SpinButton(*lernpunkte_w_ein_adj, 1, 0));
   
   Gtk::Adjustment *lernpunkte_z_ein_adj = manage(new class Gtk::Adjustment(1, 0, 100, 1, 10, 10));
   lernpunkte_z_ein = manage(new class Gtk::SpinButton(*lernpunkte_z_ein_adj, 1, 0));
   
   Gtk::Pixmap *pixmap24 = manage(new class Gtk::Pixmap(Edit_2W6_trans_50_xpm));
   Gtk::Toolbar *toolbar20 = manage(new class Gtk::Toolbar(GTK_ORIENTATION_HORIZONTAL, GTK_TOOLBAR_ICONS));
   Gtk::Button *button49 = Gtk::wrap((GtkButton*)gtk_toolbar_append_element(GTK_TOOLBAR(toolbar20->gtkobj()), GTK_TOOLBAR_CHILD_BUTTON, 0, "", 0, 0, GTK_WIDGET(manage(new Gtk::Pixmap(SchliessenIII_50_xpm))->gtkobj()), 0, 0));
   Gtk::Table *table5 = manage(new class Gtk::Table(5, 4, false));
   Gtk::Frame *frame29 = manage(new class Gtk::Frame("Lernpunkte editieren"));
   label107->set_alignment(0.5, 0.5);
   label107->set_padding(0, 0);
   label108->set_alignment(0.5, 0.5);
   label108->set_padding(0, 0);
   label109->set_alignment(0.5, 0.5);
   label109->set_padding(0, 0);
   label110->set_alignment(0.5, 0.5);
   label110->set_padding(0, 0);
   lernpunkte_b_ein->set_editable(true);
   lernpunkte_f_ein->set_editable(true);
   lernpunkte_w_ein->set_editable(true);
   lernpunkte_z_ein->set_editable(true);
   pixmap24->set_alignment(0.5, 0.5);
   pixmap24->set_padding(0, 0);
   toolbar20->set_border_width(5);
   toolbar20->set_space_size(5);
   toolbar20->set_tooltips(true);
   table5->attach(*label107, 0, 1, 0, 1, 0, 0, 0, 0);
   table5->attach(*label108, 0, 1, 1, 2, 0, 0, 0, 0);
   table5->attach(*label109, 0, 1, 2, 3, 0, 0, 0, 0);
   table5->attach(*label110, 0, 1, 3, 4, 0, 0, 0, 0);
   table5->attach(*lernpunkte_b_ein, 1, 2, 0, 1, GTK_EXPAND|GTK_FILL, 0, 0, 0);
   table5->attach(*lernpunkte_f_ein, 1, 2, 1, 2, GTK_EXPAND|GTK_FILL, 0, 0, 0);
   table5->attach(*lernpunkte_w_ein, 1, 2, 2, 3, GTK_EXPAND|GTK_FILL, 0, 0, 0);
   table5->attach(*lernpunkte_z_ein, 1, 2, 3, 4, GTK_EXPAND|GTK_FILL, 0, 0, 0);
   table5->attach(*pixmap24, 2, 3, 0, 4, GTK_FILL, GTK_FILL, 0, 0);
   table5->attach(*toolbar20, 2, 3, 4, 5, GTK_FILL, 0, 0, 0);
   frame29->set_label_align(0, 0);
   frame29->set_shadow_type(GTK_SHADOW_ETCHED_IN);
   frame29->add(*table5);
   Window_lernpunkte_editieren->set_title("Lernpunkte editieren");
   Window_lernpunkte_editieren->add(*frame29);
   label107->show();
   label108->show();
   label109->show();
   label110->show();
   lernpunkte_b_ein->show();
   lernpunkte_f_ein->show();
   lernpunkte_w_ein->show();
   lernpunkte_z_ein->show();
   pixmap24->show();
   toolbar20->show();
   table5->show();
   frame29->show();
   Window_lernpunkte_editieren->show();
   lernpunkte_b_ein->activate.connect(SigC::slot(static_cast<class Window_lernpunkte_editieren*>(this), &Window_lernpunkte_editieren::on_close_clicked));
   lernpunkte_f_ein->activate.connect(SigC::slot(static_cast<class Window_lernpunkte_editieren*>(this), &Window_lernpunkte_editieren::on_close_clicked));
   lernpunkte_w_ein->activate.connect(SigC::slot(static_cast<class Window_lernpunkte_editieren*>(this), &Window_lernpunkte_editieren::on_close_clicked));
   lernpunkte_z_ein->activate.connect(SigC::slot(static_cast<class Window_lernpunkte_editieren*>(this), &Window_lernpunkte_editieren::on_close_clicked));
   button49->clicked.connect(SigC::slot(static_cast<class Window_lernpunkte_editieren*>(this), &Window_lernpunkte_editieren::on_close_clicked));
}

Window_lernpunkte_editieren_glade::~Window_lernpunkte_editieren_glade()
{   
}
