// generated 2002/9/13 14:06:29 CEST by thoma@Tiger.(none)
// using glademm V1.1.1c_cvs
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- /home/thoma/rollenspiel/midgard/programme/gcc_3.0/midgard/midgard.glade
// for gtk 1.2.10 and gtkmm 1.2.10
//
// Please modify the corresponding derived classes in ./src/Midgard_Info.cc

#include "config.h"
#include "Midgard_Info.hh"
#include <gtk--/pixmap.h>
#include "../pixmaps/midgard_logo.xpm"
#include <gtk--/label.h>
#include "../pixmaps/Zauber-trans-50.xpm"
#include "../pixmaps/Edit-2W6-trans-50.xpm"
#include "../pixmaps/MAGUS_Logo_Small.xpm"
#include "../pixmaps/SchliessenIII-50.xpm"
#include <gtk--/separator.h>
#include "../pixmaps/LoadChar-trans-50.xpm"
#include "../pixmaps/LoadZaub-trans-50.xpm"
#include "../pixmaps/Lang_Script-trans-50.xpm"
#include "../pixmaps/Helper-50.xpm"
#include "../pixmaps/pinguin.xpm"
#include "../pixmaps/gnu-haed-trans-32.xpm"
#include <gtk--/box.h>
#include <gtk--/table.h>
#include <gtk--/frame.h>
#include "../pixmaps/schirm.xpm"
#include "../pixmaps/GnuHead-trans.xpm"
#include "../pixmaps/Tux-med.xpm"
#include "../pixmaps/MAGUS-Logo-Text-halb-t3.xpm"
#include <gtk--/viewport.h>

Midgard_Info_glade::Midgard_Info_glade(GlademmData *_data
)
{  Midgard_Info = this;
   
   Gtk::Pixmap *pixmap65 = manage(new class Gtk::Pixmap(midgard_logo_xpm));
   Gtk::Label *label340 = manage(new class Gtk::Label("MAGUS\n"
		"(Midgard Abenteuerer Generieren Und Steigern)"));
   versionsnummer = manage(new class Gtk::Label("Version: 0.3beta0"));
   frame_regionen = manage(new class Gtk::Frame("MIDGARD"));
   
   Gtk::Pixmap *pixmap1 = manage(new class Gtk::Pixmap(Zauber_trans_50_xpm));
   Gtk::Label *label327 = manage(new class Gtk::Label("Autor"));
   Gtk::Label *label328 = manage(new class Gtk::Label("Malte Thoma"));
   Gtk::Pixmap *pixmap3 = manage(new class Gtk::Pixmap(Edit_2W6_trans_50_xpm));
   Gtk::Label *label331 = manage(new class Gtk::Label("Gtk, C++ & xml\n"
		"Unterst�tzung"));
   Gtk::Label *label332 = manage(new class Gtk::Label("Christof Petig"));
   Gtk::Pixmap *pixmap2 = manage(new class Gtk::Pixmap(MAGUS_Logo_Small_xpm));
   Gtk::Label *label330 = manage(new class Gtk::Label("Alessandro Filippetti "));
   Gtk::Pixmap *pixmap60 = manage(new class Gtk::Pixmap(SchliessenIII_50_xpm));
   Gtk::Label *label407 = manage(new class Gtk::Label("M$-Windows\n"
		"portierung"));
   Gtk::Label *label406 = manage(new class Gtk::Label("Christof Petig"));
   Gtk::HSeparator *hseparator17 = manage(new class Gtk::HSeparator());
   Gtk::Pixmap *pixmap5 = manage(new class Gtk::Pixmap(LoadChar_trans_50_xpm));
   Gtk::Label *label335 = manage(new class Gtk::Label("Download"));
   Gtk::Label *label336 = manage(new class Gtk::Label("http://midgard.berlios.de"));
   Gtk::Pixmap *pixmap56 = manage(new class Gtk::Pixmap(LoadZaub_trans_50_xpm));
   Gtk::Label *label399 = manage(new class Gtk::Label("CVS Repository"));
   Gtk::Label *label400 = manage(new class Gtk::Label("http://developer.berlios.de/projects/midgard/"));
   Gtk::Pixmap *pixmap6 = manage(new class Gtk::Pixmap(Lang_Script_trans_50_xpm));
   Gtk::Label *label337 = manage(new class Gtk::Label("Kontakt"));
   Gtk::Label *label338 = manage(new class Gtk::Label("midgard-general@lists.berlios.de"));
   Gtk::Label *label401 = manage(new class Gtk::Label("MAGUS unterliegt der GNU Public Licence"));
   Gtk::Label *label329 = manage(new class Gtk::Label("Kn�pfe, Logo\n"
		"& HTML"));
   Gtk::Label *label531 = manage(new class Gtk::Label("Beim Abtippen der Daten und Testen haben Michael Gruetzki, Nils Richter,\n"
		"Roland Ritthaler Sebastian Horstmann, Joachim Jordan, Alessandro Filipetti,\n"
		"Sven Rey, Ottmar Zimmer und viele andere geholfen."));
   Gtk::Pixmap *pixmap131 = manage(new class Gtk::Pixmap(Helper_50_xpm));
   Gtk::Pixmap *pixmap57 = manage(new class Gtk::Pixmap(pinguin_xpm));
   Gtk::Pixmap *pixmap104 = manage(new class Gtk::Pixmap(gnu_haed_trans_32_xpm));
   Gtk::HBox *hbox56 = manage(new class Gtk::HBox(false, 0));
   Gtk::Table *table109 = manage(new class Gtk::Table(10, 3, false));
   Gtk::Frame *frame99 = manage(new class Gtk::Frame("MAGUS"));
   Gtk::Label *label412 = manage(new class Gtk::Label("L�nder"));
   Gtk::Label *label413 = manage(new class Gtk::Label("R�stungen"));
   Gtk::Label *label414 = manage(new class Gtk::Label("angeb. Fertigkeiten"));
   Gtk::Label *label415 = manage(new class Gtk::Label("Fertigkeiten"));
   progressbar_laender = manage(new class Gtk::ProgressBar());
   progressbar_ruestung = manage(new class Gtk::ProgressBar());
   progressbar_ang_Fert = manage(new class Gtk::ProgressBar());
   progressbar_fertigkeiten = manage(new class Gtk::ProgressBar());
   
   Gtk::Label *label432 = manage(new class Gtk::Label("Lernschema"));
   Gtk::Label *label431 = manage(new class Gtk::Label("Berufe"));
   progressbar_lernschema = manage(new class Gtk::ProgressBar());
   progressbar_beruf = manage(new class Gtk::ProgressBar());
   
   Gtk::Label *label528 = manage(new class Gtk::Label("Regionen"));
   progressbar_regionen = manage(new class Gtk::ProgressBar());
   
   Gtk::Label *label425 = manage(new class Gtk::Label("Spezies"));
   progressbar_spezies = manage(new class Gtk::ProgressBar());
   
   Gtk::Label *label426 = manage(new class Gtk::Label("Abenteurerklassen"));
   progressbar_typen = manage(new class Gtk::ProgressBar());
   
   Gtk::Label *label427 = manage(new class Gtk::Label("Grad Anstieg"));
   progressbar_grad = manage(new class Gtk::ProgressBar());
   
   Gtk::Label *label428 = manage(new class Gtk::Label("Spezialgebiete"));
   progressbar_spezial = manage(new class Gtk::ProgressBar());
   
   Gtk::Label *label436 = manage(new class Gtk::Label("Ausr�stung/Preise"));
   progressbar_preise = manage(new class Gtk::ProgressBar());
   progressbar_schrift = manage(new class Gtk::ProgressBar());
   
   Gtk::Label *label419 = manage(new class Gtk::Label("Schriften"));
   Gtk::Label *label418 = manage(new class Gtk::Label("Sprachen"));
   Gtk::Label *label420 = manage(new class Gtk::Label("KiDo"));
   Gtk::Label *label417 = manage(new class Gtk::Label("Zauberwerk"));
   Gtk::Label *label416 = manage(new class Gtk::Label("Zauber"));
   Gtk::Label *label430 = manage(new class Gtk::Label("Regionale Waffen"));
   Gtk::Label *label422 = manage(new class Gtk::Label("Waffen"));
   progressbar_sprache = manage(new class Gtk::ProgressBar());
   progressbar_kido = manage(new class Gtk::ProgressBar());
   progressbar_zauberwerk = manage(new class Gtk::ProgressBar());
   progressbar_zauber = manage(new class Gtk::ProgressBar());
   progressbar_aliaswaffen = manage(new class Gtk::ProgressBar());
   progressbar_waffen = manage(new class Gtk::ProgressBar());
   
   Gtk::Label *label421 = manage(new class Gtk::Label("Grundkenntnisse"));
   progressbar_grundkenntnisse = manage(new class Gtk::ProgressBar());
   
   Gtk::Table *table77 = manage(new class Gtk::Table(7, 6, false));
   frame_datenbank = manage(new class Gtk::Frame("Laden der Datenbank"));
   
   Gtk::Pixmap *pixmap168 = manage(new class Gtk::Pixmap(schirm_xpm));
   Gtk::Table *table149 = manage(new class Gtk::Table(1, 3, false));
   Gtk::Pixmap *pixmap154 = manage(new class Gtk::Pixmap(GnuHead_trans_xpm));
   Gtk::Pixmap *pixmap106 = manage(new class Gtk::Pixmap(Tux_med_xpm));
   Gtk::HBox *hbox90 = manage(new class Gtk::HBox(false, 0));
   Gtk::Pixmap *pixmap90 = manage(new class Gtk::Pixmap(MAGUS_Logo_Text_halb_t3_xpm));
   Gtk::Table *table167 = manage(new class Gtk::Table(2, 1, false));
   Gtk::Table *table49 = manage(new class Gtk::Table(6, 2, false));
   Gtk::Viewport *viewport33 = manage(new class Gtk::Viewport());
   pixmap65->set_alignment(0.5,0.5);
   pixmap65->set_padding(0,0);
   label340->set_alignment(0,0.5);
   label340->set_padding(0,0);
   label340->set_justify(GTK_JUSTIFY_CENTER);
   label340->set_line_wrap(false);
   versionsnummer->set_alignment(0,0.5);
   versionsnummer->set_padding(0,0);
   versionsnummer->set_justify(GTK_JUSTIFY_CENTER);
   versionsnummer->set_line_wrap(false);
   frame_regionen->set_shadow_type(GTK_SHADOW_ETCHED_IN);
   frame_regionen->set_label_align(0,0);
   pixmap1->set_alignment(0.5,0.5);
   pixmap1->set_padding(0,0);
   label327->set_usize(48,16);
   label327->set_alignment(0,0.5);
   label327->set_padding(0,0);
   label327->set_justify(GTK_JUSTIFY_LEFT);
   label327->set_line_wrap(true);
   label328->set_alignment(0,0.5);
   label328->set_padding(0,0);
   label328->set_justify(GTK_JUSTIFY_CENTER);
   label328->set_line_wrap(false);
   pixmap3->set_alignment(0.5,0.5);
   pixmap3->set_padding(0,0);
   label331->set_alignment(0,0.5);
   label331->set_padding(0,0);
   label331->set_justify(GTK_JUSTIFY_LEFT);
   label331->set_line_wrap(false);
   label332->set_alignment(0,0.5);
   label332->set_padding(0,0);
   label332->set_justify(GTK_JUSTIFY_CENTER);
   label332->set_line_wrap(false);
   pixmap2->set_alignment(0.5,0.5);
   pixmap2->set_padding(0,0);
   label330->set_alignment(0,0.5);
   label330->set_padding(0,0);
   label330->set_justify(GTK_JUSTIFY_CENTER);
   label330->set_line_wrap(false);
   pixmap60->set_alignment(0.5,0.5);
   pixmap60->set_padding(0,0);
   label407->set_alignment(0,0.5);
   label407->set_padding(0,0);
   label407->set_justify(GTK_JUSTIFY_CENTER);
   label407->set_line_wrap(false);
   label406->set_alignment(0,0.5);
   label406->set_padding(0,0);
   label406->set_justify(GTK_JUSTIFY_CENTER);
   label406->set_line_wrap(false);
   pixmap5->set_alignment(0.5,0.5);
   pixmap5->set_padding(0,0);
   label335->set_alignment(0,0.5);
   label335->set_padding(0,0);
   label335->set_justify(GTK_JUSTIFY_CENTER);
   label335->set_line_wrap(false);
   label336->set_alignment(0,0.5);
   label336->set_padding(0,0);
   label336->set_justify(GTK_JUSTIFY_CENTER);
   label336->set_line_wrap(false);
   pixmap56->set_alignment(0.5,0.5);
   pixmap56->set_padding(0,0);
   label399->set_alignment(0,0.5);
   label399->set_padding(0,0);
   label399->set_justify(GTK_JUSTIFY_CENTER);
   label399->set_line_wrap(false);
   label400->set_alignment(0,0.5);
   label400->set_padding(0,0);
   label400->set_justify(GTK_JUSTIFY_CENTER);
   label400->set_line_wrap(false);
   pixmap6->set_alignment(0.5,0.5);
   pixmap6->set_padding(0,0);
   label337->set_alignment(0,0.5);
   label337->set_padding(0,0);
   label337->set_justify(GTK_JUSTIFY_CENTER);
   label337->set_line_wrap(false);
   label338->set_alignment(0,0.5);
   label338->set_padding(0,0);
   label338->set_justify(GTK_JUSTIFY_CENTER);
   label338->set_line_wrap(false);
   label401->set_alignment(0,0.5);
   label401->set_padding(0,0);
   label401->set_justify(GTK_JUSTIFY_CENTER);
   label401->set_line_wrap(false);
   label329->set_usize(48,16);
   label329->set_alignment(0,0.5);
   label329->set_padding(0,0);
   label329->set_justify(GTK_JUSTIFY_CENTER);
   label329->set_line_wrap(false);
   label531->set_alignment(0,0.5);
   label531->set_padding(0,0);
   label531->set_justify(GTK_JUSTIFY_LEFT);
   label531->set_line_wrap(false);
   pixmap131->set_alignment(0.5,0.5);
   pixmap131->set_padding(0,0);
   pixmap57->set_alignment(0.5,0.5);
   pixmap57->set_padding(0,0);
   pixmap104->set_alignment(0.5,0.5);
   pixmap104->set_padding(0,0);
   hbox56->pack_start(*pixmap57, false, false, 0);
   hbox56->pack_start(*pixmap104, false, false, 0);
   table109->set_row_spacings(3);
   table109->set_col_spacings(5);
   table109->attach(*pixmap1, 0, 1, 0, 1, GTK_EXPAND|GTK_SHRINK|GTK_FILL, GTK_EXPAND|GTK_SHRINK|GTK_FILL, 0, 0);
   table109->attach(*label327, 1, 2, 0, 1, GTK_FILL, 0, 0, 0);
   table109->attach(*label328, 2, 3, 0, 1, GTK_FILL, 0, 0, 0);
   table109->attach(*pixmap3, 0, 1, 1, 2, GTK_FILL, GTK_EXPAND|GTK_SHRINK|GTK_FILL, 0, 0);
   table109->attach(*label331, 1, 2, 1, 2, GTK_FILL, 0, 0, 0);
   table109->attach(*label332, 2, 3, 1, 2, GTK_FILL, 0, 0, 0);
   table109->attach(*pixmap2, 0, 1, 2, 3, GTK_FILL, GTK_EXPAND|GTK_SHRINK|GTK_FILL, 0, 0);
   table109->attach(*label330, 2, 3, 2, 3, GTK_FILL, 0, 0, 0);
   table109->attach(*pixmap60, 0, 1, 3, 4, GTK_FILL, GTK_EXPAND|GTK_SHRINK|GTK_FILL, 0, 0);
   table109->attach(*label407, 1, 2, 3, 4, GTK_FILL, 0, 0, 0);
   table109->attach(*label406, 2, 3, 3, 4, GTK_FILL, 0, 0, 0);
   table109->attach(*hseparator17, 0, 3, 5, 6, GTK_FILL, GTK_EXPAND|GTK_SHRINK|GTK_FILL, 0, 0);
   table109->attach(*pixmap5, 0, 1, 6, 7, GTK_FILL, GTK_EXPAND|GTK_SHRINK|GTK_FILL, 0, 0);
   table109->attach(*label335, 1, 2, 6, 7, GTK_FILL, 0, 0, 0);
   table109->attach(*label336, 2, 3, 6, 7, GTK_FILL, 0, 0, 0);
   table109->attach(*pixmap56, 0, 1, 7, 8, GTK_FILL, GTK_EXPAND|GTK_SHRINK|GTK_FILL, 0, 0);
   table109->attach(*label399, 1, 2, 7, 8, GTK_FILL, 0, 0, 0);
   table109->attach(*label400, 2, 3, 7, 8, GTK_FILL, 0, 0, 0);
   table109->attach(*pixmap6, 0, 1, 8, 9, GTK_FILL, GTK_EXPAND|GTK_SHRINK|GTK_FILL, 0, 0);
   table109->attach(*label337, 1, 2, 8, 9, GTK_FILL, 0, 0, 0);
   table109->attach(*label338, 2, 3, 8, 9, GTK_FILL, 0, 0, 0);
   table109->attach(*label401, 1, 3, 9, 10, GTK_FILL, 0, 0, 0);
   table109->attach(*label329, 1, 2, 2, 3, GTK_FILL, GTK_FILL, 0, 0);
   table109->attach(*label531, 1, 3, 4, 5, GTK_FILL, 0, 0, 0);
   table109->attach(*pixmap131, 0, 1, 4, 5, GTK_FILL, GTK_FILL, 0, 0);
   table109->attach(*hbox56, 0, 1, 9, 10, 0, GTK_FILL, 0, 0);
   frame99->set_shadow_type(GTK_SHADOW_ETCHED_IN);
   frame99->set_label_align(0,0);
   frame99->add(*table109);
   label412->set_alignment(0,0.5);
   label412->set_padding(0,0);
   label412->set_justify(GTK_JUSTIFY_CENTER);
   label412->set_line_wrap(false);
   label413->set_alignment(0,0.5);
   label413->set_padding(0,0);
   label413->set_justify(GTK_JUSTIFY_CENTER);
   label413->set_line_wrap(false);
   label414->set_alignment(0,0.5);
   label414->set_padding(0,0);
   label414->set_justify(GTK_JUSTIFY_CENTER);
   label414->set_line_wrap(false);
   label415->set_alignment(0,0.5);
   label415->set_padding(0,0);
   label415->set_justify(GTK_JUSTIFY_CENTER);
   label415->set_line_wrap(false);
   label432->set_alignment(0,0.5);
   label432->set_padding(0,0);
   label432->set_justify(GTK_JUSTIFY_CENTER);
   label432->set_line_wrap(false);
   label431->set_alignment(0,0.5);
   label431->set_padding(0,0);
   label431->set_justify(GTK_JUSTIFY_CENTER);
   label431->set_line_wrap(false);
   label528->set_alignment(0,0.5);
   label528->set_padding(0,0);
   label528->set_justify(GTK_JUSTIFY_CENTER);
   label528->set_line_wrap(false);
   label425->set_alignment(0,0.5);
   label425->set_padding(0,0);
   label425->set_justify(GTK_JUSTIFY_CENTER);
   label425->set_line_wrap(false);
   label426->set_alignment(0,0.5);
   label426->set_padding(0,0);
   label426->set_justify(GTK_JUSTIFY_CENTER);
   label426->set_line_wrap(false);
   label427->set_alignment(0,0.5);
   label427->set_padding(0,0);
   label427->set_justify(GTK_JUSTIFY_CENTER);
   label427->set_line_wrap(false);
   label428->set_alignment(0,0.5);
   label428->set_padding(0,0);
   label428->set_justify(GTK_JUSTIFY_CENTER);
   label428->set_line_wrap(false);
   label436->set_alignment(0,0.5);
   label436->set_padding(0,0);
   label436->set_justify(GTK_JUSTIFY_CENTER);
   label436->set_line_wrap(false);
   label419->set_alignment(0,0.5);
   label419->set_padding(0,0);
   label419->set_justify(GTK_JUSTIFY_CENTER);
   label419->set_line_wrap(false);
   label418->set_alignment(0,0.5);
   label418->set_padding(0,0);
   label418->set_justify(GTK_JUSTIFY_CENTER);
   label418->set_line_wrap(false);
   label420->set_alignment(0,0.5);
   label420->set_padding(0,0);
   label420->set_justify(GTK_JUSTIFY_CENTER);
   label420->set_line_wrap(false);
   label417->set_alignment(0,0.5);
   label417->set_padding(0,0);
   label417->set_justify(GTK_JUSTIFY_CENTER);
   label417->set_line_wrap(false);
   label416->set_alignment(0,0.5);
   label416->set_padding(0,0);
   label416->set_justify(GTK_JUSTIFY_CENTER);
   label416->set_line_wrap(false);
   label430->set_alignment(0,0.5);
   label430->set_padding(0,0);
   label430->set_justify(GTK_JUSTIFY_CENTER);
   label430->set_line_wrap(false);
   label422->set_alignment(0,0.5);
   label422->set_padding(0,0);
   label422->set_justify(GTK_JUSTIFY_CENTER);
   label422->set_line_wrap(false);
   label421->set_alignment(0,0.5);
   label421->set_padding(0,0);
   label421->set_justify(GTK_JUSTIFY_CENTER);
   label421->set_line_wrap(false);
   table77->set_row_spacings(0);
   table77->set_col_spacings(0);
   table77->attach(*label412, 0, 1, 1, 2, GTK_FILL, 0, 0, 0);
   table77->attach(*label413, 0, 1, 2, 3, GTK_FILL, 0, 0, 0);
   table77->attach(*label414, 0, 1, 5, 6, GTK_FILL, 0, 0, 0);
   table77->attach(*label415, 0, 1, 6, 7, GTK_FILL, 0, 0, 0);
   table77->attach(*progressbar_laender, 1, 2, 1, 2, GTK_FILL, 0, 0, 0);
   table77->attach(*progressbar_ruestung, 1, 2, 2, 3, GTK_FILL, 0, 0, 0);
   table77->attach(*progressbar_ang_Fert, 1, 2, 5, 6, GTK_FILL, 0, 0, 0);
   table77->attach(*progressbar_fertigkeiten, 1, 2, 6, 7, GTK_FILL, 0, 0, 0);
   table77->attach(*label432, 0, 1, 3, 4, GTK_FILL, 0, 0, 0);
   table77->attach(*label431, 0, 1, 4, 5, GTK_FILL, 0, 0, 0);
   table77->attach(*progressbar_lernschema, 1, 2, 3, 4, GTK_FILL, 0, 0, 0);
   table77->attach(*progressbar_beruf, 1, 2, 4, 5, GTK_FILL, 0, 0, 0);
   table77->attach(*label528, 0, 1, 0, 1, GTK_FILL, 0, 0, 0);
   table77->attach(*progressbar_regionen, 1, 2, 0, 1, GTK_FILL, 0, 0, 0);
   table77->attach(*label425, 4, 5, 1, 2, GTK_FILL, 0, 0, 0);
   table77->attach(*progressbar_spezies, 5, 6, 1, 2, GTK_FILL, 0, 0, 0);
   table77->attach(*label426, 4, 5, 2, 3, GTK_FILL, 0, 0, 0);
   table77->attach(*progressbar_typen, 5, 6, 2, 3, GTK_FILL, 0, 0, 0);
   table77->attach(*label427, 4, 5, 3, 4, GTK_FILL, 0, 0, 0);
   table77->attach(*progressbar_grad, 5, 6, 3, 4, GTK_FILL, 0, 0, 0);
   table77->attach(*label428, 4, 5, 4, 5, GTK_FILL, 0, 0, 0);
   table77->attach(*progressbar_spezial, 5, 6, 4, 5, GTK_FILL, 0, 0, 0);
   table77->attach(*label436, 4, 5, 5, 6, GTK_FILL, 0, 0, 0);
   table77->attach(*progressbar_preise, 5, 6, 5, 6, GTK_FILL, 0, 0, 0);
   table77->attach(*progressbar_schrift, 5, 6, 0, 1, GTK_FILL, 0, 0, 0);
   table77->attach(*label419, 4, 5, 0, 1, GTK_FILL, 0, 0, 0);
   table77->attach(*label418, 2, 3, 6, 7, GTK_FILL, 0, 0, 0);
   table77->attach(*label420, 2, 3, 5, 6, GTK_FILL, 0, 0, 0);
   table77->attach(*label417, 2, 3, 4, 5, GTK_FILL, 0, 0, 0);
   table77->attach(*label416, 2, 3, 3, 4, GTK_FILL, 0, 0, 0);
   table77->attach(*label430, 2, 3, 2, 3, GTK_FILL, 0, 0, 0);
   table77->attach(*label422, 2, 3, 1, 2, GTK_FILL, 0, 0, 0);
   table77->attach(*progressbar_sprache, 3, 4, 6, 7, GTK_FILL, 0, 0, 0);
   table77->attach(*progressbar_kido, 3, 4, 5, 6, GTK_FILL, 0, 0, 0);
   table77->attach(*progressbar_zauberwerk, 3, 4, 4, 5, GTK_FILL, 0, 0, 0);
   table77->attach(*progressbar_zauber, 3, 4, 3, 4, GTK_FILL, 0, 0, 0);
   table77->attach(*progressbar_aliaswaffen, 3, 4, 2, 3, GTK_FILL, 0, 0, 0);
   table77->attach(*progressbar_waffen, 3, 4, 1, 2, GTK_FILL, 0, 0, 0);
   table77->attach(*label421, 2, 3, 0, 1, GTK_FILL, 0, 0, 0);
   table77->attach(*progressbar_grundkenntnisse, 3, 4, 0, 1, GTK_FILL, 0, 0, 0);
   frame_datenbank->set_shadow_type(GTK_SHADOW_ETCHED_IN);
   frame_datenbank->set_label_align(0,0);
   frame_datenbank->add(*table77);
   pixmap168->set_alignment(0.5,0.5);
   pixmap168->set_padding(0,0);
   table149->set_row_spacings(0);
   table149->set_col_spacings(0);
   table149->attach(*pixmap168, 1, 2, 0, 1, GTK_EXPAND|GTK_FILL, GTK_FILL, 0, 0);
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
   table167->attach(*hbox90, 0, 1, 0, 1, GTK_FILL, GTK_EXPAND|GTK_FILL, 0, 0);
   table167->attach(*pixmap90, 0, 1, 1, 2, GTK_SHRINK, GTK_EXPAND|GTK_SHRINK|GTK_FILL, 0, 0);
   table49->set_row_spacings(0);
   table49->set_col_spacings(0);
   table49->attach(*pixmap65, 0, 1, 0, 1, GTK_FILL, GTK_FILL, 0, 0);
   table49->attach(*label340, 0, 1, 1, 2, 0, 0, 5, 5);
   table49->attach(*versionsnummer, 0, 1, 2, 3, 0, 0, 0, 0);
   table49->attach(*frame_regionen, 1, 2, 5, 6, GTK_FILL, GTK_FILL, 0, 0);
   table49->attach(*frame99, 0, 1, 5, 6, GTK_FILL, GTK_FILL, 0, 0);
   table49->attach(*frame_datenbank, 0, 2, 4, 5, GTK_FILL, GTK_EXPAND|GTK_SHRINK|GTK_FILL, 0, 0);
   table49->attach(*table149, 0, 1, 3, 4, 0, 0, 0, 0);
   table49->attach(*table167, 1, 2, 0, 4, GTK_FILL, GTK_FILL, 0, 0);
   viewport33->set_shadow_type(GTK_SHADOW_NONE);
   viewport33->add(*table49);
   Midgard_Info->set_policy(GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
   Midgard_Info->add(*viewport33);
   pixmap65->show();
   label340->show();
   versionsnummer->show();
   frame_regionen->show();
   pixmap1->show();
   label327->show();
   label328->show();
   pixmap3->show();
   label331->show();
   label332->show();
   pixmap2->show();
   label330->show();
   pixmap60->show();
   label407->show();
   label406->show();
   hseparator17->show();
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
   label329->show();
   label531->show();
   pixmap131->show();
   pixmap57->show();
   pixmap104->show();
   hbox56->show();
   table109->show();
   frame99->show();
   label412->show();
   label413->show();
   label414->show();
   label415->show();
   progressbar_laender->show();
   progressbar_ruestung->show();
   progressbar_ang_Fert->show();
   progressbar_fertigkeiten->show();
   label432->show();
   label431->show();
   progressbar_lernschema->show();
   progressbar_beruf->show();
   label528->show();
   progressbar_regionen->show();
   label425->show();
   progressbar_spezies->show();
   label426->show();
   progressbar_typen->show();
   label427->show();
   progressbar_grad->show();
   label428->show();
   progressbar_spezial->show();
   label436->show();
   progressbar_preise->show();
   progressbar_schrift->show();
   label419->show();
   label418->show();
   label420->show();
   label417->show();
   label416->show();
   label430->show();
   label422->show();
   progressbar_sprache->show();
   progressbar_kido->show();
   progressbar_zauberwerk->show();
   progressbar_zauber->show();
   progressbar_aliaswaffen->show();
   progressbar_waffen->show();
   label421->show();
   progressbar_grundkenntnisse->show();
   table77->show();
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
