// generated 2002/9/16 21:06:52 CEST by thoma@Tiger.(none)
// using glademm V1.1.1c_cvs
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- /home/thoma/rollenspiel/midgard/programme/gcc_3.0/midgard/midgard.glade
// for gtk 1.2.10 and gtkmm 1.2.10
//
// Please modify the corresponding derived classes in ./src/table_grundwerte.hh and./src/table_grundwerte.cc

#ifndef _TABLE_GRUNDWERTE_GLADE_HH
#  define _TABLE_GRUNDWERTE_GLADE_HH


#if !defined(GLADEMM_DATA)
#define GLADEMM_DATA 
#include <gtk--/accelgroup.h>

class GlademmData
{  
        
        Gtk::AccelGroup *accgrp;
public:
        
        GlademmData(Gtk::AccelGroup *ag) : accgrp(ag)
        {  
        }
        
        Gtk::AccelGroup * getAccelGroup()
        {  return accgrp;
        }
};
#endif //GLADEMM_DATA

#include <gtk--/table.h>
#include <gtk--/tooltips.h>
#include <gtk--/label.h>
#include <gtk--/button.h>
#include <gtk--/spinbutton.h>
#include <gtk--/pixmap.h>
#include <gtk--/entry.h>
#include <gtk--/combo.h>
#include <gtk--/radiobutton.h>
#include <gtk--/box.h>
#include <gtk--/togglebutton.h>
#include <gtk--/frame.h>

class table_grundwerte_glade : public Gtk::Table
{  
protected:
        
        Gtk::Tooltips _tooltips;
        class Gtk::Table *table_grundwerte;
        class Gtk::Label *resistenz;
        class Gtk::Label *gift_wert;
        class Gtk::Label *abwehr_wert;
        class Gtk::Label *zaubern_wert;
        class Gtk::Button *button_grda1setzen;
        class Gtk::Label *bo_sc;
        class Gtk::Label *bo_an;
        class Gtk::Label *bo_ab;
        class Gtk::Label *bo_za;
        class Gtk::Label *bo_au;
        class Gtk::Label *bo_psy;
        class Gtk::Label *bo_phs;
        class Gtk::Label *bo_phk;
        class Gtk::Label *label_gestalt;
        class Gtk::Label *kaw;
        class Gtk::Label *wlw;
        class Gtk::SpinButton *spinbutton_b;
        class Gtk::SpinButton *spinbutton_au;
        class Gtk::SpinButton *spinbutton_pa;
        class Gtk::SpinButton *spinbutton_sb;
        class Gtk::SpinButton *spinbutton_wk;
        class Gtk::SpinButton *spinbutton_st;
        class Gtk::SpinButton *spinbutton_gs;
        class Gtk::SpinButton *spinbutton_gw;
        class Gtk::SpinButton *spinbutton_ko;
        class Gtk::SpinButton *spinbutton_in;
        class Gtk::SpinButton *spinbutton_zt;
        class Gtk::Label *label_hoeren;
        class Gtk::Label *label_schmecken;
        class Gtk::Label *label_tasten;
        class Gtk::Label *label_sehen;
        class Gtk::Label *label_riechen;
        class Gtk::Label *label_sechster_sinn;
        class Gtk::Pixmap *pixmap_dfr4;
        class Gtk::Entry *entry_nameC;
        class Gtk::SpinButton *spinbutton_ap;
        class Gtk::SpinButton *spinbutton_lp;
        class Gtk::SpinButton *spinbutton_grad;
        class Gtk::SpinButton *spinbutton_alter;
        class Gtk::SpinButton *spinbutton_Cgewicht;
        class Gtk::SpinButton *spinbutton_groesse;
        class Gtk::Entry *entry_nameS;
        class Gtk::Entry *entry_version;
        class Gtk::Entry *entry_herkunft;
        class Gtk::Combo *combo_stand;
        class Gtk::Entry *entry_glaube;
        class Gtk::Entry *entry_spezialisierung;
        class Gtk::SpinButton *spinbutton_tage;
        class Gtk::SpinButton *spinbutton_gg;
        class Gtk::SpinButton *spinbutton_sg;
        class Gtk::SpinButton *spinbutton_gfp;
        class Gtk::Combo *combo_hand;
        class Gtk::Entry *entry_bezeichnung;
        class Gtk::Entry *entry_merkmale;
        class Gtk::Combo *combo_spezies;
        class Gtk::RadioButton *radiobutton_eigenschaften_standard;
        class Gtk::RadioButton *radiobutton_eigenschaften_zuweisen;
        class Gtk::RadioButton *radiobutton_eigenschaften_69;
        class Gtk::VBox *vbox_gw_wuerfeln;
        class Gtk::RadioButton *radiobutton_mann;
        class Gtk::RadioButton *radiobutton_frau;
        class Gtk::Combo *combo_typ;
        class Gtk::Combo *combo_typ2;
        class Gtk::RadioButton *radiobutton_stadt;
        class Gtk::RadioButton *radiobutton_land;
        class Gtk::Button *button_grundwerte;
        class Gtk::Button *button_abg_werte;
        class Gtk::ToggleButton *togglebutton_edit_werte;
        class Gtk::Frame *frame_wuerfelvariante;
        
        table_grundwerte_glade(GlademmData *_data);
        
        ~table_grundwerte_glade();
};
#endif
