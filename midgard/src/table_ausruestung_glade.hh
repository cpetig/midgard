// generated 2002/5/20 8:42:42 CEST by thoma@Tiger.(none)
// using glademm V0.6.4b_cvs
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- /home/thoma/rollenspiel/midgard/programme/gcc_3.0/midgard/midgard.glade
// for gtk 1.2.10 and gtkmm 1.2.8
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
#include "SimpleTree.hh"
#include <gtk--/clist.h>
#include <gtk--/label.h>
#include <gtk--/checkbutton.h>
#include <gtk--/viewport.h>
#include <gtk--/button.h>
#include <gtk--/togglebutton.h>
#include <gtk--/entry.h>
#include <gtk--/spinbutton.h>
#include <gtk--/optionmenu.h>

class table_ausruestung_glade : public Gtk::Table
{  
protected:
        
        Gtk::Tooltips _tooltips;
        class Gtk::Table *table_ausruestung;
        class SimpleTree *preise_tree;
        class Gtk::CList *clist_preisliste;
        class Gtk::Label *label_golda;
        class Gtk::Label *label_silbera;
        class Gtk::Label *label_kupfera;
        class Gtk::CheckButton *checkbutton_ausruestung_geld;
        class Gtk::Viewport *viewport_modi;
        class Gtk::CheckButton *checkbutton_sichtbar;
        class Gtk::Button *button_ausruestung_loeschen;
        class Gtk::Viewport *viewport_ausruestung;
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
        
        table_ausruestung_glade(GlademmData *_data);
        
        ~table_ausruestung_glade();
};
#endif