// generated 2001/5/8 15:14:14 CEST by thoma@Tiger.
// using glademm V0.6.2_cvs
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- /home/thoma/rollenspiel/midgard/programme/gra_mygen/midgard.glade
// for gtk 1.2.8 and gtkmm 1.2.5
//
// Please modify the corresponding derived classes in ./src/Window_mag_bonus.cc

#include "config.h"
#include "Window_mag_bonus.hh"
#include <gtk--/adjustment.h>
#include <gtk--/pixmap.h>
#include "../pixmaps/Weapon-trans-50.xpm"
#include <gtk--/button.h>
#include "../pixmaps/SchliessenIII-50.xpm"
#include <gtk--/toolbar.h>
#include <gtk--/label.h>
#include <gtk--/table.h>

Window_mag_bonus_glade::Window_mag_bonus_glade(
) : Gtk::Window(GTK_WINDOW_TOPLEVEL)
{   
   
   Gtk::Window *Window_mag_bonus = this;
   Gtk::Adjustment *spinbutton_av_bonus_adj = manage(new class Gtk::Adjustment(0, -5, 5, 1, 10, 10));
   spinbutton_av_bonus = manage(new class Gtk::SpinButton(*spinbutton_av_bonus_adj, 1, 0));
   
   Gtk::Adjustment *spinbutton_sl_bonus_adj = manage(new class Gtk::Adjustment(0, -5, 5, 1, 10, 10));
   spinbutton_sl_bonus = manage(new class Gtk::SpinButton(*spinbutton_sl_bonus_adj, 1, 0));
   label_waffe = manage(new class Gtk::Label("Waffe"));
   label_SL_bonus = manage(new class Gtk::Label("SLbonus"));
   label_av_bonus = manage(new class Gtk::Label("AVbonus"));
   
   Gtk::Pixmap *pixmap14 = manage(new class Gtk::Pixmap(Weapon_trans_50_xpm));
   Gtk::Toolbar *toolbar30 = manage(new class Gtk::Toolbar(GTK_ORIENTATION_HORIZONTAL, GTK_TOOLBAR_ICONS));
   Gtk::Button *button59 = Gtk::wrap((GtkButton*)gtk_toolbar_append_element(GTK_TOOLBAR(toolbar30->gtkobj()), GTK_TOOLBAR_CHILD_BUTTON, 0, "", 0, 0, GTK_WIDGET(manage(new Gtk::Pixmap(SchliessenIII_50_xpm))->gtkobj()), 0, 0));
   Gtk::Label *label395 = manage(new class Gtk::Label("Kurzbeschreibung"));
   entry_magisch = manage(new class Gtk::Entry());
   
   Gtk::Table *table62 = manage(new class Gtk::Table(1, 2, false));
   Gtk::Table *table47 = manage(new class Gtk::Table(5, 2, false));
   _tooltips.set_tip(*spinbutton_av_bonus, "f�r eine mag. (+0/+0) Waffe bitte (-5/-5) einstellen", "");
   spinbutton_av_bonus->set_editable(true);
   _tooltips.set_tip(*spinbutton_sl_bonus, "f�r eine mag. (+0/+0) Waffe bitte (-5/-5) einstellen", "");
   spinbutton_sl_bonus->set_editable(true);
   label_waffe->set_alignment(0, 0.5);
   label_waffe->set_padding(0, 0);
   label_SL_bonus->set_alignment(0, 0.5);
   label_SL_bonus->set_padding(0, 0);
   label_av_bonus->set_alignment(0, 0.5);
   label_av_bonus->set_padding(0, 0);
   pixmap14->set_alignment(0.5, 0.5);
   pixmap14->set_padding(0, 0);
   toolbar30->set_border_width(5);
   toolbar30->set_space_size(5);
   toolbar30->set_tooltips(true);
   label395->set_alignment(0, 0.5);
   label395->set_padding(0, 0);
   entry_magisch->set_editable(true);
   table62->attach(*label395, 0, 1, 0, 1, GTK_FILL, 0, 5, 0);
   table62->attach(*entry_magisch, 1, 2, 0, 1, GTK_EXPAND|GTK_FILL, 0, 0, 0);
   table47->attach(*spinbutton_av_bonus, 1, 2, 1, 2, GTK_EXPAND|GTK_FILL, 0, 0, 0);
   table47->attach(*spinbutton_sl_bonus, 1, 2, 2, 3, GTK_EXPAND|GTK_FILL, 0, 0, 0);
   table47->attach(*label_waffe, 0, 2, 0, 1, 0, 0, 0, 3);
   table47->attach(*label_SL_bonus, 0, 1, 2, 3, GTK_FILL, 0, 5, 0);
   table47->attach(*label_av_bonus, 0, 1, 1, 2, GTK_FILL, 0, 5, 0);
   table47->attach(*pixmap14, 0, 1, 3, 4, GTK_FILL, GTK_FILL, 0, 0);
   table47->attach(*toolbar30, 1, 2, 3, 4, GTK_FILL, 0, 0, 0);
   table47->attach(*table62, 0, 2, 4, 5, GTK_FILL, GTK_EXPAND|GTK_FILL, 0, 0);
   Window_mag_bonus->set_title("mag. Waffen");
   Window_mag_bonus->add(*table47);
   spinbutton_av_bonus->show();
   spinbutton_sl_bonus->show();
   label_waffe->show();
   label_SL_bonus->show();
   label_av_bonus->show();
   pixmap14->show();
   toolbar30->show();
   label395->show();
   entry_magisch->show();
   table62->show();
   table47->show();
   Window_mag_bonus->show();
   button59->clicked.connect(SigC::slot(static_cast<class Window_mag_bonus*>(this), &Window_mag_bonus::on_button_close_clicked));
}

Window_mag_bonus_glade::~Window_mag_bonus_glade()
{   
}
