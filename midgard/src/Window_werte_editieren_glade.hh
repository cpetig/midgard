// generated 2001/8/28 15:08:04 CEST by thoma@Tiger.
// using glademm V0.6.2_cvs
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- /home/thoma/rollenspiel/midgard/programme/gcc_3.0/midgard/midgard.glade
// for gtk 1.2.8 and gtkmm 1.2.5
//
// Please modify the corresponding derived classes in ./src/Window_werte_editieren.hh and./src/Window_werte_editieren.cc

#ifndef _WINDOW_WERTE_EDITIEREN_GLADE_HH
#  define _WINDOW_WERTE_EDITIEREN_GLADE_HH

#include <gtk--/window.h>
#include <gtk--/spinbutton.h>
#include <gtk--/entry.h>
#include <gtk--/optionmenu.h>

class Window_werte_editieren_glade : public Gtk::Window
{   
protected:
        
        class Gtk::Window *Window_werte_editieren;
        class Gtk::SpinButton *st_ein;
        class Gtk::SpinButton *ge_ein;
        class Gtk::SpinButton *ko_ein;
        class Gtk::SpinButton *in_ein;
        class Gtk::SpinButton *zt_ein;
        class Gtk::SpinButton *au_ein;
        class Gtk::SpinButton *pa_ein;
        class Gtk::SpinButton *sb_ein;
        class Gtk::SpinButton *rw_ein;
        class Gtk::SpinButton *hgw_ein;
        class Gtk::SpinButton *b_ein;
        class Gtk::SpinButton *lp_ein;
        class Gtk::SpinButton *ap_ein;
        class Gtk::SpinButton *grad_ein;
        class Gtk::SpinButton *alter_ein;
        class Gtk::SpinButton *gewicht_ein;
        class Gtk::SpinButton *groesse_ein;
        class Gtk::Entry *gestalt_ein;
        class Gtk::Entry *spezialisierung_ein;
        class Gtk::Entry *herkunft_ein;
        class Gtk::Entry *glaube_ein;
        class Gtk::Entry *name_spieler_ein;
        class Gtk::Entry *name_charakter_ein;
        class Gtk::SpinButton *bo_au_ein;
        class Gtk::SpinButton *bo_sc_ein;
        class Gtk::SpinButton *bo_an_ein;
        class Gtk::SpinButton *bo_ab_ein;
        class Gtk::SpinButton *bo_za_ein;
        class Gtk::SpinButton *bo_psy_ein;
        class Gtk::SpinButton *bo_phs_ein;
        class Gtk::SpinButton *bo_phk_ein;
        class Gtk::SpinButton *bo_gi_ein;
        class Gtk::SpinButton *lpbasis_ein;
        class Gtk::SpinButton *kaw_ein;
        class Gtk::SpinButton *resistenz_ein;
        class Gtk::SpinButton *zaubern_ein;
        class Gtk::SpinButton *abwehr_ein;
        class Gtk::SpinButton *gfp_ein;
        class Gtk::Entry *version_ein;
        class Gtk::OptionMenu *optionmenu_stand;
        struct optionmenu_stand
        {   enum enum_t 
	   {   STAND, Unfrei, Volk, Mittelschicht, Adel, 
	   };
        };
        class Gtk::SpinButton *wlw_ein;
        
        Window_werte_editieren_glade();
        
        ~Window_werte_editieren_glade();
};
#endif
