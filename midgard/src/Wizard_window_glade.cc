// generated 2002/4/11 22:56:27 CEST by christof@puck.petig-baender.de
// using glademm V0.6.4b_cvs
//
// DO NOT EDIT THIS FILE ! It was created using
// /home/christof/cvs/glade--/src/glade-- midgard.glade
// for gtk 2.0.2 and gtkmm 1.2.8
//
// Please modify the corresponding derived classes in ./src/Wizard_window.cc

#include "config.h"
#include "Wizard_window.hh"
#include <gtk--/pixmap.h>
#include "../pixmaps/SchliessenIII-50.xpm"
#include <gtk--/label.h>
#include <gtk--/box.h>
#include <gtk--/button.h>
#include <gtk--/table.h>
#include "../pixmaps/MAGUS-Logo-Text-halb.xpm"

Wizard_window_glade::Wizard_window_glade(
) : Gtk::Window(GTK_WINDOW_TOPLEVEL)
{  
   
   Gtk::Window *Wizard_window = this;
   button_wiz_weiter = manage(new class Gtk::Button("Weiter"));
   button_wiz_wiederholen = manage(new class Gtk::Button("Wiederholen"));
   
   Gtk::Pixmap *pixmap133 = manage(new class Gtk::Pixmap(SchliessenIII_50_xpm));
   Gtk::Label *label556 = manage(new class Gtk::Label("Wizard\n"
		"schließen"));
   Gtk::HBox *hbox63 = manage(new class Gtk::HBox(false, 0));
   Gtk::Button *button_close_wizard = manage(new class Gtk::Button());
   togglebutton_wizard_start = manage(new class Gtk::ToggleButton("Wizard immer\n"
		"starten"));
   button_wiz_skip = manage(new class Gtk::Button("Überspringen"));
   
   Gtk::Table *table129 = manage(new class Gtk::Table(5, 1, false));
   LogWinWizard = new class logwin();
   
   Gtk::Pixmap *pixmap134 = manage(new class Gtk::Pixmap(MAGUS_Logo_Text_halb_xpm));
   table_wizard = manage(new class Gtk::Table(1, 4, false));
   button_wiz_weiter->set_flags(GTK_CAN_FOCUS);
   button_wiz_wiederholen->set_flags(GTK_CAN_FOCUS);
   pixmap133->set_alignment(0.5, 0.5);
   pixmap133->set_padding(0, 0);
   label556->set_alignment(0.5, 0.5);
   label556->set_padding(0, 0);
   hbox63->pack_start(*pixmap133);
   hbox63->pack_start(*label556, false, false, 0);
   button_close_wizard->set_flags(GTK_CAN_FOCUS);
   button_close_wizard->add(*hbox63);
   togglebutton_wizard_start->set_flags(GTK_CAN_FOCUS);
   togglebutton_wizard_start->set_active(true);
   button_wiz_skip->set_flags(GTK_CAN_FOCUS);
   table129->attach(*button_wiz_weiter, 0, 1, 0, 1, GTK_FILL, 0, 0, 0);
   table129->attach(*button_wiz_wiederholen, 0, 1, 1, 2, GTK_FILL, 0, 0, 0);
   table129->attach(*button_close_wizard, 0, 1, 4, 5, GTK_FILL, 0, 0, 0);
   table129->attach(*togglebutton_wizard_start, 0, 1, 3, 4, GTK_FILL, 0, 0, 0);
   table129->attach(*button_wiz_skip, 0, 1, 2, 3, GTK_FILL, 0, 0, 0);
   LogWinWizard->set_usize(340, -1);
   pixmap134->set_alignment(0.5, 0.5);
   pixmap134->set_padding(0, 0);
   table_wizard->attach(*table129, 2, 3, 0, 1, GTK_EXPAND|GTK_FILL, GTK_FILL, 0, 0);
   table_wizard->attach(*LogWinWizard, 1, 2, 0, 1, GTK_EXPAND|GTK_FILL, GTK_FILL, 0, 0);
   table_wizard->attach(*pixmap134, 3, 4, 0, 1, GTK_EXPAND|GTK_FILL, GTK_FILL, 0, 0);
   Wizard_window->set_title("Wizard");
   Wizard_window->add(*table_wizard);
   button_wiz_weiter->show();
   button_wiz_wiederholen->show();
   pixmap133->show();
   label556->show();
   hbox63->show();
   button_close_wizard->show();
   togglebutton_wizard_start->show();
   button_wiz_skip->show();
   table129->show();
   LogWinWizard->show();
   pixmap134->show();
   table_wizard->show();
   Wizard_window->show();
   button_wiz_weiter->clicked.connect(SigC::slot(static_cast<class Wizard_window*>(this), &Wizard_window::on_button_wizard_weiter_clicked));
   button_wiz_wiederholen->clicked.connect(SigC::slot(static_cast<class Wizard_window*>(this), &Wizard_window::on_button_wizard_wiederholen_clicked));
   button_close_wizard->clicked.connect(SigC::slot(static_cast<class Wizard_window*>(this), &Wizard_window::on_button_close_wizard_clicked));
   togglebutton_wizard_start->toggled.connect(SigC::slot(static_cast<class Wizard_window*>(this), &Wizard_window::on_togglebutton_wizard_start_toggled));
   button_wiz_skip->clicked.connect(SigC::slot(static_cast<class Wizard_window*>(this), &Wizard_window::on__button_wizard_skip));
   Wizard_window->delete_event.connect(SigC::slot(static_cast<class Wizard_window*>(this), &Wizard_window::on_Wizard_window_delete_event));
}

Wizard_window_glade::~Wizard_window_glade()
{  delete LogWinWizard;
}
