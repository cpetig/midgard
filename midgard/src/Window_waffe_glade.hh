// generated 2002/3/26 22:01:42 CET by thoma@Tiger.(none)
// using glademm V0.6.4b_cvs
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- /home/thoma/rollenspiel/midgard/programme/gcc_3.0/midgard/midgard.glade
// for gtk 1.2.10 and gtkmm 1.2.8
//
// Please modify the corresponding derived classes in ./src/Window_waffe.hh and./src/Window_waffe.cc

#ifndef _WINDOW_WAFFE_GLADE_HH
#  define _WINDOW_WAFFE_GLADE_HH

#include <gtk--/window.h>
#include <gtk--/clist.h>
#include <gtk--/label.h>

class Window_waffe_glade : public Gtk::Window
{  
protected:
        
        class Gtk::CList *clist_waffe;
        class Gtk::Label *label_anzahl_E;
        class Gtk::Label *label_anzahl_A;
        
        Window_waffe_glade();
        
        ~Window_waffe_glade();
};
#endif
