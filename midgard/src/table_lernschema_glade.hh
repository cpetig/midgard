// generated 2002/10/30 15:39:47 CET by christof@puck.petig-baender.de
// using glademm V1.1.2a_cvs
//
// DO NOT EDIT THIS FILE ! It was created using
// /home/christof/cvs/glade--/src/glade-- midgard.glade
// for gtk 1.2.10 and gtkmm 1.2.10
//
// Please modify the corresponding derived classes in ./src/table_lernschema.hh and./src/table_lernschema.cc

#ifndef _TABLE_LERNSCHEMA_GLADE_HH
#  define _TABLE_LERNSCHEMA_GLADE_HH


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
#include <gtk--/spinbutton.h>
#include <gtk--/radiobutton.h>
#include <gtk--/combo.h>
#include <gtk--/frame.h>
#include <gtk--/label.h>
#include <gtk--/togglebutton.h>
#include <gtk--/eventbox.h>
#include <gtk--/checkbutton.h>
#include <gtk--/pixmap.h>
#include <gtk--/scrolledwindow.h>
#include "MidgardBasicTree.hh"
#include <gtk--/button.h>
#include <gtk--/entry.h>
#include <gtk--/box.h>
#include <gtk--/handlebox.h>

class table_lernschema_glade : public Gtk::Table
{  
protected:
        
        Gtk::Tooltips _tooltips;
        class Gtk::Table *table_lernschema;
        class Gtk::SpinButton *spinbutton_fach;
        class Gtk::RadioButton *button_fachkenntnisse;
        class Gtk::SpinButton *spinbutton_allgemein;
        class Gtk::RadioButton *button_allgemeinwissen;
        class Gtk::SpinButton *spinbutton_unge;
        class Gtk::RadioButton *button_untyp_fertigkeiten;
        class Gtk::Combo *combo_kido_stil;
        class Gtk::RadioButton *button_kido_auswahl;
        class Gtk::Frame *frame_KiDo_lernschema;
        class Gtk::SpinButton *spinbutton_waffen;
        class Gtk::RadioButton *button_waffen;
        class Gtk::SpinButton *spinbutton_zauber;
        class Gtk::RadioButton *button_zauber;
        class Gtk::Combo *combo_magier_spezialgebiet;
        class Gtk::Frame *frame_lernpunkte;
        class Gtk::Label *fertig_typ;
        class Gtk::Label *label_ruestung_lernschema;
        class Gtk::ToggleButton *togglebutton_spezialwaffe;
        class Gtk::Label *label_herkunft_lernschema;
        class Gtk::EventBox *eventbox_zusatz;
        class Gtk::CheckButton *togglebutton_teure_anzeigen;
        class Gtk::CheckButton *togglebutton_gelernte_anzeigen;
        class Gtk::Table *table_lernschema_121;
        class Gtk::Pixmap *pixmap_dfr3;
        class Gtk::ScrolledWindow *scrolledwindow_dfr3;
        class MidgardBasicTree *tree_gelerntes;
        class Gtk::ScrolledWindow *scrolledwindow_lernen;
        class MidgardBasicTree *Tree_Lernschema_Zusatz;
        class Gtk::CheckButton *checkbutton_einschraenkungen_zusatz;
        class Gtk::Frame *frame_lernschema_zusatz;
        class Gtk::Label *label_lernschma_titel;
        class Gtk::Button *button_angeborene_fert;
        class Gtk::SpinButton *spinbutton_beruf;
        class Gtk::Table *table_berufsprozent;
        class Gtk::Entry *entry_berufsname;
        class Gtk::VBox *vbox_berufsname;
        class Gtk::Label *label_gwr;
        class Gtk::SpinButton *spinbutton_waffen_lernschema;
        class Gtk::Table *table_waffen_lernschema_eingabe;
        class Gtk::Button *button_herkunft;
        class Gtk::Button *button_lernpunkte;
        class Gtk::ToggleButton *togglebutton_lernpunkte_edit;
        class Gtk::Button *button_beruf;
        class Gtk::Button *button_lernschema_geld;
        class Gtk::Button *button_lernschema_waffen;
        class Gtk::Button *button_ruestung;
        class Gtk::Button *button_ausruestung;
        class Gtk::HandleBox *handlebox_lernschema;
        
        table_lernschema_glade(GlademmData *_data);
        
        ~table_lernschema_glade();
private:
        virtual void on_button_waffe_trans_clicked() = 0;
        virtual void on_button_fach_trans_clicked() = 0;
        virtual void on_spinbutton_fach_activate() = 0;
        virtual gint on_spinbutton_fach_focus_out_event(GdkEventFocus *ev) = 0;
        virtual gint on_spinbutton_fach_focus_in_event(GdkEventFocus *ev) = 0;
        virtual void on_lernliste_wahl_toggled() = 0;
        virtual void on_spinbutton_allgemein_activate() = 0;
        virtual gint on_spinbutton_allgemein_focus_out_event(GdkEventFocus *ev) = 0;
        virtual gint on_spinbutton_allgemein_focus_in_event(GdkEventFocus *ev) = 0;
        virtual void on_spinbutton_unge_activate() = 0;
        virtual gint on_spinbutton_unge_focus_out_event(GdkEventFocus *ev) = 0;
        virtual gint on_spinbutton_unge_focus_in_event(GdkEventFocus *ev) = 0;
        virtual void on_combo_kido_stil_activate() = 0;
        virtual gint on_combo_kido_stil_focus_out_event(GdkEventFocus *ev) = 0;
        virtual void on_kido_wahl_clicked() = 0;
        virtual void on_spinbutton_waffen_activate() = 0;
        virtual gint on_spinbutton_waffen_focus_out_event(GdkEventFocus *ev) = 0;
        virtual gint on_spinbutton_waffen_focus_in_event(GdkEventFocus *ev) = 0;
        virtual void on_button_waffen_clicked() = 0;
        virtual void on_spinbutton_zaubern_activate() = 0;
        virtual gint on_spinbutton_zaubern_focus_out_event(GdkEventFocus *ev) = 0;
        virtual gint on_spinbutton_zaubern_focus_in_event(GdkEventFocus *ev) = 0;
        virtual void on_combo_magier_spezialgebiet_activate() = 0;
        virtual gint on_combo_magier_spezialgebiet_focus_out_event(GdkEventFocus *ev) = 0;
        virtual void on_togglebutton_spezialwaffe_toggled() = 0;
        virtual gint on_eventbox_zusatz_leave_notify_event(GdkEventCrossing *ev) = 0;
        virtual void on_togglebutton_teure_anzeigen_toggled() = 0;
        virtual void on_togglebutton_gelernte_anzeigen_toggled() = 0;
        virtual void on_tree_gelerntes_leaf_selected(cH_RowDataBase leaf) = 0;
        virtual void on_togglebutton_einschraenkungen_zusatz_anzeigen_toggled() = 0;
        virtual void on_herkunftsland_clicked() = 0;
        virtual gint on_angeborene_fertigkeit_button_release_event(GdkEventButton *ev) = 0;
        virtual void on_lernpunkte_wuerfeln_clicked() = 0;
        virtual void on_togglebutton_lernpunkte_edit_toggled() = 0;
        virtual gint on_button_beruf_release_event(GdkEventButton *ev) = 0;
        virtual void on_spinbutton_beruf_activate() = 0;
        virtual gint on_spinbutton_beruf_focus_in(GdkEventFocus *ev) = 0;
        virtual void on_entry_berufsname_activate() = 0;
        virtual gint on_button_lernschema_geld_button_release_event(GdkEventButton *ev) = 0;
        virtual gint on_button_lernschema_waffen_button_release_event(GdkEventButton *ev) = 0;
        virtual void on_spinbutton_waffen_lernschema_activate() = 0;
        virtual gint on_spinbutton_waffen_lernschema_focus_in_event(GdkEventFocus *ev) = 0;
        virtual gint on_button_ruestung_button_release_event(GdkEventButton *ev) = 0;
        virtual gint on_button_ausruestung_button_release_event(GdkEventButton *ev) = 0;
};
#endif
