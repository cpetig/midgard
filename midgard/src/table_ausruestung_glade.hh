// generated 2002/12/11 19:15:26 CET by christof@puck.petig-baender.de
// using glademm V1.1.3c_cvs
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- --gnome2 midgard.glade
// for gtk 2.0.9 and gtkmm 2.0.1
//
// Please modify the corresponding derived classes in ./src/table_ausruestung.hh and./src/table_ausruestung.cc

#ifndef _TABLE_AUSRUESTUNG_GLADE_HH
#  define _TABLE_AUSRUESTUNG_GLADE_HH


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

#include <gtkmm/table.h>
#include <gtkmm/tooltips.h>
#include <gtkmm/togglebutton.h>
#include <gtkmm/entry.h>
#include <gtkmm/button.h>
#include <gtkmm/combo.h>
#include <gtkmm/spinbutton.h>
#include <gtkmm/checkbutton.h>
#include <gtkmm/scrolledwindow.h>
#include <gtkmm/label.h>
#include "SimpleTree.hh"

class table_ausruestung_glade : public Gtk::Table
{  
protected:
        
        Gtk::Tooltips _tooltips;
        class Gtk::Table *table_ausruestung;
        class Gtk::ToggleButton *togglebutton_gruppe_neu;
        class Gtk::ToggleButton *togglebutton_artikel_neu;
        class Gtk::Entry *entry_art;
        class Gtk::Entry *entry_art2;
        class Gtk::Button *button_art_speichern;
        class Gtk::Table *table_gruppe;
        class Gtk::Entry *entry_name;
        class Gtk::Combo *combo_region;
        class Gtk::Combo *combo_einheit;
        class Gtk::SpinButton *spinbutton_preis;
        class Gtk::SpinButton *spinbutton_gewicht;
        class Gtk::Button *button_artikel_speichern;
        class Gtk::Combo *combo_art;
        class Gtk::Combo *combo_art2;
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
        class Gtk::ToggleButton *togglebutton_unverkauflich;
        
        table_ausruestung_glade(GlademmData *_data);
        
        ~table_ausruestung_glade();
private:
        virtual bool on_button_ausruestung_druck_release_event(GdkEventButton *ev) = 0;
        virtual void on_togglebutton_gruppe_neu_toggled() = 0;
        virtual void on_togglebutton_artikel_neu_toggled() = 0;
        virtual void on_entry_art_activate() = 0;
        virtual void on_entry_art2_activate() = 0;
        virtual void on_button_art_speichern_clicked() = 0;
        virtual void on_entry_name_activate() = 0;
        virtual void on_combo_entry_region_activate() = 0;
        virtual void on_combo_entry_einheit_activate() = 0;
        virtual void on_combo_entry_einheit_changed() = 0;
        virtual void on_spinbutton_preis_activate() = 0;
        virtual void on_spinbutton_gewicht_activate() = 0;
        virtual void on_button_artikel_speichern_clicked() = 0;
        virtual void on_combo_entry_artikel_art_activate() = 0;
        virtual bool on_combo_entry_artikel_art_focus_out_event(GdkEventFocus *ev) = 0;
        virtual void on_combo_entry_artikel_art_changed() = 0;
        virtual void on_combo_entry_art2_activate() = 0;
        virtual bool on_combo_entry_art2_focus_out_event(GdkEventFocus *ev) = 0;
        virtual void on_combo_entry_art2_changed() = 0;
        virtual void on_ausruestung_loeschen_clicked() = 0;
        virtual void on_preise_tree_neu_leaf_selected(cH_RowDataBase leaf) = 0;
        virtual void on_preise_tree_neu_drag_data_get(GdkDragContext *context,GtkSelectionData *selection_data,guint info,guint time) = 0;
        virtual void on_checkbutton_ausruestung_geld_toggled() = 0;
        virtual void on_togglebutton_unverkauflich_toggled() = 0;
};
#endif
