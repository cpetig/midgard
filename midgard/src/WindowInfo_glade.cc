// generated 2002/9/26 15:36:22 CEST by thoma@Tiger.(none)
// using glademm V1.1.1c_cvs
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- /home/thoma/rollenspiel/midgard/programme/gcc_3.0/midgard/midgard.glade
// for gtk 1.2.10 and gtkmm 1.2.10
//
// Please modify the corresponding derived classes in ./src/WindowInfo.cc

#include "config.h"
#include "WindowInfo.hh"
#include <gdk/gdkkeysyms.h>
#include <gtk--/accelgroup.h>
#include "../pixmaps/Gross_ark_pre.xpm"
#include <gtk--/pixmap.h>
#include "../pixmaps/Excl-32.xpm"
#include <gtk--/label.h>
#include <gtk--/box.h>
#include "../pixmaps/Erase-50.xpm"
#include "../pixmaps/Yellow-Dice-trans-50.xpm"
#include <gtk--/button.h>
#include <gtk--/table.h>

WindowInfo_glade::WindowInfo_glade(
) : Gtk::Window(GTK_WINDOW_DIALOG)
{  
   
   Gtk::Window *WindowInfo = this;
   Gtk::AccelGroup *WindowInfo_accgrp = Gtk::AccelGroup::create();
   _data = new GlademmData(WindowInfo_accgrp);
   pixmap_arkanum = manage(new class Gtk::Pixmap(Gross_ark_pre_xpm));
   LogWin = new class logwin();
   
   Gtk::Pixmap *pixmap_ja = manage(new class Gtk::Pixmap(Excl_32_xpm));
   Gtk::Label *label570 = manage(new class Gtk::Label("Ja"));
   Gtk::HBox *hbox73 = manage(new class Gtk::HBox(false, 0));
   button_bestaetigen = manage(new class Gtk::Button());
   
   Gtk::Pixmap *pixmap_nein = manage(new class Gtk::Pixmap(Erase_50_xpm));
   Gtk::Label *label569 = manage(new class Gtk::Label("Nein"));
   Gtk::HBox *hbox72 = manage(new class Gtk::HBox(false, 0));
   button_abbrechen = manage(new class Gtk::Button());
   table_bestaetigen = manage(new class Gtk::Table(1, 2, true));
   
   Gtk::Pixmap *pixmap144 = manage(new class Gtk::Pixmap(Yellow_Dice_trans_50_xpm));
   Gtk::Label *label564 = manage(new class Gtk::Label("Fenster\n"
		"schlie�en"));
   Gtk::HBox *hbox68 = manage(new class Gtk::HBox(false, 0));
   button_info_ok = manage(new class Gtk::Button());
   
   Gtk::Pixmap *pixmap143 = manage(new class Gtk::Pixmap(Erase_50_xpm));
   Gtk::Label *label563 = manage(new class Gtk::Label("Textfeld\n"
		"l�schen"));
   Gtk::HBox *hbox67 = manage(new class Gtk::HBox(false, 0));
   Gtk::Button *button_erase = manage(new class Gtk::Button());
   table_schliessen = manage(new class Gtk::Table(1, 2, true));
   frame_auswahl = manage(new class Gtk::Frame());
   
   Gtk::Table *table125 = manage(new class Gtk::Table(3, 4, false));
   Gtk::Table *table133 = manage(new class Gtk::Table(10, 2, false));
   pixmap_arkanum->set_alignment(0.5,0.5);
   pixmap_arkanum->set_padding(0,0);
   pixmap_ja->set_alignment(0.5,0.5);
   pixmap_ja->set_padding(0,0);
   label570->set_alignment(0.5,0.5);
   label570->set_padding(0,0);
   label570->set_justify(GTK_JUSTIFY_CENTER);
   label570->set_line_wrap(false);
   hbox73->pack_start(*pixmap_ja);
   hbox73->pack_start(*label570);
   button_bestaetigen->set_flags(GTK_CAN_FOCUS);
   button_bestaetigen->set_relief(GTK_RELIEF_NORMAL);
   button_bestaetigen->add(*hbox73);
   pixmap_nein->set_alignment(0.5,0.5);
   pixmap_nein->set_padding(0,0);
   label569->set_alignment(0.5,0.5);
   label569->set_padding(0,0);
   label569->set_justify(GTK_JUSTIFY_CENTER);
   label569->set_line_wrap(false);
   hbox72->pack_start(*pixmap_nein);
   hbox72->pack_start(*label569);
   button_abbrechen->set_flags(GTK_CAN_FOCUS);
   button_abbrechen->set_relief(GTK_RELIEF_NORMAL);
   button_abbrechen->add(*hbox72);
   table_bestaetigen->set_row_spacings(0);
   table_bestaetigen->set_col_spacings(10);
   table_bestaetigen->attach(*button_bestaetigen, 0, 1, 0, 1, GTK_FILL, 0, 0, 0);
   table_bestaetigen->attach(*button_abbrechen, 1, 2, 0, 1, GTK_FILL, 0, 0, 0);
   pixmap144->set_alignment(0.5,0.5);
   pixmap144->set_padding(0,0);
   label564->set_alignment(0.5,0.5);
   label564->set_padding(0,0);
   label564->set_justify(GTK_JUSTIFY_CENTER);
   label564->set_line_wrap(false);
   hbox68->pack_start(*pixmap144);
   hbox68->pack_start(*label564, false, false, 0);
   button_info_ok->set_usize(50,-1);
   button_info_ok->set_flags(GTK_CAN_FOCUS);
   button_info_ok->set_relief(GTK_RELIEF_NORMAL);
   button_info_ok->add(*hbox68);
   pixmap143->set_alignment(0.5,0.5);
   pixmap143->set_padding(0,0);
   label563->set_alignment(0.5,0.5);
   label563->set_padding(0,0);
   label563->set_justify(GTK_JUSTIFY_CENTER);
   label563->set_line_wrap(false);
   hbox67->pack_start(*pixmap143);
   hbox67->pack_start(*label563, false, false, 0);
   button_erase->set_flags(GTK_CAN_FOCUS);
   button_erase->set_relief(GTK_RELIEF_NORMAL);
   button_erase->add(*hbox67);
   table_schliessen->set_row_spacings(0);
   table_schliessen->set_col_spacings(10);
   table_schliessen->attach(*button_info_ok, 0, 1, 0, 1, GTK_FILL, 0, 0, 0);
   table_schliessen->attach(*button_erase, 1, 2, 0, 1, GTK_FILL, 0, 0, 0);
   frame_auswahl->set_shadow_type(GTK_SHADOW_NONE);
   frame_auswahl->set_label_align(0,0);
   table125->set_row_spacings(0);
   table125->set_col_spacings(0);
   table125->attach(*table_bestaetigen, 0, 1, 1, 2, GTK_FILL, GTK_FILL, 0, 0);
   table125->attach(*table_schliessen, 0, 1, 0, 1, GTK_FILL, GTK_FILL, 0, 0);
   table125->attach(*frame_auswahl, 0, 1, 2, 3, GTK_FILL, GTK_EXPAND|GTK_SHRINK|GTK_FILL, 0, 0);
   table133->set_row_spacings(0);
   table133->set_col_spacings(0);
   table133->attach(*pixmap_arkanum, 1, 2, 0, 10, 0, 0, 0, 0);
   table133->attach(*LogWin, 0, 1, 0, 9, GTK_EXPAND|GTK_SHRINK|GTK_FILL, GTK_EXPAND|GTK_SHRINK|GTK_FILL, 0, 0);
   table133->attach(*table125, 0, 1, 9, 10, 0, 0, 0, 0);
   WindowInfo->set_title("Info");
   WindowInfo->set_default_size(677,422);
   WindowInfo->set_modal(false);
   WindowInfo->set_position(GTK_WIN_POS_NONE);
   WindowInfo->add_accel_group(*(_data->getAccelGroup()));
   WindowInfo->add(*table133);
   pixmap_arkanum->show();
   LogWin->show();
   pixmap_ja->show();
   label570->show();
   hbox73->show();
   button_bestaetigen->show();
   pixmap_nein->show();
   label569->show();
   hbox72->show();
   button_abbrechen->show();
   table_bestaetigen->show();
   pixmap144->show();
   label564->show();
   hbox68->show();
   button_info_ok->show();
   pixmap143->show();
   label563->show();
   hbox67->show();
   button_erase->show();
   table_schliessen->show();
   frame_auswahl->show();
   table125->show();
   table133->show();
   button_bestaetigen->clicked.connect(SigC::slot(static_cast<class WindowInfo*>(this), &WindowInfo::on_button_bestaetigen_clicked));
   button_abbrechen->clicked.connect(SigC::slot(static_cast<class WindowInfo*>(this), &WindowInfo::on_button_abbrechen_clicked));
   button_info_ok->clicked.connect(SigC::slot(static_cast<class WindowInfo*>(this), &WindowInfo::on_button_abbrechen_clicked));
   button_erase->clicked.connect(SigC::slot(static_cast<class WindowInfo*>(this), &WindowInfo::on_button_erase_clicked));
   WindowInfo->delete_event.connect(SigC::slot(static_cast<class WindowInfo*>(this), &WindowInfo::on_WindowInfo_delete_event));
   glademm_set_Widget("button_bestaetigen", button_bestaetigen);
   glademm_set_Widget("button_abbrechen", button_abbrechen);
}

WindowInfo_glade::~WindowInfo_glade()
{  delete LogWin;
   delete _data;
}
