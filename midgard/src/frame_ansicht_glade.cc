// generated 2005/9/7 21:59:16 CEST by christof@vesta.petig-baender.de
// using glademm V2.10.0.0
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- --image-provider=MagusImage --gtkmmversion 2.4.0 midgard.glade
// for gtk 2.8.3 and gtkmm 2.4.0
//
// Please modify the corresponding derived classes in ./src/frame_ansicht.cc


#if defined __GNUC__ && __GNUC__ < 3
#error This program will crash if compiled with g++ 2.x
// see the dynamic_cast bug in the gtkmm FAQ
#endif //
#include "config.h"
#include <gtkmmconfig.h>
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>2
#include <sigc++/compatibility.h>
#include <sigc++/bind.h>
#define GMM_GTKMM_22_24(a,b) b
#else //gtkmm 2.2
#define GMM_GTKMM_22_24(a,b) a
#endif //
#include "frame_ansicht_glade.hh"
#include <gtkmm/label.h>

frame_ansicht_glade::frame_ansicht_glade(GlademmData *gmm_data
)
{  frame_ansicht = this;
   
   Gtk::Label *label679 = Gtk::manage(new class Gtk::Label("Ansicht"));
   label679->set_alignment(0.5,0.5);
   label679->set_padding(0,0);
   label679->set_justify(Gtk::JUSTIFY_LEFT);
   label679->set_line_wrap(false);
   label679->set_use_markup(false);
   label679->set_selectable(false);
   frame_ansicht->set_shadow_type(Gtk::SHADOW_ETCHED_IN);
   frame_ansicht->set_label_align(0,0.5);
   frame_ansicht->set_label_widget(*label679);
   label679->show();
   frame_ansicht->show();
}

frame_ansicht_glade::~frame_ansicht_glade()
{  
}
