// generated 2002/9/10 12:23:59 CEST by thoma@Tiger.(none)
// using glademm V1.1.1c_cvs
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- /home/thoma/rollenspiel/midgard/programme/gcc_3.0/midgard/midgard.glade
// for gtk 1.2.10 and gtkmm 1.2.10
//
// Please modify the corresponding derived classes in ./src/midgard_CG.hh and./src/midgard_CG.cc

#ifndef _MIDGARD_CG_GLADE_HH
#  define _MIDGARD_CG_GLADE_HH


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
#include <gtk--/tooltips.h>
#include <gtk--/button.h>
#include <gtk--/toolbar.h>
#include <gtk--/handlebox.h>
#include <gtk--/menubar.h>
#include "Midgard_Info.hh"
#include <gtk--/pixmap.h>
#include <gtk--/label.h>
#include "table_grundwerte.hh"
#include "table_lernschema.hh"
#include <gtk--/frame.h>
#include "table_steigern.hh"
#include "table_beschreibung.hh"
#include "table_ausruestung.hh"
#include "table_optionen.hh"
#include <gtk--/list.h>
#include <gtk--/togglebutton.h>
#include "SimpleTree.hh"
#include "table_zufall.hh"
#include <gtk--/notebook.h>
#include <gtk--/eventbox.h>

class midgard_CG_glade : public Gtk::Window
{  
        
        GlademmData *_data;
protected:
        Gtk::Tooltips _tooltips;
        class Gtk::Window *midgard_CG;
        class Gtk::Toolbar *toolbar_top;
        class Gtk::Button *button_main_drucken;
        class Gtk::Button *button_undo;
        class Gtk::Button *button_redo;
        class Gtk::HandleBox *griff_toolbar_top;
        class Gtk::MenuBar *main_menubar;
        class Gtk::HandleBox *handlebox_menu;
        class Midgard_Info *Midgard_Info;
        class Gtk::Pixmap *pixmap_original_tux;
        class Gtk::Pixmap *pixmap_logo;
        class Gtk::Label *label_notebook_info;
        class table_grundwerte *table_grundwerte;
        class Gtk::Pixmap *pixmap_notebook_grundwerte;
        class Gtk::Label *label_notebook_grundwerte;
        class table_lernschema *table_lernschema;
        class Gtk::Frame *frame_lernschema;
        class Gtk::Pixmap *pixmap_notebook_lernen;
        class Gtk::Label *label_notebook_lernen;
        class table_steigern *table_steigern;
        class Gtk::Frame *frame_steigern;
        class Gtk::Pixmap *pixmap_notebook_steigern;
        class Gtk::Label *label_notebook_steigern;
        class table_beschreibung *table_beschreibung;
        class Gtk::Pixmap *pixmap_notebook_beschreibung;
        class Gtk::Label *label_notebook_beschreibung;
        class table_ausruestung *table_ausruestung;
        class Gtk::Pixmap *pixmap_notebook_ausruestung;
        class Gtk::Label *label_notebook_ausruestung;
        class table_optionen *table_optionen;
        class Gtk::Pixmap *pixmap_notebook_optionen;
        class Gtk::Label *label_notebook_optionen;
        class Gtk::List *list_news;
        class Gtk::ToggleButton *togglebutton_delete_abenteurer_aus_liste;
        class SimpleTree *AbenteurerListe;
        class SimpleTree *undo_tree;
        class Gtk::Pixmap *pixmap_notebook_news_1;
        class Gtk::Pixmap *pixmap_notebook_news_2;
        class Gtk::Label *label_notebook_news;
        class table_zufall *table_zufall;
        class Gtk::Pixmap *pixmap167;
        class Gtk::Label *label603;
        class Gtk::Notebook *notebook_main;
        class Gtk::Label *label_status;
        class Gtk::Label *label_wizard;
        class Gtk::Frame *frame_regionen_status;
        class Gtk::EventBox *eventbox_NSC_aktiv;
        class Gtk::EventBox *eventbox_wizard_aktiv;
        class Gtk::EventBox *eventbox_haus_aktiv;
        class Gtk::HandleBox *handlebox_status;
        
        midgard_CG_glade();
        
        ~midgard_CG_glade();
};
#endif
