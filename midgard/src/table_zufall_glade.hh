// generated 2002/9/16 13:56:51 CEST by thoma@Tiger.(none)
// using glademm V1.1.1c_cvs
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- /home/thoma/rollenspiel/midgard/programme/gcc_3.0/midgard/midgard.glade
// for gtk 1.2.10 and gtkmm 1.2.10
//
// Please modify the corresponding derived classes in ./src/table_zufall.hh and./src/table_zufall.cc

#ifndef _TABLE_ZUFALL_GLADE_HH
#  define _TABLE_ZUFALL_GLADE_HH


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

#include <gtk--/table.h>
#include <gtk--/togglebutton.h>
#include <gtk--/checkbutton.h>
#include <gtk--/frame.h>

class table_zufall_glade : public Gtk::Table
{  
protected:
        
        class Gtk::Table *table_zufall;
        class Gtk::ToggleButton *togglebutton_vorgaben;
        class Gtk::CheckButton *checkbutton_spezies;
        class Gtk::CheckButton *checkbutton_herkunft;
        class Gtk::CheckButton *checkbutton_typ;
        class Gtk::CheckButton *checkbutton_werte;
        class Gtk::CheckButton *checkbutton_ange_fert;
        class Gtk::CheckButton *checkbutton_st;
        class Gtk::CheckButton *checkbutton_gs;
        class Gtk::CheckButton *checkbutton_gw;
        class Gtk::CheckButton *checkbutton_ko;
        class Gtk::CheckButton *checkbutton_in;
        class Gtk::CheckButton *checkbutton_zt;
        class Gtk::CheckButton *checkbutton_au;
        class Gtk::CheckButton *checkbutton_pa;
        class Gtk::CheckButton *checkbutton_wk;
        class Gtk::CheckButton *checkbutton_sb;
        class Gtk::CheckButton *checkbutton_b;
        class Gtk::Frame *frame_werte_vorgaben;
        class Gtk::Frame *frame_vorgaben;
        
        table_zufall_glade(GlademmData *_data);
        
        ~table_zufall_glade();
};
#endif
