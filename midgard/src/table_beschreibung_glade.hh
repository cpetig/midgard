// generated 2002/9/13 14:06:30 CEST by thoma@Tiger.(none)
// using glademm V1.1.1c_cvs
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- /home/thoma/rollenspiel/midgard/programme/gcc_3.0/midgard/midgard.glade
// for gtk 1.2.10 and gtkmm 1.2.10
//
// Please modify the corresponding derived classes in ./src/table_beschreibung.hh and./src/table_beschreibung.cc

#ifndef _TABLE_BESCHREIBUNG_GLADE_HH
#  define _TABLE_BESCHREIBUNG_GLADE_HH


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
#include <gtk--/label.h>
#include <gtk--/spinbutton.h>
#include <gtk--/text.h>

class table_beschreibung_glade : public Gtk::Table
{  
protected:
        
        class Gtk::Table *table_beschreibung;
        class Gtk::Label *label_grafik;
        class Gtk::SpinButton *spinbutton_pix_breite;
        class Gtk::Text *text_charakter_beschreibung;
        
        table_beschreibung_glade(GlademmData *_data);
        
        ~table_beschreibung_glade();
};
#endif
