// generated 2002/9/13 14:06:29 CEST by thoma@Tiger.(none)
// using glademm V1.1.1c_cvs
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- /home/thoma/rollenspiel/midgard/programme/gcc_3.0/midgard/midgard.glade
// for gtk 1.2.10 and gtkmm 1.2.10
//
// Please modify the corresponding derived classes in ./src/Midgard_Info.hh and./src/Midgard_Info.cc

#ifndef _MIDGARD_INFO_GLADE_HH
#  define _MIDGARD_INFO_GLADE_HH


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

#include <gtk--/scrolledwindow.h>
#include <gtk--/label.h>
#include <gtk--/frame.h>
#include <gtk--/progressbar.h>

class Midgard_Info_glade : public Gtk::ScrolledWindow
{  
protected:
        
        class Gtk::ScrolledWindow *Midgard_Info;
        class Gtk::Label *versionsnummer;
        class Gtk::Frame *frame_regionen;
        class Gtk::ProgressBar *progressbar_laender;
        class Gtk::ProgressBar *progressbar_ruestung;
        class Gtk::ProgressBar *progressbar_ang_Fert;
        class Gtk::ProgressBar *progressbar_fertigkeiten;
        class Gtk::ProgressBar *progressbar_lernschema;
        class Gtk::ProgressBar *progressbar_beruf;
        class Gtk::ProgressBar *progressbar_regionen;
        class Gtk::ProgressBar *progressbar_spezies;
        class Gtk::ProgressBar *progressbar_typen;
        class Gtk::ProgressBar *progressbar_grad;
        class Gtk::ProgressBar *progressbar_spezial;
        class Gtk::ProgressBar *progressbar_preise;
        class Gtk::ProgressBar *progressbar_schrift;
        class Gtk::ProgressBar *progressbar_sprache;
        class Gtk::ProgressBar *progressbar_kido;
        class Gtk::ProgressBar *progressbar_zauberwerk;
        class Gtk::ProgressBar *progressbar_zauber;
        class Gtk::ProgressBar *progressbar_aliaswaffen;
        class Gtk::ProgressBar *progressbar_waffen;
        class Gtk::ProgressBar *progressbar_grundkenntnisse;
        class Gtk::Frame *frame_datenbank;
        
        Midgard_Info_glade(GlademmData *_data);
        
        ~Midgard_Info_glade();
};
#endif
