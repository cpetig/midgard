// $Id: zeige_werte.cc,v 1.29 2002/01/11 08:48:11 thoma Exp $
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

void midgard_CG::zeige_werte(const Grundwerte& w)
{
   Database.ausnahmen.set_Werte(w);       
       st->set_text(itos(w.St()));
       gw->set_text(itos(w.Gw()));
       gs->set_text(itos(w.Gs()));
       ko->set_text(itos(w.Ko()));
       in->set_text(itos(w.In()));
       zt->set_text(itos(w.Zt()));
       label_sehen->set_text(itos(w.Sehen()));
       label_hoeren->set_text(itos(w.Hoeren()));
       label_riechen->set_text(itos(w.Riechen()));
       label_schmecken->set_text(itos(w.Schmecken()));
       label_tasten->set_text(itos(w.Tasten()));
       label_sechster_sinn->set_text(itos(w.SechsterSinn()));

       au->set_text(itos(w.Au()));
       pa->set_text(itos(w.pA()));
       sb->set_text(itos(w.Sb()));      
       wk->set_text(itos(w.Wk()));      
//       rw->set_text(itos(w.RW()));    
//       hgw->set_text(itos(w.HGW())); 
       b->set_text(itos(w.B()));     
       lp->set_text(itos(w.LP()));      
       ap->set_text(itos(w.AP()));   
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
       bo_psy->set_text(itos(w.bo_Psy())) ;
       bo_phs->set_text(itos(w.bo_Phs())) ;
       bo_phk->set_text(itos(w.bo_Phk())) ;
//       bo_gi->set_text(itos(w.bo_Gift())) ;
       alter->set_text(itos(w.Alter()));
       gestalt->set_text(w.Gestalt());  
       gewicht->set_text(itos(w.Gewicht()));
       groesse->set_text(itos(w.Groesse()));
       grad->set_text(itos(w.Grad()));      
       spezialisierung->set_text(w.Spezialisierung());
       stand->set_text(w.Stand());
       herkunft->set_text(w.Herkunft()->Name());
       glaube->set_text(w.Glaube());
       name_charakter->set_text(w.Name_Charakter());
       name_spieler->set_text(w.Name_Spieler());
       gfp->set_text(itos(w.GFP()));

       label_s_grad->set_text(itos(w.Grad()));
       label_s_ap->set_text(itos(w.AP()));
       label_s_abwehr->set_text(itos(w.Abwehr_wert()));
       label_s_zaubern->set_text(itos(w.Zaubern_wert()));
       label_s_resistenz->set_text(itos(w.Resistenz()));
       label_pp_abwehr->set_text(itos(w.AbwehrPP()));
       label_pp_zaubern->set_text(itos(w.ZaubernPP()));
       label_pp_resistenz->set_text(itos(w.ResistenzPP()));
       label_steigertage->set_text(dtos(w.Steigertage()));
       label_alter->set_text(dtos(w.Alter()));
}
