// generated 2003/5/5 23:49:44 CEST by christof@puck.petig-baender.de
// using glademm V2.0.0
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- --image-provider=MagusImage midgard.glade
// for gtk 2.2.1 and gtkmm 2.2.1
//
// Please modify the corresponding derived classes in ./src/Midgard_Info.cc


#if defined __GNUC__ && __GNUC__ < 3
#error This program will crash if compiled with g++ 2.x
// see the dynamic_cast bug in the gtkmm FAQ
#endif //
#include "config.h"
#include "Midgard_Info_glade.hh"
#include <gtkmm/image.h>

extern Glib::RefPtr<Gdk::Pixbuf> MagusImage(const std::string &name);

#include <gtkmm/label.h>
#include <gtkmm/box.h>
#include <gtkmm/separator.h>
#include <gtkmm/table.h>
#include <gtkmm/frame.h>
#include <gtkmm/viewport.h>
#include <gtkmm/adjustment.h>

Midgard_Info_glade::Midgard_Info_glade(GlademmData *gmm_data
)
{  Midgard_Info = this;
   
   Gtk::Image *pixmap65 = Gtk::manage(new class Gtk::Image(MagusImage("midgard_logo.xpm")));
   Gtk::Label *label340 = Gtk::manage(new class Gtk::Label("MAGUS\n"
		"(Midgard Abenteuerer Generieren Und Steigern)"));
   versionsnummer = Gtk::manage(new class Gtk::Label("Version: 0.3beta0"));
   
   Gtk::Label *label341 = Gtk::manage(new class Gtk::Label("MIDGARD"));
   frame_regionen = Gtk::manage(new class Gtk::Frame());
   
   Gtk::Label *label406 = Gtk::manage(new class Gtk::Label("Christof Petig"));
   Gtk::Image *pixmap1 = Gtk::manage(new class Gtk::Image(MagusImage("Zauber-trans-50.xpm")));
   Gtk::Image *pixmap3 = Gtk::manage(new class Gtk::Image(MagusImage("Edit-2W6-trans-50.xpm")));
   Gtk::Image *pixmap2 = Gtk::manage(new class Gtk::Image(MagusImage("MAGUS_Logo_Small.xpm")));
   Gtk::Image *pixmap60 = Gtk::manage(new class Gtk::Image(MagusImage("ulf_24_info.xpm")));
   Gtk::Image *pixmap169 = Gtk::manage(new class Gtk::Image(MagusImage("ulf_24_wuerfel.xpm")));
   Gtk::Image *pixmap131 = Gtk::manage(new class Gtk::Image(MagusImage("Helper-50.xpm")));
   Gtk::Label *label329 = Gtk::manage(new class Gtk::Label("Knöpfe, Logo\n"
		"& HTML"));
   Gtk::Label *label331 = Gtk::manage(new class Gtk::Label("Gtk, C++ & xml\n"
		"Unterstützung"));
   Gtk::Label *label327 = Gtk::manage(new class Gtk::Label("Autor"));
   Gtk::Label *label328 = Gtk::manage(new class Gtk::Label("Malte Thoma"));
   Gtk::Label *label332 = Gtk::manage(new class Gtk::Label("Christof Petig"));
   Gtk::Label *label330 = Gtk::manage(new class Gtk::Label("Alessandro Filippetti "));
   Gtk::Label *label407 = Gtk::manage(new class Gtk::Label("M$-Windows\n"
		"portierung"));
   Gtk::Label *label604 = Gtk::manage(new class Gtk::Label("Win32-Icons"));
   Gtk::Label *label605 = Gtk::manage(new class Gtk::Label("Ulf Kaiser"));
   Gtk::Label *label531 = Gtk::manage(new class Gtk::Label("Beim Abtippen der Daten und Testen haben Michael Gruetzki, Nils Richter,\n"
		"Roland Ritthaler Sebastian Horstmann, Joachim Jordan, Stefan Peschl,\n"
		"Sven Rey, Markus Steinberg, Ottmar Zimmer und viele andere geholfen."));
   Gtk::Image *pixmap5 = Gtk::manage(new class Gtk::Image(MagusImage("LoadChar-trans-50.xpm")));
   Gtk::Label *label335 = Gtk::manage(new class Gtk::Label("Download"));
   Gtk::Label *label336 = Gtk::manage(new class Gtk::Label("http://midgard.berlios.de"));
   Gtk::Image *pixmap56 = Gtk::manage(new class Gtk::Image(MagusImage("LoadZaub-trans-50.xpm")));
   Gtk::Label *label399 = Gtk::manage(new class Gtk::Label("CVS Repository"));
   Gtk::Label *label400 = Gtk::manage(new class Gtk::Label("http://developer.berlios.de/projects/midgard/"));
   Gtk::Image *pixmap6 = Gtk::manage(new class Gtk::Image(MagusImage("Lang_Script-trans-50.xpm")));
   Gtk::Label *label337 = Gtk::manage(new class Gtk::Label("Kontakt"));
   Gtk::Label *label338 = Gtk::manage(new class Gtk::Label("midgard-general@lists.berlios.de"));
   Gtk::Label *label401 = Gtk::manage(new class Gtk::Label("MAGUS unterliegt der GNU Public Licence"));
   Gtk::Image *pixmap57 = Gtk::manage(new class Gtk::Image(MagusImage("pinguin.xpm")));
   Gtk::Image *pixmap104 = Gtk::manage(new class Gtk::Image(MagusImage("gnu-haed-trans-32.xpm")));
   Gtk::HBox *hbox56 = Gtk::manage(new class Gtk::HBox(false, 0));
   Gtk::HSeparator *hseparator17 = Gtk::manage(new class Gtk::HSeparator());
   Gtk::Table *table109 = Gtk::manage(new class Gtk::Table(2, 2, false));
   Gtk::Label *label342 = Gtk::manage(new class Gtk::Label("MAGUS"));
   Gtk::Frame *frame99 = Gtk::manage(new class Gtk::Frame());
   progressbar_regionen = Gtk::manage(new class Gtk::ProgressBar());
   
   Gtk::Table *table77 = Gtk::manage(new class Gtk::Table(2, 2, false));
   Gtk::Label *label606 = Gtk::manage(new class Gtk::Label("Laden der Datenbank"));
   frame_datenbank = Gtk::manage(new class Gtk::Frame());
   
   Gtk::Image *pixmap168 = Gtk::manage(new class Gtk::Image(MagusImage("schirm.xpm")));
   Gtk::Table *table149 = Gtk::manage(new class Gtk::Table(2, 2, false));
   Gtk::Image *pixmap154 = Gtk::manage(new class Gtk::Image(MagusImage("GnuHead-trans.xpm")));
   Gtk::Image *pixmap106 = Gtk::manage(new class Gtk::Image(MagusImage("Tux-med.xpm")));
   Gtk::HBox *hbox90 = Gtk::manage(new class Gtk::HBox(false, 0));
   Gtk::Image *pixmap90 = Gtk::manage(new class Gtk::Image(MagusImage("MAGUS-Logo-Text-halb-t3.xpm")));
   Gtk::Table *table167 = Gtk::manage(new class Gtk::Table(2, 2, false));
   Gtk::Table *table49 = Gtk::manage(new class Gtk::Table(2, 2, false));
   Gtk::Viewport *viewport33 = Gtk::manage(new class Gtk::Viewport(*manage(new Gtk::Adjustment(0,0,1)), *manage(new Gtk::Adjustment(0,0,1))));
   pixmap65->set_alignment(0.5,0.5);
   pixmap65->set_padding(0,0);
   label340->set_alignment(0,0.5);
   label340->set_padding(0,0);
   label340->set_justify(Gtk::JUSTIFY_CENTER);
   label340->set_line_wrap(false);
   label340->set_use_markup(false);
   label340->set_selectable(false);
   versionsnummer->set_alignment(0,0.5);
   versionsnummer->set_padding(0,0);
   versionsnummer->set_justify(Gtk::JUSTIFY_CENTER);
   versionsnummer->set_line_wrap(false);
   versionsnummer->set_use_markup(false);
   versionsnummer->set_selectable(false);
   label341->set_alignment(0.5,0.5);
   label341->set_padding(0,0);
   label341->set_justify(Gtk::JUSTIFY_LEFT);
   label341->set_line_wrap(false);
   label341->set_use_markup(false);
   label341->set_selectable(false);
   frame_regionen->set_shadow_type(Gtk::SHADOW_ETCHED_IN);
   frame_regionen->set_label_align(0,0.5);
   frame_regionen->set_label_widget(*label341);
   label406->set_alignment(0,0.5);
   label406->set_padding(0,0);
   label406->set_justify(Gtk::JUSTIFY_CENTER);
   label406->set_line_wrap(false);
   label406->set_use_markup(false);
   label406->set_selectable(false);
   pixmap1->set_alignment(0.5,0.5);
   pixmap1->set_padding(0,0);
   pixmap3->set_alignment(0.5,0.5);
   pixmap3->set_padding(0,0);
   pixmap2->set_alignment(0.5,0.5);
   pixmap2->set_padding(0,0);
   pixmap60->set_alignment(0.5,0.5);
   pixmap60->set_padding(0,0);
   pixmap169->set_alignment(0.5,0.5);
   pixmap169->set_padding(0,0);
   pixmap131->set_alignment(0.5,0.5);
   pixmap131->set_padding(0,0);
   label329->set_alignment(0,0.5);
   label329->set_padding(0,0);
   label329->set_justify(Gtk::JUSTIFY_CENTER);
   label329->set_line_wrap(false);
   label329->set_use_markup(false);
   label329->set_selectable(false);
   label331->set_alignment(0,0.5);
   label331->set_padding(0,0);
   label331->set_justify(Gtk::JUSTIFY_LEFT);
   label331->set_line_wrap(false);
   label331->set_use_markup(false);
   label331->set_selectable(false);
   label327->set_alignment(0,0.5);
   label327->set_padding(0,0);
   label327->set_justify(Gtk::JUSTIFY_LEFT);
   label327->set_line_wrap(true);
   label327->set_use_markup(false);
   label327->set_selectable(false);
   label328->set_alignment(0,0.5);
   label328->set_padding(0,0);
   label328->set_justify(Gtk::JUSTIFY_CENTER);
   label328->set_line_wrap(false);
   label328->set_use_markup(false);
   label328->set_selectable(false);
   label332->set_alignment(0,0.5);
   label332->set_padding(0,0);
   label332->set_justify(Gtk::JUSTIFY_CENTER);
   label332->set_line_wrap(false);
   label332->set_use_markup(false);
   label332->set_selectable(false);
   label330->set_alignment(0,0.5);
   label330->set_padding(0,0);
   label330->set_justify(Gtk::JUSTIFY_CENTER);
   label330->set_line_wrap(false);
   label330->set_use_markup(false);
   label330->set_selectable(false);
   label407->set_alignment(0,0.5);
   label407->set_padding(0,0);
   label407->set_justify(Gtk::JUSTIFY_CENTER);
   label407->set_line_wrap(false);
   label407->set_use_markup(false);
   label407->set_selectable(false);
   label604->set_alignment(0,0.5);
   label604->set_padding(0,0);
   label604->set_justify(Gtk::JUSTIFY_CENTER);
   label604->set_line_wrap(false);
   label604->set_use_markup(false);
   label604->set_selectable(false);
   label605->set_alignment(0,0.5);
   label605->set_padding(0,0);
   label605->set_justify(Gtk::JUSTIFY_CENTER);
   label605->set_line_wrap(false);
   label605->set_use_markup(false);
   label605->set_selectable(false);
   label531->set_alignment(0,0.5);
   label531->set_padding(0,0);
   label531->set_justify(Gtk::JUSTIFY_LEFT);
   label531->set_line_wrap(false);
   label531->set_use_markup(false);
   label531->set_selectable(false);
   pixmap5->set_alignment(0.5,0.5);
   pixmap5->set_padding(0,0);
   label335->set_alignment(0,0.5);
   label335->set_padding(0,0);
   label335->set_justify(Gtk::JUSTIFY_CENTER);
   label335->set_line_wrap(false);
   label335->set_use_markup(false);
   label335->set_selectable(false);
   label336->set_alignment(0,0.5);
   label336->set_padding(0,0);
   label336->set_justify(Gtk::JUSTIFY_CENTER);
   label336->set_line_wrap(false);
   label336->set_use_markup(false);
   label336->set_selectable(false);
   pixmap56->set_alignment(0.5,0.5);
   pixmap56->set_padding(0,0);
   label399->set_alignment(0,0.5);
   label399->set_padding(0,0);
   label399->set_justify(Gtk::JUSTIFY_CENTER);
   label399->set_line_wrap(false);
   label399->set_use_markup(false);
   label399->set_selectable(false);
   label400->set_alignment(0,0.5);
   label400->set_padding(0,0);
   label400->set_justify(Gtk::JUSTIFY_CENTER);
   label400->set_line_wrap(false);
   label400->set_use_markup(false);
   label400->set_selectable(false);
   pixmap6->set_alignment(0.5,0.5);
   pixmap6->set_padding(0,0);
   label337->set_alignment(0,0.5);
   label337->set_padding(0,0);
   label337->set_justify(Gtk::JUSTIFY_CENTER);
   label337->set_line_wrap(false);
   label337->set_use_markup(false);
   label337->set_selectable(false);
   label338->set_alignment(0,0.5);
   label338->set_padding(0,0);
   label338->set_justify(Gtk::JUSTIFY_CENTER);
   label338->set_line_wrap(false);
   label338->set_use_markup(false);
   label338->set_selectable(false);
   label401->set_alignment(0,0.5);
   label401->set_padding(0,0);
   label401->set_justify(Gtk::JUSTIFY_CENTER);
   label401->set_line_wrap(false);
   label401->set_use_markup(false);
   label401->set_selectable(false);
   pixmap57->set_alignment(0.5,0.5);
   pixmap57->set_padding(0,0);
   pixmap104->set_alignment(0.5,0.5);
   pixmap104->set_padding(0,0);
   hbox56->pack_start(*pixmap57, Gtk::PACK_SHRINK, 0);
   hbox56->pack_start(*pixmap104, Gtk::PACK_SHRINK, 0);
   table109->set_row_spacings(3);
   table109->set_col_spacings(5);
   table109->attach(*label406, 2, 3, 3, 4, Gtk::FILL, Gtk::AttachOptions(), 0, 0);
   table109->attach(*pixmap1, 0, 1, 0, 1, Gtk::SHRINK|Gtk::FILL, Gtk::SHRINK, 0, 0);
   table109->attach(*pixmap3, 0, 1, 1, 2, Gtk::SHRINK|Gtk::FILL, Gtk::SHRINK, 0, 0);
   table109->attach(*pixmap2, 0, 1, 2, 3, Gtk::SHRINK|Gtk::FILL, Gtk::SHRINK, 0, 0);
   table109->attach(*pixmap60, 0, 1, 3, 4, Gtk::SHRINK|Gtk::FILL, Gtk::SHRINK, 0, 0);
   table109->attach(*pixmap169, 0, 1, 4, 5, Gtk::SHRINK|Gtk::FILL, Gtk::SHRINK, 0, 0);
   table109->attach(*pixmap131, 0, 1, 5, 6, Gtk::SHRINK|Gtk::FILL, Gtk::SHRINK, 0, 0);
   table109->attach(*label329, 1, 2, 2, 3, Gtk::SHRINK|Gtk::FILL, Gtk::SHRINK, 0, 0);
   table109->attach(*label331, 1, 2, 1, 2, Gtk::SHRINK|Gtk::FILL, Gtk::SHRINK, 0, 0);
   table109->attach(*label327, 1, 2, 0, 1, Gtk::SHRINK|Gtk::FILL, Gtk::SHRINK, 0, 0);
   table109->attach(*label328, 2, 3, 0, 1, Gtk::SHRINK|Gtk::FILL, Gtk::SHRINK, 0, 0);
   table109->attach(*label332, 2, 3, 1, 2, Gtk::SHRINK|Gtk::FILL, Gtk::SHRINK, 0, 0);
   table109->attach(*label330, 2, 3, 2, 3, Gtk::SHRINK|Gtk::FILL, Gtk::SHRINK, 0, 0);
   table109->attach(*label407, 1, 2, 3, 4, Gtk::SHRINK|Gtk::FILL, Gtk::SHRINK, 0, 0);
   table109->attach(*label604, 1, 2, 4, 5, Gtk::SHRINK|Gtk::FILL, Gtk::SHRINK, 0, 0);
   table109->attach(*label605, 2, 3, 4, 5, Gtk::SHRINK|Gtk::FILL, Gtk::SHRINK, 0, 0);
   table109->attach(*label531, 1, 3, 5, 6, Gtk::SHRINK|Gtk::FILL, Gtk::SHRINK, 0, 0);
   table109->attach(*pixmap5, 0, 1, 7, 8, Gtk::SHRINK|Gtk::FILL, Gtk::SHRINK, 0, 0);
   table109->attach(*label335, 1, 2, 7, 8, Gtk::SHRINK|Gtk::FILL, Gtk::SHRINK, 0, 0);
   table109->attach(*label336, 2, 3, 7, 8, Gtk::SHRINK|Gtk::FILL, Gtk::SHRINK, 0, 0);
   table109->attach(*pixmap56, 0, 1, 8, 9, Gtk::SHRINK|Gtk::FILL, Gtk::SHRINK, 0, 0);
   table109->attach(*label399, 1, 2, 8, 9, Gtk::SHRINK|Gtk::FILL, Gtk::SHRINK, 0, 0);
   table109->attach(*label400, 2, 3, 8, 9, Gtk::SHRINK|Gtk::FILL, Gtk::SHRINK, 0, 0);
   table109->attach(*pixmap6, 0, 1, 9, 10, Gtk::SHRINK|Gtk::FILL, Gtk::SHRINK, 0, 0);
   table109->attach(*label337, 1, 2, 9, 10, Gtk::SHRINK|Gtk::FILL, Gtk::SHRINK, 0, 0);
   table109->attach(*label338, 2, 3, 9, 10, Gtk::SHRINK|Gtk::FILL, Gtk::SHRINK, 0, 0);
   table109->attach(*label401, 1, 3, 10, 11, Gtk::SHRINK|Gtk::FILL, Gtk::SHRINK, 0, 0);
   table109->attach(*hbox56, 0, 1, 10, 11, Gtk::SHRINK|Gtk::FILL, Gtk::SHRINK, 0, 0);
   table109->attach(*hseparator17, 0, 3, 6, 7, Gtk::SHRINK|Gtk::FILL, Gtk::SHRINK, 0, 0);
   label342->set_alignment(0.5,0.5);
   label342->set_padding(0,0);
   label342->set_justify(Gtk::JUSTIFY_LEFT);
   label342->set_line_wrap(false);
   label342->set_use_markup(false);
   label342->set_selectable(false);
   frame99->set_shadow_type(Gtk::SHADOW_ETCHED_IN);
   frame99->set_label_align(0,0.5);
   frame99->add(*table109);
   frame99->set_label_widget(*label342);
   table77->set_row_spacings(0);
   table77->set_col_spacings(0);
   table77->attach(*progressbar_regionen, 0, 6, 0, 1, Gtk::EXPAND|Gtk::FILL, Gtk::AttachOptions(), 0, 0);
   label606->set_alignment(0.5,0.5);
   label606->set_padding(0,0);
   label606->set_justify(Gtk::JUSTIFY_LEFT);
   label606->set_line_wrap(false);
   label606->set_use_markup(false);
   label606->set_selectable(false);
   frame_datenbank->set_shadow_type(Gtk::SHADOW_ETCHED_IN);
   frame_datenbank->set_label_align(0,0.5);
   frame_datenbank->add(*table77);
   frame_datenbank->set_label_widget(*label606);
   pixmap168->set_alignment(0.5,0.5);
   pixmap168->set_padding(0,0);
   table149->set_row_spacings(0);
   table149->set_col_spacings(0);
   table149->attach(*pixmap168, 1, 2, 0, 1, Gtk::EXPAND|Gtk::FILL, Gtk::FILL, 0, 0);
   pixmap154->set_alignment(0.5,0.5);
   pixmap154->set_padding(0,0);
   pixmap106->set_alignment(0.5,0.5);
   pixmap106->set_padding(0,0);
   hbox90->pack_start(*pixmap154);
   hbox90->pack_start(*pixmap106);
   pixmap90->set_alignment(0.5,0.5);
   pixmap90->set_padding(0,0);
   table167->set_row_spacings(0);
   table167->set_col_spacings(0);
   table167->attach(*hbox90, 0, 1, 0, 1, Gtk::FILL, Gtk::EXPAND|Gtk::FILL, 0, 0);
   table167->attach(*pixmap90, 0, 1, 1, 2, Gtk::SHRINK, Gtk::EXPAND|Gtk::SHRINK|Gtk::FILL, 0, 0);
   table49->set_row_spacings(0);
   table49->set_col_spacings(0);
   table49->attach(*pixmap65, 0, 1, 0, 1, Gtk::FILL, Gtk::FILL, 0, 0);
   table49->attach(*label340, 0, 1, 1, 2, Gtk::AttachOptions(), Gtk::AttachOptions(), 5, 5);
   table49->attach(*versionsnummer, 0, 1, 2, 3, Gtk::AttachOptions(), Gtk::AttachOptions(), 0, 0);
   table49->attach(*frame_regionen, 1, 2, 5, 6, Gtk::FILL, Gtk::FILL, 0, 0);
   table49->attach(*frame99, 0, 1, 5, 6, Gtk::FILL, Gtk::FILL, 0, 0);
   table49->attach(*frame_datenbank, 0, 2, 4, 5, Gtk::FILL, Gtk::EXPAND|Gtk::SHRINK|Gtk::FILL, 0, 0);
   table49->attach(*table149, 0, 1, 3, 4, Gtk::AttachOptions(), Gtk::AttachOptions(), 0, 0);
   table49->attach(*table167, 1, 2, 0, 4, Gtk::FILL, Gtk::FILL, 0, 0);
   viewport33->set_shadow_type(Gtk::SHADOW_NONE);
   viewport33->add(*table49);
   Midgard_Info->set_shadow_type(Gtk::SHADOW_NONE);
   Midgard_Info->set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
   Midgard_Info->property_window_placement().set_value(Gtk::CORNER_TOP_LEFT);
   Midgard_Info->add(*viewport33);
   pixmap65->show();
   label340->show();
   versionsnummer->show();
   label341->show();
   frame_regionen->show();
   label406->show();
   pixmap1->show();
   pixmap3->show();
   pixmap2->show();
   pixmap60->show();
   pixmap169->show();
   pixmap131->show();
   label329->show();
   label331->show();
   label327->show();
   label328->show();
   label332->show();
   label330->show();
   label407->show();
   label604->show();
   label605->show();
   label531->show();
   pixmap5->show();
   label335->show();
   label336->show();
   pixmap56->show();
   label399->show();
   label400->show();
   pixmap6->show();
   label337->show();
   label338->show();
   label401->show();
   pixmap57->show();
   pixmap104->show();
   hbox56->show();
   hseparator17->show();
   table109->show();
   label342->show();
   frame99->show();
   progressbar_regionen->show();
   table77->show();
   label606->show();
   frame_datenbank->show();
   pixmap168->show();
   table149->show();
   pixmap154->show();
   pixmap106->show();
   hbox90->show();
   pixmap90->show();
   table167->show();
   table49->show();
   viewport33->show();
   Midgard_Info->show();
}

Midgard_Info_glade::~Midgard_Info_glade()
{  
}
