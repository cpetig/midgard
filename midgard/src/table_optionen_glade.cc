// generated 2002/10/25 22:56:22 CEST by thoma@Tiger.(none)
// using glademm V1.1.1c_cvs
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- /home/thoma/rollenspiel/midgard/programme/gcc_3.0/midgard/midgard.glade
// for gtk 1.2.10 and gtkmm 1.2.10
//
// Please modify the corresponding derived classes in ./src/table_optionen.cc

#include "config.h"
#include "table_optionen.hh"
#include <gtk--/label.h>
#include <gtk--/adjustment.h>
#include <gtk--/button.h>
#include <gtk--/table.h>

table_optionen_glade::table_optionen_glade(GlademmData *_data
) : Gtk::Table(1, 1, false)
{  table_optionen = this;
   frame_globale_optionen = manage(new class frame_globale_optionen(_data));
   frame_ansicht = manage(new class frame_ansicht(_data));
   
   Gtk::Label *label578 = manage(new class Gtk::Label("HTML-Browser (f�r Hilfe)"));
   Gtk::Label *label576 = manage(new class Gtk::Label("Tempor�res Verzeichnis"));
   Gtk::Label *label577 = manage(new class Gtk::Label("Speichern"));
   Gtk::Label *label575 = manage(new class Gtk::Label("Pfade"));
   entry_html = manage(new class Gtk::Entry());
   entry_tmp_verz = manage(new class Gtk::Entry());
   entry_speicher_verz = manage(new class Gtk::Entry());
   
   Gtk::Label *label599 = manage(new class Gtk::Label("Anzahl der Dateien in der History"));
   Gtk::Adjustment *spinbutton_datei_history_adj = manage(new class Gtk::Adjustment(1, 0, 9, 1, 10, 10));
   spinbutton_datei_history = manage(new class Gtk::SpinButton(*spinbutton_datei_history_adj, 1, 0));
   
   Gtk::Button *button_html_browser = manage(new class Gtk::Button("..."));
   Gtk::Button *button_tmp = manage(new class Gtk::Button("..."));
   Gtk::Button *button_speicherplatz = manage(new class Gtk::Button("..."));
   Gtk::Table *table147 = manage(new class Gtk::Table(5, 3, false));
   frame_drucken = manage(new class frame_drucken(_data));
   frame_icons = manage(new class frame_icons(_data));
   
   Gtk::Table *table146 = manage(new class Gtk::Table(3, 4, false));
   label578->set_alignment(0,0.5);
   label578->set_padding(0,0);
   label578->set_justify(GTK_JUSTIFY_CENTER);
   label578->set_line_wrap(false);
   label576->set_alignment(0,0.5);
   label576->set_padding(0,0);
   label576->set_justify(GTK_JUSTIFY_CENTER);
   label576->set_line_wrap(false);
   label577->set_alignment(0,0.5);
   label577->set_padding(0,0);
   label577->set_justify(GTK_JUSTIFY_CENTER);
   label577->set_line_wrap(false);
   label575->set_alignment(0.5,0.5);
   label575->set_padding(0,0);
   label575->set_justify(GTK_JUSTIFY_LEFT);
   label575->set_line_wrap(false);
   entry_html->set_flags(GTK_CAN_FOCUS);
   entry_html->set_visibility(true);
   entry_html->set_editable(true);
   entry_html->set_text("mozilla ");
   entry_tmp_verz->set_flags(GTK_CAN_FOCUS);
   entry_tmp_verz->set_visibility(true);
   entry_tmp_verz->set_editable(true);
   entry_tmp_verz->set_text("$TEMP");
   entry_speicher_verz->set_flags(GTK_CAN_FOCUS);
   entry_speicher_verz->set_visibility(true);
   entry_speicher_verz->set_editable(true);
   entry_speicher_verz->set_text("~/magus");
   label599->set_alignment(0,0.5);
   label599->set_padding(0,0);
   label599->set_justify(GTK_JUSTIFY_LEFT);
   label599->set_line_wrap(false);
   spinbutton_datei_history->set_flags(GTK_CAN_FOCUS);
   spinbutton_datei_history->set_update_policy(GTK_UPDATE_ALWAYS);
   spinbutton_datei_history->set_numeric(false);
   spinbutton_datei_history->set_digits(0);
   spinbutton_datei_history->set_wrap(false);
   spinbutton_datei_history->set_snap_to_ticks(false);
   button_html_browser->set_flags(GTK_CAN_FOCUS);
   button_html_browser->set_relief(GTK_RELIEF_NORMAL);
   button_tmp->set_flags(GTK_CAN_FOCUS);
   button_tmp->set_relief(GTK_RELIEF_NORMAL);
   button_speicherplatz->set_flags(GTK_CAN_FOCUS);
   button_speicherplatz->set_relief(GTK_RELIEF_NORMAL);
   table147->set_row_spacings(0);
   table147->set_col_spacings(3);
   table147->attach(*label578, 0, 1, 0, 1, GTK_FILL, 0, 0, 0);
   table147->attach(*label576, 0, 1, 2, 3, GTK_FILL, 0, 0, 0);
   table147->attach(*label577, 0, 1, 3, 4, GTK_FILL, 0, 0, 0);
   table147->attach(*label575, 0, 2, 1, 2, GTK_FILL, 0, 0, 0);
   table147->attach(*entry_html, 1, 2, 0, 1, GTK_FILL, 0, 0, 0);
   table147->attach(*entry_tmp_verz, 1, 2, 2, 3, GTK_FILL, 0, 0, 0);
   table147->attach(*entry_speicher_verz, 1, 2, 3, 4, GTK_FILL, 0, 0, 0);
   table147->attach(*label599, 0, 1, 4, 5, GTK_FILL, 0, 0, 0);
   table147->attach(*spinbutton_datei_history, 1, 2, 4, 5, GTK_EXPAND|GTK_SHRINK|GTK_FILL, 0, 0, 0);
   table147->attach(*button_html_browser, 2, 3, 0, 1, 0, 0, 0, 0);
   table147->attach(*button_tmp, 2, 3, 2, 3, GTK_FILL, 0, 0, 0);
   table147->attach(*button_speicherplatz, 2, 3, 3, 4, GTK_FILL, 0, 0, 0);
   table146->set_row_spacings(0);
   table146->set_col_spacings(0);
   table146->attach(*frame_globale_optionen, 0, 1, 0, 1, GTK_EXPAND|GTK_SHRINK|GTK_FILL, GTK_EXPAND|GTK_SHRINK|GTK_FILL, 0, 0);
   table146->attach(*frame_ansicht, 1, 2, 0, 1, GTK_FILL, GTK_FILL, 0, 0);
   table146->attach(*table147, 0, 2, 1, 2, GTK_FILL, GTK_FILL, 0, 3);
   table146->attach(*frame_drucken, 3, 4, 0, 1, GTK_EXPAND|GTK_FILL, GTK_FILL, 0, 0);
   table146->attach(*frame_icons, 2, 3, 0, 1, GTK_EXPAND|GTK_SHRINK|GTK_FILL, GTK_FILL, 0, 0);
   table_optionen->set_row_spacings(0);
   table_optionen->set_col_spacings(0);
   table_optionen->attach(*table146, 0, 1, 0, 1, GTK_FILL, GTK_FILL, 0, 0);
   label578->show();
   label576->show();
   label577->show();
   label575->show();
   entry_html->show();
   entry_tmp_verz->show();
   entry_speicher_verz->show();
   label599->show();
   spinbutton_datei_history->show();
   button_html_browser->show();
   button_tmp->show();
   button_speicherplatz->show();
   table147->show();
   table146->show();
   table_optionen->show();
   entry_html->changed.connect(SigC::slot(static_cast<class table_optionen*>(this), &table_optionen::on_entry_html_changed));
   entry_tmp_verz->changed.connect(SigC::slot(static_cast<class table_optionen*>(this), &table_optionen::on_entry_tmp_verz_changed));
   entry_speicher_verz->changed.connect(SigC::slot(static_cast<class table_optionen*>(this), &table_optionen::on_entry_speicher_verz_changed));
   spinbutton_datei_history->changed.connect(SigC::slot(static_cast<class table_optionen*>(this), &table_optionen::on_spinbutton_datei_history_changed));
   button_html_browser->clicked.connect(SigC::slot(static_cast<class table_optionen*>(this), &table_optionen::on_button_html_browser_clicked));
   button_tmp->clicked.connect(SigC::slot(static_cast<class table_optionen*>(this), &table_optionen::on_button_tmp_clicked));
   button_speicherplatz->clicked.connect(SigC::slot(static_cast<class table_optionen*>(this), &table_optionen::on_button_speicherplatz_clicked));
}

table_optionen_glade::~table_optionen_glade()
{  
}
