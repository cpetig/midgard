// generated 2002/2/14 21:11:09 CET by thoma@Tiger.
// using glademm V0.6.2c_cvs
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- /home/thoma/rollenspiel/midgard/programme/gcc_3.0/midgard/midgard.glade
// for gtk 1.2.10 and gtkmm 1.2.5
//
// Please modify the corresponding derived classes in ./src/Wizard_window.hh and./src/Wizard_window.cc

#ifndef _WIZARD_WINDOW_GLADE_HH
#  define _WIZARD_WINDOW_GLADE_HH

#include <gtk--/window.h>
#include <gtk--/togglebutton.h>
#include "logwin.hh"
#include <gtk--/table.h>

class Wizard_window_glade : public Gtk::Window
{   
protected:
        
        class Gtk::ToggleButton *togglebutton_wizard_start;
        class logwin *LogWinWizard;
        class Gtk::Table *table_wizard;
        
        Wizard_window_glade();
        
        ~Wizard_window_glade();
};
#endif
