// generated 2001/5/8 15:14:13 CEST by thoma@Tiger.
// using glademm V0.6.2_cvs
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- /home/thoma/rollenspiel/midgard/programme/gra_mygen/midgard.glade
// for gtk 1.2.8 and gtkmm 1.2.5
//
// Please modify the corresponding derived classes in ./src/Zauber_auswahl.hh and./src/Zauber_auswahl.cc

#ifndef _ZAUBER_AUSWAHL_GLADE_HH
#  define _ZAUBER_AUSWAHL_GLADE_HH

#include <gtk--/window.h>
#include <gtk--/clist.h>
#include <gtk--/label.h>

class Zauber_auswahl_glade : public Gtk::Window
{   
protected:
        
        class Gtk::CList *zauber_clist_auswahl;
        class Gtk::Label *zauber_auswahl_lernpunkte;
        
        Zauber_auswahl_glade();
        
        ~Zauber_auswahl_glade();
};
#endif
