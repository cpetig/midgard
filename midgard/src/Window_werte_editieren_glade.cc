// generated 2001/12/31 9:20:53 CET by thoma@Tiger.
// using glademm V0.6.2c_cvs
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- /home/thoma/rollenspiel/midgard/programme/gcc_3.0/midgard/midgard.glade
// for gtk 1.2.10 and gtkmm 1.2.5
//
// Please modify the corresponding derived classes in ./src/Window_werte_editieren.cc

#include "config.h"
#include "Window_werte_editieren.hh"
#include <gtk--/adjustment.h>
#include <gtk--/label.h>
#include <gtk--/separator.h>
#include <gtk--/menu.h>
#include <gtk--/menuitem.h>
#include <gtk--/pixmap.h>
#include "../pixmaps/EditChar-trans-50.xpm"
#include "../pixmaps/Falke-trans-lowCol-20.xpm"
#include <gtk--/button.h>
#include "../pixmaps/SchliessenIII-50.xpm"
#include <gtk--/toolbar.h>
#include <gtk--/table.h>
#include <gtk--/frame.h>

Window_werte_editieren_glade::Window_werte_editieren_glade(
) : Gtk::Window(GTK_WINDOW_TOPLEVEL)
{   Window_werte_editieren = this;
   
   Gtk::Adjustment *st_ein_adj = manage(new class Gtk::Adjustment(1, 0, 200, 1, 10, 10));
   st_ein = manage(new class Gtk::SpinButton(*st_ein_adj, 1, 0));
   
   Gtk::Adjustment *gw_ein_adj = manage(new class Gtk::Adjustment(1, 0, 200, 1, 10, 10));
   gw_ein = manage(new class Gtk::SpinButton(*gw_ein_adj, 1, 0));
   
   Gtk::Adjustment *ko_ein_adj = manage(new class Gtk::Adjustment(1, 0, 200, 1, 10, 10));
   ko_ein = manage(new class Gtk::SpinButton(*ko_ein_adj, 1, 0));
   
   Gtk::Adjustment *in_ein_adj = manage(new class Gtk::Adjustment(1, 0, 200, 1, 10, 10));
   in_ein = manage(new class Gtk::SpinButton(*in_ein_adj, 1, 0));
   
   Gtk::Adjustment *zt_ein_adj = manage(new class Gtk::Adjustment(1, 0, 200, 1, 10, 10));
   zt_ein = manage(new class Gtk::SpinButton(*zt_ein_adj, 1, 0));
   
   Gtk::Adjustment *au_ein_adj = manage(new class Gtk::Adjustment(1, 0, 200, 1, 10, 10));
   au_ein = manage(new class Gtk::SpinButton(*au_ein_adj, 1, 0));
   
   Gtk::Adjustment *pa_ein_adj = manage(new class Gtk::Adjustment(1, 0, 200, 1, 10, 10));
   pa_ein = manage(new class Gtk::SpinButton(*pa_ein_adj, 1, 0));
   
   Gtk::Adjustment *sb_ein_adj = manage(new class Gtk::Adjustment(1, 0, 200, 1, 10, 10));
   sb_ein = manage(new class Gtk::SpinButton(*sb_ein_adj, 1, 0));
   
   Gtk::Adjustment *b_ein_adj = manage(new class Gtk::Adjustment(1, 0, 100, 1, 10, 10));
   b_ein = manage(new class Gtk::SpinButton(*b_ein_adj, 1, 0));
   
   Gtk::Adjustment *lp_ein_adj = manage(new class Gtk::Adjustment(1, 0, 100, 1, 10, 10));
   lp_ein = manage(new class Gtk::SpinButton(*lp_ein_adj, 1, 0));
   
   Gtk::Adjustment *ap_ein_adj = manage(new class Gtk::Adjustment(1, 0, 100, 1, 10, 10));
   ap_ein = manage(new class Gtk::SpinButton(*ap_ein_adj, 1, 0));
   
   Gtk::Adjustment *grad_ein_adj = manage(new class Gtk::Adjustment(1, 0, 100, 1, 10, 10));
   grad_ein = manage(new class Gtk::SpinButton(*grad_ein_adj, 1, 0));
   
   Gtk::Adjustment *alter_ein_adj = manage(new class Gtk::Adjustment(1, 0, 10000, 1, 10, 10));
   alter_ein = manage(new class Gtk::SpinButton(*alter_ein_adj, 1, 0));
   
   Gtk::Adjustment *gewicht_ein_adj = manage(new class Gtk::Adjustment(1, 0, 50000, 1, 10, 10));
   gewicht_ein = manage(new class Gtk::SpinButton(*gewicht_ein_adj, 1, 0));
   
   Gtk::Adjustment *groesse_ein_adj = manage(new class Gtk::Adjustment(1, 0, 10000, 1, 10, 10));
   groesse_ein = manage(new class Gtk::SpinButton(*groesse_ein_adj, 1, 0));
   gestalt_ein = manage(new class Gtk::Entry());
   spezialisierung_ein = manage(new class Gtk::Entry());
   herkunft_ein = manage(new class Gtk::Entry());
   glaube_ein = manage(new class Gtk::Entry());
   name_spieler_ein = manage(new class Gtk::Entry());
   name_charakter_ein = manage(new class Gtk::Entry());
   
   Gtk::Label *label161 = manage(new class Gtk::Label("Boni f�r"));
   Gtk::Adjustment *bo_au_ein_adj = manage(new class Gtk::Adjustment(1, -5, 200, 1, 10, 10));
   bo_au_ein = manage(new class Gtk::SpinButton(*bo_au_ein_adj, 1, 0));
   
   Gtk::Adjustment *bo_sc_ein_adj = manage(new class Gtk::Adjustment(1, -5, 200, 1, 10, 10));
   bo_sc_ein = manage(new class Gtk::SpinButton(*bo_sc_ein_adj, 1, 0));
   
   Gtk::Adjustment *bo_an_ein_adj = manage(new class Gtk::Adjustment(1, -5, 200, 1, 10, 10));
   bo_an_ein = manage(new class Gtk::SpinButton(*bo_an_ein_adj, 1, 0));
   
   Gtk::Adjustment *bo_ab_ein_adj = manage(new class Gtk::Adjustment(1, -5, 200, 1, 10, 10));
   bo_ab_ein = manage(new class Gtk::SpinButton(*bo_ab_ein_adj, 1, 0));
   
   Gtk::Adjustment *bo_za_ein_adj = manage(new class Gtk::Adjustment(1, -5, 200, 1, 10, 10));
   bo_za_ein = manage(new class Gtk::SpinButton(*bo_za_ein_adj, 1, 0));
   
   Gtk::Adjustment *bo_psy_ein_adj = manage(new class Gtk::Adjustment(1, -5, 200, 1, 10, 10));
   bo_psy_ein = manage(new class Gtk::SpinButton(*bo_psy_ein_adj, 1, 0));
   
   Gtk::Adjustment *bo_phs_ein_adj = manage(new class Gtk::Adjustment(1, -5, 200, 1, 10, 10));
   bo_phs_ein = manage(new class Gtk::SpinButton(*bo_phs_ein_adj, 1, 0));
   
   Gtk::Adjustment *bo_phk_ein_adj = manage(new class Gtk::Adjustment(1, -5, 200, 1, 10, 10));
   bo_phk_ein = manage(new class Gtk::SpinButton(*bo_phk_ein_adj, 1, 0));
   
   Gtk::HSeparator *hseparator4 = manage(new class Gtk::HSeparator());
   Gtk::HSeparator *hseparator9 = manage(new class Gtk::HSeparator());
   Gtk::HSeparator *hseparator5 = manage(new class Gtk::HSeparator());
   Gtk::Label *label174 = manage(new class Gtk::Label("Werte f�r"));
   Gtk::Adjustment *zaubern_ein_adj = manage(new class Gtk::Adjustment(1, 0, 200, 1, 10, 10));
   zaubern_ein = manage(new class Gtk::SpinButton(*zaubern_ein_adj, 1, 0));
   
   Gtk::Adjustment *abwehr_ein_adj = manage(new class Gtk::Adjustment(1, 0, 200, 1, 10, 10));
   abwehr_ein = manage(new class Gtk::SpinButton(*abwehr_ein_adj, 1, 0));
   
   Gtk::Label *label249 = manage(new class Gtk::Label("GFP"));
   Gtk::Adjustment *gfp_ein_adj = manage(new class Gtk::Adjustment(0, 0, 100000, 1, 10, 10));
   gfp_ein = manage(new class Gtk::SpinButton(*gfp_ein_adj, 1, 0));
   
   Gtk::Label *label250 = manage(new class Gtk::Label("Version"));
   version_ein = manage(new class Gtk::Entry());
   optionmenu_stand = manage(new class Gtk::OptionMenu());
   
   Gtk::Pixmap *pixmap25 = manage(new class Gtk::Pixmap(EditChar_trans_50_xpm));
   Gtk::Label *label83 = manage(new class Gtk::Label("Sb"));
   Gtk::Label *label82 = manage(new class Gtk::Label("pA"));
   Gtk::Label *label81 = manage(new class Gtk::Label("Au"));
   Gtk::Label *label80 = manage(new class Gtk::Label("Zt"));
   Gtk::Label *label79 = manage(new class Gtk::Label("In"));
   Gtk::Label *label78 = manage(new class Gtk::Label("Ko"));
   Gtk::Label *label77 = manage(new class Gtk::Label("Gw"));
   Gtk::Label *label76 = manage(new class Gtk::Label("St"));
   Gtk::Label *label89 = manage(new class Gtk::Label("Grad"));
   Gtk::Label *label86 = manage(new class Gtk::Label("B"));
   Gtk::Label *label87 = manage(new class Gtk::Label("LP"));
   Gtk::Label *label90 = manage(new class Gtk::Label("AP"));
   Gtk::Label *label169 = manage(new class Gtk::Label("phkZR"));
   Gtk::Label *label168 = manage(new class Gtk::Label("phsZR"));
   Gtk::Label *label167 = manage(new class Gtk::Label("psyZR"));
   Gtk::Label *label166 = manage(new class Gtk::Label("Zaubern"));
   Gtk::Label *label165 = manage(new class Gtk::Label("Abwehr"));
   Gtk::Label *label164 = manage(new class Gtk::Label("Angriff"));
   Gtk::Label *label163 = manage(new class Gtk::Label("Schaden"));
   Gtk::Label *label162 = manage(new class Gtk::Label("Ausdauer"));
   Gtk::Label *label175 = manage(new class Gtk::Label("Abwehr"));
   Gtk::Label *label176 = manage(new class Gtk::Label("Zaubern"));
   Gtk::Label *label115 = manage(new class Gtk::Label("Name des\n"
		"Spielers"));
   Gtk::Label *label114 = manage(new class Gtk::Label("Name des\n"
		"Charakters"));
   Gtk::Label *label102 = manage(new class Gtk::Label("Glaube"));
   Gtk::Label *label101 = manage(new class Gtk::Label("Herkunft"));
   Gtk::Label *label100 = manage(new class Gtk::Label("Stand"));
   Gtk::Label *label99 = manage(new class Gtk::Label("Spezialisierung"));
   Gtk::Label *label92 = manage(new class Gtk::Label("Gestalt"));
   Gtk::Label *label94 = manage(new class Gtk::Label("K�rpergr��e (cm)"));
   Gtk::Label *label93 = manage(new class Gtk::Label("Gewicht (kg)"));
   Gtk::Label *label91 = manage(new class Gtk::Label("Alter"));
   Gtk::VSeparator *vseparator5 = manage(new class Gtk::VSeparator());
   Gtk::Label *label481 = manage(new class Gtk::Label("Wk"));
   Gtk::Adjustment *wk_ein_adj = manage(new class Gtk::Adjustment(1, 0, 200, 1, 10, 10));
   wk_ein = manage(new class Gtk::SpinButton(*wk_ein_adj, 1, 0));
   
   Gtk::Label *label482 = manage(new class Gtk::Label("Gs"));
   Gtk::Adjustment *gs_ein_adj = manage(new class Gtk::Adjustment(1, 0, 200, 1, 10, 10));
   gs_ein = manage(new class Gtk::SpinButton(*gs_ein_adj, 1, 0));
   optionmenu_hand = manage(new class Gtk::OptionMenu());
   
   Gtk::Label *label499 = manage(new class Gtk::Label("GG"));
   Gtk::Adjustment *gg_ein_adj = manage(new class Gtk::Adjustment(0, 0, 100000, 1, 10, 10));
   gg_ein = manage(new class Gtk::SpinButton(*gg_ein_adj, 1, 0));
   
   Gtk::VSeparator *vseparator6 = manage(new class Gtk::VSeparator());
   Gtk::VSeparator *vseparator7 = manage(new class Gtk::VSeparator());
   Gtk::Label *label501 = manage(new class Gtk::Label("SG"));
   Gtk::Adjustment *sg_ein_adj = manage(new class Gtk::Adjustment(0, 0, 100000, 1, 10, 10));
   sg_ein = manage(new class Gtk::SpinButton(*sg_ein_adj, 1, 0));
   
   Gtk::Label *label179 = manage(new class Gtk::Label("Resistenz"));
   Gtk::Adjustment *resistenz_ein_adj = manage(new class Gtk::Adjustment(1, 0, 200, 1, 10, 10));
   resistenz_ein = manage(new class Gtk::SpinButton(*resistenz_ein_adj, 1, 0));
   
   Gtk::HSeparator *hseparator6 = manage(new class Gtk::HSeparator());
   Gtk::Pixmap *pixmap55 = manage(new class Gtk::Pixmap(Falke_trans_lowCol_20_xpm));
   Gtk::Toolbar *toolbar18 = manage(new class Gtk::Toolbar(GTK_ORIENTATION_HORIZONTAL, GTK_TOOLBAR_ICONS));
   Gtk::Button *button47 = Gtk::wrap((GtkButton*)gtk_toolbar_append_element(GTK_TOOLBAR(toolbar18->gtkobj()), GTK_TOOLBAR_CHILD_BUTTON, 0, "", 0, 0, GTK_WIDGET(manage(new Gtk::Pixmap(SchliessenIII_50_xpm))->gtkobj()), 0, 0));
   Gtk::Label *label525 = manage(new class Gtk::Label("steiger Tage"));
   Gtk::Adjustment *spinbutton_steigertage_adj = manage(new class Gtk::Adjustment(1, 0, 100, 1, 10, 10));
   spinbutton_steigertage = manage(new class Gtk::SpinButton(*spinbutton_steigertage_adj, 1, 0));
   
   Gtk::Table *table3 = manage(new class Gtk::Table(18, 13, false));
   Gtk::Frame *frame13 = manage(new class Gtk::Frame("Werte editieren"));
   st_ein->set_editable(true);
   gw_ein->set_editable(true);
   ko_ein->set_editable(true);
   in_ein->set_editable(true);
   zt_ein->set_editable(true);
   au_ein->set_editable(true);
   pa_ein->set_editable(true);
   sb_ein->set_editable(true);
   b_ein->set_editable(true);
   lp_ein->set_editable(true);
   ap_ein->set_editable(true);
   grad_ein->set_editable(true);
   alter_ein->set_editable(true);
   gewicht_ein->set_editable(true);
   groesse_ein->set_editable(true);
   gestalt_ein->set_editable(true);
   spezialisierung_ein->set_editable(true);
   herkunft_ein->set_editable(true);
   glaube_ein->set_editable(true);
   name_spieler_ein->set_editable(true);
   name_charakter_ein->set_editable(true);
   label161->set_alignment(0.5, 0.5);
   label161->set_padding(0, 0);
   bo_au_ein->set_editable(true);
   bo_sc_ein->set_editable(true);
   bo_an_ein->set_editable(true);
   bo_ab_ein->set_editable(true);
   bo_za_ein->set_editable(true);
   bo_psy_ein->set_editable(true);
   bo_phs_ein->set_editable(true);
   bo_phk_ein->set_editable(true);
   label174->set_alignment(0.5, 0.5);
   label174->set_padding(0, 0);
   zaubern_ein->set_editable(true);
   abwehr_ein->set_editable(true);
   label249->set_alignment(0, 0);
   label249->set_padding(0, 0);
   gfp_ein->set_usize(67, -1);
   gfp_ein->set_editable(true);
   label250->set_alignment(0, 0);
   label250->set_padding(0, 0);
   version_ein->set_editable(true);
   optionmenu_stand->set_flags(GTK_CAN_FOCUS);
   {   
      
      Gtk::Menu *_m(manage(new Gtk::Menu()));
      Gtk::MenuItem *_mi;
      _mi = manage(new Gtk::MenuItem("STAND"));
      _m->append(*_mi);
      _mi->show();
      _mi->set_user_data((gpointer)0);
      _mi = manage(new Gtk::MenuItem("Unfrei"));
      _m->append(*_mi);
      _mi->show();
      _mi->set_user_data((gpointer)1);
      _mi = manage(new Gtk::MenuItem("Volk"));
      _m->append(*_mi);
      _mi->show();
      _mi->set_user_data((gpointer)2);
      _mi = manage(new Gtk::MenuItem("Mittelschicht"));
      _m->append(*_mi);
      _mi->show();
      _mi->set_user_data((gpointer)3);
      _mi = manage(new Gtk::MenuItem("Adel"));
      _m->append(*_mi);
      _mi->show();
      _mi->set_user_data((gpointer)4);
      optionmenu_stand->set_menu(*_m);
      optionmenu_stand->set_history(0);
   }
   pixmap25->set_alignment(0.5, 0.5);
   pixmap25->set_padding(0, 0);
   label83->set_alignment(0, 0.5);
   label83->set_padding(0, 0);
   label82->set_alignment(0, 0.5);
   label82->set_padding(0, 0);
   label81->set_alignment(0, 0.5);
   label81->set_padding(0, 0);
   label80->set_alignment(0, 0.5);
   label80->set_padding(0, 0);
   label79->set_alignment(0, 0.5);
   label79->set_padding(0, 0);
   label78->set_alignment(0, 0.5);
   label78->set_padding(0, 0);
   label77->set_alignment(0, 0.5);
   label77->set_padding(0, 0);
   label76->set_alignment(0, 0);
   label76->set_padding(0, 0);
   label89->set_alignment(0, 0);
   label89->set_padding(0, 0);
   label86->set_alignment(0, 0);
   label86->set_padding(0, 0);
   label87->set_alignment(0, 0);
   label87->set_padding(0, 0);
   label90->set_alignment(0, 0);
   label90->set_padding(0, 0);
   label169->set_alignment(0, 0);
   label169->set_padding(0, 0);
   label168->set_alignment(0, 0);
   label168->set_padding(0, 0);
   label167->set_alignment(0, 0);
   label167->set_padding(0, 0);
   label166->set_alignment(0, 0);
   label166->set_padding(0, 0);
   label165->set_alignment(0, 0);
   label165->set_padding(0, 0);
   label164->set_alignment(0, 0);
   label164->set_padding(0, 0);
   label163->set_alignment(0, 0);
   label163->set_padding(0, 0);
   label162->set_alignment(0, 0);
   label162->set_padding(0, 0);
   label175->set_alignment(0, 0);
   label175->set_padding(0, 0);
   label176->set_alignment(0, 0);
   label176->set_padding(0, 0);
   label115->set_alignment(0, 0);
   label115->set_padding(0, 0);
   label114->set_alignment(0, 0);
   label114->set_padding(0, 0);
   label102->set_alignment(0, 0);
   label102->set_padding(0, 0);
   label101->set_alignment(0, 0);
   label101->set_padding(0, 0);
   label100->set_alignment(0, 0);
   label100->set_padding(0, 0);
   label99->set_alignment(0, 0);
   label99->set_padding(0, 0);
   label92->set_alignment(0, 0);
   label92->set_padding(0, 0);
   label94->set_alignment(0, 0);
   label94->set_padding(0, 0);
   label93->set_alignment(0, 0);
   label93->set_padding(0, 0);
   label91->set_alignment(0, 0);
   label91->set_padding(0, 0);
   label481->set_alignment(0, 0.5);
   label481->set_padding(0, 0);
   wk_ein->set_editable(true);
   label482->set_alignment(0, 0.5);
   label482->set_padding(0, 0);
   gs_ein->set_editable(true);
   optionmenu_hand->set_flags(GTK_CAN_FOCUS);
   {   
      
      Gtk::Menu *_m(manage(new Gtk::Menu()));
      Gtk::MenuItem *_mi;
      _mi = manage(new Gtk::MenuItem("Rechtsh�nder"));
      _m->append(*_mi);
      _mi->show();
      _mi->set_user_data((gpointer)0);
      _mi = manage(new Gtk::MenuItem("Linksh�nder"));
      _m->append(*_mi);
      _mi->show();
      _mi->set_user_data((gpointer)1);
      _mi = manage(new Gtk::MenuItem("Beidh�ndig"));
      _m->append(*_mi);
      _mi->show();
      _mi->set_user_data((gpointer)2);
      optionmenu_hand->set_menu(*_m);
      optionmenu_hand->set_history(0);
   }
   label499->set_alignment(0, 0);
   label499->set_padding(0, 0);
   gg_ein->set_editable(true);
   label501->set_alignment(0, 0);
   label501->set_padding(0, 0);
   sg_ein->set_editable(true);
   label179->set_alignment(0, 0);
   label179->set_padding(0, 0);
   resistenz_ein->set_editable(true);
   pixmap55->set_alignment(0.5, 0.5);
   pixmap55->set_padding(0, 0);
   toolbar18->set_border_width(5);
   toolbar18->set_space_size(5);
   toolbar18->set_tooltips(true);
   label525->set_alignment(0, 0.5);
   label525->set_padding(0, 0);
   spinbutton_steigertage->set_editable(true);
   table3->attach(*st_ein, 1, 2, 2, 3, GTK_EXPAND|GTK_FILL, 0, 0, 0);
   table3->attach(*gw_ein, 1, 2, 3, 4, GTK_EXPAND|GTK_FILL, 0, 0, 0);
   table3->attach(*ko_ein, 1, 2, 5, 6, GTK_EXPAND|GTK_FILL, 0, 0, 0);
   table3->attach(*in_ein, 1, 2, 6, 7, GTK_EXPAND|GTK_FILL, 0, 0, 0);
   table3->attach(*zt_ein, 1, 2, 7, 8, GTK_EXPAND|GTK_FILL, 0, 0, 0);
   table3->attach(*au_ein, 1, 2, 9, 10, GTK_EXPAND|GTK_FILL, 0, 0, 0);
   table3->attach(*pa_ein, 1, 2, 10, 11, GTK_EXPAND|GTK_FILL, 0, 0, 0);
   table3->attach(*sb_ein, 1, 2, 11, 12, GTK_EXPAND|GTK_FILL, 0, 0, 0);
   table3->attach(*b_ein, 1, 2, 15, 16, GTK_EXPAND|GTK_FILL, 0, 0, 0);
   table3->attach(*lp_ein, 1, 2, 16, 17, GTK_EXPAND|GTK_FILL, 0, 0, 0);
   table3->attach(*ap_ein, 1, 2, 17, 18, GTK_EXPAND|GTK_FILL, 0, 0, 0);
   table3->attach(*grad_ein, 1, 2, 0, 1, GTK_EXPAND|GTK_FILL, 0, 0, 0);
   table3->attach(*alter_ein, 10, 11, 0, 1, GTK_EXPAND|GTK_FILL, 0, 0, 0);
   table3->attach(*gewicht_ein, 10, 11, 2, 3, GTK_EXPAND|GTK_FILL, 0, 0, 0);
   table3->attach(*groesse_ein, 10, 11, 3, 4, GTK_EXPAND|GTK_FILL, 0, 0, 0);
   table3->attach(*gestalt_ein, 10, 11, 5, 6, GTK_EXPAND|GTK_FILL, 0, 0, 0);
   table3->attach(*spezialisierung_ein, 10, 11, 9, 10, GTK_EXPAND|GTK_FILL, 0, 0, 0);
   table3->attach(*herkunft_ein, 10, 11, 11, 12, GTK_EXPAND|GTK_FILL, 0, 0, 0);
   table3->attach(*glaube_ein, 10, 11, 12, 13, GTK_EXPAND|GTK_FILL, 0, 0, 0);
   table3->attach(*name_spieler_ein, 10, 11, 16, 17, GTK_EXPAND|GTK_FILL, 0, 0, 0);
   table3->attach(*name_charakter_ein, 10, 11, 15, 16, GTK_EXPAND|GTK_FILL, 0, 0, 0);
   table3->attach(*label161, 3, 5, 0, 1, 0, 0, 0, 0);
   table3->attach(*bo_au_ein, 4, 5, 2, 3, GTK_EXPAND|GTK_FILL, 0, 0, 0);
   table3->attach(*bo_sc_ein, 4, 5, 3, 4, GTK_EXPAND|GTK_FILL, 0, 0, 0);
   table3->attach(*bo_an_ein, 4, 5, 5, 6, GTK_EXPAND|GTK_FILL, 0, 0, 0);
   table3->attach(*bo_ab_ein, 4, 5, 6, 7, GTK_EXPAND|GTK_FILL, 0, 0, 0);
   table3->attach(*bo_za_ein, 4, 5, 7, 8, GTK_EXPAND|GTK_FILL, 0, 0, 0);
   table3->attach(*bo_psy_ein, 4, 5, 9, 10, GTK_EXPAND|GTK_FILL, 0, 0, 0);
   table3->attach(*bo_phs_ein, 4, 5, 10, 11, GTK_EXPAND|GTK_FILL, 0, 0, 0);
   table3->attach(*bo_phk_ein, 4, 5, 11, 12, GTK_EXPAND|GTK_FILL, 0, 0, 0);
   table3->attach(*hseparator4, 0, 2, 8, 9, GTK_FILL, GTK_EXPAND|GTK_FILL, 0, 0);
   table3->attach(*hseparator9, 9, 11, 8, 9, GTK_FILL, GTK_FILL, 0, 0);
   table3->attach(*hseparator5, 0, 11, 14, 15, GTK_FILL, GTK_EXPAND|GTK_FILL, 0, 0);
   table3->attach(*label174, 6, 8, 0, 1, 0, 0, 0, 0);
   table3->attach(*zaubern_ein, 7, 8, 3, 4, GTK_EXPAND|GTK_FILL, 0, 0, 0);
   table3->attach(*abwehr_ein, 7, 8, 2, 3, GTK_EXPAND|GTK_FILL, 0, 0, 0);
   table3->attach(*label249, 6, 7, 15, 16, GTK_FILL, 0, 0, 0);
   table3->attach(*gfp_ein, 7, 8, 15, 16, GTK_EXPAND|GTK_FILL, 0, 0, 0);
   table3->attach(*label250, 9, 10, 17, 18, GTK_FILL, 0, 0, 0);
   table3->attach(*version_ein, 10, 11, 17, 18, GTK_EXPAND|GTK_FILL, 0, 0, 0);
   table3->attach(*optionmenu_stand, 10, 11, 10, 11, GTK_FILL, 0, 0, 0);
   table3->attach(*pixmap25, 6, 8, 6, 9, GTK_FILL, GTK_FILL, 0, 0);
   table3->attach(*label83, 0, 1, 11, 12, GTK_FILL, 0, 0, 0);
   table3->attach(*label82, 0, 1, 10, 11, GTK_FILL, 0, 0, 0);
   table3->attach(*label81, 0, 1, 9, 10, GTK_FILL, 0, 0, 0);
   table3->attach(*label80, 0, 1, 7, 8, GTK_FILL, 0, 0, 0);
   table3->attach(*label79, 0, 1, 6, 7, GTK_FILL, 0, 0, 0);
   table3->attach(*label78, 0, 1, 5, 6, GTK_FILL, 0, 0, 0);
   table3->attach(*label77, 0, 1, 3, 4, GTK_FILL, 0, 0, 0);
   table3->attach(*label76, 0, 1, 2, 3, GTK_FILL, 0, 0, 0);
   table3->attach(*label89, 0, 1, 0, 1, GTK_FILL, 0, 0, 0);
   table3->attach(*label86, 0, 1, 15, 16, GTK_FILL, 0, 0, 0);
   table3->attach(*label87, 0, 1, 16, 17, GTK_FILL, 0, 0, 0);
   table3->attach(*label90, 0, 1, 17, 18, GTK_FILL, 0, 0, 0);
   table3->attach(*label169, 3, 4, 11, 12, GTK_FILL, 0, 0, 0);
   table3->attach(*label168, 3, 4, 10, 11, GTK_FILL, 0, 0, 0);
   table3->attach(*label167, 3, 4, 9, 10, GTK_FILL, 0, 0, 0);
   table3->attach(*label166, 3, 4, 7, 8, GTK_FILL, 0, 0, 0);
   table3->attach(*label165, 3, 4, 6, 7, GTK_FILL, 0, 0, 0);
   table3->attach(*label164, 3, 4, 5, 6, GTK_FILL, 0, 0, 0);
   table3->attach(*label163, 3, 4, 3, 4, GTK_FILL, 0, 0, 0);
   table3->attach(*label162, 3, 4, 2, 3, GTK_FILL, 0, 0, 0);
   table3->attach(*label175, 6, 7, 2, 3, GTK_FILL, 0, 0, 0);
   table3->attach(*label176, 6, 7, 3, 4, GTK_FILL, 0, 0, 0);
   table3->attach(*label115, 9, 10, 16, 17, GTK_FILL, 0, 0, 0);
   table3->attach(*label114, 9, 10, 15, 16, GTK_FILL, 0, 0, 0);
   table3->attach(*label102, 9, 10, 12, 13, GTK_FILL, 0, 0, 0);
   table3->attach(*label101, 9, 10, 11, 12, GTK_FILL, 0, 0, 0);
   table3->attach(*label100, 9, 10, 10, 11, GTK_FILL, 0, 0, 0);
   table3->attach(*label99, 9, 10, 9, 10, GTK_FILL, 0, 0, 0);
   table3->attach(*label92, 9, 10, 5, 6, GTK_FILL, 0, 0, 0);
   table3->attach(*label94, 9, 10, 3, 4, GTK_FILL, 0, 0, 0);
   table3->attach(*label93, 9, 10, 2, 3, GTK_FILL, 0, 0, 0);
   table3->attach(*label91, 9, 10, 0, 1, GTK_FILL, 0, 0, 0);
   table3->attach(*vseparator5, 2, 3, 0, 17, GTK_FILL, GTK_FILL, 0, 0);
   table3->attach(*label481, 0, 1, 12, 13, GTK_FILL, 0, 0, 0);
   table3->attach(*wk_ein, 1, 2, 12, 13, GTK_EXPAND|GTK_FILL, 0, 0, 0);
   table3->attach(*label482, 0, 1, 4, 5, GTK_FILL, 0, 0, 0);
   table3->attach(*gs_ein, 1, 2, 4, 5, GTK_EXPAND|GTK_FILL, 0, 0, 0);
   table3->attach(*optionmenu_hand, 10, 11, 6, 7, GTK_FILL, 0, 0, 0);
   table3->attach(*label499, 6, 7, 16, 17, GTK_FILL, 0, 0, 0);
   table3->attach(*gg_ein, 7, 8, 16, 17, GTK_EXPAND|GTK_FILL, 0, 0, 0);
   table3->attach(*vseparator6, 5, 6, 0, 18, GTK_FILL, GTK_FILL, 0, 0);
   table3->attach(*vseparator7, 8, 9, 0, 18, GTK_EXPAND|GTK_FILL, GTK_FILL, 0, 0);
   table3->attach(*label501, 6, 7, 17, 18, GTK_FILL, 0, 0, 0);
   table3->attach(*sg_ein, 7, 8, 17, 18, GTK_EXPAND|GTK_FILL, 0, 0, 0);
   table3->attach(*label179, 6, 7, 4, 5, GTK_FILL, 0, 0, 0);
   table3->attach(*resistenz_ein, 7, 8, 4, 5, GTK_EXPAND|GTK_FILL, 0, 0, 0);
   table3->attach(*hseparator6, 0, 12, 1, 2, GTK_FILL, GTK_EXPAND|GTK_FILL, 0, 0);
   table3->attach(*pixmap55, 11, 13, 2, 13, GTK_EXPAND|GTK_FILL, GTK_FILL, 0, 0);
   table3->attach(*toolbar18, 11, 13, 17, 18, 0, 0, 0, 0);
   table3->attach(*label525, 11, 12, 0, 1, GTK_FILL, 0, 0, 0);
   table3->attach(*spinbutton_steigertage, 12, 13, 0, 1, GTK_EXPAND|GTK_FILL, 0, 0, 0);
   frame13->set_label_align(0, 0);
   frame13->set_shadow_type(GTK_SHADOW_ETCHED_IN);
   frame13->add(*table3);
   Window_werte_editieren->set_title("Werte editieren");
   Window_werte_editieren->set_modal(true);
   Window_werte_editieren->add(*frame13);
   st_ein->show();
   gw_ein->show();
   ko_ein->show();
   in_ein->show();
   zt_ein->show();
   au_ein->show();
   pa_ein->show();
   sb_ein->show();
   b_ein->show();
   lp_ein->show();
   ap_ein->show();
   grad_ein->show();
   alter_ein->show();
   gewicht_ein->show();
   groesse_ein->show();
   gestalt_ein->show();
   spezialisierung_ein->show();
   herkunft_ein->show();
   glaube_ein->show();
   name_spieler_ein->show();
   name_charakter_ein->show();
   label161->show();
   bo_au_ein->show();
   bo_sc_ein->show();
   bo_an_ein->show();
   bo_ab_ein->show();
   bo_za_ein->show();
   bo_psy_ein->show();
   bo_phs_ein->show();
   bo_phk_ein->show();
   hseparator4->show();
   hseparator9->show();
   hseparator5->show();
   label174->show();
   zaubern_ein->show();
   abwehr_ein->show();
   label249->show();
   gfp_ein->show();
   label250->show();
   version_ein->show();
   optionmenu_stand->show();
   pixmap25->show();
   label83->show();
   label82->show();
   label81->show();
   label80->show();
   label79->show();
   label78->show();
   label77->show();
   label76->show();
   label89->show();
   label86->show();
   label87->show();
   label90->show();
   label169->show();
   label168->show();
   label167->show();
   label166->show();
   label165->show();
   label164->show();
   label163->show();
   label162->show();
   label175->show();
   label176->show();
   label115->show();
   label114->show();
   label102->show();
   label101->show();
   label100->show();
   label99->show();
   label92->show();
   label94->show();
   label93->show();
   label91->show();
   vseparator5->show();
   label481->show();
   wk_ein->show();
   label482->show();
   gs_ein->show();
   optionmenu_hand->show();
   label499->show();
   gg_ein->show();
   vseparator6->show();
   vseparator7->show();
   label501->show();
   sg_ein->show();
   label179->show();
   resistenz_ein->show();
   hseparator6->show();
   pixmap55->show();
   toolbar18->show();
   label525->show();
   spinbutton_steigertage->show();
   table3->show();
   frame13->show();
   Window_werte_editieren->show();
   st_ein->activate.connect_after(SigC::slot(static_cast<class Window_werte_editieren*>(this), &Window_werte_editieren::st_activate));
   gw_ein->activate.connect_after(SigC::slot(static_cast<class Window_werte_editieren*>(this), &Window_werte_editieren::gw_activate));
   ko_ein->activate.connect_after(SigC::slot(static_cast<class Window_werte_editieren*>(this), &Window_werte_editieren::ko_activate));
   in_ein->activate.connect_after(SigC::slot(static_cast<class Window_werte_editieren*>(this), &Window_werte_editieren::in_activate));
   zt_ein->activate.connect_after(SigC::slot(static_cast<class Window_werte_editieren*>(this), &Window_werte_editieren::zt_activate));
   au_ein->activate.connect_after(SigC::slot(static_cast<class Window_werte_editieren*>(this), &Window_werte_editieren::au_activate));
   pa_ein->activate.connect_after(SigC::slot(static_cast<class Window_werte_editieren*>(this), &Window_werte_editieren::pa_activate));
   sb_ein->activate.connect_after(SigC::slot(static_cast<class Window_werte_editieren*>(this), &Window_werte_editieren::sb_activate));
   b_ein->activate.connect_after(SigC::slot(static_cast<class Window_werte_editieren*>(this), &Window_werte_editieren::b_activate));
   lp_ein->activate.connect_after(SigC::slot(static_cast<class Window_werte_editieren*>(this), &Window_werte_editieren::lp_activate));
   ap_ein->activate.connect_after(SigC::slot(static_cast<class Window_werte_editieren*>(this), &Window_werte_editieren::ap_activate));
   grad_ein->activate.connect_after(SigC::slot(static_cast<class Window_werte_editieren*>(this), &Window_werte_editieren::grad_activate));
   alter_ein->activate.connect_after(SigC::slot(static_cast<class Window_werte_editieren*>(this), &Window_werte_editieren::alter_activate));
   gewicht_ein->activate.connect_after(SigC::slot(static_cast<class Window_werte_editieren*>(this), &Window_werte_editieren::gewicht_activate));
   groesse_ein->activate.connect_after(SigC::slot(static_cast<class Window_werte_editieren*>(this), &Window_werte_editieren::groesse_activate));
   gestalt_ein->activate.connect_after(SigC::slot(static_cast<class Window_werte_editieren*>(this), &Window_werte_editieren::gestalt_activate));
   spezialisierung_ein->activate.connect_after(SigC::slot(static_cast<class Window_werte_editieren*>(this), &Window_werte_editieren::spezial_activate));
   herkunft_ein->activate.connect_after(SigC::slot(static_cast<class Window_werte_editieren*>(this), &Window_werte_editieren::her_activate));
   glaube_ein->activate.connect_after(SigC::slot(static_cast<class Window_werte_editieren*>(this), &Window_werte_editieren::glau_activate));
   name_spieler_ein->activate.connect_after(SigC::slot(static_cast<class Window_werte_editieren*>(this), &Window_werte_editieren::ns_activate));
   name_charakter_ein->activate.connect_after(SigC::slot(static_cast<class Window_werte_editieren*>(this), &Window_werte_editieren::nc_activate));
   bo_au_ein->activate.connect_after(SigC::slot(static_cast<class Window_werte_editieren*>(this), &Window_werte_editieren::bau_activate));
   bo_sc_ein->activate.connect_after(SigC::slot(static_cast<class Window_werte_editieren*>(this), &Window_werte_editieren::sc_activate));
   bo_an_ein->activate.connect_after(SigC::slot(static_cast<class Window_werte_editieren*>(this), &Window_werte_editieren::an_activate));
   bo_ab_ein->activate.connect_after(SigC::slot(static_cast<class Window_werte_editieren*>(this), &Window_werte_editieren::ab_activate));
   bo_za_ein->activate.connect_after(SigC::slot(static_cast<class Window_werte_editieren*>(this), &Window_werte_editieren::bzt_activate));
   bo_psy_ein->activate.connect_after(SigC::slot(static_cast<class Window_werte_editieren*>(this), &Window_werte_editieren::psy_activate));
   bo_phs_ein->activate.connect_after(SigC::slot(static_cast<class Window_werte_editieren*>(this), &Window_werte_editieren::phs_activate));
   bo_phk_ein->activate.connect_after(SigC::slot(static_cast<class Window_werte_editieren*>(this), &Window_werte_editieren::phk_activate));
   zaubern_ein->activate.connect_after(SigC::slot(static_cast<class Window_werte_editieren*>(this), &Window_werte_editieren::wza_activate));
   abwehr_ein->activate.connect_after(SigC::slot(static_cast<class Window_werte_editieren*>(this), &Window_werte_editieren::wab_activate));
   gfp_ein->activate.connect(SigC::slot(static_cast<class Window_werte_editieren*>(this), &Window_werte_editieren::gfp_activate));
   version_ein->activate.connect(SigC::slot(static_cast<class Window_werte_editieren*>(this), &Window_werte_editieren::vers_activate));
   wk_ein->activate.connect_after(SigC::slot(static_cast<class Window_werte_editieren*>(this), &Window_werte_editieren::wk_activate));
   gs_ein->activate.connect_after(SigC::slot(static_cast<class Window_werte_editieren*>(this), &Window_werte_editieren::gs_activate));
   gg_ein->activate.connect(SigC::slot(static_cast<class Window_werte_editieren*>(this), &Window_werte_editieren::gg_activate));
   sg_ein->activate.connect(SigC::slot(static_cast<class Window_werte_editieren*>(this), &Window_werte_editieren::gs_activate));
   resistenz_ein->activate.connect_after(SigC::slot(static_cast<class Window_werte_editieren*>(this), &Window_werte_editieren::re_activate));
   button47->clicked.connect(SigC::slot(static_cast<class Window_werte_editieren*>(this), &Window_werte_editieren::on_nwe_close_clicked));
   spinbutton_steigertage->activate.connect(SigC::slot(static_cast<class Window_werte_editieren*>(this), &Window_werte_editieren::on_spinbutton_steigertage_activate));
}

Window_werte_editieren_glade::~Window_werte_editieren_glade()
{   
}
