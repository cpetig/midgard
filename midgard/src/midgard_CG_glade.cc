// generated 2002/10/31 9:30:29 CET by thoma@Tiger.(none)
// using glademm V1.1.2a_cvs
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- /home/thoma/rollenspiel/midgard/programme/gcc_3.0/midgard/midgard.glade
// for gtk 1.2.10 and gtkmm 1.2.10
//
// Please modify the corresponding derived classes in ./src/midgard_CG.cc

#include "config.h"
#include "midgard_CG_glade.hh"
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
#include <gtk--/menuitem.h>
#include <gtk--/menu.h>
#include "../pixmaps/MAGUS_Logo_Small.xpm"
#include <gtk--/box.h>
#include <gtk--/eventbox.h>
#include <gtk--/frame.h>
#include "../pixmaps/Grundwert_small.xpm"
#include "../pixmaps/L_Schema_small.xpm"
#include "../pixmaps/Steigern_small.xpm"
#include "../pixmaps/Descr.Char-40.xpm"
#include "../pixmaps/Ausruest_small.xpm"
#include "../pixmaps/Regio_Hausregel-50.xpm"
#include <gtk--/viewport.h>
#include <gtk--/scrolledwindow.h>
#include "../pixmaps/KillChar-32.xpm"
#include <gtk--/label.h>
#include <gtk--/table.h>
#include "../pixmaps/NewsGeschichte.xpm"
#include "../pixmaps/Z-NewChar.xpm"
#include "../pixmaps/midgard_logo_status.xpm"
#include "../pixmaps/NSC-Mode-26.xpm"
#include "../pixmaps/MAGUS_Logo_Tiny.xpm"
#include "../pixmaps/Haus-26.xpm"

midgard_CG_glade::midgard_CG_glade(
) : Gtk::Window(GTK_WINDOW_TOPLEVEL)
{  midgard_CG = this;
   
   Gtk::AccelGroup *midgard_CG_accgrp = Gtk::AccelGroup::create();
   _data = new GlademmData(midgard_CG_accgrp);
   toolbar_top = manage(new class Gtk::Toolbar(GTK_ORIENTATION_HORIZONTAL, GTK_TOOLBAR_BOTH));
   griff_toolbar_top = manage(new class Gtk::HandleBox());
   
   Gtk::MenuItem *neuen_abenteurer1 = NULL;
   Gtk::MenuItem *neuer_abenteurer_mit_wizard1 = NULL;
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
   Gtk::MenuItem *trennlinie6 = NULL;
   Gtk::MenuItem *spielleiterbogen_drucken = NULL;
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
   Gtk::MenuItem *anleitung_menu = NULL;
   Gtk::MenuItem *hilfe_menu = NULL;
   Gtk::MenuItem *info_credits_menu = NULL;
   Gtk::MenuItem *news_menu = NULL;
   Gtk::Menu *hilfe1_menu = manage(new class Gtk::Menu());
   Gtk::MenuItem *hilfe1 = NULL;
   main_menubar = manage(new class Gtk::MenuBar());
   handlebox_menu = manage(new class Gtk::HandleBox());
   Midgard_Info = manage(new class Midgard_Info(_data));
   pixmap_original_tux = manage(new class Gtk::Pixmap(MAGUS_Logo_Small_xpm));
   label_notebook_info = manage(new class Gtk::Label("Info & Credits"));
   
   Gtk::VBox *vbox66 = manage(new class Gtk::VBox(false, 0));
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
   eventbox_lernen = manage(new class Gtk::EventBox());
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
   pixmap_notebook_ausruestung = manage(new class Gtk::Pixmap(Ausruest_small_xpm));
   label_notebook_ausruestung = manage(new class Gtk::Label("Ausr�stung"));
   
   Gtk::VBox *vbox55 = manage(new class Gtk::VBox(false, 0));
   Gtk::EventBox *eventbox_ausruestung = manage(new class Gtk::EventBox());
   table_optionen = manage(new class table_optionen(_data));
   pixmap_notebook_optionen = manage(new class Gtk::Pixmap(Regio_Hausregel_50_xpm));
   label_notebook_optionen = manage(new class Gtk::Label("Optionen"));
   
   Gtk::VBox *vbox56 = manage(new class Gtk::VBox(false, 0));
   Gtk::EventBox *eventbox_optionen = manage(new class Gtk::EventBox());
   list_news = manage(new class Gtk::List());
   
   Gtk::Viewport *viewport38 = manage(new class Gtk::Viewport());
   Gtk::ScrolledWindow *scrolledwindow76 = manage(new class Gtk::ScrolledWindow());
   Gtk::Pixmap *pixmap162 = manage(new class Gtk::Pixmap(KillChar_32_xpm));
   Gtk::Label *label598 = manage(new class Gtk::Label("Abenteurer aus\n"
		"Liste l�schen"));
   Gtk::HBox *hbox84 = manage(new class Gtk::HBox(false, 0));
   togglebutton_delete_abenteurer_aus_liste = manage(new class Gtk::ToggleButton());
   
   Gtk::Label *label597 = manage(new class Gtk::Label("Zum Editieren eines Abenteurers diesen anklicken."));
   AbenteurerListe = new class SimpleTree(7, 7);
   
   Gtk::Viewport *viewport47 = manage(new class Gtk::Viewport());
   Gtk::ScrolledWindow *scrolledwindow86 = manage(new class Gtk::ScrolledWindow());
   Gtk::Label *label579 = manage(new class Gtk::Label("Durch anklicken einer Zeile aus der Liste wird der entsprechende Abenteurer geladen."));
   undo_tree = new class SimpleTree(2, 2);
   
   Gtk::Viewport *viewport44 = manage(new class Gtk::Viewport());
   Gtk::ScrolledWindow *scrolledwindow81 = manage(new class Gtk::ScrolledWindow());
   Gtk::Table *table161 = manage(new class Gtk::Table(3, 2, false));
   Gtk::Table *table139 = manage(new class Gtk::Table(2, 1, false));
   Gtk::Pixmap *pixmap175 = manage(new class Gtk::Pixmap(NewsGeschichte_xpm));
   label_notebook_news = manage(new class Gtk::Label("News & Geschichte"));
   
   Gtk::VBox *vbox57 = manage(new class Gtk::VBox(false, 0));
   eventbox_geschichte = manage(new class Gtk::EventBox());
   table_zufall = manage(new class table_zufall(_data));
   pixmap167 = manage(new class Gtk::Pixmap(Z_NewChar_xpm));
   label603 = manage(new class Gtk::Label("Zufallsgenerator"));
   
   Gtk::VBox *vbox65 = manage(new class Gtk::VBox(false, 0));
   Gtk::EventBox *eventbox_zufall = manage(new class Gtk::EventBox());
   notebook_main = manage(new class Gtk::Notebook());
   label_status = manage(new class Gtk::Label(""));
   label_wizard = manage(new class Gtk::Label(""));
   
   Gtk::VBox *vbox64 = manage(new class Gtk::VBox(false, 0));
   frame_regionen_status = manage(new class Gtk::Frame());
   
   Gtk::Pixmap *pixmap176 = manage(new class Gtk::Pixmap(midgard_logo_status_xpm));
   eventbox_Original_Midgard = manage(new class Gtk::EventBox());
   
   Gtk::Pixmap *pixmap164 = manage(new class Gtk::Pixmap(NSC_Mode_26_xpm));
   eventbox_NSC_aktiv = manage(new class Gtk::EventBox());
   
   Gtk::Pixmap *pixmap165 = manage(new class Gtk::Pixmap(MAGUS_Logo_Tiny_xpm));
   eventbox_wizard_aktiv = manage(new class Gtk::EventBox());
   
   Gtk::Pixmap *pixmap166 = manage(new class Gtk::Pixmap(Haus_26_xpm));
   eventbox_haus_aktiv = manage(new class Gtk::EventBox());
   
   Gtk::HBox *hbox88 = manage(new class Gtk::HBox(false, 0));
   handlebox_status = manage(new class Gtk::HandleBox());
   
   Gtk::Table *main_table = manage(new class Gtk::Table(4, 1, false));
   
   toolbar_top->tools().push_back(Gtk::Toolbar_Helpers::ButtonElem("Neu", *manage(new Gtk::Pixmap(NewChar_trans_50_xpm)), 0));
   Gtk::Button *button_neuer_charakter = static_cast<Gtk::Button *>(toolbar_top->tools().back()->get_widget());
   
   toolbar_top->tools().push_back(Gtk::Toolbar_Helpers::ButtonElem("�ffnen", *manage(new Gtk::Pixmap(LoadChar_trans_50_xpm)), 0));
   Gtk::Button *button9 = static_cast<Gtk::Button *>(toolbar_top->tools().back()->get_widget());
   
   toolbar_top->tools().push_back(Gtk::Toolbar_Helpers::ButtonElem("Speichern", *manage(new Gtk::Pixmap(SaveChar_trans_50_xpm)), 0));
   Gtk::Button *button8 = static_cast<Gtk::Button *>(toolbar_top->tools().back()->get_widget());
   
   toolbar_top->tools().push_back(Gtk::Toolbar_Helpers::ButtonElem("Drucken", *manage(new Gtk::Pixmap(PrintChar_trans_50_xpm)), 0));
   button_main_drucken = static_cast<Gtk::Button *>(toolbar_top->tools().back()->get_widget());
   toolbar_top->tools().push_back(Gtk::Toolbar_Helpers::Space());
   
   
   toolbar_top->tools().push_back(Gtk::Toolbar_Helpers::ButtonElem("Zur�ck", *manage(new Gtk::Pixmap(Undo_xpm)), 0));
   button_undo = static_cast<Gtk::Button *>(toolbar_top->tools().back()->get_widget());
   
   toolbar_top->tools().push_back(Gtk::Toolbar_Helpers::ButtonElem("Vorw�rts", *manage(new Gtk::Pixmap(redo_xpm)), 0));
   button_redo = static_cast<Gtk::Button *>(toolbar_top->tools().back()->get_widget());
   toolbar_top->tools().push_back(Gtk::Toolbar_Helpers::Space());
   
   
   toolbar_top->tools().push_back(Gtk::Toolbar_Helpers::ButtonElem("Men�", *manage(new Gtk::Pixmap(wizzard_trans_50_2_xpm)), 0));
   Gtk::Button *button_menu = static_cast<Gtk::Button *>(toolbar_top->tools().back()->get_widget());
   
   toolbar_top->tools().push_back(Gtk::Toolbar_Helpers::ButtonElem("Info", *manage(new Gtk::Pixmap(Info_trans_50_xpm)), 0));
   Gtk::Button *button_info = static_cast<Gtk::Button *>(toolbar_top->tools().back()->get_widget());
   
   toolbar_top->tools().push_back(Gtk::Toolbar_Helpers::ButtonElem("Hilfe", *manage(new Gtk::Pixmap(Help_trans_new1_xpm)), 0));
   Gtk::Button *button11 = static_cast<Gtk::Button *>(toolbar_top->tools().back()->get_widget());
   
   toolbar_top->tools().push_back(Gtk::Toolbar_Helpers::ButtonElem("Anleitung", *manage(new Gtk::Pixmap(Help_trans_new1_xpm)), 0));
   Gtk::Button *button_html_hilfe = static_cast<Gtk::Button *>(toolbar_top->tools().back()->get_widget());
   toolbar_top->tools().push_back(Gtk::Toolbar_Helpers::Space());
   
   
   toolbar_top->tools().push_back(Gtk::Toolbar_Helpers::ButtonElem("Schlie�en", *manage(new Gtk::Pixmap(Exit_trans_50_xpm)), 0));
   button_schliessen = static_cast<Gtk::Button *>(toolbar_top->tools().back()->get_widget());
   
   ausr_stungsdokument_menu->items().push_back(Gtk::Menu_Helpers::MenuElem("Nur sichtbares", "<Control>A"));
   nur_sichtbares = (Gtk::MenuItem *)ausr_stungsdokument_menu->items().back();
   
   ausr_stungsdokument_menu->items().push_back(Gtk::Menu_Helpers::MenuElem("Alles drucken", "<Mod1>A"));
   unsichtbares_drucken = (Gtk::MenuItem *)ausr_stungsdokument_menu->items().back();
   
   drucken1_menu->items().push_back(Gtk::Menu_Helpers::MenuElem("Abenteurerdokument", "<Control>P"));
   abenteurerdokument = (Gtk::MenuItem *)drucken1_menu->items().back();
   
   drucken1_menu->items().push_back(Gtk::Menu_Helpers::MenuElem("Ausr�stungsdokument", *ausr_stungsdokument_menu));
   ausr_stungsdokument = (Gtk::MenuItem *)drucken1_menu->items().back();
   
   drucken1_menu->items().push_back(Gtk::Menu_Helpers::MenuElem("Beschreibung", "<Control>B"));
   beschreibung = (Gtk::MenuItem *)drucken1_menu->items().back();
   
   drucken1_menu->items().push_back(Gtk::Menu_Helpers::MenuElem("Alles drucken", "<Mod1>P"));
   alles_drucken = (Gtk::MenuItem *)drucken1_menu->items().back();
   
   drucken1_menu->items().push_back(Gtk::Menu_Helpers::SeparatorElem());
   trennlinie4 = (Gtk::MenuItem *)drucken1_menu->items().back();
   
   drucken1_menu->items().push_back(Gtk::Menu_Helpers::MenuElem("Leeres Abenteurerblatt", "<Control>E"));
   leeres_abenteurerblatt = (Gtk::MenuItem *)drucken1_menu->items().back();
   
   drucken1_menu->items().push_back(Gtk::Menu_Helpers::SeparatorElem());
   trennlinie6 = (Gtk::MenuItem *)drucken1_menu->items().back();
   
   drucken1_menu->items().push_back(Gtk::Menu_Helpers::MenuElem("Spielleiterbogen", "<Mod1>S"));
   spielleiterbogen_drucken = (Gtk::MenuItem *)drucken1_menu->items().back();
   
   magus1_menu->items().push_back(Gtk::Menu_Helpers::MenuElem("Neuer Abenteurer", "<Mod1>N"));
   neuen_abenteurer1 = (Gtk::MenuItem *)magus1_menu->items().back();
   
   magus1_menu->items().push_back(Gtk::Menu_Helpers::MenuElem("Neuer Abenteurer mit Wizard", "<Control>N"));
   neuer_abenteurer_mit_wizard1 = (Gtk::MenuItem *)magus1_menu->items().back();
   
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
   
   hilfe1_menu->items().push_back(Gtk::Menu_Helpers::MenuElem("Anleitung"));
   anleitung_menu = (Gtk::MenuItem *)hilfe1_menu->items().back();
   
   hilfe1_menu->items().push_back(Gtk::Menu_Helpers::MenuElem("Hilfe"));
   hilfe_menu = (Gtk::MenuItem *)hilfe1_menu->items().back();
   
   hilfe1_menu->items().push_back(Gtk::Menu_Helpers::MenuElem("Info & Credits"));
   info_credits_menu = (Gtk::MenuItem *)hilfe1_menu->items().back();
   
   hilfe1_menu->items().push_back(Gtk::Menu_Helpers::MenuElem("News"));
   news_menu = (Gtk::MenuItem *)hilfe1_menu->items().back();
   
   main_menubar->items().push_back(Gtk::Menu_Helpers::MenuElem("_Datei", "<Control>D", *magus1_menu));
   magus1 = (Gtk::MenuItem *)main_menubar->items().back();
   
   main_menubar->items().push_back(Gtk::Menu_Helpers::MenuElem("_Bearbeiten", "<Control>B", *bearbeiten1_menu));
   bearbeiten1 = (Gtk::MenuItem *)main_menubar->items().back();
   
   main_menubar->items().push_back(Gtk::Menu_Helpers::MenuElem("_Hilfe", "<Control>H", *hilfe1_menu));
   hilfe1 = (Gtk::MenuItem *)main_menubar->items().back();
   button_neuer_charakter->set_flags(GTK_CAN_FOCUS);
   _tooltips.set_tip(*button_neuer_charakter, "Neuer Abenteurer mit Wizard generieren", "");
   button9->set_flags(GTK_CAN_FOCUS);
   _tooltips.set_tip(*button9, "Abenteurer laden", "");
   button8->set_flags(GTK_CAN_FOCUS);
   _tooltips.set_tip(*button8, "Linke Maustaste: Speichern           Rechte Maustaste: Speichern unter ...", "");
   button_main_drucken->set_flags(GTK_CAN_FOCUS);
   _tooltips.set_tip(*button_main_drucken, "Linke Maustaste: LaTeX Abenteurerblatt drucken (pdf Datei). Mittlere Maustaste: Charakterbeschreibung drucken. Rechte Maustaste: Ausr�stung drucken.", "");
   button_undo->set_flags(GTK_CAN_FOCUS);
   _tooltips.set_tip(*button_undo, "Letzte �nderung r�ckg�ngig machen.", "");
   button_redo->set_flags(GTK_CAN_FOCUS);
   _tooltips.set_tip(*button_redo, "R�ckg�ngmachen r�ckg�ngig machen", "");
   button_menu->set_flags(GTK_CAN_FOCUS);
   _tooltips.set_tip(*button_menu, "Dieses Men� ist auch �ber die rechte Maustaste (an fast jeder beliebiegen Stelle im Programm) verf�gbar.", "");
   button_info->set_flags(GTK_CAN_FOCUS);
   _tooltips.set_tip(*button_info, "Info", "");
   button11->set_flags(GTK_CAN_FOCUS);
   _tooltips.set_tip(*button11, "Hilfe", "");
   button_html_hilfe->set_flags(GTK_CAN_FOCUS);
   _tooltips.set_tip(*button_html_hilfe, "HTML Hilfe (wenn verf�gbar)", "");
   button_schliessen->set_flags(GTK_CAN_FOCUS);
   _tooltips.set_tip(*button_schliessen, "Schlie�en", "");
   toolbar_top->set_space_size(10);
   toolbar_top->set_tooltips(true);
   toolbar_top->set_space_style(GTK_TOOLBAR_SPACE_EMPTY);
   griff_toolbar_top->set_shadow_type(GTK_SHADOW_NONE);
   griff_toolbar_top->set_handle_position(GTK_POS_LEFT);
   griff_toolbar_top->set_snap_edge(GTK_POS_TOP);
   griff_toolbar_top->add(*toolbar_top);
   main_menubar->set_shadow_type(GTK_SHADOW_NONE);
   handlebox_menu->set_shadow_type(GTK_SHADOW_NONE);
   handlebox_menu->set_handle_position(GTK_POS_LEFT);
   handlebox_menu->set_snap_edge(GTK_POS_TOP);
   handlebox_menu->add(*main_menubar);
   pixmap_original_tux->set_alignment(0.5,0.5);
   pixmap_original_tux->set_padding(0,0);
   label_notebook_info->set_alignment(0.5,0.5);
   label_notebook_info->set_padding(0,0);
   label_notebook_info->set_justify(GTK_JUSTIFY_CENTER);
   label_notebook_info->set_line_wrap(false);
   vbox66->pack_start(*pixmap_original_tux);
   vbox66->pack_start(*label_notebook_info, false, false, 0);
   _tooltips.set_tip(*eventbox_credits, "Info & Credits", "");
   eventbox_credits->add(*vbox66);
   frame4->set_shadow_type(GTK_SHADOW_NONE);
   frame4->set_label_align(0,0);
   frame4->add(*table_grundwerte);
   pixmap_notebook_grundwerte->set_alignment(0.5,0.5);
   pixmap_notebook_grundwerte->set_padding(0,0);
   label_notebook_grundwerte->set_alignment(0.5,0.5);
   label_notebook_grundwerte->set_padding(0,0);
   label_notebook_grundwerte->set_justify(GTK_JUSTIFY_CENTER);
   label_notebook_grundwerte->set_line_wrap(false);
   vbox51->pack_start(*pixmap_notebook_grundwerte);
   vbox51->pack_start(*label_notebook_grundwerte, false, false, 0);
   _tooltips.set_tip(*eventbox_grundwerte, "Grundwerte", "");
   eventbox_grundwerte->add(*vbox51);
   frame_lernschema->set_shadow_type(GTK_SHADOW_NONE);
   frame_lernschema->set_label_align(0,0);
   frame_lernschema->add(*table_lernschema);
   pixmap_notebook_lernen->set_alignment(0.5,0.5);
   pixmap_notebook_lernen->set_padding(0,0);
   label_notebook_lernen->set_alignment(0.5,0.5);
   label_notebook_lernen->set_padding(0,0);
   label_notebook_lernen->set_justify(GTK_JUSTIFY_CENTER);
   label_notebook_lernen->set_line_wrap(false);
   vbox52->pack_start(*pixmap_notebook_lernen);
   vbox52->pack_start(*label_notebook_lernen, false, false, 0);
   _tooltips.set_tip(*eventbox_lernen, "Lernschema", "");
   eventbox_lernen->add(*vbox52);
   frame_steigern->set_shadow_type(GTK_SHADOW_NONE);
   frame_steigern->set_label_align(0,0);
   frame_steigern->add(*table_steigern);
   pixmap_notebook_steigern->set_alignment(0.5,0.5);
   pixmap_notebook_steigern->set_padding(0,0);
   label_notebook_steigern->set_alignment(0.5,0.5);
   label_notebook_steigern->set_padding(0,0);
   label_notebook_steigern->set_justify(GTK_JUSTIFY_CENTER);
   label_notebook_steigern->set_line_wrap(false);
   vbox53->pack_start(*pixmap_notebook_steigern);
   vbox53->pack_start(*label_notebook_steigern, false, false, 0);
   _tooltips.set_tip(*eventbox_steigern, "Steigern", "");
   eventbox_steigern->add(*vbox53);
   pixmap_notebook_beschreibung->set_usize(80,-1);
   pixmap_notebook_beschreibung->set_alignment(0.5,0.5);
   pixmap_notebook_beschreibung->set_padding(0,0);
   label_notebook_beschreibung->set_alignment(0.5,0.5);
   label_notebook_beschreibung->set_padding(0,0);
   label_notebook_beschreibung->set_justify(GTK_JUSTIFY_CENTER);
   label_notebook_beschreibung->set_line_wrap(false);
   vbox54->pack_start(*pixmap_notebook_beschreibung);
   vbox54->pack_start(*label_notebook_beschreibung, false, false, 0);
   _tooltips.set_tip(*eventbox15, "Beschreibung des Abenteurers und/oder des Hintergrundes", "");
   eventbox15->add(*vbox54);
   pixmap_notebook_ausruestung->set_alignment(0.5,0.5);
   pixmap_notebook_ausruestung->set_padding(0,0);
   label_notebook_ausruestung->set_alignment(0.5,0.5);
   label_notebook_ausruestung->set_padding(0,0);
   label_notebook_ausruestung->set_justify(GTK_JUSTIFY_CENTER);
   label_notebook_ausruestung->set_line_wrap(false);
   vbox55->pack_start(*pixmap_notebook_ausruestung);
   vbox55->pack_start(*label_notebook_ausruestung, false, false, 0);
   _tooltips.set_tip(*eventbox_ausruestung, "Ausr�stung", "");
   eventbox_ausruestung->add(*vbox55);
   pixmap_notebook_optionen->set_alignment(0.5,0.5);
   pixmap_notebook_optionen->set_padding(0,0);
   label_notebook_optionen->set_alignment(0.5,0.5);
   label_notebook_optionen->set_padding(0,0);
   label_notebook_optionen->set_justify(GTK_JUSTIFY_CENTER);
   label_notebook_optionen->set_line_wrap(false);
   vbox56->pack_start(*pixmap_notebook_optionen);
   vbox56->pack_start(*label_notebook_optionen, false, false, 0);
   _tooltips.set_tip(*eventbox_optionen, "Optionen", "");
   eventbox_optionen->add(*vbox56);
   list_news->set_selection_mode(GTK_SELECTION_SINGLE);
   viewport38->set_shadow_type(GTK_SHADOW_IN);
   viewport38->add(*list_news);
   scrolledwindow76->set_policy(GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
   scrolledwindow76->add(*viewport38);
   pixmap162->set_alignment(0.5,0.5);
   pixmap162->set_padding(0,0);
   label598->set_alignment(0.5,0.5);
   label598->set_padding(0,0);
   label598->set_justify(GTK_JUSTIFY_CENTER);
   label598->set_line_wrap(false);
   hbox84->pack_start(*pixmap162);
   hbox84->pack_start(*label598, false, false, 0);
   togglebutton_delete_abenteurer_aus_liste->set_flags(GTK_CAN_FOCUS);
   togglebutton_delete_abenteurer_aus_liste->set_relief(GTK_RELIEF_NORMAL);
   togglebutton_delete_abenteurer_aus_liste->set_active(false);
   togglebutton_delete_abenteurer_aus_liste->add(*hbox84);
   label597->set_alignment(0,0.5);
   label597->set_padding(0,0);
   label597->set_justify(GTK_JUSTIFY_CENTER);
   label597->set_line_wrap(false);
   viewport47->set_shadow_type(GTK_SHADOW_NONE);
   viewport47->add(*AbenteurerListe);
   scrolledwindow86->set_policy(GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
   scrolledwindow86->add(*viewport47);
   label579->set_alignment(0,0.02);
   label579->set_padding(2,0);
   label579->set_justify(GTK_JUSTIFY_LEFT);
   label579->set_line_wrap(false);
   viewport44->set_shadow_type(GTK_SHADOW_NONE);
   viewport44->add(*undo_tree);
   scrolledwindow81->set_policy(GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
   scrolledwindow81->add(*viewport44);
   table161->set_row_spacings(0);
   table161->set_col_spacings(0);
   table161->attach(*togglebutton_delete_abenteurer_aus_liste, 1, 2, 2, 3, 0, 0, 0, 0);
   table161->attach(*label597, 1, 2, 0, 1, GTK_SHRINK|GTK_FILL, GTK_SHRINK, 0, 0);
   table161->attach(*scrolledwindow86, 1, 2, 1, 2, GTK_EXPAND|GTK_SHRINK|GTK_FILL, GTK_EXPAND|GTK_SHRINK|GTK_FILL, 0, 0);
   table161->attach(*label579, 0, 1, 0, 1, GTK_FILL, 0, 0, 0);
   table161->attach(*scrolledwindow81, 0, 1, 1, 3, GTK_FILL, GTK_FILL, 0, 0);
   table139->set_row_spacings(0);
   table139->set_col_spacings(0);
   table139->attach(*scrolledwindow76, 0, 1, 1, 2, GTK_EXPAND|GTK_SHRINK|GTK_FILL, GTK_EXPAND|GTK_SHRINK|GTK_FILL, 0, 0);
   table139->attach(*table161, 0, 1, 0, 1, GTK_SHRINK|GTK_FILL, GTK_EXPAND|GTK_SHRINK|GTK_FILL, 0, 0);
   pixmap175->set_alignment(0.5,0.5);
   pixmap175->set_padding(0,0);
   label_notebook_news->set_alignment(0.5,0.5);
   label_notebook_news->set_padding(0,0);
   label_notebook_news->set_justify(GTK_JUSTIFY_CENTER);
   label_notebook_news->set_line_wrap(false);
   vbox57->pack_start(*pixmap175);
   vbox57->pack_start(*label_notebook_news, false, false, 0);
   eventbox_geschichte->add(*vbox57);
   pixmap167->set_alignment(0.5,0.5);
   pixmap167->set_padding(0,0);
   label603->set_alignment(0.5,0.5);
   label603->set_padding(0,0);
   label603->set_justify(GTK_JUSTIFY_CENTER);
   label603->set_line_wrap(false);
   vbox65->pack_start(*pixmap167);
   vbox65->pack_start(*label603, false, false, 0);
   _tooltips.set_tip(*eventbox_zufall, "Zufallsabenteurer (NSC) erstellen", "");
   eventbox_zufall->add(*vbox65);
   notebook_main->set_flags(GTK_CAN_FOCUS);
   notebook_main->set_show_tabs(true);
   notebook_main->set_show_border(true);
   notebook_main->set_tab_pos(GTK_POS_TOP);
   notebook_main->set_scrollable(false);
   notebook_main->popup_disable();
   notebook_main->pages().push_back(Gtk::Notebook_Helpers::TabElem(*Midgard_Info, *eventbox_credits));
   notebook_main->pages().push_back(Gtk::Notebook_Helpers::TabElem(*frame4, *eventbox_grundwerte));
   notebook_main->pages().push_back(Gtk::Notebook_Helpers::TabElem(*frame_lernschema, *eventbox_lernen));
   notebook_main->pages().push_back(Gtk::Notebook_Helpers::TabElem(*frame_steigern, *eventbox_steigern));
   notebook_main->pages().push_back(Gtk::Notebook_Helpers::TabElem(*table_beschreibung, *eventbox15));
   notebook_main->pages().push_back(Gtk::Notebook_Helpers::TabElem(*table_ausruestung, *eventbox_ausruestung));
   notebook_main->pages().push_back(Gtk::Notebook_Helpers::TabElem(*table_optionen, *eventbox_optionen));
   notebook_main->pages().push_back(Gtk::Notebook_Helpers::TabElem(*table139, *eventbox_geschichte));
   notebook_main->pages().push_back(Gtk::Notebook_Helpers::TabElem(*table_zufall, *eventbox_zufall));
   label_status->set_alignment(0,0.5);
   label_status->set_padding(0,2);
   label_status->set_justify(GTK_JUSTIFY_LEFT);
   label_status->set_line_wrap(true);
   label_wizard->set_alignment(0.01,0.5);
   label_wizard->set_padding(0,2);
   label_wizard->set_justify(GTK_JUSTIFY_LEFT);
   label_wizard->set_line_wrap(true);
   vbox64->pack_start(*label_status);
   vbox64->pack_start(*label_wizard, false, false, 0);
   frame_regionen_status->set_shadow_type(GTK_SHADOW_NONE);
   frame_regionen_status->set_label_align(0,0);
   pixmap176->set_alignment(0.5,0.5);
   pixmap176->set_padding(0,0);
   _tooltips.set_tip(*eventbox_Original_Midgard, "Dieses Icon zeigt an, da� die Originalregeln verwendet werden.", "");
   eventbox_Original_Midgard->add(*pixmap176);
   pixmap164->set_alignment(0.5,0.5);
   pixmap164->set_padding(0,0);
   _tooltips.set_tip(*eventbox_NSC_aktiv, "Dieses Icon zeigt an, da� der NSC Modus eingeschaltet ist.", "");
   eventbox_NSC_aktiv->add(*pixmap164);
   pixmap165->set_alignment(0.5,0.5);
   pixmap165->set_padding(0,0);
   _tooltips.set_tip(*eventbox_wizard_aktiv, "Dieses Icon zeigt an, da� der Wizard aktiv ist.", "");
   eventbox_wizard_aktiv->add(*pixmap165);
   pixmap166->set_alignment(0.5,0.5);
   pixmap166->set_padding(0,0);
   _tooltips.set_tip(*eventbox_haus_aktiv, "Dieses Icon zeigt an, da� Hausregeln aktiv sind.", "");
   eventbox_haus_aktiv->add(*pixmap166);
   hbox88->pack_start(*vbox64);
   hbox88->pack_start(*frame_regionen_status, false, true, 0);
   hbox88->pack_start(*eventbox_Original_Midgard, false, false, 0);
   hbox88->pack_start(*eventbox_NSC_aktiv, false, true, 0);
   hbox88->pack_start(*eventbox_wizard_aktiv, false, true, 0);
   hbox88->pack_start(*eventbox_haus_aktiv, false, true, 0);
   handlebox_status->set_shadow_type(GTK_SHADOW_NONE);
   handlebox_status->set_handle_position(GTK_POS_LEFT);
   handlebox_status->set_snap_edge(GTK_POS_LEFT);
   handlebox_status->add(*hbox88);
   main_table->set_row_spacings(0);
   main_table->set_col_spacings(0);
   main_table->attach(*griff_toolbar_top, 0, 1, 1, 2, GTK_EXPAND|GTK_SHRINK|GTK_FILL, 0, 0, 0);
   main_table->attach(*handlebox_menu, 0, 1, 0, 1, GTK_EXPAND|GTK_SHRINK|GTK_FILL, 0, 0, 0);
   main_table->attach(*notebook_main, 0, 1, 2, 3, GTK_EXPAND|GTK_SHRINK|GTK_FILL, GTK_EXPAND|GTK_SHRINK|GTK_FILL, 0, 0);
   main_table->attach(*handlebox_status, 0, 1, 3, 4, GTK_EXPAND|GTK_SHRINK|GTK_FILL, GTK_SHRINK, 0, 0);
   midgard_CG->set_events(GDK_BUTTON_PRESS_MASK);
   midgard_CG->set_sensitive(false);
   midgard_CG->set_title("Magus");
   midgard_CG->set_modal(false);
   midgard_CG->set_position(GTK_WIN_POS_NONE);
   midgard_CG->set_policy(true, true, false);
   midgard_CG->add_accel_group(*(_data->getAccelGroup()));
   midgard_CG->add(*main_table);
   toolbar_top->show();
   griff_toolbar_top->show();
   neuen_abenteurer1->show();
   neuer_abenteurer_mit_wizard1->show();
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
   trennlinie6->show();
   spielleiterbogen_drucken->show();
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
   anleitung_menu->show();
   hilfe_menu->show();
   info_credits_menu->show();
   news_menu->show();
   hilfe1_menu->show();
   hilfe1->show();
   main_menubar->show();
   handlebox_menu->show();
   pixmap_original_tux->show();
   label_notebook_info->show();
   vbox66->show();
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
   pixmap_notebook_ausruestung->show();
   label_notebook_ausruestung->show();
   vbox55->show();
   eventbox_ausruestung->show();
   pixmap_notebook_optionen->show();
   label_notebook_optionen->show();
   vbox56->show();
   eventbox_optionen->show();
   list_news->show();
   viewport38->show();
   scrolledwindow76->show();
   pixmap162->show();
   label598->show();
   hbox84->show();
   togglebutton_delete_abenteurer_aus_liste->show();
   label597->show();
   AbenteurerListe->show();
   viewport47->show();
   scrolledwindow86->show();
   label579->show();
   undo_tree->show();
   viewport44->show();
   scrolledwindow81->show();
   table161->show();
   table139->show();
   pixmap175->show();
   label_notebook_news->show();
   vbox57->show();
   eventbox_geschichte->show();
   pixmap167->show();
   label603->show();
   vbox65->show();
   eventbox_zufall->show();
   notebook_main->show();
   label_status->show();
   label_wizard->show();
   vbox64->show();
   frame_regionen_status->show();
   pixmap176->show();
   eventbox_Original_Midgard->show();
   pixmap164->show();
   eventbox_NSC_aktiv->show();
   pixmap165->show();
   eventbox_wizard_aktiv->show();
   pixmap166->show();
   eventbox_haus_aktiv->show();
   hbox88->show();
   handlebox_status->show();
   main_table->show();
   midgard_CG->show();
   button_neuer_charakter->button_release_event.connect(SigC::slot(this, &midgard_CG_glade::on_neuer_charakter_release_event));
   button9->button_release_event.connect(SigC::slot(this, &midgard_CG_glade::on_laden_release_event));
   button8->button_release_event.connect(SigC::slot(this, &midgard_CG_glade::on_speichern_release_event));
   button_main_drucken->button_release_event.connect(SigC::slot(this, &midgard_CG_glade::on_latex_release_event));
   button_undo->clicked.connect(SigC::slot(this, &midgard_CG_glade::on_button_undo_clicked));
   button_redo->clicked.connect(SigC::slot(this, &midgard_CG_glade::on_button_redo_clicked));
   button_menu->button_release_event.connect(SigC::slot(this, &midgard_CG_glade::on_button_menu_button_release_event));
   button_info->clicked.connect(SigC::slot(this, &midgard_CG_glade::on_button_info_clicked));
   button11->clicked.connect(SigC::slot(this, &midgard_CG_glade::on_button_hilfe_clicked));
   button_html_hilfe->clicked.connect(SigC::slot(this, &midgard_CG_glade::on_button_html_hilfe_clicked));
   button_schliessen->clicked.connect(SigC::slot(this, &midgard_CG_glade::on_schliessen_CG_clicked));
   neuen_abenteurer1->activate.connect(SigC::slot(this, &midgard_CG_glade::on_neuer_charakter_clicked));
   neuer_abenteurer_mit_wizard1->activate.connect(SigC::slot(this, &midgard_CG_glade::on_neuer_abenteurer_mit_wizard_activate));
   wizard_beenden->activate.connect(SigC::slot(this, &midgard_CG_glade::on_wizard_beenden_activate));
   laden1->activate.connect(SigC::slot(this, &midgard_CG_glade::xml_import_auswahl));
   speichern1->activate.connect(SigC::slot(this, &midgard_CG_glade::save_existing_filename));
   speichern_unter_->activate.connect(SigC::slot(this, &midgard_CG_glade::xml_export_auswahl));
   exportieren->activate.connect(SigC::slot(this, &midgard_CG_glade::on_exportieren_activate));
   abenteurerdokument->activate.connect(SigC::slot(this, &midgard_CG_glade::on_abenteurerdokument_drucken));
   nur_sichtbares->activate.connect(SigC::slot(this, &midgard_CG_glade::on_nur_sichtbares_drucken));
   unsichtbares_drucken->activate.connect(SigC::slot(this, &midgard_CG_glade::on_auch_unsichtbares_drucken));
   beschreibung->activate.connect(SigC::slot(this, &midgard_CG_glade::on_beschreibung_drucken));
   alles_drucken->activate.connect(SigC::slot(this, &midgard_CG_glade::on_alles_drucken));
   leeres_abenteurerblatt->activate.connect(SigC::slot(this, &midgard_CG_glade::on_leeres_abenteurerdokument_drucken));
   spielleiterbogen_drucken->activate.connect(SigC::slot(this, &midgard_CG_glade::on_spielleiterbogen_drucken_activate));
   beenden1->activate.connect(SigC::slot(this, &midgard_CG_glade::on_schliessen_CG_clicked));
   r_ckg_ngig1->activate.connect(SigC::slot(this, &midgard_CG_glade::on_button_undo_clicked));
   erneut_vorw_rts1->activate.connect(SigC::slot(this, &midgard_CG_glade::on_button_redo_clicked));
   geschichte->activate.connect(SigC::slot(this, &midgard_CG_glade::menu_geschichte_selected));
   anleitung_menu->activate.connect(SigC::slot(this, &midgard_CG_glade::on_anleitung_menu_activate));
   hilfe_menu->activate.connect(SigC::slot(this, &midgard_CG_glade::on_hilfe_menu_activate));
   info_credits_menu->activate.connect(SigC::slot(this, &midgard_CG_glade::on_info_credits_menu_activate));
   news_menu->activate.connect(SigC::slot(this, &midgard_CG_glade::on_news_menu_activate));
   eventbox_credits->button_release_event.connect(SigC::slot(this, &midgard_CG_glade::on_eventbox_credits_button_release_event));
   eventbox_grundwerte->button_release_event.connect(SigC::slot(this, &midgard_CG_glade::on_eventbox_grundwerte_button_release_event));
   eventbox_lernen->button_release_event.connect(SigC::slot(this, &midgard_CG_glade::on_eventbox_lernen_button_release_event));
   eventbox_steigern->button_release_event.connect(SigC::slot(this, &midgard_CG_glade::on_eventbox_steigern_button_release_event));
   eventbox15->button_release_event.connect(SigC::slot(this, &midgard_CG_glade::on_eventbox_beschreibung_button_release_event));
   eventbox_ausruestung->button_release_event.connect(SigC::slot(this, &midgard_CG_glade::on_eventbox_ausruestung_button_release_event));
   eventbox_optionen->button_release_event.connect(SigC::slot(this, &midgard_CG_glade::on_eventbox_optionen_button_release_event));
   togglebutton_delete_abenteurer_aus_liste->toggled.connect(SigC::slot(this, &midgard_CG_glade::on_togglebutton_delete_abenteurer_aus_liste_toggled));
   AbenteurerListe->leaf_selected.connect(SigC::slot(this, &midgard_CG_glade::on_AbenteurerListe_leaf));
   undo_tree->leaf_selected.connect(SigC::slot(this, &midgard_CG_glade::on_undo_leaf_selected));
   eventbox_geschichte->button_release_event.connect(SigC::slot(this, &midgard_CG_glade::on_eventbox_geschichte_button_release_event));
   eventbox_zufall->button_release_event.connect(SigC::slot(this, &midgard_CG_glade::on_eventbox_zufall_button_release_event));
   notebook_main->switch_page.connect(SigC::slot(this, &midgard_CG_glade::on_notebook_main_switch_page));
   midgard_CG->delete_event.connect(SigC::slot(this, &midgard_CG_glade::on_midgard_CG_delete_event));
   midgard_CG->button_press_event.connect(SigC::slot(this, &midgard_CG_glade::on_eventbox_MCG_button_press_event));
}

midgard_CG_glade::~midgard_CG_glade()
{  delete AbenteurerListe;
   delete undo_tree;
   delete _data;
}
