// generated 2001/4/18 10:01:10 CEST by thoma@ig23.
// using glademm V0.5_11f_cvs
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- /home/thoma/rollenspiel/midgard/programme/gra_mygen/midgard.glade
// for gtk 1.2.8 and gtkmm 1.2.4
//
// Please modify the corresponding derived classes in ./src/Window_Geld_eingeben.hh and./src/Window_Geld_eingeben.cc

#ifndef _WINDOW_GELD_EINGEBEN_GLADE_HH
#  define _WINDOW_GELD_EINGEBEN_GLADE_HH

#include <gtk--/window.h>
#include <gtk--/spinbutton.h>

class Window_Geld_eingeben_glade : public Gtk::Window
{   
protected:
        
        class Gtk::SpinButton *spinbutton_gold;
        class Gtk::SpinButton *spinbutton_silber;
        class Gtk::SpinButton *spinbutton_kupfer;
        
        Window_Geld_eingeben_glade();
        
        ~Window_Geld_eingeben_glade();
};
#endif
