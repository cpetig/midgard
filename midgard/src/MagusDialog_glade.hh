// generated 2005/4/27 10:13:17 CEST by thoma@Tiger.(none)
// using glademm V2.6.0
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- --image-provider=MagusImage --gtkmmversion 2.4.0 midgard.glade
// for gtk 2.6.2 and gtkmm 2.4.0
//
// Please modify the corresponding derived classes in ./src/MagusDialog.hh and./src/MagusDialog.cc

#ifndef _MAGUSDIALOG_GLADE_HH
#  define _MAGUSDIALOG_GLADE_HH


#if !defined(GLADEMM_DATA)
#define GLADEMM_DATA 
#include <gtkmm/accelgroup.h>

class GlademmData
{  
        
        Glib::RefPtr<Gtk::AccelGroup> accgrp;
public:
        
        GlademmData(Glib::RefPtr<Gtk::AccelGroup> ag) : accgrp(ag)
        {  
        }
        
        Glib::RefPtr<Gtk::AccelGroup>  getAccelGroup()
        {  return accgrp;
        }
};
#endif //GLADEMM_DATA

#include <gtkmm/dialog.h>
#include <gtkmm/label.h>
#include <gtkmm/button.h>
#include <gtkmm/box.h>

class MagusDialog_glade : public Gtk::Dialog
{  
        
        GlademmData *gmm_data;
protected:
        class Gtk::Label * text_no;
        class Gtk::Button * cancelbutton;
        class Gtk::Label * text_yes;
        class Gtk::Button * okbutton;
        class Gtk::Button * closebutton;
        class Gtk::Label * text;
        
        MagusDialog_glade();
        
        ~MagusDialog_glade();
private:
        virtual bool on_WindowInfo_delete_event(GdkEventAny *ev) = 0;
};
#endif
