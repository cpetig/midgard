// generated 2001/5/8 15:14:13 CEST by thoma@Tiger.
// using glademm V0.6.2_cvs
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- /home/thoma/rollenspiel/midgard/programme/gra_mygen/midgard.glade
// for gtk 1.2.8 and gtkmm 1.2.5
//
// Please modify the corresponding derived classes in ./src/WindowInfo.cc

#include "config.h"
#include "WindowInfo.hh"
#include <gtk--/box.h>

WindowInfo_glade::WindowInfo_glade(
) : Gtk::Window(GTK_WINDOW_DIALOG)
{   
   
   Gtk::Window *WindowInfo = this;
   infotext = manage(new class Gtk::Label("infotext"));
   button_info_ok = manage(new class Gtk::Button("OK"));
   
   Gtk::VBox *vbox4 = manage(new class Gtk::VBox(false, 0));
   infotext->set_usize(400, 300);
   infotext->set_alignment(0.5, 0.5);
   infotext->set_padding(0, 0);
   vbox4->pack_start(*infotext);
   vbox4->pack_start(*button_info_ok, false, false, 0);
   WindowInfo->set_title("Info");
   WindowInfo->set_policy(true, true, true);
   WindowInfo->add(*vbox4);
   infotext->show();
   button_info_ok->show();
   vbox4->show();
   WindowInfo->show();
   button_info_ok->clicked.connect(SigC::slot(static_cast<class WindowInfo*>(this), &WindowInfo::on_button_info_ok_clicked));
}

WindowInfo_glade::~WindowInfo_glade()
{   
}
