// generated 2002/5/31 15:40:47 CEST by thoma@Tiger.(none)
// using glademm V0.6.4b_cvs
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- /home/thoma/rollenspiel/midgard/programme/gcc_3.0/midgard/midgard.glade
// for gtk 1.2.10 and gtkmm 1.2.8
//
// Please modify the corresponding derived classes in ./src/midgard_CG.cc

#include "config.h"
#include "midgard_CG.hh"
#include <gdk/gdkkeysyms.h>
#include <gtk--/accelgroup.h>
#include <gtk--/button.h>
#include <gtk--/pixmap.h>
#include "../pixmaps/NewChar-trans-50.xpm"
#include "../pixmaps/LoadChar-trans-50.xpm"
#include "../pixmaps/SaveChar-trans-50.xpm"
#include "../pixmaps/PrintChar-trans-50.xpm"
#include "../pixmaps/Undo.xpm"
#include "../pixmaps/redo.xpm"
#include "../pixmaps/wizzard-trans-50_2.xpm"
#include "../pixmaps/Info-trans-50.xpm"
#include "../pixmaps/Help-trans-50.xpm"
#include "../pixmaps/Exit-trans-50.xpm"
#include <gtk--/list.h>
#include <gtk--/menu.h>
#include <gtk--/box.h>
#include "../pixmaps/MAGUS_Logo_Small.xpm"
#include "../pixmaps/midgard_logo_small.xpm"
#include <gtk--/table.h>
#include <gtk--/eventbox.h>
#include <gtk--/frame.h>
#include "../pixmaps/Grundwert_small.xpm"
#include "../pixmaps/L_Schema_small.xpm"
#include "../pixmaps/Steigern_small.xpm"
#include "../pixmaps/Descr.Char-40.xpm"
#include "../pixmaps/Ausruest_small.xpm"
#include "../pixmaps/Regio_Hausregel-50.xpm"
#include <gtk--/label.h>
#include <gtk--/viewport.h>
#include <gtk--/scrolledwindow.h>
#include "../pixmaps/Fert_Lesen-32.xpm"

midgard_CG_glade::midgard_CG_glade(
) : Gtk::Window(GTK_WINDOW_TOPLEVEL)
{  
   
   Gtk::Window *midgard_CG = this;
   Gtk::AccelGroup *midgard_CG_accgrp = Gtk::AccelGroup::create();
   _data = new GlademmData(midgard_CG_accgrp);
   toolbar_top = manage(new class Gtk::Toolbar(GTK_ORIENTATION_HORIZONTAL, GTK_TOOLBAR_BOTH));
   
   Gtk::Button *button_neuer_charakter = Gtk::wrap((GtkButton*)gtk_toolbar_append_element(GTK_TOOLBAR(toolbar_top->gtkobj()), GTK_TOOLBAR_CHILD_BUTTON, 0, "Neu", 0, 0, GTK_WIDGET(manage(new Gtk::Pixmap(NewChar_trans_50_xpm))->gtkobj()), 0, 0));
   Gtk::Button *button9 = Gtk::wrap((GtkButton*)gtk_toolbar_append_element(GTK_TOOLBAR(toolbar_top->gtkobj()), GTK_TOOLBAR_CHILD_BUTTON, 0, "Laden", 0, 0, GTK_WIDGET(manage(new Gtk::Pixmap(LoadChar_trans_50_xpm))->gtkobj()), 0, 0));
   Gtk::Button *button8 = Gtk::wrap((GtkButton*)gtk_toolbar_append_element(GTK_TOOLBAR(toolbar_top->gtkobj()), GTK_TOOLBAR_CHILD_BUTTON, 0, "Speichern", 0, 0, GTK_WIDGET(manage(new Gtk::Pixmap(SaveChar_trans_50_xpm))->gtkobj()), 0, 0));
   Gtk::Button *button10 = Gtk::wrap((GtkButton*)gtk_toolbar_append_element(GTK_TOOLBAR(toolbar_top->gtkobj()), GTK_TOOLBAR_CHILD_BUTTON, 0, "Drucken", 0, 0, GTK_WIDGET(manage(new Gtk::Pixmap(PrintChar_trans_50_xpm))->gtkobj()), 0, 0));
   toolbar_top->tools().push_back(Gtk::Toolbar_Helpers::Space());
   button_undo = Gtk::wrap((GtkButton*)gtk_toolbar_append_element(GTK_TOOLBAR(toolbar_top->gtkobj()), GTK_TOOLBAR_CHILD_BUTTON, 0, "Zur�ck", 0, 0, GTK_WIDGET(manage(new Gtk::Pixmap(Undo_xpm))->gtkobj()), 0, 0));
   button_redo = Gtk::wrap((GtkButton*)gtk_toolbar_append_element(GTK_TOOLBAR(toolbar_top->gtkobj()), GTK_TOOLBAR_CHILD_BUTTON, 0, "Vorw�rts", 0, 0, GTK_WIDGET(manage(new Gtk::Pixmap(redo_xpm))->gtkobj()), 0, 0));
   toolbar_top->tools().push_back(Gtk::Toolbar_Helpers::Space());
   
   Gtk::Button *button_menu = Gtk::wrap((GtkButton*)gtk_toolbar_append_element(GTK_TOOLBAR(toolbar_top->gtkobj()), GTK_TOOLBAR_CHILD_BUTTON, 0, "Men�", 0, 0, GTK_WIDGET(manage(new Gtk::Pixmap(wizzard_trans_50_2_xpm))->gtkobj()), 0, 0));
   Gtk::Button *button_info = Gtk::wrap((GtkButton*)gtk_toolbar_append_element(GTK_TOOLBAR(toolbar_top->gtkobj()), GTK_TOOLBAR_CHILD_BUTTON, 0, "Info", 0, 0, GTK_WIDGET(manage(new Gtk::Pixmap(Info_trans_50_xpm))->gtkobj()), 0, 0));
   Gtk::Button *button11 = Gtk::wrap((GtkButton*)gtk_toolbar_append_element(GTK_TOOLBAR(toolbar_top->gtkobj()), GTK_TOOLBAR_CHILD_BUTTON, 0, "Hilfe", 0, 0, GTK_WIDGET(manage(new Gtk::Pixmap(Help_trans_50_xpm))->gtkobj()), 0, 0));
   Gtk::Button *button_html_hilfe = Gtk::wrap((GtkButton*)gtk_toolbar_append_element(GTK_TOOLBAR(toolbar_top->gtkobj()), GTK_TOOLBAR_CHILD_BUTTON, 0, "HTMLHilfe", 0, 0, GTK_WIDGET(manage(new Gtk::Pixmap(Help_trans_50_xpm))->gtkobj()), 0, 0));
   toolbar_top->tools().push_back(Gtk::Toolbar_Helpers::Space());
   
   Gtk::Button *button12 = Gtk::wrap((GtkButton*)gtk_toolbar_append_element(GTK_TOOLBAR(toolbar_top->gtkobj()), GTK_TOOLBAR_CHILD_BUTTON, 0, "Schlie�en", 0, 0, GTK_WIDGET(manage(new Gtk::Pixmap(Exit_trans_50_xpm))->gtkobj()), 0, 0));
   griff_toolbar_top = manage(new class Gtk::HandleBox());
   
   Gtk::MenuItem *neuen_abenteurer1 = NULL;
   Gtk::MenuItem *neuer_abenteurer_mit_wizard1 = NULL;
   Gtk::MenuItem *wizard_starten = NULL;
   Gtk::MenuItem *wizard_beenden = NULL;
   Gtk::MenuItem *trennlinie3 = NULL;
   Gtk::MenuItem *laden1 = NULL;
   Gtk::MenuItem *speichern1 = NULL;
   Gtk::MenuItem *speichern_unter_ = NULL;
   Gtk::MenuItem *exportieren = NULL;
   Gtk::MenuItem *trennlinie1 = NULL;
   Gtk::MenuItem *abenteurerdokument = NULL;
   Gtk::MenuItem *nur_sichtbares = NULL;
   Gtk::MenuItem *unsichtbares_drucken = NULL;
   Gtk::Menu *ausr_stungsdokument_menu = manage(new class Gtk::Menu());
   Gtk::MenuItem *ausr_stungsdokument = NULL;
   Gtk::MenuItem *beschreibung = NULL;
   Gtk::MenuItem *alles_drucken = NULL;
   Gtk::MenuItem *trennlinie4 = NULL;
   Gtk::MenuItem *leeres_abenteurerblatt = NULL;
   Gtk::Menu *drucken1_menu = manage(new class Gtk::Menu());
   Gtk::MenuItem *drucken1 = NULL;
   Gtk::MenuItem *trennlinie2 = NULL;
   Gtk::MenuItem *beenden1 = NULL;
   Gtk::MenuItem *trennlinie5 = NULL;
   Gtk::Menu *magus1_menu = manage(new class Gtk::Menu());
   Gtk::MenuItem *magus1 = NULL;
   Gtk::MenuItem *r_ckg_ngig1 = NULL;
   Gtk::MenuItem *erneut_vorw_rts1 = NULL;
   Gtk::MenuItem *geschichte = NULL;
   Gtk::Menu *bearbeiten1_menu = manage(new class Gtk::Menu());
   Gtk::MenuItem *bearbeiten1 = NULL;
   main_menubar = manage(new class Gtk::MenuBar());
   handlebox_menu = manage(new class Gtk::HandleBox());
   label_status = manage(new class Gtk::Label(""));
   label_wizard = manage(new class Gtk::Label(""));
   
   Gtk::VBox *vbox50 = manage(new class Gtk::VBox(false, 0));
   handlebox_status = manage(new class Gtk::HandleBox());
   Midgard_Info = manage(new class Midgard_Info(_data));
   pixmap_original_tux = manage(new class Gtk::Pixmap(MAGUS_Logo_Small_xpm));
   label_notebook_info = manage(new class Gtk::Label("Info & Credits"));
   pixmap_logo = manage(new class Gtk::Pixmap(midgard_logo_small_xpm));
   
   Gtk::Table *table_notebook_credits = manage(new class Gtk::Table(2, 2, false));
   Gtk::EventBox *eventbox_credits = manage(new class Gtk::EventBox());
   table_grundwerte = manage(new class table_grundwerte(_data));
   
   Gtk::Frame *frame4 = manage(new class Gtk::Frame());
   pixmap_notebook_grundwerte = manage(new class Gtk::Pixmap(Grundwert_small_xpm));
   label_notebook_grundwerte = manage(new class Gtk::Label("Grundwerte"));
   
   Gtk::VBox *vbox51 = manage(new class Gtk::VBox(false, 0));
   Gtk::EventBox *eventbox_grundwerte = manage(new class Gtk::EventBox());
   table_lernschema = manage(new class table_lernschema(_data));
   frame_lernschema = manage(new class Gtk::Frame());
   pixmap_notebook_lernen = manage(new class Gtk::Pixmap(L_Schema_small_xpm));
   label_notebook_lernen = manage(new class Gtk::Label("Lernschema"));
   
   Gtk::VBox *vbox52 = manage(new class Gtk::VBox(false, 0));
   Gtk::EventBox *eventbox_lernen = manage(new class Gtk::EventBox());
   table_steigern = manage(new class table_steigern(_data));
   frame_steigern = manage(new class Gtk::Frame());
   pixmap_notebook_steigern = manage(new class Gtk::Pixmap(Steigern_small_xpm));
   label_notebook_steigern = manage(new class Gtk::Label("Steigern"));
   
   Gtk::VBox *vbox53 = manage(new class Gtk::VBox(false, 0));
   Gtk::EventBox *eventbox_steigern = manage(new class Gtk::EventBox());
   table_beschreibung = manage(new class table_beschreibung(_data));
   pixmap_notebook_beschreibung = manage(new class Gtk::Pixmap(Descr_Char_40_xpm));
   label_notebook_beschreibung = manage(new class Gtk::Label("Beschreibung"));
   
   Gtk::VBox *vbox54 = manage(new class Gtk::VBox(false, 0));
   Gtk::EventBox *eventbox15 = manage(new class Gtk::EventBox());
   table_ausruestung = manage(new class table_ausruestung(_data));
   
   Gtk::Frame *frame79 = manage(new class Gtk::Frame());
   pixmap_notebook_ausruestung = manage(new class Gtk::Pixmap(Ausruest_small_xpm));
   label_notebook_ausruestung = manage(new class Gtk::Label("Ausr�stung"));
   
   Gtk::VBox *vbox55 = manage(new class Gtk::VBox(false, 0));
   Gtk::EventBox *eventbox_ausruestung = manage(new class Gtk::EventBox());
   table_optionen = manage(new class table_optionen(_data));
   pixmap_notebook_optionen = manage(new class Gtk::Pixmap(Regio_Hausregel_50_xpm));
   label_notebook_optionen = manage(new class Gtk::Label("Optionen"));
   
   Gtk::VBox *vbox56 = manage(new class Gtk::VBox(false, 0));
   Gtk::EventBox *eventbox_optionen = manage(new class Gtk::EventBox());
   Gtk::Label *label579 = manage(new class Gtk::Label("Durch anklicken einer Zeile aus der Liste wird der entsprechende Abenteurer geladen."));
   undo_tree = new class SimpleTree(2, 2);
   
   Gtk::Table *table148 = manage(new class Gtk::Table(2, 1, false));
   Gtk::Viewport *viewport44 = manage(new class Gtk::Viewport());
   Gtk::ScrolledWindow *scrolledwindow81 = manage(new class Gtk::ScrolledWindow());
   list_news = manage(new class Gtk::List());
   
   Gtk::Viewport *viewport38 = manage(new class Gtk::Viewport());
   Gtk::ScrolledWindow *scrolledwindow76 = manage(new class Gtk::ScrolledWindow());
   Gtk::Label *label597 = manage(new class Gtk::Label("Zum Editieren eines Abenteurers diesen anklicken."));
   AbenteurerListe = new class SimpleTree(7, 7);
   
   Gtk::Viewport *viewport47 = manage(new class Gtk::Viewport());
   Gtk::ScrolledWindow *scrolledwindow86 = manage(new class Gtk::ScrolledWindow());
   Gtk::Table *table161 = manage(new class Gtk::Table(3, 1, false));
   Gtk::Table *table139 = manage(new class Gtk::Table(2, 2, false));
   pixmap_notebook_news_1 = manage(new class Gtk::Pixmap(Fert_Lesen_32_xpm));
   pixmap_notebook_news_2 = manage(new class Gtk::Pixmap(redo_xpm));
   
   Gtk::HBox *hbox74 = manage(new class Gtk::HBox(false, 0));
   label_notebook_news = manage(new class Gtk::Label("News & Geschichte"));
   
   Gtk::VBox *vbox57 = manage(new class Gtk::VBox(false, 0));
   Gtk::EventBox *eventbox_geschichte = manage(new class Gtk::EventBox());
   notebook_main = manage(new class Gtk::Notebook());
   
   Gtk::Table *main_table = manage(new class Gtk::Table(4, 1, false));
   Gtk::EventBox *eventbox_MCG = manage(new class Gtk::EventBox());
   _tooltips.set_tip(*button_neuer_charakter, "Neuer Abenteurer", "");
   _tooltips.set_tip(*button9, "Abenteurer laden", "");
   _tooltips.set_tip(*button8, "Linke Maustaste: Speichern           Rechte Maustaste: Speichern unter ...", "");
   _tooltips.set_tip(*button10, "Linke Maustaste: LaTeX Abenteurerblatt drucken (pdf Datei). Mittlere Maustaste: Charakterbeschreibung drucken. Rechte Maustaste: Ausr�stung drucken.", "");
   _tooltips.set_tip(*button_undo, "Letzte �nderung r�ckg�ngig machen.", "");
   _tooltips.set_tip(*button_redo, "R�ckg�ngmachen r�ckg�ngig machen", "");
   _tooltips.set_tip(*button_menu, "Dieses Men� ist auch �ber die rechte Maustaste (an fast jeder beliebiegen Stelle im Programm) verf�gbar.", "");
   _tooltips.set_tip(*button_info, "Info", "");
   _tooltips.set_tip(*button11, "Hilfe", "");
   _tooltips.set_tip(*button_html_hilfe, "HTML Hilfe (Achtung, es wird der Browser ge�ffnet.", "");
   _tooltips.set_tip(*button12, "Schlie�en", "");
   toolbar_top->set_space_size(10);
   toolbar_top->set_tooltips(true);
   griff_toolbar_top->add(*toolbar_top);
   
   
   ausr_stungsdokument_menu->items().push_back(Gtk::Menu_Helpers::MenuElem("Nur sichtbares"));
   nur_sichtbares = (Gtk::MenuItem *)ausr_stungsdokument_menu->items().back();
   
   ausr_stungsdokument_menu->items().push_back(Gtk::Menu_Helpers::MenuElem("Alles drucken"));
   unsichtbares_drucken = (Gtk::MenuItem *)ausr_stungsdokument_menu->items().back();
   
   drucken1_menu->items().push_back(Gtk::Menu_Helpers::MenuElem("Abenteurerdokument", "<Control>P"));
   abenteurerdokument = (Gtk::MenuItem *)drucken1_menu->items().back();
   
   drucken1_menu->items().push_back(Gtk::Menu_Helpers::MenuElem("Ausr�stungsdokument", *ausr_stungsdokument_menu));
   ausr_stungsdokument = (Gtk::MenuItem *)drucken1_menu->items().back();
   
   drucken1_menu->items().push_back(Gtk::Menu_Helpers::MenuElem("Beschreibung"));
   beschreibung = (Gtk::MenuItem *)drucken1_menu->items().back();
   
   drucken1_menu->items().push_back(Gtk::Menu_Helpers::MenuElem("Alles drucken"));
   alles_drucken = (Gtk::MenuItem *)drucken1_menu->items().back();
   
   drucken1_menu->items().push_back(Gtk::Menu_Helpers::SeparatorElem());
   trennlinie4 = (Gtk::MenuItem *)drucken1_menu->items().back();
   
   drucken1_menu->items().push_back(Gtk::Menu_Helpers::MenuElem("Leeres Abenteurerblatt"));
   leeres_abenteurerblatt = (Gtk::MenuItem *)drucken1_menu->items().back();
   
   magus1_menu->items().push_back(Gtk::Menu_Helpers::MenuElem("Neuen Abenteurer", "<Mod1>N"));
   neuen_abenteurer1 = (Gtk::MenuItem *)magus1_menu->items().back();
   
   magus1_menu->items().push_back(Gtk::Menu_Helpers::MenuElem("Neuer Abenteurer mit Wizard", "<Control>N"));
   neuer_abenteurer_mit_wizard1 = (Gtk::MenuItem *)magus1_menu->items().back();
   
   magus1_menu->items().push_back(Gtk::Menu_Helpers::MenuElem("Wizard starten", "<Control>W"));
   wizard_starten = (Gtk::MenuItem *)magus1_menu->items().back();
   
   magus1_menu->items().push_back(Gtk::Menu_Helpers::MenuElem("Wizard beenden", "<Mod1>W"));
   wizard_beenden = (Gtk::MenuItem *)magus1_menu->items().back();
   
   magus1_menu->items().push_back(Gtk::Menu_Helpers::SeparatorElem());
   trennlinie3 = (Gtk::MenuItem *)magus1_menu->items().back();
   
   magus1_menu->items().push_back(Gtk::Menu_Helpers::MenuElem("�ffnen", "<Control>O"));
   laden1 = (Gtk::MenuItem *)magus1_menu->items().back();
   
   magus1_menu->items().push_back(Gtk::Menu_Helpers::MenuElem("Speichern", "<Control>S"));
   speichern1 = (Gtk::MenuItem *)magus1_menu->items().back();
   
   magus1_menu->items().push_back(Gtk::Menu_Helpers::MenuElem("Speichern unter ..."));
   speichern_unter_ = (Gtk::MenuItem *)magus1_menu->items().back();
   
   magus1_menu->items().push_back(Gtk::Menu_Helpers::MenuElem("Exportieren"));
   exportieren = (Gtk::MenuItem *)magus1_menu->items().back();
   
   magus1_menu->items().push_back(Gtk::Menu_Helpers::SeparatorElem());
   trennlinie1 = (Gtk::MenuItem *)magus1_menu->items().back();
   
   magus1_menu->items().push_back(Gtk::Menu_Helpers::MenuElem("Drucken", *drucken1_menu));
   drucken1 = (Gtk::MenuItem *)magus1_menu->items().back();
   
   magus1_menu->items().push_back(Gtk::Menu_Helpers::SeparatorElem());
   trennlinie2 = (Gtk::MenuItem *)magus1_menu->items().back();
   
   magus1_menu->items().push_back(Gtk::Menu_Helpers::MenuElem("Beenden", "<Control>Q"));
   beenden1 = (Gtk::MenuItem *)magus1_menu->items().back();
   
   magus1_menu->items().push_back(Gtk::Menu_Helpers::SeparatorElem());
   trennlinie5 = (Gtk::MenuItem *)magus1_menu->items().back();
   
   bearbeiten1_menu->items().push_back(Gtk::Menu_Helpers::MenuElem("R�ckg�ngig", "<Control>Z"));
   r_ckg_ngig1 = (Gtk::MenuItem *)bearbeiten1_menu->items().back();
   
   bearbeiten1_menu->items().push_back(Gtk::Menu_Helpers::MenuElem("Erneut/Vorw�rts", "<Control>R"));
   erneut_vorw_rts1 = (Gtk::MenuItem *)bearbeiten1_menu->items().back();
   
   bearbeiten1_menu->items().push_back(Gtk::Menu_Helpers::MenuElem("Geschichte"));
   geschichte = (Gtk::MenuItem *)bearbeiten1_menu->items().back();
   
   main_menubar->items().push_back(Gtk::Menu_Helpers::MenuElem("Datei", *magus1_menu));
   magus1 = (Gtk::MenuItem *)main_menubar->items().back();
   
   main_menubar->items().push_back(Gtk::Menu_Helpers::MenuElem("Bearbeiten", *bearbeiten1_menu));
   bearbeiten1 = (Gtk::MenuItem *)main_menubar->items().back();
   handlebox_menu->add(*main_menubar);
   label_status->set_alignment(0.01, 0.5);
   label_status->set_padding(0, 2);
   label_status->set_justify(GTK_JUSTIFY_LEFT);
   label_wizard->set_alignment(0.01, 0.5);
   label_wizard->set_padding(0, 2);
   label_wizard->set_justify(GTK_JUSTIFY_LEFT);
   vbox50->pack_start(*label_status, false, false, 0);
   vbox50->pack_start(*label_wizard, false, false, 0);
   handlebox_status->add(*vbox50);
   pixmap_original_tux->set_alignment(0.5, 0.5);
   pixmap_original_tux->set_padding(0, 0);
   label_notebook_info->set_alignment(0.5, 0.5);
   label_notebook_info->set_padding(0, 0);
   pixmap_logo->set_alignment(0.5, 0.5);
   pixmap_logo->set_padding(0, 0);
   table_notebook_credits->attach(*pixmap_original_tux, 1, 2, 0, 1, GTK_EXPAND|GTK_FILL, GTK_FILL, 0, 0);
   table_notebook_credits->attach(*label_notebook_info, 0, 2, 1, 2, GTK_FILL, 0, 0, 0);
   table_notebook_credits->attach(*pixmap_logo, 0, 1, 0, 1, GTK_EXPAND|GTK_FILL, GTK_EXPAND|GTK_FILL, 0, 0);
   _tooltips.set_tip(*eventbox_credits, "Info & Credits", "");
   eventbox_credits->add(*table_notebook_credits);
   frame4->set_label_align(0, 0);
   frame4->set_shadow_type(GTK_SHADOW_NONE);
   frame4->add(*table_grundwerte);
   pixmap_notebook_grundwerte->set_alignment(0.5, 0.5);
   pixmap_notebook_grundwerte->set_padding(0, 0);
   label_notebook_grundwerte->set_alignment(0.5, 0.5);
   label_notebook_grundwerte->set_padding(0, 0);
   vbox51->pack_start(*pixmap_notebook_grundwerte);
   vbox51->pack_start(*label_notebook_grundwerte, false, false, 0);
   _tooltips.set_tip(*eventbox_grundwerte, "Grundwerte", "");
   eventbox_grundwerte->add(*vbox51);
   frame_lernschema->set_label_align(0, 0);
   frame_lernschema->set_shadow_type(GTK_SHADOW_NONE);
   frame_lernschema->add(*table_lernschema);
   pixmap_notebook_lernen->set_alignment(0.5, 0.5);
   pixmap_notebook_lernen->set_padding(0, 0);
   label_notebook_lernen->set_alignment(0.5, 0.5);
   label_notebook_lernen->set_padding(0, 0);
   vbox52->pack_start(*pixmap_notebook_lernen);
   vbox52->pack_start(*label_notebook_lernen, false, false, 0);
   _tooltips.set_tip(*eventbox_lernen, "Lernschema", "");
   eventbox_lernen->add(*vbox52);
   frame_steigern->set_label_align(0, 0);
   frame_steigern->set_shadow_type(GTK_SHADOW_NONE);
   frame_steigern->add(*table_steigern);
   pixmap_notebook_steigern->set_alignment(0.5, 0.5);
   pixmap_notebook_steigern->set_padding(0, 0);
   label_notebook_steigern->set_alignment(0.5, 0.5);
   label_notebook_steigern->set_padding(0, 0);
   vbox53->pack_start(*pixmap_notebook_steigern);
   vbox53->pack_start(*label_notebook_steigern, false, false, 0);
   _tooltips.set_tip(*eventbox_steigern, "Steigern", "");
   eventbox_steigern->add(*vbox53);
   pixmap_notebook_beschreibung->set_usize(80, -1);
   pixmap_notebook_beschreibung->set_alignment(0.5, 0.5);
   pixmap_notebook_beschreibung->set_padding(0, 0);
   label_notebook_beschreibung->set_alignment(0.5, 0.5);
   label_notebook_beschreibung->set_padding(0, 0);
   vbox54->pack_start(*pixmap_notebook_beschreibung);
   vbox54->pack_start(*label_notebook_beschreibung, false, false, 0);
   _tooltips.set_tip(*eventbox15, "Beschreibung des Abenteurers und/oder des Hintergrundes", "");
   eventbox15->add(*vbox54);
   frame79->set_label_align(0, 0);
   frame79->set_shadow_type(GTK_SHADOW_NONE);
   frame79->add(*table_ausruestung);
   pixmap_notebook_ausruestung->set_alignment(0.5, 0.5);
   pixmap_notebook_ausruestung->set_padding(0, 0);
   label_notebook_ausruestung->set_alignment(0.5, 0.5);
   label_notebook_ausruestung->set_padding(0, 0);
   vbox55->pack_start(*pixmap_notebook_ausruestung);
   vbox55->pack_start(*label_notebook_ausruestung, false, false, 0);
   _tooltips.set_tip(*eventbox_ausruestung, "Ausr�stung", "");
   eventbox_ausruestung->add(*vbox55);
   pixmap_notebook_optionen->set_alignment(0.5, 0.5);
   pixmap_notebook_optionen->set_padding(0, 0);
   label_notebook_optionen->set_alignment(0.5, 0.5);
   label_notebook_optionen->set_padding(0, 0);
   vbox56->pack_start(*pixmap_notebook_optionen);
   vbox56->pack_start(*label_notebook_optionen, false, false, 0);
   _tooltips.set_tip(*eventbox_optionen, "Optionen", "");
   eventbox_optionen->add(*vbox56);
   label579->set_alignment(0, 0.02);
   label579->set_padding(2, 0);
   label579->set_justify(GTK_JUSTIFY_LEFT);
   table148->attach(*label579, 0, 1, 0, 1, GTK_FILL, GTK_FILL, 0, 0);
   table148->attach(*undo_tree, 0, 1, 1, 2, GTK_EXPAND|GTK_FILL, GTK_EXPAND|GTK_FILL, 0, 0);
   viewport44->set_shadow_type(GTK_SHADOW_NONE);
   viewport44->add(*table148);
   scrolledwindow81->set_policy(GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
   scrolledwindow81->add(*viewport44);
   viewport38->add(*list_news);
   scrolledwindow76->set_policy(GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
   scrolledwindow76->add(*viewport38);
   label597->set_alignment(0, 0.5);
   label597->set_padding(0, 0);
   viewport47->set_shadow_type(GTK_SHADOW_NONE);
   viewport47->add(*AbenteurerListe);
   scrolledwindow86->set_policy(GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
   scrolledwindow86->add(*viewport47);
   table161->attach(*label597, 0, 1, 0, 1, GTK_FILL, 0, 0, 0);
   table161->attach(*scrolledwindow86, 0, 1, 1, 2, GTK_EXPAND|GTK_FILL, GTK_EXPAND|GTK_FILL, 0, 0);
   table139->attach(*scrolledwindow81, 0, 1, 0, 1, GTK_FILL, GTK_EXPAND|GTK_FILL, 0, 0);
   table139->attach(*scrolledwindow76, 0, 2, 1, 2, GTK_EXPAND|GTK_FILL, GTK_EXPAND|GTK_FILL, 0, 0);
   table139->attach(*table161, 1, 2, 0, 1, GTK_FILL, GTK_FILL, 0, 0);
   pixmap_notebook_news_1->set_alignment(0.5, 0.5);
   pixmap_notebook_news_1->set_padding(0, 0);
   pixmap_notebook_news_2->set_alignment(0.5, 0.5);
   pixmap_notebook_news_2->set_padding(0, 0);
   hbox74->pack_start(*pixmap_notebook_news_1);
   hbox74->pack_start(*pixmap_notebook_news_2);
   label_notebook_news->set_alignment(0.5, 0.5);
   label_notebook_news->set_padding(0, 0);
   vbox57->pack_start(*hbox74);
   vbox57->pack_start(*label_notebook_news, false, false, 0);
   eventbox_geschichte->add(*vbox57);
   notebook_main->set_flags(GTK_CAN_FOCUS);
   notebook_main->set_show_tabs(true);
   notebook_main->set_tab_border(3);
   notebook_main->pages().push_back(Gtk::Notebook_Helpers::TabElem(*Midgard_Info, *eventbox_credits));
   notebook_main->pages().push_back(Gtk::Notebook_Helpers::TabElem(*frame4, *eventbox_grundwerte));
   notebook_main->pages().push_back(Gtk::Notebook_Helpers::TabElem(*frame_lernschema, *eventbox_lernen));
   notebook_main->pages().push_back(Gtk::Notebook_Helpers::TabElem(*frame_steigern, *eventbox_steigern));
   notebook_main->pages().push_back(Gtk::Notebook_Helpers::TabElem(*table_beschreibung, *eventbox15));
   notebook_main->pages().push_back(Gtk::Notebook_Helpers::TabElem(*frame79, *eventbox_ausruestung));
   notebook_main->pages().push_back(Gtk::Notebook_Helpers::TabElem(*table_optionen, *eventbox_optionen));
   notebook_main->pages().push_back(Gtk::Notebook_Helpers::TabElem(*table139, *eventbox_geschichte));
   main_table->attach(*griff_toolbar_top, 0, 1, 1, 2, GTK_EXPAND|GTK_FILL, 0, 0, 0);
   main_table->attach(*handlebox_menu, 0, 1, 0, 1, GTK_EXPAND|GTK_FILL, 0, 0, 0);
   main_table->attach(*handlebox_status, 0, 1, 3, 4, GTK_EXPAND|GTK_FILL, 0, 0, 0);
   main_table->attach(*notebook_main, 0, 1, 2, 3, GTK_EXPAND|GTK_SHRINK|GTK_FILL, GTK_EXPAND|GTK_SHRINK|GTK_FILL, 0, 0);
   eventbox_MCG->add(*main_table);
   midgard_CG->set_sensitive(false);
   midgard_CG->set_title("Magus");
   midgard_CG->set_policy(true, true, false);
   midgard_CG->add_accel_group(*(_data->getAccelGroup()));
   midgard_CG->add(*eventbox_MCG);
   toolbar_top->show();
   griff_toolbar_top->show();
   neuen_abenteurer1->show();
   neuer_abenteurer_mit_wizard1->show();
   wizard_starten->show();
   wizard_beenden->show();
   trennlinie3->show();
   laden1->show();
   speichern1->show();
   speichern_unter_->show();
   exportieren->show();
   trennlinie1->show();
   abenteurerdokument->show();
   nur_sichtbares->show();
   unsichtbares_drucken->show();
   ausr_stungsdokument_menu->show();
   ausr_stungsdokument->show();
   beschreibung->show();
   alles_drucken->show();
   trennlinie4->show();
   leeres_abenteurerblatt->show();
   drucken1_menu->show();
   drucken1->show();
   trennlinie2->show();
   beenden1->show();
   trennlinie5->show();
   magus1_menu->show();
   magus1->show();
   r_ckg_ngig1->show();
   erneut_vorw_rts1->show();
   geschichte->show();
   bearbeiten1_menu->show();
   bearbeiten1->show();
   main_menubar->show();
   handlebox_menu->show();
   label_status->show();
   label_wizard->show();
   vbox50->show();
   handlebox_status->show();
   pixmap_original_tux->show();
   label_notebook_info->show();
   pixmap_logo->show();
   table_notebook_credits->show();
   eventbox_credits->show();
   frame4->show();
   pixmap_notebook_grundwerte->show();
   label_notebook_grundwerte->show();
   vbox51->show();
   eventbox_grundwerte->show();
   frame_lernschema->show();
   pixmap_notebook_lernen->show();
   label_notebook_lernen->show();
   vbox52->show();
   eventbox_lernen->show();
   frame_steigern->show();
   pixmap_notebook_steigern->show();
   label_notebook_steigern->show();
   vbox53->show();
   eventbox_steigern->show();
   pixmap_notebook_beschreibung->show();
   label_notebook_beschreibung->show();
   vbox54->show();
   eventbox15->show();
   frame79->show();
   pixmap_notebook_ausruestung->show();
   label_notebook_ausruestung->show();
   vbox55->show();
   eventbox_ausruestung->show();
   pixmap_notebook_optionen->show();
   label_notebook_optionen->show();
   vbox56->show();
   eventbox_optionen->show();
   label579->show();
   undo_tree->show();
   table148->show();
   viewport44->show();
   scrolledwindow81->show();
   list_news->show();
   viewport38->show();
   scrolledwindow76->show();
   label597->show();
   AbenteurerListe->show();
   viewport47->show();
   scrolledwindow86->show();
   table161->show();
   table139->show();
   pixmap_notebook_news_1->show();
   pixmap_notebook_news_2->show();
   hbox74->show();
   label_notebook_news->show();
   vbox57->show();
   eventbox_geschichte->show();
   notebook_main->show();
   main_table->show();
   eventbox_MCG->show();
   midgard_CG->show();
   button_neuer_charakter->button_release_event.connect(SigC::slot(static_cast<class midgard_CG*>(this), &midgard_CG::on_neuer_charakter_release_event));
   button9->button_release_event.connect(SigC::slot(static_cast<class midgard_CG*>(this), &midgard_CG::on_laden_release_event));
   button8->button_release_event.connect(SigC::slot(static_cast<class midgard_CG*>(this), &midgard_CG::on_speichern_release_event));
   button10->button_release_event.connect(SigC::slot(static_cast<class midgard_CG*>(this), &midgard_CG::on_latex_release_event));
   button_undo->clicked.connect(SigC::slot(static_cast<class midgard_CG*>(this), &midgard_CG::on_button_undo_clicked));
   button_redo->clicked.connect(SigC::slot(static_cast<class midgard_CG*>(this), &midgard_CG::on_button_redo_clicked));
   button_menu->button_release_event.connect(SigC::slot(static_cast<class midgard_CG*>(this), &midgard_CG::on_button_menu_button_release_event));
   button_info->clicked.connect(SigC::slot(static_cast<class midgard_CG*>(this), &midgard_CG::on_button_info_clicked));
   button11->clicked.connect(SigC::slot(static_cast<class midgard_CG*>(this), &midgard_CG::on_button_hilfe_clicked));
   button_html_hilfe->clicked.connect(SigC::slot(static_cast<class midgard_CG*>(this), &midgard_CG::on_button_html_hilfe_clicked));
   button12->clicked.connect(SigC::slot(static_cast<class midgard_CG*>(this), &midgard_CG::on_schliessen_CG_clicked));
   neuen_abenteurer1->activate.connect(SigC::slot(static_cast<class midgard_CG*>(this), &midgard_CG::on_neuer_charakter_clicked));
   neuer_abenteurer_mit_wizard1->activate.connect(SigC::slot(static_cast<class midgard_CG*>(this), &midgard_CG::on_neuer_abenteurer_mit_wizard_activate));
   wizard_starten->activate.connect(SigC::slot(static_cast<class midgard_CG*>(this), &midgard_CG::on_wizard_starten_activate));
   wizard_beenden->activate.connect(SigC::slot(static_cast<class midgard_CG*>(this), &midgard_CG::on_wizard_beenden_activate));
   laden1->activate.connect(SigC::slot(static_cast<class midgard_CG*>(this), &midgard_CG::xml_import_auswahl));
   speichern1->activate.connect(SigC::slot(static_cast<class midgard_CG*>(this), &midgard_CG::xml_export_auswahl));
   speichern_unter_->activate.connect(SigC::slot(static_cast<class midgard_CG*>(this), &midgard_CG::save_existing_filename));
   exportieren->activate.connect(SigC::slot(static_cast<class midgard_CG*>(this), &midgard_CG::on_exportieren_activate));
   abenteurerdokument->activate.connect(SigC::slot(static_cast<class midgard_CG*>(this), &midgard_CG::on_abenteurerdokument_drucken));
   nur_sichtbares->activate.connect(SigC::slot(static_cast<class midgard_CG*>(this), &midgard_CG::on_nur_sichtbares_drucken));
   unsichtbares_drucken->activate.connect(SigC::slot(static_cast<class midgard_CG*>(this), &midgard_CG::on_auch_unsichtbares_drucken));
   beschreibung->activate.connect(SigC::slot(static_cast<class midgard_CG*>(this), &midgard_CG::on_beschreibung_drucken));
   alles_drucken->activate.connect(SigC::slot(static_cast<class midgard_CG*>(this), &midgard_CG::on_alles_drucken));
   leeres_abenteurerblatt->activate.connect(SigC::slot(static_cast<class midgard_CG*>(this), &midgard_CG::on_leeres_abenteurerdokument_drucken));
   beenden1->activate.connect(SigC::slot(static_cast<class midgard_CG*>(this), &midgard_CG::on_schliessen_CG_clicked));
   r_ckg_ngig1->activate.connect(SigC::slot(static_cast<class midgard_CG*>(this), &midgard_CG::on_button_undo_clicked));
   erneut_vorw_rts1->activate.connect(SigC::slot(static_cast<class midgard_CG*>(this), &midgard_CG::on_button_redo_clicked));
   geschichte->activate.connect(SigC::slot(static_cast<class midgard_CG*>(this), &midgard_CG::menu_geschichte_selected));
   eventbox_credits->button_release_event.connect(SigC::slot(static_cast<class midgard_CG*>(this), &midgard_CG::on_eventbox_credits_button_release_event));
   eventbox_grundwerte->button_release_event.connect(SigC::slot(static_cast<class midgard_CG*>(this), &midgard_CG::on_eventbox_grundwerte_button_release_event));
   eventbox_lernen->button_release_event.connect(SigC::slot(static_cast<class midgard_CG*>(this), &midgard_CG::on_eventbox_lernen_button_release_event));
   eventbox_steigern->button_release_event.connect(SigC::slot(static_cast<class midgard_CG*>(this), &midgard_CG::on_eventbox_steigern_button_release_event));
   eventbox15->button_release_event.connect(SigC::slot(static_cast<class midgard_CG*>(this), &midgard_CG::on_eventbox_beschreibung_button_release_event));
   eventbox_ausruestung->button_release_event.connect(SigC::slot(static_cast<class midgard_CG*>(this), &midgard_CG::on_eventbox_ausruestung_button_release_event));
   eventbox_optionen->button_release_event.connect(SigC::slot(static_cast<class midgard_CG*>(this), &midgard_CG::on_eventbox_optionen_button_release_event));
   undo_tree->leaf_selected.connect(SigC::slot(static_cast<class midgard_CG*>(this), &midgard_CG::on_undo_leaf_selected));
   AbenteurerListe->leaf_selected.connect(SigC::slot(static_cast<class midgard_CG*>(this), &midgard_CG::on_AbenteurerListe_leaf));
   eventbox_geschichte->button_release_event.connect(SigC::slot(static_cast<class midgard_CG*>(this), &midgard_CG::on_eventbox_geschichte_button_release_event));
   notebook_main->switch_page.connect(SigC::slot(static_cast<class midgard_CG*>(this), &midgard_CG::on_notebook_main_switch_page));
   eventbox_MCG->button_press_event.connect(SigC::slot(static_cast<class midgard_CG*>(this), &midgard_CG::on_eventbox_MCG_button_press_event));
   midgard_CG->delete_event.connect(SigC::slot(static_cast<class midgard_CG*>(this), &midgard_CG::on_midgard_CG_delete_event));
}

midgard_CG_glade::~midgard_CG_glade()
{  delete undo_tree;
   delete AbenteurerListe;
   delete _data;
}
