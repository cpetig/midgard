// generated 2003/11/24 16:28:25 CET by christof@puck.petig-baender.de
// using glademm V2.0.0c_cvs
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- --image-provider=MagusImage midgard.glade
// for gtk 2.2.4 and gtkmm 2.2.8
//
// Please modify the corresponding derived classes in ./src/midgard_CG.hh and./src/midgard_CG.cc

#ifndef _MIDGARD_CG_GLADE_HH
#  define _MIDGARD_CG_GLADE_HH


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

#include <gtkmm/window.h>
#include <gtkmm/tooltips.h>
#include "ChoiceButton.hh"
#include "DoubleButton.hh"
#include <gtkmm/button.h>
#include <gtkmm/toolbar.h>
#include <gtkmm/handlebox.h>
#include <gtkmm/menubar.h>
#include "table_grundwerte.hh"
#include <gtkmm/eventbox.h>
#include <gtkmm/image.h>
#include <gtkmm/label.h>
#include "table_lernschema.hh"
#include <gtkmm/frame.h>
#include "table_steigern.hh"
#include "table_beschreibung.hh"
#include "table_ausruestung.hh"
#include "table_optionen.hh"
#include "Midgard_Info.hh"
#include <gtkmm/treeview.h>
#include <gtkmm/togglebutton.h>
#include "SimpleTree.hh"
#include "table_zufall.hh"
#include <gtkmm/notebook.h>
#include <gtkmm/box.h>

class midgard_CG_glade : public Gtk::Window
{  
        
        GlademmData *gmm_data;
protected:
        Gtk::Tooltips _tooltips;
        class Gtk::Window *midgard_CG;
        class ChoiceButton *button_neuer_charakter;
        class ChoiceButton *button_speichern;
        class ChoiceButton *button_main_drucken;
        class DoubleButton *button_undo;
        class DoubleButton *button_redo;
        class Gtk::Toolbar *toolbar_top;
        class Gtk::Button *button_schliessen;
        class Gtk::HandleBox *griff_toolbar_top;
        class Gtk::MenuBar *main_menubar;
        class Gtk::HandleBox *handlebox_menu;
        class table_grundwerte *table_grundwerte;
        class Gtk::EventBox *grundwerte_background;
        class Gtk::Image *pixmap_notebook_grundwerte;
        class Gtk::Label *label_notebook_grundwerte;
        class Gtk::EventBox *eventbox_grundwerte;
        class table_lernschema *table_lernschema;
        class Gtk::Frame *frame_lernschema;
        class Gtk::Image *pixmap_notebook_lernen;
        class Gtk::Label *label_notebook_lernen;
        class Gtk::EventBox *eventbox_lernen;
        class table_steigern *table_steigern;
        class Gtk::Frame *frame_steigern;
        class Gtk::Image *pixmap_notebook_steigern;
        class Gtk::Label *label_notebook_steigern;
        class Gtk::EventBox *eventbox_steigern;
        class table_beschreibung *table_beschreibung;
        class Gtk::Image *pixmap_notebook_beschreibung;
        class Gtk::Label *label_notebook_beschreibung;
        class Gtk::EventBox *eventbox_beschreibung;
        class table_ausruestung *table_ausruestung;
        class Gtk::Image *pixmap_notebook_ausruestung;
        class Gtk::Label *label_notebook_ausruestung;
        class Gtk::EventBox *eventbox_ausruestung;
        class table_optionen *table_optionen;
        class Gtk::Image *pixmap_notebook_optionen;
        class Gtk::Label *label_notebook_optionen;
        class Gtk::EventBox *eventbox_optionen;
        class Midgard_Info *Midgard_Info;
        class Gtk::Image *pixmap_original_tux;
        class Gtk::Label *label_notebook_info;
        class Gtk::EventBox *eventbox_credits;
        class Gtk::TreeView *list_news;
        class Gtk::ToggleButton *togglebutton_delete_abenteurer_aus_liste;
        class SimpleTree *AbenteurerListe;
        class Gtk::Label *label_notebook_news;
        class Gtk::EventBox *eventbox_geschichte;
        class table_zufall *table_zufall;
        class Gtk::Image *pixmap167;
        class Gtk::Label *label603;
        class Gtk::EventBox *eventbox_zufall;
        class Gtk::Notebook *notebook_main;
        class Gtk::Label *label_status;
        class Gtk::Label *label_wizard;
        class Gtk::Frame *frame_regionen_status;
        class Gtk::EventBox *eventbox_Original_Midgard;
        class Gtk::EventBox *eventbox_NSC_aktiv;
        class Gtk::EventBox *eventbox_wizard_aktiv;
        class Gtk::Frame *frame_haus_status;
        class Gtk::HBox *hbox_status;
        class Gtk::HandleBox *handlebox_status;
        
        midgard_CG_glade();
        
        ~midgard_CG_glade();
private:
        virtual void on_laden() = 0;
        virtual void on_button_undo_clicked() = 0;
        virtual void on_undo_secondpressed(int mousebutton) = 0;
        virtual void on_button_redo_clicked() = 0;
        virtual void on_redo_secondpressed(int mousebutton) = 0;
        virtual void on_button_menu() = 0;
        virtual void on_button_info_clicked() = 0;
        virtual void on_button_html_hilfe_clicked() = 0;
        virtual void on_schliessen_CG_clicked() = 0;
        virtual void on_neuer_charakter_clicked() = 0;
        virtual void on_neuer_abenteurer_mit_wizard_activate() = 0;
        virtual void on_wizard_beenden_activate() = 0;
        virtual void xml_import_auswahl() = 0;
        virtual void save_existing_filename() = 0;
        virtual void xml_export_auswahl() = 0;
        virtual void on_exportieren_activate() = 0;
        virtual void on_exportieren_ranas_pdf_dokumente_activate() = 0;
        virtual void on_abenteurerdokument_drucken() = 0;
        virtual void on_nur_sichtbares_drucken() = 0;
        virtual void on_auch_unsichtbares_drucken() = 0;
        virtual void on_beschreibung_drucken() = 0;
        virtual void on_alles_drucken() = 0;
        virtual void on_leeres_abenteurerdokument_drucken() = 0;
        virtual void on_spielleiterbogen_drucken_activate() = 0;
        virtual void on_schlie__en1_activate() = 0;
        virtual void menu_geschichte_selected() = 0;
        virtual void on_anleitung_menu_activate() = 0;
        virtual void on_info_credits_menu_activate() = 0;
        virtual void on_news_menu_activate() = 0;
        virtual void grundwerte_background_create() = 0;
        virtual bool on_eventbox_grundwerte_button_release_event(GdkEventButton *ev) = 0;
        virtual bool on_eventbox_lernen_button_release_event(GdkEventButton *ev) = 0;
        virtual bool on_eventbox_steigern_button_release_event(GdkEventButton *ev) = 0;
        virtual bool on_eventbox_beschreibung_button_release_event(GdkEventButton *ev) = 0;
        virtual bool on_eventbox_ausruestung_button_release_event(GdkEventButton *ev) = 0;
        virtual bool on_eventbox_optionen_button_release_event(GdkEventButton *ev) = 0;
        virtual bool on_eventbox_credits_button_release_event(GdkEventButton *ev) = 0;
        virtual void on_togglebutton_delete_abenteurer_aus_liste_toggled() = 0;
        virtual void on_AbenteurerListe_leaf(cH_RowDataBase leaf) = 0;
        virtual bool on_eventbox_geschichte_button_release_event(GdkEventButton *ev) = 0;
        virtual bool on_eventbox_zufall_button_release_event(GdkEventButton *ev) = 0;
        virtual void on_notebook_main_switch_page(GtkNotebookPage *p0, guint p1) = 0;
        virtual bool on_midgard_CG_delete_event(GdkEventAny *ev) = 0;
        virtual bool on_eventbox_MCG_button_press_event(GdkEventButton *ev) = 0;
};
#endif
