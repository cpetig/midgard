// generated 2002/12/11 19:15:24 CET by christof@puck.petig-baender.de
// using glademm V1.1.3c_cvs
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- --gnome2 midgard.glade
// for gtk 2.0.9 and gtkmm 2.0.1
//
// Please modify the corresponding derived classes in ./src/table_steigern.hh and./src/table_steigern.cc

#ifndef _TABLE_STEIGERN_GLADE_HH
#  define _TABLE_STEIGERN_GLADE_HH


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
#include <gtkmm/label.h>
#include <gtkmm/frame.h>
#include <gtkmm/handlebox.h>
#include "LabelSpin.hh"
#include <gtkmm/scale.h>
#include <gtkmm/checkbutton.h>
#include <gtkmm/eventbox.h>
#include "FlashingPixmap.hh"
#include <gtkmm/button.h>
#include <gtkmm/spinbutton.h>
#include <gtkmm/radiobutton.h>
#include <gtkmm/togglebutton.h>
#include <gtkmm/box.h>
#include "MidgardBasicTree.hh"
#include <gtkmm/scrolledwindow.h>
#include <gtkmm/image.h>
#include <gtkmm/treeview.h>
#include <gtkmm/entry.h>
#include "SimpleTree.hh"
#include <gtkmm/notebook.h>

class table_steigern_glade : public Gtk::Table
{  
protected:
        
        Gtk::Tooltips _tooltips;
        class Gtk::Table *table_steigern;
        class Gtk::Label *label_s_grad;
        class Gtk::Label *label_s_resistenz;
        class Gtk::Label *label_s_zaubern;
        class Gtk::Label *label_s_abwehr;
        class Gtk::Label *label_alter;
        class Gtk::Label *label_s_ap;
        class Gtk::Label *label_steigertage;
        class Gtk::Label *steigern_typ;
        class Gtk::Label *label_steigern_spezies;
        class Gtk::Label *label_pp_abwehr;
        class Gtk::Label *label_pp_zaubern;
        class Gtk::Frame *frame_pp_zaubern;
        class Gtk::Label *label_pp_resistenz;
        class Gtk::Label *label_pp_spezial;
        class Gtk::Frame *frame_pp_spezial;
        class Gtk::HandleBox *handlebox_steigern_1;
        class LabelSpin *LabelSpin_aep;
        class LabelSpin *LabelSpin_kep;
        class LabelSpin *LabelSpin_zep;
        class LabelSpin *LabelSpin_gold;
        class LabelSpin *LabelSpin_silber;
        class LabelSpin *LabelSpin_kupfer;
        class LabelSpin *LabelSpin_gfp;
        class Gtk::Label *label_EP;
        class Gtk::Label *label_Gold;
        class Gtk::VScale *vscale_EP_Gold;
        class Gtk::CheckButton *button_gold_eingeben;
        class Gtk::CheckButton *checkbutton_gfp;
        class Gtk::CheckButton *button_EP;
        class Gtk::EventBox *eventbox_eppp_steigern;
        class Gtk::HandleBox *handlebox_steigern_2;
        class FlashingPixmap *flashing_gradanstieg;
        class Gtk::Label *label_grad_GFP;
        class Gtk::Label *label_ausdauer_GFP;
        class Gtk::Label *label_abwehr_GFP;
        class Gtk::Label *label_zauber_GFP;
        class Gtk::Button *button_grad_zaubern;
        class Gtk::Label *label_resistenz_GFP;
        class Gtk::SpinButton *spinbutton_eigenschaften_grad_anstieg;
        class Gtk::Button *button_grad_basiswerte;
        class Gtk::Table *table_gradsteigern_lang;
        class Gtk::HandleBox *handlebox_steigern_4;
        class Gtk::RadioButton *radiobutton_pp_hoch_wie_geht;
        class Gtk::RadioButton *radiobutton_pp_1stufe;
        class Gtk::ToggleButton *togglebutton_pp_verfallen;
        class Gtk::ToggleButton *togglebutton_pp_aep_fuellen;
        class Gtk::Table *table_pp_einstellungen;
        class Gtk::RadioButton *radiobutton_praxis;
        class Gtk::RadioButton *radiobutton_unterweisung;
        class Gtk::RadioButton *radiobutton_selbst;
        class Gtk::Frame *frame_lernen_mit;
        class Gtk::RadioButton *radio_spruchrolle_auto;
        class Gtk::RadioButton *radio_spruchrolle_wuerfeln;
        class Gtk::ToggleButton *togglebutton_spruchrolle;
        class Gtk::ToggleButton *togglebutton_alle_zauber;
        class Gtk::ToggleButton *togglebutton_zaubersalze;
        class Gtk::Frame *frame_zauber_zusatz;
        class Gtk::RadioButton *radiobutton_reduzieren;
        class Gtk::RadioButton *radiobutton_verlernen;
        class Gtk::RadioButton *radiobutton_steigern;
        class Gtk::Frame *frame_fertigkeit;
        class Gtk::SpinButton *spinbutton_pp_eingeben;
        class Gtk::ToggleButton *togglebutton_praxispunkte;
        class Gtk::RadioButton *radiobutton_pp_fertigkeit;
        class Gtk::RadioButton *radiobutton_pp_abwehr;
        class Gtk::RadioButton *radiobutton_pp_zauber;
        class Gtk::RadioButton *radiobutton_pp_spezial;
        class Gtk::RadioButton *radiobutton_pp_resistenz;
        class Gtk::VBox *vbox_praxispunkte;
        class Gtk::Frame *frame_praxispunkte;
        class Gtk::HandleBox *handlebox_steigern_3;
        class Gtk::Table *table_handlebox1;
        class MidgardBasicTree *tree_steigern_zusatz;
        class Gtk::ScrolledWindow *scrolledwindow_landauswahl;
        class MidgardBasicTree *alte_fert_tree;
        class MidgardBasicTree *neue_fert_tree;
        class Gtk::Label *label_ns_fertigkeiten;
        class Gtk::Image *pixmap_ns_fertig;
        class MidgardBasicTree *alte_waffen_tree;
        class MidgardBasicTree *neue_waffen_tree;
        class MidgardBasicTree *alte_grund_tree;
        class MidgardBasicTree *neue_grund_tree;
        class Gtk::Label *label_nw_waffen;
        class Gtk::Image *pixmap_ns_waffen;
        class MidgardBasicTree *alte_zauber_tree;
        class MidgardBasicTree *neue_zauber_tree;
        class MidgardBasicTree *alte_zaubermittel_tree;
        class MidgardBasicTree *neue_zaubermittel_tree;
        class Gtk::Table *table_magier_steigern;
        class Gtk::Label *label_ns_zauber;
        class Gtk::Image *pixmap_ns_zauber;
        class MidgardBasicTree *alte_kido_tree;
        class MidgardBasicTree *neue_kido_tree;
        class Gtk::Image *pixmap_kurai;
        class Gtk::Table *table_kido_steigern;
        class Gtk::Label *label_ns_kido;
        class Gtk::Image *pixmap_ns_kido;
        class MidgardBasicTree *alte_sprache_tree;
        class Gtk::ToggleButton *togglebutton_neue_sprache_pp;
        class MidgardBasicTree *neue_sprache_tree;
        class MidgardBasicTree *alte_schrift_tree;
        class MidgardBasicTree *neue_schrift_tree;
        class Gtk::Label *label_ns_sprache;
        class Gtk::Image *pixmap_ns_sprache;
        class Gtk::Label *label_ruestung_1;
        class Gtk::CheckButton *button_ruestung_1;
        class Gtk::Label *label_ruestung_2;
        class Gtk::CheckButton *button_ruestung_2;
        class Gtk::TreeView *clist_ruestung;
        class Gtk::Label *label_av_bonus;
        class Gtk::Label *label_sl_bonus;
        class Gtk::SpinButton *spinbutton_av_bonus;
        class Gtk::SpinButton *spinbutton_sl_bonus;
        class Gtk::Entry *entry_magisch;
        class Gtk::Table *table_magbonus;
        class Gtk::CheckButton *checkbutton_mag_waffenbonus;
        class SimpleTree *waffenbesitz_alt_tree;
        class SimpleTree *waffenbesitz_neu_tree;
        class Gtk::Label *label_ns_besitz;
        class Gtk::Image *pixmap_ns_besitz;
        class Gtk::Notebook *notebook_lernen;
        
        table_steigern_glade(GlademmData *_data);
        
        ~table_steigern_glade();
private:
        virtual void on_button_alter_clicked() = 0;
        virtual void on_LabelSpin_aep_activate() = 0;
        virtual void on_LabelSpin_kep_activate() = 0;
        virtual void on_LabelSpin_zep_activate() = 0;
        virtual void on_LabelSpin_gold_activate() = 0;
        virtual void on_LabelSpin_silber_activate() = 0;
        virtual void on_LabelSpin_kupfer_activate() = 0;
        virtual void on_LabelSpin_gfp_activate() = 0;
        virtual bool vscale_value_changed(GdkEventButton *ev) = 0;
        virtual bool on_button_gold_eingeben_button_release_event(GdkEventButton *ev) = 0;
        virtual bool on_checkbutton_gfp_button_release_event(GdkEventButton *ev) = 0;
        virtual bool on_button_EP_eingeben_button_release_event(GdkEventButton *ev) = 0;
        virtual void on_button_grad_clicked() = 0;
        virtual void on_button_grad_ausdauer_clicked() = 0;
        virtual void on_button_grad_abwehr_clicked() = 0;
        virtual void on_button_grad_zaubern_clicked() = 0;
        virtual void on_grad_anstieg_clicked() = 0;
        virtual void on_button_grad_resistenz_clicked() = 0;
        virtual void on_spinbutton_eigenschaften_grad_anstieg_activate() = 0;
        virtual bool on_button_grad_basiswerte_button_release_event(GdkEventButton *ev) = 0;
        virtual void on_togglebutton_pp_verfallen_toggled() = 0;
        virtual void on_togglebutton_pp_aep_fuellen_toggled() = 0;
        virtual void on_radio_praxis_toggled() = 0;
        virtual void on_radio_unterweisung_toggled() = 0;
        virtual void on_radio_selbst_toggled() = 0;
        virtual void on_spruchrolle_toggled() = 0;
        virtual void on_togglebutton_alle_zauber_toggled() = 0;
        virtual void on_togglebutton_zaubersalze_toggled() = 0;
        virtual void on_radio_reduzieren_toggled() = 0;
        virtual void on_radio_verlernen_toggled() = 0;
        virtual void on_radio_steigern_toggled() = 0;
        virtual void on_spinbutton_pp_eingeben_activate() = 0;
        virtual void on_togglebutton_praxispunkte_toggled() = 0;
        virtual void on_radiobutton_pp_fertigkeit_toggled() = 0;
        virtual void on_radiobutton_pp_abwehr_toggled() = 0;
        virtual void on_radiobutton_pp_zauber_toggled() = 0;
        virtual void on_radiobutton_pp_spezial_toggled() = 0;
        virtual void on_radiobutton_pp_resistenz_toggled() = 0;
        virtual void on_steigern_zusatz_leaf_selected(cH_RowDataBase leaf) = 0;
        virtual void on_leaf_selected_alte_fert(cH_RowDataBase leaf) = 0;
        virtual void on_alte_fert_reorder() = 0;
        virtual void on_leaf_selected_neue_fert(cH_RowDataBase leaf) = 0;
        virtual void on_leaf_selected_alte_waffen(cH_RowDataBase leaf) = 0;
        virtual void on_alte_waffen_reorder() = 0;
        virtual void on_leaf_selected_neue_waffen(cH_RowDataBase leaf) = 0;
        virtual void on_leaf_selected_alte_grund(cH_RowDataBase leaf) = 0;
        virtual void on_leaf_selected_neue_grund(cH_RowDataBase leaf) = 0;
        virtual void on_leaf_selected_alte_zauber(cH_RowDataBase leaf) = 0;
        virtual void on_alte_zauber_reorder() = 0;
        virtual void on_leaf_selected_neue_zauber(cH_RowDataBase leaf) = 0;
        virtual void on_leaf_selected_alte_zauberwerk(cH_RowDataBase leaf) = 0;
        virtual void on_alte_zaubermittel_reorder() = 0;
        virtual void on_leaf_selected_neue_zauberwerk(cH_RowDataBase leaf) = 0;
        virtual void on_leaf_selected_alte_kido(cH_RowDataBase leaf) = 0;
        virtual void on_alte_kido_reorder() = 0;
        virtual void on_leaf_selected_neue_kido(cH_RowDataBase leaf) = 0;
        virtual void on_leaf_selected_alte_sprache(cH_RowDataBase leaf) = 0;
        virtual void on_alte_sprache_reorder() = 0;
        virtual void on_leaf_selected_neue_sprache(cH_RowDataBase leaf) = 0;
        virtual void on_leaf_selected_alte_schrift(cH_RowDataBase leaf) = 0;
        virtual void on_leaf_selected_neue_schrift(cH_RowDataBase leaf) = 0;
        virtual void on_button_ruestung_1_toggled() = 0;
        virtual void on_button_ruestung_2_toggled() = 0;
        virtual void on_spinbutton_av_bonus_activate() = 0;
        virtual void on_spinbutton_sl_bonus_activate() = 0;
        virtual void on_entry_magisch_activate() = 0;
        virtual void on_checkbutton_mag_waffenbonus_toggled() = 0;
        virtual void on_leaf_waffenbesitz_selected_alt(cH_RowDataBase leaf) = 0;
        virtual void on_alte_waffenbesitz_reorder() = 0;
        virtual void on_leaf_waffenbesitz_selected_neu(cH_RowDataBase leaf) = 0;
        virtual void on_notebook_lernen_switch_page(GtkNotebookPage *p0, guint p1) = 0;
};
#endif
