// generated 2003/4/23 14:25:51 CEST by christof@puck.petig-baender.de
// using glademm V1.1.3g_cvs
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- --image-provider=MagusImage midgard.glade
// for gtk 2.2.1 and gtkmm 2.2.1
//
// Please modify the corresponding derived classes in ./src/frame_drucken.cc


#if defined __GNUC__ && __GNUC__ < 3
#error This program will crash if compiled with g++ 2.x
// see the dynamic_cast bug in the gtkmm FAQ
#endif //
#include "config.h"
#include "frame_drucken_glade.hh"
#include <gtkmm/label.h>

frame_drucken_glade::frame_drucken_glade(GlademmData *gmm_data
)
{  frame_drucken = this;
   
   Gtk::Label *label680 = Gtk::manage(new class Gtk::Label("PDF Viewer"));
   label680->set_alignment(0.5,0.5);
   label680->set_padding(0,0);
   label680->set_justify(Gtk::JUSTIFY_LEFT);
   label680->set_line_wrap(false);
   label680->set_use_markup(false);
   label680->set_selectable(false);
   frame_drucken->set_shadow_type(Gtk::SHADOW_ETCHED_IN);
   frame_drucken->set_label_align(0,0.5);
   frame_drucken->set_label_widget(*label680);
   label680->show();
   frame_drucken->show();
}

frame_drucken_glade::~frame_drucken_glade()
{  
}
