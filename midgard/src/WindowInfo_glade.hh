// generated 2002/10/24 17:42:55 CEST by thoma@Tiger.(none)
// using glademm V1.1.1c_cvs
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- /home/thoma/rollenspiel/midgard/programme/gcc_3.0/midgard/midgard.glade
// for gtk 1.2.10 and gtkmm 1.2.10
//
// Please modify the corresponding derived classes in ./src/WindowInfo.hh and./src/WindowInfo.cc

#ifndef _WINDOWINFO_GLADE_HH
#  define _WINDOWINFO_GLADE_HH


#if !defined(GLADEMM_DATA)
#define GLADEMM_DATA 
#include <gtk--/accelgroup.h>

class GlademmData
{  
        
        Gtk::AccelGroup *accgrp;
public:
        
        GlademmData(Gtk::AccelGroup *ag) : accgrp(ag)
        {  
        }
        
        Gtk::AccelGroup * getAccelGroup()
        {  return accgrp;
        }
};
#endif //GLADEMM_DATA

#include <gtk--/window.h>
#include <gtk--/pixmap.h>
#include "logwin.hh"
#include <gtk--/button.h>
#include <gtk--/table.h>
#include <gtk--/frame.h>

class WindowInfo_glade : public Gtk::Window
{  
        
        GlademmData *_data;
protected:
        class Gtk::Pixmap *pixmap_arkanum;
        class logwin *LogWin;
public:
        class Gtk::Button *button_bestaetigen;
        class Gtk::Button *button_abbrechen;
protected:
        class Gtk::Table *table_bestaetigen;
        class Gtk::Button *button_info_ok;
        class Gtk::Table *table_schliessen;
        class Gtk::Frame *frame_auswahl;
        
        WindowInfo_glade();
        
        ~WindowInfo_glade();
};
#define GMM_BUTTON_BESTAETIGEN (glademm_get<Gtk::Button >("button_bestaetigen"))
#define GMM_BUTTON_ABBRECHEN (glademm_get<Gtk::Button >("button_abbrechen"))
#endif
