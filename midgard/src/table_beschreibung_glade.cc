// generated 2006/8/14 10:07:53 CEST by christof@vesta.petig-baender.de
// using glademm V2.12.1
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- --image-provider=MagusImage --gtkmmversion 2.4.0 midgard.glade
// for gtk 2.10.1 and gtkmm 2.4.0
//
// Please modify the corresponding derived classes in ./src/table_beschreibung.cc


#if defined __GNUC__ && __GNUC__ < 3
#error This program will crash if compiled with g++ 2.x
// see the dynamic_cast bug in the gtkmm FAQ
#endif //
#include "config.h"
#include <gtkmmconfig.h>
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>2
#include <sigc++/compatibility.h>
#include <sigc++/bind.h>
#define GMM_GTKMM_22_24(a,b) b
#else //gtkmm 2.2
#define GMM_GTKMM_22_24(a,b) a
#endif //
#include "table_beschreibung_glade.hh"
#include <gtkmm/image.h>

extern Glib::RefPtr<Gdk::Pixbuf> MagusImage(const std::string &name);

#include <gtkmm/label.h>
#include <gtkmm/box.h>
#include <gtkmm/adjustment.h>
#include <gtkmm/table.h>
#include <gtkmm/viewport.h>
#include <gtkmm/scrolledwindow.h>
#include <gtkmm/button.h>
#include <gtkmm/frame.h>

table_beschreibung_glade::table_beschreibung_glade(GlademmData *gmm_data
) : Gtk::Table(2, 2, false)
{  table_beschreibung = this;
   
   Gtk::Image *pixmap147 = Gtk::manage(new class Gtk::Image(MagusImage("PrintChar-trans-50.xpm")));
   Gtk::Label *label566 = Gtk::manage(new class Gtk::Label("Beschreibung\n"
		"Drucken"));
   Gtk::HBox *hbox70 = Gtk::manage(new class Gtk::HBox(false, 0));
   button_beschreibung_drucken = Gtk::manage(new class Gtk::Button());
   grafik_image = Gtk::manage(new class Gtk::Image(MagusImage("Portrait-32.xpm")));
   label_grafik = Gtk::manage(new class Gtk::Label("Abbildung"));
   
   Gtk::HBox *hbox71 = Gtk::manage(new class Gtk::HBox(false, 0));
   button_grafik = Gtk::manage(new class Gtk::Button());
   
   Gtk::Label *label398 = Gtk::manage(new class Gtk::Label("(Die Abenteurerbeschreibung darf sämtliche LaTeX Befehle enthalten)"));
   Gtk::Label *label567 = Gtk::manage(new class Gtk::Label("Breite des Bildes"));
   Gtk::Adjustment *spinbutton_pix_breite_adj = Gtk::manage(new class Gtk::Adjustment(8, 3, 13, 1, 10, 10));
   spinbutton_pix_breite = Gtk::manage(new class Gtk::SpinButton(*spinbutton_pix_breite_adj, 1, 0));
   
   Gtk::Label *label568 = Gtk::manage(new class Gtk::Label("cm"));
   Gtk::Table *table135 = Gtk::manage(new class Gtk::Table(2, 2, false));
   Gtk::Table *table134 = Gtk::manage(new class Gtk::Table(2, 2, false));
   text_charakter_beschreibung = Gtk::manage(new class Gtk::TextView());
   
   Gtk::Viewport *viewport43 = Gtk::manage(new class Gtk::Viewport(*manage(new Gtk::Adjustment(0,0,1)), *manage(new Gtk::Adjustment(0,0,1))));
   Gtk::ScrolledWindow *scrolledwindow80 = Gtk::manage(new class Gtk::ScrolledWindow());
   Gtk::Label *label636 = Gtk::manage(new class Gtk::Label(""));
   Gtk::Button *button_fett = Gtk::manage(new class Gtk::Button("Fett"));
   Gtk::Button *button_kursiv = Gtk::manage(new class Gtk::Button("Kursiv"));
   Gtk::Button *button_liste = Gtk::manage(new class Gtk::Button("Liste"));
   Gtk::Button *button_liste2 = Gtk::manage(new class Gtk::Button("2.Liste"));
   Gtk::Table *table179 = Gtk::manage(new class Gtk::Table(2, 2, true));
   Gtk::Label *label673 = Gtk::manage(new class Gtk::Label("Formatierungen"));
   Gtk::Frame *frame118 = Gtk::manage(new class Gtk::Frame());
   pixmap147->set_alignment(0.5,0.5);
   pixmap147->set_padding(0,0);
   label566->set_alignment(0.5,0.5);
   label566->set_padding(0,0);
   label566->set_justify(Gtk::JUSTIFY_CENTER);
   label566->set_ellipsize(Pango::ELLIPSIZE_NONE);
   hbox70->pack_start(*pixmap147, Gtk::PACK_SHRINK, 0);
   hbox70->pack_start(*label566, Gtk::PACK_SHRINK, 0);
   button_beschreibung_drucken->set_flags(Gtk::CAN_FOCUS);
   button_beschreibung_drucken->set_relief(Gtk::RELIEF_NORMAL);
   button_beschreibung_drucken->add(*hbox70);
   grafik_image->set_alignment(0.5,0.5);
   grafik_image->set_padding(0,0);
   label_grafik->set_alignment(0.5,0.5);
   label_grafik->set_padding(0,0);
   label_grafik->set_justify(Gtk::JUSTIFY_CENTER);
   label_grafik->set_ellipsize(Pango::ELLIPSIZE_NONE);
   hbox71->pack_start(*grafik_image);
   hbox71->pack_start(*label_grafik, Gtk::PACK_SHRINK, 0);
   button_grafik->set_flags(Gtk::CAN_FOCUS);
   _tooltips.set_tip(*button_grafik, "Grafik hinzufügen/wegnehmen.", "");
   button_grafik->set_relief(Gtk::RELIEF_NORMAL);
   button_grafik->add(*hbox71);
   label398->set_alignment(0,0.5);
   label398->set_padding(0,0);
   label398->set_justify(Gtk::JUSTIFY_CENTER);
   label398->set_ellipsize(Pango::ELLIPSIZE_NONE);
   label567->set_alignment(0,0.5);
   label567->set_padding(0,0);
   label567->set_justify(Gtk::JUSTIFY_CENTER);
   label567->set_ellipsize(Pango::ELLIPSIZE_NONE);
   spinbutton_pix_breite->set_flags(Gtk::CAN_FOCUS);
   spinbutton_pix_breite->set_update_policy(Gtk::UPDATE_ALWAYS);
   label568->set_alignment(0,0.5);
   label568->set_padding(0,0);
   label568->set_justify(Gtk::JUSTIFY_CENTER);
   label568->set_ellipsize(Pango::ELLIPSIZE_NONE);
   table135->attach(*label567, 0, 2, 0, 1, Gtk::FILL, Gtk::AttachOptions(), 0, 0);
   table135->attach(*spinbutton_pix_breite, 0, 1, 1, 2, Gtk::AttachOptions(), Gtk::AttachOptions(), 0, 0);
   table135->attach(*label568, 1, 2, 1, 2, Gtk::FILL, Gtk::AttachOptions(), 0, 0);
   table134->attach(*button_beschreibung_drucken, 0, 1, 0, 1, Gtk::AttachOptions(), Gtk::AttachOptions(), 0, 0);
   table134->attach(*button_grafik, 1, 2, 0, 1, Gtk::AttachOptions(), Gtk::AttachOptions(), 0, 0);
   table134->attach(*label398, 0, 3, 1, 2, Gtk::FILL, Gtk::AttachOptions(), 0, 0);
   table134->attach(*table135, 2, 3, 0, 1, Gtk::FILL, Gtk::FILL, 0, 0);
   text_charakter_beschreibung->set_flags(Gtk::CAN_FOCUS);
   text_charakter_beschreibung->set_wrap_mode(Gtk::WRAP_WORD);
   text_charakter_beschreibung->set_justification(Gtk::JUSTIFY_LEFT);
   viewport43->set_shadow_type(Gtk::SHADOW_NONE);
   viewport43->add(*text_charakter_beschreibung);
   scrolledwindow80->set_shadow_type(Gtk::SHADOW_NONE);
   scrolledwindow80->set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
   scrolledwindow80->property_window_placement().set_value(Gtk::CORNER_TOP_LEFT);
   scrolledwindow80->add(*viewport43);
   label636->set_alignment(0,0.5);
   label636->set_padding(0,0);
   label636->set_justify(Gtk::JUSTIFY_CENTER);
   label636->set_ellipsize(Pango::ELLIPSIZE_NONE);
   button_fett->set_flags(Gtk::CAN_FOCUS);
   button_fett->set_relief(Gtk::RELIEF_NORMAL);
   button_kursiv->set_flags(Gtk::CAN_FOCUS);
   button_kursiv->set_relief(Gtk::RELIEF_NORMAL);
   button_liste->set_flags(Gtk::CAN_FOCUS);
   button_liste->set_relief(Gtk::RELIEF_NORMAL);
   button_liste2->set_flags(Gtk::CAN_FOCUS);
   button_liste2->set_relief(Gtk::RELIEF_NORMAL);
   table179->attach(*button_fett, 0, 1, 0, 1, Gtk::FILL, Gtk::AttachOptions(), 0, 0);
   table179->attach(*button_kursiv, 1, 2, 0, 1, Gtk::FILL, Gtk::AttachOptions(), 0, 0);
   table179->attach(*button_liste, 2, 3, 0, 1, Gtk::FILL, Gtk::AttachOptions(), 0, 0);
   table179->attach(*button_liste2, 3, 4, 0, 1, Gtk::FILL, Gtk::AttachOptions(), 0, 0);
   label673->set_alignment(0.5,0.5);
   label673->set_padding(0,0);
   label673->set_justify(Gtk::JUSTIFY_LEFT);
   label673->set_ellipsize(Pango::ELLIPSIZE_NONE);
   frame118->set_shadow_type(Gtk::SHADOW_ETCHED_IN);
   frame118->set_label_align(0,0.5);
   frame118->add(*table179);
   frame118->set_label_widget(*label673);
   table_beschreibung->attach(*table134, 0, 1, 0, 1, Gtk::SHRINK, Gtk::SHRINK, 0, 6);
   table_beschreibung->attach(*scrolledwindow80, 0, 3, 1, 2, Gtk::EXPAND|Gtk::SHRINK|Gtk::FILL, Gtk::EXPAND|Gtk::SHRINK|Gtk::FILL, 0, 0);
   table_beschreibung->attach(*label636, 2, 3, 0, 1, Gtk::EXPAND|Gtk::SHRINK|Gtk::FILL, Gtk::SHRINK, 0, 0);
   table_beschreibung->attach(*frame118, 1, 2, 0, 1, Gtk::SHRINK, Gtk::SHRINK, 5, 0);
   pixmap147->show();
   label566->show();
   hbox70->show();
   button_beschreibung_drucken->show();
   grafik_image->show();
   label_grafik->show();
   hbox71->show();
   button_grafik->show();
   label398->show();
   label567->show();
   spinbutton_pix_breite->show();
   label568->show();
   table135->show();
   table134->show();
   text_charakter_beschreibung->show();
   viewport43->show();
   scrolledwindow80->show();
   label636->show();
   button_fett->show();
   button_kursiv->show();
   button_liste->show();
   button_liste2->show();
   table179->show();
   label673->show();
   frame118->show();
   table_beschreibung->show();
   button_beschreibung_drucken->signal_clicked().connect(SigC::slot(*this, &table_beschreibung_glade::on_button_beschreibung_drucken_clicked), false);
   button_grafik->signal_clicked().connect(SigC::slot(*this, &table_beschreibung_glade::on_button_grafik), false);
   spinbutton_pix_breite->signal_focus_out_event().connect(SigC::slot(*this, &table_beschreibung_glade::on_spinbutton_pix_breite_focus_out_event), false);
   spinbutton_pix_breite->signal_focus_in_event().connect(SigC::slot(*this, &table_beschreibung_glade::on_spinbutton_pix_breite_focus_in_event), false);
   text_charakter_beschreibung->signal_focus_out_event().connect(SigC::slot(*this, &table_beschreibung_glade::on_text_charakter_beschreibung_focus_out_event), false);
   button_fett->signal_clicked().connect(SigC::slot(*this, &table_beschreibung_glade::on_button_fett_clicked), false);
   button_kursiv->signal_clicked().connect(SigC::slot(*this, &table_beschreibung_glade::on_button_kursiv_clicked), false);
   button_liste->signal_clicked().connect(SigC::slot(*this, &table_beschreibung_glade::on_button_liste_clicked), false);
   button_liste2->signal_clicked().connect(SigC::slot(*this, &table_beschreibung_glade::on_button_liste2_clicked), false);
}

table_beschreibung_glade::~table_beschreibung_glade()
{  
}
