// generated 2002/9/11 16:30:54 CEST by thoma@Tiger.(none)
// using glademm V1.1.1c_cvs
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- /home/thoma/rollenspiel/midgard/programme/gcc_3.0/midgard/midgard.glade
// for gtk 1.2.10 and gtkmm 1.2.10
//
// Please modify the corresponding derived classes in ./src/table_zufall.cc

#include "config.h"
#include "table_zufall.hh"
#include <gtk--/button.h>
#include <gtk--/table.h>

table_zufall_glade::table_zufall_glade(GlademmData *_data
) : Gtk::Table(3, 3, false)
{  table_zufall = this;
   
   Gtk::Button *button_zufall_voll = manage(new class Gtk::Button("Zufallsabenteurer \n"
		"Grad 1 erzeugen"));
   togglebutton_vorgaben = manage(new class Gtk::ToggleButton("Vorgaben\n"
		"machen"));
   checkbutton_spezies = manage(new class Gtk::CheckButton("Spezies", 0, 0.5));
   checkbutton_herkunft = manage(new class Gtk::CheckButton("Herkunft", 0, 0.5));
   checkbutton_typ = manage(new class Gtk::CheckButton("Typ", 0, 0.5));
   checkbutton_werte = manage(new class Gtk::CheckButton("Werte", 0, 0.5));
   checkbutton_st = manage(new class Gtk::CheckButton("St", 0, 0.5));
   checkbutton_gs = manage(new class Gtk::CheckButton("Gs", 0, 0.5));
   checkbutton_gw = manage(new class Gtk::CheckButton("Gw", 0, 0.5));
   checkbutton_ko = manage(new class Gtk::CheckButton("Ko", 0, 0.5));
   checkbutton_in = manage(new class Gtk::CheckButton("In", 0, 0.5));
   checkbutton_zt = manage(new class Gtk::CheckButton("Zt", 0, 0.5));
   checkbutton_au = manage(new class Gtk::CheckButton("Au", 0, 0.5));
   checkbutton_pa = manage(new class Gtk::CheckButton("pA", 0, 0.5));
   checkbutton_wk = manage(new class Gtk::CheckButton("Wk", 0, 0.5));
   checkbutton_sb = manage(new class Gtk::CheckButton("Sb", 0, 0.5));
   checkbutton_b = manage(new class Gtk::CheckButton("B", 0, 0.5));
   
   Gtk::Table *table168 = manage(new class Gtk::Table(6, 2, false));
   frame_werte_vorgaben = manage(new class Gtk::Frame("Werte"));
   
   Gtk::Table *table166 = manage(new class Gtk::Table(9, 2, false));
   frame_vorgaben = manage(new class Gtk::Frame("Vorgaben"));
   
   Gtk::Table *table165 = manage(new class Gtk::Table(3, 3, false));
   button_zufall_voll->set_flags(GTK_CAN_FOCUS);
   button_zufall_voll->set_relief(GTK_RELIEF_NORMAL);
   togglebutton_vorgaben->set_flags(GTK_CAN_FOCUS);
   togglebutton_vorgaben->set_relief(GTK_RELIEF_NORMAL);
   togglebutton_vorgaben->set_active(false);
   checkbutton_spezies->set_flags(GTK_CAN_FOCUS);
   checkbutton_spezies->set_mode(true);
   checkbutton_spezies->set_active(false);
   checkbutton_herkunft->set_flags(GTK_CAN_FOCUS);
   checkbutton_herkunft->set_mode(true);
   checkbutton_herkunft->set_active(false);
   checkbutton_typ->set_flags(GTK_CAN_FOCUS);
   checkbutton_typ->set_mode(true);
   checkbutton_typ->set_active(false);
   checkbutton_werte->set_flags(GTK_CAN_FOCUS);
   checkbutton_werte->set_mode(true);
   checkbutton_werte->set_active(false);
   checkbutton_st->set_flags(GTK_CAN_FOCUS);
   checkbutton_st->set_mode(true);
   checkbutton_st->set_active(false);
   checkbutton_gs->set_flags(GTK_CAN_FOCUS);
   checkbutton_gs->set_mode(true);
   checkbutton_gs->set_active(false);
   checkbutton_gw->set_flags(GTK_CAN_FOCUS);
   checkbutton_gw->set_mode(true);
   checkbutton_gw->set_active(false);
   checkbutton_ko->set_flags(GTK_CAN_FOCUS);
   checkbutton_ko->set_mode(true);
   checkbutton_ko->set_active(false);
   checkbutton_in->set_flags(GTK_CAN_FOCUS);
   checkbutton_in->set_mode(true);
   checkbutton_in->set_active(false);
   checkbutton_zt->set_flags(GTK_CAN_FOCUS);
   checkbutton_zt->set_mode(true);
   checkbutton_zt->set_active(false);
   checkbutton_au->set_flags(GTK_CAN_FOCUS);
   checkbutton_au->set_mode(true);
   checkbutton_au->set_active(false);
   checkbutton_pa->set_flags(GTK_CAN_FOCUS);
   checkbutton_pa->set_mode(true);
   checkbutton_pa->set_active(false);
   checkbutton_wk->set_flags(GTK_CAN_FOCUS);
   checkbutton_wk->set_mode(true);
   checkbutton_wk->set_active(false);
   checkbutton_sb->set_flags(GTK_CAN_FOCUS);
   checkbutton_sb->set_mode(true);
   checkbutton_sb->set_active(false);
   checkbutton_b->set_flags(GTK_CAN_FOCUS);
   checkbutton_b->set_mode(true);
   checkbutton_b->set_active(false);
   table168->set_row_spacings(0);
   table168->set_col_spacings(0);
   table168->attach(*checkbutton_st, 0, 1, 0, 1, GTK_FILL, 0, 0, 0);
   table168->attach(*checkbutton_gs, 0, 1, 1, 2, GTK_FILL, 0, 0, 0);
   table168->attach(*checkbutton_gw, 0, 1, 2, 3, GTK_FILL, 0, 0, 0);
   table168->attach(*checkbutton_ko, 0, 1, 3, 4, GTK_FILL, 0, 0, 0);
   table168->attach(*checkbutton_in, 0, 1, 4, 5, GTK_FILL, 0, 0, 0);
   table168->attach(*checkbutton_zt, 0, 1, 5, 6, GTK_FILL, 0, 0, 0);
   table168->attach(*checkbutton_au, 1, 2, 0, 1, GTK_FILL, 0, 0, 0);
   table168->attach(*checkbutton_pa, 1, 2, 1, 2, GTK_FILL, 0, 0, 0);
   table168->attach(*checkbutton_wk, 1, 2, 2, 3, GTK_FILL, 0, 0, 0);
   table168->attach(*checkbutton_sb, 1, 2, 3, 4, GTK_FILL, 0, 0, 0);
   table168->attach(*checkbutton_b, 1, 2, 4, 5, GTK_FILL, 0, 0, 0);
   frame_werte_vorgaben->set_shadow_type(GTK_SHADOW_ETCHED_IN);
   frame_werte_vorgaben->set_label_align(0,0);
   frame_werte_vorgaben->add(*table168);
   table166->set_row_spacings(0);
   table166->set_col_spacings(0);
   table166->attach(*checkbutton_spezies, 0, 1, 0, 1, GTK_FILL, 0, 0, 0);
   table166->attach(*checkbutton_herkunft, 0, 1, 3, 4, GTK_FILL, 0, 0, 0);
   table166->attach(*checkbutton_typ, 0, 1, 2, 3, GTK_FILL, 0, 0, 0);
   table166->attach(*checkbutton_werte, 0, 1, 1, 2, GTK_FILL, 0, 0, 0);
   table166->attach(*frame_werte_vorgaben, 1, 2, 0, 4, GTK_EXPAND|GTK_FILL, GTK_FILL, 0, 0);
   frame_vorgaben->set_shadow_type(GTK_SHADOW_ETCHED_IN);
   frame_vorgaben->set_label_align(0,0);
   frame_vorgaben->add(*table166);
   table165->set_row_spacings(0);
   table165->set_col_spacings(0);
   table165->attach(*togglebutton_vorgaben, 0, 1, 0, 1, GTK_FILL, 0, 0, 0);
   table165->attach(*frame_vorgaben, 0, 1, 1, 2, GTK_FILL, GTK_EXPAND|GTK_FILL, 0, 0);
   table_zufall->set_row_spacings(0);
   table_zufall->set_col_spacings(0);
   table_zufall->attach(*button_zufall_voll, 0, 1, 0, 1, GTK_FILL, 0, 0, 0);
   table_zufall->attach(*table165, 1, 2, 0, 1, GTK_EXPAND|GTK_FILL, GTK_FILL, 0, 0);
   button_zufall_voll->show();
   togglebutton_vorgaben->show();
   checkbutton_spezies->show();
   checkbutton_herkunft->show();
   checkbutton_typ->show();
   checkbutton_werte->show();
   checkbutton_st->show();
   checkbutton_gs->show();
   checkbutton_gw->show();
   checkbutton_ko->show();
   checkbutton_in->show();
   checkbutton_zt->show();
   checkbutton_au->show();
   checkbutton_pa->show();
   checkbutton_wk->show();
   checkbutton_sb->show();
   checkbutton_b->show();
   table168->show();
   table166->show();
   table165->show();
   table_zufall->show();
   button_zufall_voll->clicked.connect(SigC::slot(static_cast<class table_zufall*>(this), &table_zufall::on_button_zufall_voll_clicked));
   togglebutton_vorgaben->toggled.connect(SigC::slot(static_cast<class table_zufall*>(this), &table_zufall::on_togglebutton_vorgaben_toggled));
   checkbutton_werte->toggled.connect(SigC::slot(static_cast<class table_zufall*>(this), &table_zufall::on_checkbutton_werte_toggled));
}

table_zufall_glade::~table_zufall_glade()
{  
}