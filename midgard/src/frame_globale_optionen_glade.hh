// generated 2002/9/26 10:15:05 CEST by thoma@Tiger.(none)
// using glademm V1.1.1c_cvs
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- /home/thoma/rollenspiel/midgard/programme/gcc_3.0/midgard/midgard.glade
// for gtk 1.2.10 and gtkmm 1.2.10
//
// Please modify the corresponding derived classes in ./src/frame_globale_optionen.hh and./src/frame_globale_optionen.cc

#ifndef _FRAME_GLOBALE_OPTIONEN_GLADE_HH
#  define _FRAME_GLOBALE_OPTIONEN_GLADE_HH


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

#include <gtk--/frame.h>

class frame_globale_optionen_glade : public Gtk::Frame
{  
protected:
        
        class Gtk::Frame *frame_globale_optionen;
        
        frame_globale_optionen_glade(GlademmData *_data);
        
        ~frame_globale_optionen_glade();
};
#endif
