// generated 2002/10/26 9:31:50 CEST by thoma@Tiger.(none)
// using glademm V1.1.1c_cvs
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- /home/thoma/rollenspiel/midgard/programme/gcc_3.0/midgard/midgard.glade
// for gtk 1.2.10 and gtkmm 1.2.10
//
// Please modify the corresponding derived classes in ./src/table_ausruestung.hh and./src/table_ausruestung.cc

#ifndef _TABLE_AUSRUESTUNG_GLADE_HH
#  define _TABLE_AUSRUESTUNG_GLADE_HH


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
#include <gtk--/tooltips.h>
#include <gtk--/togglebutton.h>
#include <gtk--/entry.h>
#include <gtk--/spinbutton.h>
#include <gtk--/optionmenu.h>
#include <gtk--/button.h>
#include <gtk--/checkbutton.h>
#include <gtk--/scrolledwindow.h>
#include <gtk--/label.h>
#include "SimpleTree.hh"

class table_ausruestung_glade : public Gtk::Table
{  
protected:
        
        Gtk::Tooltips _tooltips;
        class Gtk::Table *table_ausruestung;
        class Gtk::ToggleButton *togglebutton_gruppe_neu;
        class Gtk::ToggleButton *togglebutton_artikel_neu;
        class Gtk::Entry *entry_art;
        class Gtk::Entry *entry_typ;
        class Gtk::Entry *entry_eigenschaft;
        class Gtk::Table *table_gruppe;
        class Gtk::SpinButton *spinbutton_preis;
        class Gtk::SpinButton *spinbutton_gewicht;
        class Gtk::OptionMenu *optionmenu_einheit;
        struct optionmenu_einheit
        {  enum enum_t 
	   {  GS, SS, KS, 
	   };
        };
        class Gtk::Entry *entry_name;
        class Gtk::Entry *entry_artikel_art2;
        class Gtk::Entry *entry_artikel_art;
        class Gtk::Table *table_artikel;
        class Gtk::Button *button_ausruestung_loeschen;
        class Gtk::CheckButton *checkbutton_sichtbar;
        class Gtk::ScrolledWindow *scrolledwindow_ausruestung;
        class Gtk::Label *label_gesamtlast;
        class Gtk::Label *label_normallast;
        class Gtk::Label *label_hoechstlast;
        class Gtk::Label *label_schublast;
        class SimpleTree *preise_tree_neu;
        class Gtk::CheckButton *checkbutton_ausruestung_geld;
        class Gtk::Label *label_golda;
        class Gtk::Label *label_silbera;
        class Gtk::Label *label_kupfera;
        
        table_ausruestung_glade(GlademmData *_data);
        
        ~table_ausruestung_glade();
};
#endif
