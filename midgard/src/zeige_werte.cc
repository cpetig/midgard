// $Id: zeige_werte.cc,v 1.47 2002/02/13 11:21:00 thoma Exp $
/*  Midgard Character Generator
 *  Copyright (C) 2001 Malte Thoma
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#include "midgard_CG.hh"
//#include "class_spezies.hh"
#include "dtos1.h"
#include <Aux/itos.h>
#include <Aux/fixedpoint.h>
#include <Aux/Ausgabe_neu.h>
#include "Grad_anstieg.hh"

void midgard_CG::zeige_werte(const Grundwerte& w)
{
   if (OptionenCheck(Original).active) original_midgard_check() ;
   Database.ausnahmen.set_Werte(w);       
       spinbutton_st->set_value(w.St());
       spinbutton_gw->set_value(w.Gw());
       spinbutton_gs->set_value(w.Gs());
       spinbutton_ko->set_value(w.Ko());
       spinbutton_in->set_value(w.In());
       spinbutton_zt->set_value(w.Zt());
       label_sehen->set_text(itos(w.Sehen()));
       label_hoeren->set_text(itos(w.Hoeren()));
       label_riechen->set_text(itos(w.Riechen()));
       label_schmecken->set_text(itos(w.Schmecken()));
       label_tasten->set_text(itos(w.Tasten()));
       label_sechster_sinn->set_text(itos(w.SechsterSinn()));

       spinbutton_au->set_value(w.Au());
       spinbutton_pa->set_value(w.pA());
       spinbutton_sb->set_value(w.Sb());      
       spinbutton_wk->set_value(w.Wk());      
       spinbutton_b->set_value(w.B());     
       spinbutton_lp->set_value(w.LP());      
       spinbutton_ap->set_value(w.AP());   
       abwehr_wert->set_text(itos(w.Abwehr_wert()));
       zaubern_wert->set_text(itos(w.Zaubern_wert()));
       kaw->set_text(itos(w.KAW()));
       wlw->set_text(itos(w.WLW()));
       resistenz->set_text(itos(w.Resistenz()));
       gift_wert->set_text(itos(w.Gift()));
       bo_au->set_text(itos(w.bo_Au())) ;
       bo_sc->set_text(itos(w.bo_Sc())) ;
       bo_an->set_text(itos(w.bo_An())) ;
       bo_ab->set_text(itos(w.bo_Ab())) ;
       bo_za->set_text(itos(w.bo_Za())) ;
       bo_psy->set_text(itos(w.bo_Psy(Typ))) ;
       bo_phs->set_text(itos(w.bo_Phs(Typ))) ;
       bo_phk->set_text(itos(w.bo_Phk(Typ))) ;
       spinbutton_alter->set_value(w.Alter());
       spinbutton_gfp->set_value(w.GFP());
       spinbutton_tage->set_value(w.Steigertage());
//       spinbutton_tage->set_text(Formatiere_short(fixedpoint<1>(w.Steigertage())));
       spinbutton_gg->set_value(w.GG());
       spinbutton_sg->set_value(w.SG());
       label_gestalt->set_text(w.Gestalt());  
       spinbutton_Cgewicht->set_value(w.Gewicht());
       spinbutton_groesse->set_value(w.Groesse());
       spinbutton_grad->set_value(w.Grad());      
       entry_spezialisierung->set_text(w.Spezialisierung());
       {
        int inr=0;
        for (unsigned int i=0; i<Vstand.size();++i)
           if (Vstand[i]==Werte.Stand()) inr=i;
        optionmenu_stand->set_history(inr);
       }
       {
        int inr=0;
        for (unsigned int i=0; i<Vhand.size();++i)
           if (Vhand[i]==Werte.Hand()) inr=i;
        optionmenu_hand->set_history(inr);
       }
       entry_herkunft->set_text(w.Herkunft()->Name());
       entry_glaube->set_text(w.Glaube());
       entry_nameC->set_text(w.Name_Abenteurer());
       entry_nameS->set_text(w.Name_Spieler());
       entry_version->set_text(w.Version());
       gfp->set_text(itos(w.GFP()));

       label_ruestung_lernschema->set_text(Werte.Ruestung()->Long());
       label_herkunft_lernschema->set_text(Werte.Herkunft()->Name());
      
       label_s_grad->set_text(itos(w.Grad()));
       label_s_ap->set_text(itos(w.AP()));
       label_s_abwehr->set_text(itos(w.Abwehr_wert()));
       label_s_zaubern->set_text(itos(w.Zaubern_wert()));
       label_s_resistenz->set_text(itos(w.Resistenz()));
       label_pp_abwehr->set_text(itos(w.AbwehrPP()));
       label_pp_zaubern->set_text(itos(w.ZaubernPP()));
       label_pp_resistenz->set_text(itos(w.ResistenzPP()));
       label_steigertage->set_text(dtos1(w.Steigertage()));
       label_steigertage->set_text(Formatiere_short(fixedpoint<1>(w.Steigertage())));
       label_alter->set_text(itos(w.Alter()));

   
   label_grad_GFP->set_text(Database.GradAnstieg.getGFP_for_str(Grad_anstieg::Grad,Werte));
   label_ausdauer_GFP->set_text(Database.GradAnstieg.getGFP_for_str(Grad_anstieg::Ausdauer,Werte));
   label_abwehr_GFP->set_text(Database.GradAnstieg.getGFP_for_str(Grad_anstieg::Abwehr,Werte));
   label_resistenz_GFP->set_text(Database.GradAnstieg.getGFP_for_str(Grad_anstieg::Resistenz,Werte));
   std::string z=Database.GradAnstieg.getGFP_for_str(Grad_anstieg::Zaubern,Werte);
   if(!Typ[0]->is_mage() && !Typ[1]->is_mage()) z="";
   label_zauber_GFP->set_text(z);
}
