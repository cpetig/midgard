// generated 2002/9/13 14:06:30 CEST by thoma@Tiger.(none)
// using glademm V1.1.1c_cvs
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- /home/thoma/rollenspiel/midgard/programme/gcc_3.0/midgard/midgard.glade
// for gtk 1.2.10 and gtkmm 1.2.10
//
// Please modify the corresponding derived classes in ./src/table_ausruestung.cc

#include "config.h"
#include "table_ausruestung.hh"
#include <gtk--/button.h>
#include <gtk--/pixmap.h>
#include "../pixmaps/PrintChar-trans-50.xpm"
#include "../pixmaps/pinguin.xpm"
#include <gtk--/toolbar.h>
#include <gtk--/label.h>
#include <gtk--/adjustment.h>
#include <gtk--/menu.h>
#include <gtk--/menuitem.h>
#include <gtk--/table.h>
#include <gtk--/handlebox.h>
#include <gtk--/scrolledwindow.h>
#include <gtk--/viewport.h>
#include <gtk--/paned.h>
#include "../pixmaps/Money-50.xpm"
#include <gtk--/box.h>
#include <gtk--/frame.h>
#include "../pixmaps/Job-trans-50.xpm"
#include "../pixmaps/Weapon-trans-50.xpm"
#include "../pixmaps/sichtbar.xpm"
#include "../pixmaps/Erase-50.xpm"

table_ausruestung_glade::table_ausruestung_glade(GlademmData *_data
) : Gtk::Table(2, 2, false)
{  table_ausruestung = this;
   
   Gtk::Toolbar *toolbar39 = manage(new class Gtk::Toolbar(GTK_ORIENTATION_HORIZONTAL, GTK_TOOLBAR_BOTH));
   Gtk::Label *label503 = manage(new class Gtk::Label("Art"));
   Gtk::Label *label504 = manage(new class Gtk::Label("Typ"));
   Gtk::Label *label505 = manage(new class Gtk::Label("Eigenschaft"));
   entry_art = manage(new class Gtk::Entry());
   entry_typ = manage(new class Gtk::Entry());
   entry_eigenschaft = manage(new class Gtk::Entry());
   table_gruppe = manage(new class Gtk::Table(2, 3, false));
   
   Gtk::Label *label506 = manage(new class Gtk::Label("Name"));
   Gtk::Label *label507 = manage(new class Gtk::Label("Preis"));
   Gtk::Label *label508 = manage(new class Gtk::Label("Einheit"));
   Gtk::Label *label509 = manage(new class Gtk::Label("Gewicht (kg)"));
   Gtk::Adjustment *spinbutton_preis_adj = manage(new class Gtk::Adjustment(1, 0, 1000, 1, 10, 10));
   spinbutton_preis = manage(new class Gtk::SpinButton(*spinbutton_preis_adj, 1, 1));
   
   Gtk::Adjustment *spinbutton_gewicht_adj = manage(new class Gtk::Adjustment(1, 0, 100, 1, 10, 10));
   spinbutton_gewicht = manage(new class Gtk::SpinButton(*spinbutton_gewicht_adj, 1, 2));
   optionmenu_einheit = manage(new class Gtk::OptionMenu());
   
   Gtk::Label *label511 = manage(new class Gtk::Label("Art"));
   Gtk::Label *label527 = manage(new class Gtk::Label("Art2"));
   entry_name = manage(new class Gtk::Entry());
   entry_artikel_art2 = manage(new class Gtk::Entry());
   entry_artikel_art = manage(new class Gtk::Entry());
   table_artikel = manage(new class Gtk::Table(2, 6, false));
   
   Gtk::Table *table81 = manage(new class Gtk::Table(3, 1, false));
   Gtk::HandleBox *handlebox7 = manage(new class Gtk::HandleBox());
   viewport_modi = manage(new class Gtk::Viewport());
   
   Gtk::ScrolledWindow *scrolledwindow64 = manage(new class Gtk::ScrolledWindow());
   preise_tree = new class SimpleTree(5);
   
   Gtk::Viewport *viewport26 = manage(new class Gtk::Viewport());
   Gtk::ScrolledWindow *scrolledwindow65 = manage(new class Gtk::ScrolledWindow());
   clist_preisliste = manage(new class Gtk::CList(4));
   
   Gtk::Viewport *viewport22 = manage(new class Gtk::Viewport());
   Gtk::ScrolledWindow *scrolledwindow58 = manage(new class Gtk::ScrolledWindow());
   Gtk::HPaned *hpaned4 = manage(new class Gtk::HPaned());
   Gtk::Pixmap *pixmap83 = manage(new class Gtk::Pixmap(Money_50_xpm));
   Gtk::Label *label526 = manage(new class Gtk::Label("Mit Geld ausr�sten"));
   Gtk::HBox *hbox46 = manage(new class Gtk::HBox(false, 0));
   checkbutton_ausruestung_geld = manage(new class Gtk::CheckButton());
   label_golda = manage(new class Gtk::Label("0"));
   
   Gtk::Frame *frame81 = manage(new class Gtk::Frame("Gold"));
   label_silbera = manage(new class Gtk::Label("0"));
   
   Gtk::Frame *frame82 = manage(new class Gtk::Frame("Silber"));
   label_kupfera = manage(new class Gtk::Label("0"));
   
   Gtk::Frame *frame83 = manage(new class Gtk::Frame("Kupfer"));
   Gtk::Table *table92 = manage(new class Gtk::Table(2, 3, true));
   Gtk::Label *label474 = manage(new class Gtk::Label("Modifikatoren entfernen"));
   Gtk::Pixmap *pixmap67 = manage(new class Gtk::Pixmap(Job_trans_50_xpm));
   Gtk::Pixmap *pixmap68 = manage(new class Gtk::Pixmap(Weapon_trans_50_xpm));
   Gtk::Table *table90 = manage(new class Gtk::Table(2, 2, false));
   Gtk::Button *button_modi = manage(new class Gtk::Button());
   Gtk::Table *table93 = manage(new class Gtk::Table(2, 4, false));
   viewport_ausruestung = manage(new class Gtk::Viewport());
   
   Gtk::ScrolledWindow *scrolledwindow66 = manage(new class Gtk::ScrolledWindow());
   Gtk::Pixmap *pixmap89 = manage(new class Gtk::Pixmap(sichtbar_xpm));
   checkbutton_sichtbar = manage(new class Gtk::CheckButton());
   
   Gtk::Pixmap *pixmap69 = manage(new class Gtk::Pixmap(Erase_50_xpm));
   Gtk::Label *label475 = manage(new class Gtk::Label("L�schen"));
   Gtk::HBox *hbox35 = manage(new class Gtk::HBox(false, 0));
   button_ausruestung_loeschen = manage(new class Gtk::Button());
   
   Gtk::Table *table105 = manage(new class Gtk::Table(2, 1, false));
   Gtk::Table *table94 = manage(new class Gtk::Table(3, 2, false));
   Gtk::VPaned *vpaned11 = manage(new class Gtk::VPaned());
   
   toolbar39->tools().push_back(Gtk::Toolbar_Helpers::ButtonElem("Drucken", *manage(new Gtk::Pixmap(PrintChar_trans_50_xpm)), 0));
   Gtk::Button *button_ausruestung_druck = static_cast<Gtk::Button *>(toolbar39->tools().back()->get_widget());
   toolbar39->tools().push_back(Gtk::Toolbar_Helpers::Space());
   
   
   toolbar39->tools().push_back(Gtk::Toolbar_Helpers::ToggleElem("Neue Gruppe", *manage(new Gtk::Pixmap(pinguin_xpm)), 0));
   togglebutton_gruppe_neu = static_cast<Gtk::ToggleButton *>(toolbar39->tools().back()->get_widget());
   
   toolbar39->tools().push_back(Gtk::Toolbar_Helpers::ToggleElem("Neuer Artikel", *manage(new Gtk::Pixmap(pinguin_xpm)), 0));
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
   label505->set_alignment(0,0.5);
   label505->set_padding(0,0);
   label505->set_justify(GTK_JUSTIFY_CENTER);
   label505->set_line_wrap(false);
   entry_art->set_flags(GTK_CAN_FOCUS);
   entry_art->set_visibility(true);
   entry_art->set_editable(true);
   entry_art->set_text("");
   entry_typ->set_flags(GTK_CAN_FOCUS);
   entry_typ->set_visibility(true);
   entry_typ->set_editable(true);
   entry_typ->set_text("");
   entry_eigenschaft->set_flags(GTK_CAN_FOCUS);
   entry_eigenschaft->set_visibility(true);
   entry_eigenschaft->set_editable(true);
   entry_eigenschaft->set_text("");
   table_gruppe->set_row_spacings(0);
   table_gruppe->set_col_spacings(0);
   table_gruppe->attach(*label503, 0, 1, 0, 1, GTK_FILL, 0, 0, 0);
   table_gruppe->attach(*label504, 1, 2, 0, 1, GTK_FILL, 0, 0, 0);
   table_gruppe->attach(*label505, 2, 3, 0, 1, GTK_FILL, 0, 0, 0);
   table_gruppe->attach(*entry_art, 0, 1, 1, 2, GTK_FILL, 0, 0, 0);
   table_gruppe->attach(*entry_typ, 1, 2, 1, 2, GTK_FILL, 0, 0, 0);
   table_gruppe->attach(*entry_eigenschaft, 2, 3, 1, 2, GTK_FILL, 0, 0, 0);
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
   label509->set_alignment(0,0.5);
   label509->set_padding(0,0);
   label509->set_justify(GTK_JUSTIFY_CENTER);
   label509->set_line_wrap(false);
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
   optionmenu_einheit->set_flags(GTK_CAN_FOCUS);
   {  
      
      Gtk::Menu *_m(manage(new Gtk::Menu()));
      Gtk::MenuItem *_mi;
      _mi = manage(new Gtk::MenuItem("GS"));
      _m->append(*_mi);
      _mi->show();
      _mi->set_user_data((gpointer)0);
      _mi = manage(new Gtk::MenuItem("SS"));
      _m->append(*_mi);
      _mi->show();
      _mi->set_user_data((gpointer)1);
      _mi = manage(new Gtk::MenuItem("KS"));
      _m->append(*_mi);
      _mi->show();
      _mi->set_user_data((gpointer)2);
      optionmenu_einheit->set_menu(*_m);
      optionmenu_einheit->set_history(0);
   }
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
   entry_artikel_art2->set_flags(GTK_CAN_FOCUS);
   entry_artikel_art2->set_visibility(true);
   entry_artikel_art2->set_editable(false);
   entry_artikel_art2->set_text("");
   entry_artikel_art->set_flags(GTK_CAN_FOCUS);
   entry_artikel_art->set_visibility(true);
   entry_artikel_art->set_editable(false);
   entry_artikel_art->set_text("");
   table_artikel->set_row_spacings(0);
   table_artikel->set_col_spacings(0);
   table_artikel->attach(*label506, 2, 3, 0, 1, GTK_FILL, 0, 0, 0);
   table_artikel->attach(*label507, 3, 4, 0, 1, GTK_FILL, 0, 0, 0);
   table_artikel->attach(*label508, 4, 5, 0, 1, GTK_FILL, 0, 0, 0);
   table_artikel->attach(*label509, 5, 6, 0, 1, GTK_FILL, 0, 0, 0);
   table_artikel->attach(*spinbutton_preis, 3, 4, 1, 2, GTK_EXPAND|GTK_SHRINK|GTK_FILL, 0, 0, 0);
   table_artikel->attach(*spinbutton_gewicht, 5, 6, 1, 2, GTK_EXPAND|GTK_SHRINK|GTK_FILL, 0, 0, 0);
   table_artikel->attach(*optionmenu_einheit, 4, 5, 1, 2, GTK_FILL, 0, 0, 0);
   table_artikel->attach(*label511, 0, 1, 0, 1, GTK_FILL, 0, 0, 0);
   table_artikel->attach(*label527, 1, 2, 0, 1, GTK_FILL, 0, 0, 0);
   table_artikel->attach(*entry_name, 2, 3, 1, 2, GTK_FILL, 0, 0, 0);
   table_artikel->attach(*entry_artikel_art2, 1, 2, 1, 2, GTK_FILL, 0, 0, 0);
   table_artikel->attach(*entry_artikel_art, 0, 1, 1, 2, GTK_FILL, 0, 0, 0);
   table81->set_row_spacings(0);
   table81->set_col_spacings(0);
   table81->attach(*toolbar39, 0, 1, 0, 1, GTK_SHRINK|GTK_FILL, GTK_SHRINK, 5, 5);
   table81->attach(*table_gruppe, 0, 1, 1, 2, GTK_FILL, GTK_EXPAND|GTK_SHRINK|GTK_FILL, 0, 0);
   table81->attach(*table_artikel, 0, 1, 2, 3, GTK_FILL, GTK_EXPAND|GTK_SHRINK|GTK_FILL, 0, 0);
   handlebox7->set_shadow_type(GTK_SHADOW_NONE);
   handlebox7->set_handle_position(GTK_POS_LEFT);
   handlebox7->set_snap_edge(GTK_POS_TOP);
   handlebox7->add(*table81);
   viewport_modi->set_shadow_type(GTK_SHADOW_NONE);
   scrolledwindow64->set_policy(GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
   scrolledwindow64->add(*viewport_modi);
   viewport26->set_shadow_type(GTK_SHADOW_NONE);
   viewport26->add(*preise_tree);
   scrolledwindow65->set_policy(GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
   scrolledwindow65->add(*viewport26);
   clist_preisliste->set_flags(GTK_CAN_FOCUS);
   clist_preisliste->set_column_title(0, "Name");
   clist_preisliste->set_column_width(0, 80);
   clist_preisliste->set_column_title(1, "Preis");
   clist_preisliste->set_column_width(1, 80);
   clist_preisliste->set_column_title(2, "Einheit");
   clist_preisliste->set_column_justification(2, GTK_JUSTIFY_RIGHT);
   clist_preisliste->set_column_width(2, 80);
   clist_preisliste->set_column_title(3, "Gewicht (kg)");
   clist_preisliste->set_column_justification(3, GTK_JUSTIFY_RIGHT);
   clist_preisliste->set_column_width(3, 80);
   clist_preisliste->set_selection_mode(GTK_SELECTION_SINGLE);
   clist_preisliste->set_shadow_type(GTK_SHADOW_IN);
   clist_preisliste->column_titles_show();
   viewport22->set_shadow_type(GTK_SHADOW_NONE);
   viewport22->add(*clist_preisliste);
   scrolledwindow58->set_policy(GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
   scrolledwindow58->add(*viewport22);
   hpaned4->set_handle_size(10);
   hpaned4->set_gutter_size(10);
   hpaned4->pack1(*scrolledwindow65, true, true);
   hpaned4->pack2(*scrolledwindow58, true, true);
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
   table92->set_row_spacings(0);
   table92->set_col_spacings(0);
   table92->attach(*checkbutton_ausruestung_geld, 0, 3, 0, 1, GTK_FILL, 0, 0, 0);
   table92->attach(*frame81, 0, 1, 1, 2, GTK_EXPAND|GTK_SHRINK|GTK_FILL, GTK_EXPAND|GTK_SHRINK|GTK_FILL, 0, 0);
   table92->attach(*frame82, 1, 2, 1, 2, GTK_EXPAND|GTK_SHRINK|GTK_FILL, GTK_SHRINK|GTK_FILL, 0, 0);
   table92->attach(*frame83, 2, 3, 1, 2, GTK_EXPAND|GTK_SHRINK|GTK_FILL, GTK_SHRINK|GTK_FILL, 0, 0);
   label474->set_alignment(0,0.5);
   label474->set_padding(0,0);
   label474->set_justify(GTK_JUSTIFY_CENTER);
   label474->set_line_wrap(false);
   pixmap67->set_alignment(0.5,0.5);
   pixmap67->set_padding(0,0);
   pixmap68->set_alignment(0.5,0.5);
   pixmap68->set_padding(0,0);
   table90->set_row_spacings(0);
   table90->set_col_spacings(0);
   table90->attach(*label474, 0, 2, 1, 2, GTK_FILL, 0, 0, 0);
   table90->attach(*pixmap67, 0, 1, 0, 1, GTK_FILL, GTK_EXPAND|GTK_SHRINK|GTK_FILL, 0, 0);
   table90->attach(*pixmap68, 1, 2, 0, 1, GTK_FILL, GTK_FILL, 0, 0);
   button_modi->set_flags(GTK_CAN_FOCUS);
   button_modi->set_border_width(5);
   button_modi->set_relief(GTK_RELIEF_NORMAL);
   button_modi->add(*table90);
   table93->set_row_spacings(0);
   table93->set_col_spacings(0);
   table93->attach(*scrolledwindow64, 0, 1, 1, 2, GTK_SHRINK|GTK_FILL, GTK_SHRINK|GTK_FILL, 0, 0);
   table93->attach(*hpaned4, 0, 4, 0, 1, GTK_EXPAND|GTK_SHRINK|GTK_FILL, GTK_EXPAND|GTK_SHRINK|GTK_FILL, 0, 0);
   table93->attach(*table92, 2, 3, 1, 2, GTK_SHRINK, GTK_SHRINK, 5, 4);
   table93->attach(*button_modi, 1, 2, 1, 2, GTK_SHRINK, GTK_SHRINK, 5, 0);
   viewport_ausruestung->set_shadow_type(GTK_SHADOW_NONE);
   scrolledwindow66->set_policy(GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
   scrolledwindow66->add(*viewport_ausruestung);
   pixmap89->set_alignment(0.5,0.5);
   pixmap89->set_padding(0,0);
   checkbutton_sichtbar->set_flags(GTK_CAN_FOCUS);
   checkbutton_sichtbar->set_mode(false);
   checkbutton_sichtbar->set_active(false);
   checkbutton_sichtbar->add(*pixmap89);
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
   table105->set_row_spacings(0);
   table105->set_col_spacings(0);
   table105->attach(*checkbutton_sichtbar, 0, 1, 0, 1, GTK_SHRINK|GTK_FILL, GTK_SHRINK, 0, 0);
   table105->attach(*button_ausruestung_loeschen, 0, 1, 1, 2, GTK_SHRINK|GTK_FILL, GTK_SHRINK, 0, 0);
   table94->set_row_spacings(0);
   table94->set_col_spacings(0);
   table94->attach(*scrolledwindow66, 0, 1, 0, 3, GTK_EXPAND|GTK_SHRINK|GTK_FILL, GTK_EXPAND|GTK_SHRINK|GTK_FILL, 0, 0);
   table94->attach(*table105, 1, 2, 0, 1, GTK_SHRINK|GTK_FILL, GTK_SHRINK|GTK_FILL, 0, 0);
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
   label505->show();
   entry_art->show();
   entry_typ->show();
   entry_eigenschaft->show();
   table_gruppe->show();
   label506->show();
   label507->show();
   label508->show();
   label509->show();
   spinbutton_preis->show();
   spinbutton_gewicht->show();
   optionmenu_einheit->show();
   label511->show();
   label527->show();
   entry_name->show();
   entry_artikel_art2->show();
   entry_artikel_art->show();
   table_artikel->show();
   table81->show();
   handlebox7->show();
   viewport_modi->show();
   scrolledwindow64->show();
   preise_tree->show();
   viewport26->show();
   scrolledwindow65->show();
   clist_preisliste->show();
   viewport22->show();
   scrolledwindow58->show();
   hpaned4->show();
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
   table92->show();
   label474->show();
   pixmap67->show();
   pixmap68->show();
   table90->show();
   button_modi->show();
   table93->show();
   viewport_ausruestung->show();
   scrolledwindow66->show();
   pixmap89->show();
   checkbutton_sichtbar->show();
   pixmap69->show();
   label475->show();
   hbox35->show();
   button_ausruestung_loeschen->show();
   table105->show();
   table94->show();
   vpaned11->show();
   table_ausruestung->show();
   button_ausruestung_druck->button_release_event.connect(SigC::slot(static_cast<class table_ausruestung*>(this), &table_ausruestung::on_button_ausruestung_druck_release_event));
   togglebutton_gruppe_neu->toggled.connect(SigC::slot(static_cast<class table_ausruestung*>(this), &table_ausruestung::on_togglebutton_gruppe_neu_toggled));
   togglebutton_artikel_neu->toggled.connect(SigC::slot(static_cast<class table_ausruestung*>(this), &table_ausruestung::on_togglebutton_artikel_neu_toggled));
   entry_art->activate.connect(SigC::slot(static_cast<class table_ausruestung*>(this), &table_ausruestung::on_entry_art_activate));
   entry_typ->activate.connect(SigC::slot(static_cast<class table_ausruestung*>(this), &table_ausruestung::on_entry_typ_activate));
   entry_eigenschaft->activate.connect(SigC::slot(static_cast<class table_ausruestung*>(this), &table_ausruestung::on_entry_eigenschaft_activate));
   spinbutton_preis->activate.connect(SigC::slot(static_cast<class table_ausruestung*>(this), &table_ausruestung::on_spinbutton_preis_activate));
   spinbutton_gewicht->activate.connect(SigC::slot(static_cast<class table_ausruestung*>(this), &table_ausruestung::on_spinbutton_gewicht_activate));
   entry_name->activate.connect(SigC::slot(static_cast<class table_ausruestung*>(this), &table_ausruestung::on_entry_name_activate));
   entry_artikel_art2->activate.connect(SigC::slot(static_cast<class table_ausruestung*>(this), &table_ausruestung::on_entry_artikel_art2_activate));
   entry_artikel_art->activate.connect(SigC::slot(static_cast<class table_ausruestung*>(this), &table_ausruestung::on_entry_artikel_art_activate));
   preise_tree->leaf_selected.connect(SigC::slot(static_cast<class table_ausruestung*>(this), &table_ausruestung::on_preise_leaf_selected));
   clist_preisliste->select_row.connect(SigC::slot(static_cast<class table_ausruestung*>(this), &table_ausruestung::on_clist_preisliste_select_row));
   clist_preisliste->drag_data_get.connect(SigC::slot(static_cast<class table_ausruestung*>(this), &table_ausruestung::on_clist_preisliste_drag_data_get));
   checkbutton_ausruestung_geld->toggled.connect(SigC::slot(static_cast<class table_ausruestung*>(this), &table_ausruestung::on_checkbutton_ausruestung_geld_toggled));
   button_modi->clicked.connect(SigC::slot(static_cast<class table_ausruestung*>(this), &table_ausruestung::on_button_modi_clicked));
   button_ausruestung_loeschen->clicked.connect(SigC::slot(static_cast<class table_ausruestung*>(this), &table_ausruestung::on_ausruestung_loeschen_clicked));
}

table_ausruestung_glade::~table_ausruestung_glade()
{  delete preise_tree;
}
