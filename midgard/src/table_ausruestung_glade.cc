// generated 2002/12/9 20:37:43 CET by thoma@Tiger.(none)
// using glademm V1.1.2a_cvs
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- /home/thoma/Berlios/Midgard/midgard/midgard.glade
// for gtk 1.2.10 and gtkmm 1.2.10
//
// Please modify the corresponding derived classes in ./src/table_ausruestung.cc

#include "config.h"
#include "table_ausruestung.hh"
#include <gtk--/button.h>
#include <gtk--/pixmap.h>
#include "../pixmaps/PrintChar-trans-50.xpm"
#include "../pixmaps/New_Art-50.xpm"
#include <gtk--/toolbar.h>
#include <gtk--/label.h>
#include "../pixmaps/SaveChar-trans-50.xpm"
#include <gtk--/box.h>
#include <gtk--/adjustment.h>
#include <gtk--/table.h>
#include <gtk--/handlebox.h>
#include "../pixmaps/Trash-32.xpm"
#include "../pixmaps/sichtbar.xpm"
#include <gtk--/separator.h>
#include <gtk--/frame.h>
#include <gtk--/scrolledwindow.h>
#include "../pixmaps/Money-50.xpm"
#include "../pixmaps/Angeb_Sicht-32.xpm"
#include <gtk--/paned.h>

table_ausruestung_glade::table_ausruestung_glade(GlademmData *_data
) : Gtk::Table(2, 2, false)
{  table_ausruestung = this;
   
   Gtk::Toolbar *toolbar39 = manage(new class Gtk::Toolbar(GTK_ORIENTATION_HORIZONTAL, GTK_TOOLBAR_BOTH));
   Gtk::Label *label503 = manage(new class Gtk::Label("Art"));
   Gtk::Label *label504 = manage(new class Gtk::Label("Art2"));
   entry_art = manage(new class Gtk::Entry());
   entry_art2 = manage(new class Gtk::Entry());
   
   Gtk::Pixmap *pixmap189 = manage(new class Gtk::Pixmap(SaveChar_trans_50_xpm));
   Gtk::Label *label651 = manage(new class Gtk::Label("Art\n"
		"speichern"));
   Gtk::HBox *hbox103 = manage(new class Gtk::HBox(false, 0));
   button_art_speichern = manage(new class Gtk::Button());
   table_gruppe = manage(new class Gtk::Table(2, 3, false));
   
   Gtk::Label *label506 = manage(new class Gtk::Label("Gegenstand"));
   Gtk::Label *label507 = manage(new class Gtk::Label("Preis"));
   Gtk::Label *label508 = manage(new class Gtk::Label("Einheit"));
   Gtk::Label *label511 = manage(new class Gtk::Label("Art"));
   Gtk::Label *label527 = manage(new class Gtk::Label("Art2"));
   entry_name = manage(new class Gtk::Entry());
   
   Gtk::Label *label509 = manage(new class Gtk::Label("Gew. (kg)"));
   Gtk::Label *label649 = manage(new class Gtk::Label("Region"));
   combo_region = manage(new class Gtk::Combo());
   combo_einheit = manage(new class Gtk::Combo());
   
   Gtk::Adjustment *spinbutton_preis_adj = manage(new class Gtk::Adjustment(1, 0, 100000, 1, 10, 10));
   spinbutton_preis = manage(new class Gtk::SpinButton(*spinbutton_preis_adj, 1, 1));
   
   Gtk::Adjustment *spinbutton_gewicht_adj = manage(new class Gtk::Adjustment(1, 0, 100, 1, 10, 10));
   spinbutton_gewicht = manage(new class Gtk::SpinButton(*spinbutton_gewicht_adj, 1, 2));
   
   Gtk::Pixmap *pixmap188 = manage(new class Gtk::Pixmap(SaveChar_trans_50_xpm));
   Gtk::Label *label650 = manage(new class Gtk::Label("Artikel\n"
		"speichern"));
   Gtk::HBox *hbox102 = manage(new class Gtk::HBox(false, 0));
   button_artikel_speichern = manage(new class Gtk::Button());
   combo_art = manage(new class Gtk::Combo());
   combo_art2 = manage(new class Gtk::Combo());
   table_artikel = manage(new class Gtk::Table(2, 8, false));
   
   Gtk::Table *table81 = manage(new class Gtk::Table(3, 1, false));
   Gtk::HandleBox *handlebox7 = manage(new class Gtk::HandleBox());
   Gtk::Pixmap *pixmap69 = manage(new class Gtk::Pixmap(Trash_32_xpm));
   Gtk::Label *label475 = manage(new class Gtk::Label("Löschen"));
   Gtk::HBox *hbox35 = manage(new class Gtk::HBox(false, 0));
   button_ausruestung_loeschen = manage(new class Gtk::Button());
   
   Gtk::Pixmap *pixmap89 = manage(new class Gtk::Pixmap(sichtbar_xpm));
   checkbutton_sichtbar = manage(new class Gtk::CheckButton());
   
   Gtk::Table *table105 = manage(new class Gtk::Table(4, 1, false));
   Gtk::Label *label623 = manage(new class Gtk::Label("Zunächst oben auswählen, wo der neue Gegenstand eingefügt werden soll,\n"
		"anschließend unten den neuen Gegenstand auswählen."));
   scrolledwindow_ausruestung = manage(new class Gtk::ScrolledWindow());
   label_gesamtlast = manage(new class Gtk::Label("kg"));
   
   Gtk::Label *label629 = manage(new class Gtk::Label("Gesamtlast:"));
   Gtk::Label *label630 = manage(new class Gtk::Label("Normallast:"));
   Gtk::Label *label = manage(new class Gtk::Label("Höchstlast:"));
   Gtk::Label *label632 = manage(new class Gtk::Label("Schublast:"));
   label_normallast = manage(new class Gtk::Label("kg"));
   label_hoechstlast = manage(new class Gtk::Label("kg"));
   label_schublast = manage(new class Gtk::Label("kg"));
   
   Gtk::HSeparator *hseparator22 = manage(new class Gtk::HSeparator());
   Gtk::Table *table178 = manage(new class Gtk::Table(5, 2, false));
   Gtk::Frame *frame117 = manage(new class Gtk::Frame("Belastbarkeit"));
   Gtk::Table *table93 = manage(new class Gtk::Table(3, 3, false));
   preise_tree_neu = new class SimpleTree(9, 9);
   
   Gtk::ScrolledWindow *scrolledwindow66 = manage(new class Gtk::ScrolledWindow());
   Gtk::Pixmap *pixmap83 = manage(new class Gtk::Pixmap(Money_50_xpm));
   Gtk::Label *label526 = manage(new class Gtk::Label("Mit Geld\n"
		"ausrüsten"));
   Gtk::HBox *hbox46 = manage(new class Gtk::HBox(false, 0));
   checkbutton_ausruestung_geld = manage(new class Gtk::CheckButton());
   label_golda = manage(new class Gtk::Label("0"));
   
   Gtk::Frame *frame81 = manage(new class Gtk::Frame("Gold"));
   label_silbera = manage(new class Gtk::Label("0"));
   
   Gtk::Frame *frame82 = manage(new class Gtk::Frame("Silber"));
   label_kupfera = manage(new class Gtk::Label("0"));
   
   Gtk::Frame *frame83 = manage(new class Gtk::Frame("Kupfer"));
   Gtk::Pixmap *pixmap177 = manage(new class Gtk::Pixmap(Angeb_Sicht_32_xpm));
   Gtk::Label *label637 = manage(new class Gtk::Label("Unverkäufliches\n"
		"anzeigen"));
   Gtk::HBox *hbox96 = manage(new class Gtk::HBox(false, 0));
   togglebutton_unverkauflich = manage(new class Gtk::ToggleButton());
   
   Gtk::Table *table92 = manage(new class Gtk::Table(3, 3, true));
   Gtk::Table *table94 = manage(new class Gtk::Table(3, 2, false));
   Gtk::VPaned *vpaned11 = manage(new class Gtk::VPaned());
   
   toolbar39->tools().push_back(Gtk::Toolbar_Helpers::ButtonElem("Drucken", *manage(new Gtk::Pixmap(PrintChar_trans_50_xpm)), 0));
   Gtk::Button *button_ausruestung_druck = static_cast<Gtk::Button *>(toolbar39->tools().back()->get_widget());
   toolbar39->tools().push_back(Gtk::Toolbar_Helpers::Space());
   
   
   toolbar39->tools().push_back(Gtk::Toolbar_Helpers::ToggleElem("Neue Art", *manage(new Gtk::Pixmap(New_Art_50_xpm)), 0));
   togglebutton_gruppe_neu = static_cast<Gtk::ToggleButton *>(toolbar39->tools().back()->get_widget());
   
   toolbar39->tools().push_back(Gtk::Toolbar_Helpers::ToggleElem("Neuer Artikel", *manage(new Gtk::Pixmap(New_Art_50_xpm)), 0));
   togglebutton_artikel_neu = static_cast<Gtk::ToggleButton *>(toolbar39->tools().back()->get_widget());
   _tooltips.set_tip(*button_ausruestung_druck, "Linker Mausknopf: Alles drucken. Rechter Mausknopf: Nur sichtbares drucken.", "");
   togglebutton_gruppe_neu->set_active(false);
   togglebutton_artikel_neu->set_active(false);
   toolbar39->set_space_size(5);
   toolbar39->set_tooltips(true);
   toolbar39->set_space_style(GTK_TOOLBAR_SPACE_EMPTY);
   label503->set_alignment(0,0.5);
   label503->set_padding(0,0);
   label503->set_justify(GTK_JUSTIFY_CENTER);
   label503->set_line_wrap(false);
   label504->set_alignment(0,0.5);
   label504->set_padding(0,0);
   label504->set_justify(GTK_JUSTIFY_CENTER);
   label504->set_line_wrap(false);
   entry_art->set_flags(GTK_CAN_FOCUS);
   entry_art->set_visibility(true);
   entry_art->set_editable(true);
   entry_art->set_text("");
   entry_art2->set_flags(GTK_CAN_FOCUS);
   entry_art2->set_visibility(true);
   entry_art2->set_editable(true);
   entry_art2->set_text("");
   pixmap189->set_alignment(0.5,0.5);
   pixmap189->set_padding(0,0);
   label651->set_alignment(0.5,0.5);
   label651->set_padding(0,0);
   label651->set_justify(GTK_JUSTIFY_CENTER);
   label651->set_line_wrap(false);
   hbox103->pack_start(*pixmap189);
   hbox103->pack_start(*label651, false, false, 0);
   button_art_speichern->set_flags(GTK_CAN_FOCUS);
   button_art_speichern->set_relief(GTK_RELIEF_NORMAL);
   button_art_speichern->add(*hbox103);
   table_gruppe->set_row_spacings(0);
   table_gruppe->set_col_spacings(0);
   table_gruppe->attach(*label503, 0, 1, 0, 1, GTK_FILL, 0, 0, 0);
   table_gruppe->attach(*label504, 1, 2, 0, 1, GTK_FILL, 0, 0, 0);
   table_gruppe->attach(*entry_art, 0, 1, 1, 2, GTK_FILL, 0, 0, 0);
   table_gruppe->attach(*entry_art2, 1, 2, 1, 2, GTK_FILL, 0, 0, 0);
   table_gruppe->attach(*button_art_speichern, 2, 3, 0, 2, GTK_SHRINK, GTK_SHRINK, 0, 0);
   label506->set_alignment(0,0.5);
   label506->set_padding(0,0);
   label506->set_justify(GTK_JUSTIFY_CENTER);
   label506->set_line_wrap(false);
   label507->set_alignment(0,0.5);
   label507->set_padding(0,0);
   label507->set_justify(GTK_JUSTIFY_CENTER);
   label507->set_line_wrap(false);
   label508->set_alignment(0,0.5);
   label508->set_padding(0,0);
   label508->set_justify(GTK_JUSTIFY_CENTER);
   label508->set_line_wrap(false);
   label511->set_alignment(0,0.5);
   label511->set_padding(0,0);
   label511->set_justify(GTK_JUSTIFY_CENTER);
   label511->set_line_wrap(false);
   label527->set_alignment(0,0.5);
   label527->set_padding(0,0);
   label527->set_justify(GTK_JUSTIFY_CENTER);
   label527->set_line_wrap(false);
   entry_name->set_flags(GTK_CAN_FOCUS);
   entry_name->set_visibility(true);
   entry_name->set_editable(true);
   entry_name->set_text("");
   label509->set_alignment(0,0.5);
   label509->set_padding(0,0);
   label509->set_justify(GTK_JUSTIFY_CENTER);
   label509->set_line_wrap(false);
   label649->set_alignment(0,0.5);
   label649->set_padding(0,0);
   label649->set_justify(GTK_JUSTIFY_CENTER);
   label649->set_line_wrap(false);
   combo_region->get_entry()->set_flags(GTK_CAN_FOCUS);
   combo_region->get_entry()->set_visibility(true);
   combo_region->get_entry()->set_editable(false);
   combo_region->get_entry()->set_text("Eigene Erweiterung");
   combo_region->set_usize(115,-1);
   combo_region->set_sensitive(false);
   combo_region->get_entry()->set_usize(115,-1);
   combo_region->set_case_sensitive(false);
   combo_region->set_use_arrows(true);
   combo_region->set_use_arrows_always(false);
   {  
      
      const char * const items[] = { "Eigene Erweiterung", 0 };
      combo_region->set_popdown_strings(items);
   }
   combo_region->get_entry()->set_text("Eigene Erweiterung");
   combo_einheit->get_entry()->set_flags(GTK_CAN_FOCUS);
   combo_einheit->get_entry()->set_visibility(true);
   combo_einheit->get_entry()->set_editable(false);
   combo_einheit->get_entry()->set_text("GS");
   combo_einheit->set_usize(50,-1);
   combo_einheit->get_entry()->set_usize(50,-1);
   combo_einheit->set_case_sensitive(false);
   combo_einheit->set_use_arrows(true);
   combo_einheit->set_use_arrows_always(false);
   {  
      
      const char * const items[] = { "GS", "SS", "KS", 0 };
      combo_einheit->set_popdown_strings(items);
   }
   combo_einheit->get_entry()->set_text("GS");
   spinbutton_preis->set_flags(GTK_CAN_FOCUS);
   spinbutton_preis->set_update_policy(GTK_UPDATE_ALWAYS);
   spinbutton_preis->set_numeric(false);
   spinbutton_preis->set_digits(1);
   spinbutton_preis->set_wrap(false);
   spinbutton_preis->set_snap_to_ticks(false);
   spinbutton_gewicht->set_flags(GTK_CAN_FOCUS);
   spinbutton_gewicht->set_update_policy(GTK_UPDATE_ALWAYS);
   spinbutton_gewicht->set_numeric(false);
   spinbutton_gewicht->set_digits(2);
   spinbutton_gewicht->set_wrap(false);
   spinbutton_gewicht->set_snap_to_ticks(false);
   pixmap188->set_alignment(0.5,0.5);
   pixmap188->set_padding(0,0);
   label650->set_alignment(0.5,0.5);
   label650->set_padding(0,0);
   label650->set_justify(GTK_JUSTIFY_CENTER);
   label650->set_line_wrap(false);
   hbox102->pack_start(*pixmap188);
   hbox102->pack_start(*label650, false, false, 0);
   button_artikel_speichern->set_flags(GTK_CAN_FOCUS);
   button_artikel_speichern->set_relief(GTK_RELIEF_NORMAL);
   button_artikel_speichern->add(*hbox102);
   combo_art->get_entry()->set_flags(GTK_CAN_FOCUS);
   combo_art->get_entry()->set_visibility(true);
   combo_art->get_entry()->set_editable(false);
   combo_art->get_entry()->set_text("");
   combo_art->set_case_sensitive(false);
   combo_art->set_use_arrows(true);
   combo_art->set_use_arrows_always(false);
   {  
      
      const char * const items[] = { "", 0 };
      combo_art->set_popdown_strings(items);
   }
   combo_art->get_entry()->set_text("");
   combo_art2->get_entry()->set_flags(GTK_CAN_FOCUS);
   combo_art2->get_entry()->set_visibility(true);
   combo_art2->get_entry()->set_editable(false);
   combo_art2->get_entry()->set_text("");
   combo_art2->set_case_sensitive(false);
   combo_art2->set_use_arrows(true);
   combo_art2->set_use_arrows_always(false);
   {  
      
      const char * const items[] = { "", 0 };
      combo_art2->set_popdown_strings(items);
   }
   combo_art2->get_entry()->set_text("");
   table_artikel->set_row_spacings(0);
   table_artikel->set_col_spacings(0);
   table_artikel->attach(*label506, 2, 3, 0, 1, GTK_FILL, 0, 0, 0);
   table_artikel->attach(*label507, 4, 5, 0, 1, GTK_FILL, 0, 0, 0);
   table_artikel->attach(*label508, 5, 6, 0, 1, GTK_FILL, 0, 0, 0);
   table_artikel->attach(*label511, 0, 1, 0, 1, GTK_FILL, 0, 0, 0);
   table_artikel->attach(*label527, 1, 2, 0, 1, GTK_FILL, 0, 0, 0);
   table_artikel->attach(*entry_name, 2, 3, 1, 2, GTK_FILL, 0, 0, 0);
   table_artikel->attach(*label509, 3, 4, 0, 1, GTK_FILL, 0, 0, 0);
   table_artikel->attach(*label649, 6, 7, 0, 1, GTK_FILL, 0, 0, 0);
   table_artikel->attach(*combo_region, 6, 7, 1, 2, GTK_SHRINK, GTK_SHRINK, 0, 0);
   table_artikel->attach(*combo_einheit, 5, 6, 1, 2, GTK_SHRINK, GTK_SHRINK, 0, 0);
   table_artikel->attach(*spinbutton_preis, 4, 5, 1, 2, GTK_SHRINK, GTK_SHRINK, 0, 0);
   table_artikel->attach(*spinbutton_gewicht, 3, 4, 1, 2, GTK_SHRINK, GTK_SHRINK, 0, 0);
   table_artikel->attach(*button_artikel_speichern, 7, 8, 0, 2, GTK_EXPAND|GTK_SHRINK, GTK_SHRINK|GTK_FILL, 0, 0);
   table_artikel->attach(*combo_art, 0, 1, 1, 2, GTK_EXPAND|GTK_FILL, 0, 0, 0);
   table_artikel->attach(*combo_art2, 1, 2, 1, 2, GTK_EXPAND|GTK_FILL, 0, 0, 0);
   table81->set_row_spacings(0);
   table81->set_col_spacings(0);
   table81->attach(*toolbar39, 0, 1, 0, 1, GTK_SHRINK|GTK_FILL, GTK_SHRINK, 5, 5);
   table81->attach(*table_gruppe, 0, 1, 1, 2, GTK_FILL, GTK_EXPAND|GTK_SHRINK|GTK_FILL, 0, 0);
   table81->attach(*table_artikel, 0, 1, 2, 3, GTK_SHRINK, GTK_SHRINK, 0, 0);
   handlebox7->set_shadow_type(GTK_SHADOW_NONE);
   handlebox7->set_handle_position(GTK_POS_LEFT);
   handlebox7->set_snap_edge(GTK_POS_TOP);
   handlebox7->add(*table81);
   pixmap69->set_alignment(0.5,0.5);
   pixmap69->set_padding(0,0);
   label475->set_alignment(0.5,0.5);
   label475->set_padding(0,0);
   label475->set_justify(GTK_JUSTIFY_CENTER);
   label475->set_line_wrap(false);
   hbox35->pack_start(*pixmap69);
   hbox35->pack_start(*label475, false, false, 0);
   button_ausruestung_loeschen->set_flags(GTK_CAN_FOCUS);
   button_ausruestung_loeschen->set_relief(GTK_RELIEF_NORMAL);
   button_ausruestung_loeschen->add(*hbox35);
   pixmap89->set_alignment(0.5,0.5);
   pixmap89->set_padding(0,0);
   checkbutton_sichtbar->set_flags(GTK_CAN_FOCUS);
   checkbutton_sichtbar->set_mode(false);
   checkbutton_sichtbar->set_active(false);
   checkbutton_sichtbar->add(*pixmap89);
   table105->set_row_spacings(0);
   table105->set_col_spacings(0);
   table105->attach(*button_ausruestung_loeschen, 0, 1, 2, 3, GTK_SHRINK|GTK_FILL, GTK_SHRINK, 0, 0);
   table105->attach(*checkbutton_sichtbar, 0, 1, 0, 1, GTK_SHRINK|GTK_FILL, GTK_SHRINK, 0, 0);
   label623->set_alignment(0,7.45058e-09);
   label623->set_padding(0,0);
   label623->set_justify(GTK_JUSTIFY_LEFT);
   label623->set_line_wrap(false);
   scrolledwindow_ausruestung->set_policy(GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
   label_gesamtlast->set_alignment(0,0.5);
   label_gesamtlast->set_padding(0,0);
   label_gesamtlast->set_justify(GTK_JUSTIFY_CENTER);
   label_gesamtlast->set_line_wrap(false);
   label629->set_alignment(0,0.5);
   label629->set_padding(2,0);
   label629->set_justify(GTK_JUSTIFY_CENTER);
   label629->set_line_wrap(false);
   label630->set_alignment(0,0.5);
   label630->set_padding(2,0);
   label630->set_justify(GTK_JUSTIFY_CENTER);
   label630->set_line_wrap(false);
   label->set_alignment(0,0.5);
   label->set_padding(2,0);
   label->set_justify(GTK_JUSTIFY_CENTER);
   label->set_line_wrap(false);
   label632->set_alignment(0,0.5);
   label632->set_padding(2,0);
   label632->set_justify(GTK_JUSTIFY_CENTER);
   label632->set_line_wrap(false);
   label_normallast->set_alignment(1,0.5);
   label_normallast->set_padding(0,0);
   label_normallast->set_justify(GTK_JUSTIFY_CENTER);
   label_normallast->set_line_wrap(false);
   label_hoechstlast->set_alignment(1,0.5);
   label_hoechstlast->set_padding(0,0);
   label_hoechstlast->set_justify(GTK_JUSTIFY_CENTER);
   label_hoechstlast->set_line_wrap(false);
   label_schublast->set_alignment(1,0.5);
   label_schublast->set_padding(0,0);
   label_schublast->set_justify(GTK_JUSTIFY_CENTER);
   label_schublast->set_line_wrap(false);
   table178->set_row_spacings(0);
   table178->set_col_spacings(2);
   table178->attach(*label_gesamtlast, 1, 2, 4, 5, GTK_FILL, 0, 0, 0);
   table178->attach(*label629, 0, 1, 4, 5, GTK_FILL, 0, 0, 0);
   table178->attach(*label630, 0, 1, 0, 1, GTK_FILL, 0, 0, 0);
   table178->attach(*label, 0, 1, 1, 2, GTK_FILL, 0, 0, 0);
   table178->attach(*label632, 0, 1, 2, 3, GTK_FILL, 0, 0, 0);
   table178->attach(*label_normallast, 1, 2, 0, 1, GTK_FILL, 0, 0, 0);
   table178->attach(*label_hoechstlast, 1, 2, 1, 2, GTK_FILL, 0, 0, 0);
   table178->attach(*label_schublast, 1, 2, 2, 3, GTK_FILL, 0, 0, 0);
   table178->attach(*hseparator22, 0, 2, 3, 4, GTK_FILL, GTK_EXPAND|GTK_FILL, 0, 0);
   frame117->set_shadow_type(GTK_SHADOW_ETCHED_IN);
   frame117->set_label_align(0,0);
   frame117->add(*table178);
   table93->set_row_spacings(0);
   table93->set_col_spacings(0);
   table93->attach(*table105, 1, 2, 0, 1, GTK_FILL, 0, 0, 0);
   table93->attach(*label623, 1, 3, 1, 2, GTK_SHRINK|GTK_FILL, GTK_EXPAND|GTK_SHRINK|GTK_FILL, 0, 0);
   table93->attach(*scrolledwindow_ausruestung, 0, 1, 0, 3, GTK_EXPAND|GTK_SHRINK|GTK_FILL, GTK_EXPAND|GTK_SHRINK|GTK_FILL, 0, 0);
   table93->attach(*frame117, 1, 2, 2, 3, GTK_SHRINK, GTK_SHRINK, 0, 0);
   scrolledwindow66->set_policy(GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
   scrolledwindow66->add(*preise_tree_neu);
   pixmap83->set_alignment(0.5,0.5);
   pixmap83->set_padding(0,0);
   label526->set_alignment(0.5,0.5);
   label526->set_padding(0,0);
   label526->set_justify(GTK_JUSTIFY_CENTER);
   label526->set_line_wrap(false);
   hbox46->pack_start(*pixmap83, false, false, 0);
   hbox46->pack_start(*label526, false, false, 0);
   checkbutton_ausruestung_geld->set_flags(GTK_CAN_FOCUS);
   checkbutton_ausruestung_geld->set_mode(false);
   checkbutton_ausruestung_geld->set_active(true);
   checkbutton_ausruestung_geld->add(*hbox46);
   label_golda->set_alignment(0.5,0.5);
   label_golda->set_padding(0,0);
   label_golda->set_justify(GTK_JUSTIFY_CENTER);
   label_golda->set_line_wrap(false);
   frame81->set_shadow_type(GTK_SHADOW_ETCHED_IN);
   frame81->set_label_align(0,0);
   frame81->add(*label_golda);
   label_silbera->set_alignment(0.5,0.5);
   label_silbera->set_padding(0,0);
   label_silbera->set_justify(GTK_JUSTIFY_CENTER);
   label_silbera->set_line_wrap(false);
   frame82->set_shadow_type(GTK_SHADOW_ETCHED_IN);
   frame82->set_label_align(0,0);
   frame82->add(*label_silbera);
   label_kupfera->set_alignment(0.5,0.5);
   label_kupfera->set_padding(0,0);
   label_kupfera->set_justify(GTK_JUSTIFY_CENTER);
   label_kupfera->set_line_wrap(false);
   frame83->set_shadow_type(GTK_SHADOW_ETCHED_IN);
   frame83->set_label_align(0,0);
   frame83->add(*label_kupfera);
   pixmap177->set_alignment(0.5,0.5);
   pixmap177->set_padding(0,0);
   label637->set_alignment(0.5,0.5);
   label637->set_padding(0,0);
   label637->set_justify(GTK_JUSTIFY_CENTER);
   label637->set_line_wrap(false);
   hbox96->pack_start(*pixmap177);
   hbox96->pack_start(*label637, false, false, 0);
   togglebutton_unverkauflich->set_flags(GTK_CAN_FOCUS);
   togglebutton_unverkauflich->set_relief(GTK_RELIEF_NORMAL);
   togglebutton_unverkauflich->set_active(false);
   togglebutton_unverkauflich->add(*hbox96);
   table92->set_row_spacings(0);
   table92->set_col_spacings(0);
   table92->attach(*checkbutton_ausruestung_geld, 0, 3, 0, 1, GTK_FILL, 0, 0, 0);
   table92->attach(*frame81, 0, 1, 2, 3, GTK_EXPAND|GTK_SHRINK|GTK_FILL, GTK_EXPAND|GTK_SHRINK|GTK_FILL, 0, 0);
   table92->attach(*frame82, 1, 2, 2, 3, GTK_EXPAND|GTK_SHRINK|GTK_FILL, GTK_SHRINK|GTK_FILL, 0, 0);
   table92->attach(*frame83, 2, 3, 2, 3, GTK_EXPAND|GTK_SHRINK|GTK_FILL, GTK_SHRINK|GTK_FILL, 0, 0);
   table92->attach(*togglebutton_unverkauflich, 0, 3, 1, 2, GTK_FILL, 0, 0, 0);
   table94->set_row_spacings(0);
   table94->set_col_spacings(0);
   table94->attach(*scrolledwindow66, 0, 1, 0, 3, GTK_EXPAND|GTK_SHRINK|GTK_FILL, GTK_EXPAND|GTK_SHRINK|GTK_FILL, 0, 0);
   table94->attach(*table92, 1, 2, 0, 1, GTK_SHRINK, GTK_SHRINK, 0, 0);
   vpaned11->set_handle_size(10);
   vpaned11->set_gutter_size(10);
   vpaned11->set_position(264);
   vpaned11->pack1(*table93, false, true);
   vpaned11->pack2(*table94, true, true);
   table_ausruestung->set_row_spacings(0);
   table_ausruestung->set_col_spacings(0);
   table_ausruestung->attach(*handlebox7, 0, 2, 0, 1, GTK_SHRINK|GTK_FILL, GTK_SHRINK|GTK_FILL, 0, 0);
   table_ausruestung->attach(*vpaned11, 0, 2, 1, 2, GTK_EXPAND|GTK_SHRINK|GTK_FILL, GTK_EXPAND|GTK_SHRINK|GTK_FILL, 0, 0);
   toolbar39->show();
   label503->show();
   label504->show();
   entry_art->show();
   entry_art2->show();
   pixmap189->show();
   label651->show();
   hbox103->show();
   button_art_speichern->show();
   table_gruppe->show();
   label506->show();
   label507->show();
   label508->show();
   label511->show();
   label527->show();
   entry_name->show();
   label509->show();
   label649->show();
   combo_region->show();
   combo_einheit->show();
   spinbutton_preis->show();
   spinbutton_gewicht->show();
   pixmap188->show();
   label650->show();
   hbox102->show();
   button_artikel_speichern->show();
   combo_art->show();
   combo_art2->show();
   table_artikel->show();
   table81->show();
   handlebox7->show();
   pixmap69->show();
   label475->show();
   hbox35->show();
   button_ausruestung_loeschen->show();
   pixmap89->show();
   checkbutton_sichtbar->show();
   table105->show();
   label623->show();
   scrolledwindow_ausruestung->show();
   label_gesamtlast->show();
   label629->show();
   label630->show();
   label->show();
   label632->show();
   label_normallast->show();
   label_hoechstlast->show();
   label_schublast->show();
   hseparator22->show();
   table178->show();
   frame117->show();
   table93->show();
   preise_tree_neu->show();
   scrolledwindow66->show();
   pixmap83->show();
   label526->show();
   hbox46->show();
   checkbutton_ausruestung_geld->show();
   label_golda->show();
   frame81->show();
   label_silbera->show();
   frame82->show();
   label_kupfera->show();
   frame83->show();
   pixmap177->show();
   label637->show();
   hbox96->show();
   togglebutton_unverkauflich->show();
   table92->show();
   table94->show();
   vpaned11->show();
   table_ausruestung->show();
   button_ausruestung_druck->button_release_event.connect(SigC::slot(this, &table_ausruestung_glade::on_button_ausruestung_druck_release_event));
   togglebutton_gruppe_neu->toggled.connect(SigC::slot(this, &table_ausruestung_glade::on_togglebutton_gruppe_neu_toggled));
   togglebutton_artikel_neu->toggled.connect(SigC::slot(this, &table_ausruestung_glade::on_togglebutton_artikel_neu_toggled));
   entry_art->activate.connect(SigC::slot(this, &table_ausruestung_glade::on_entry_art_activate));
   entry_art2->activate.connect(SigC::slot(this, &table_ausruestung_glade::on_entry_art2_activate));
   button_art_speichern->clicked.connect(SigC::slot(this, &table_ausruestung_glade::on_button_art_speichern_clicked));
   entry_name->activate.connect(SigC::slot(this, &table_ausruestung_glade::on_entry_name_activate));
   combo_region->get_entry()->activate.connect(SigC::slot(this, &table_ausruestung_glade::on_combo_entry_region_activate));
   combo_einheit->get_entry()->activate.connect(SigC::slot(this, &table_ausruestung_glade::on_combo_entry_einheit_activate));
   combo_einheit->get_entry()->changed.connect(SigC::slot(this, &table_ausruestung_glade::on_combo_entry_einheit_changed));
   spinbutton_preis->activate.connect(SigC::slot(this, &table_ausruestung_glade::on_spinbutton_preis_activate));
   spinbutton_gewicht->activate.connect(SigC::slot(this, &table_ausruestung_glade::on_spinbutton_gewicht_activate));
   button_artikel_speichern->clicked.connect(SigC::slot(this, &table_ausruestung_glade::on_button_artikel_speichern_clicked));
   combo_art->get_entry()->activate.connect(SigC::slot(this, &table_ausruestung_glade::on_combo_entry_artikel_art_activate));
   combo_art->get_entry()->focus_out_event.connect(SigC::slot(this, &table_ausruestung_glade::on_combo_entry_artikel_art_focus_out_event));
   combo_art->get_entry()->changed.connect(SigC::slot(this, &table_ausruestung_glade::on_combo_entry_artikel_art_changed));
   combo_art2->get_entry()->activate.connect(SigC::slot(this, &table_ausruestung_glade::on_combo_entry_art2_activate));
   combo_art2->get_entry()->focus_out_event.connect(SigC::slot(this, &table_ausruestung_glade::on_combo_entry_art2_focus_out_event));
   combo_art2->get_entry()->changed.connect(SigC::slot(this, &table_ausruestung_glade::on_combo_entry_art2_changed));
   button_ausruestung_loeschen->clicked.connect(SigC::slot(this, &table_ausruestung_glade::on_ausruestung_loeschen_clicked));
   preise_tree_neu->leaf_selected.connect(SigC::slot(this, &table_ausruestung_glade::on_preise_tree_neu_leaf_selected));
   preise_tree_neu->drag_data_get.connect(SigC::slot(this, &table_ausruestung_glade::on_preise_tree_neu_drag_data_get));
   checkbutton_ausruestung_geld->toggled.connect(SigC::slot(this, &table_ausruestung_glade::on_checkbutton_ausruestung_geld_toggled));
   togglebutton_unverkauflich->toggled.connect(SigC::slot(this, &table_ausruestung_glade::on_togglebutton_unverkauflich_toggled));
}

table_ausruestung_glade::~table_ausruestung_glade()
{  delete preise_tree_neu;
}
