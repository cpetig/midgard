/*  Midgard Character Generator
 *  Copyright (C) 2001-2002 Malte Thoma
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

#include "table_steigern.hh"
#include "midgard_CG.hh"
#include "class_SimpleTree.hh"
#include "Fertigkeiten.hh"
#include "Sprache.hh"
#include "Zauber.hh"
#include <Misc/itos.h>

bool table_steigern::MidgardBasicElement_leaf_alt(const cH_RowDataBase &d)
{
 const Data_SimpleTree *dt=dynamic_cast<const Data_SimpleTree*>(&*d);
 MBEmlt &MBE = const_cast<MBEmlt&>(dt->getMBE());
 if(togglebutton_praxispunkte->get_active() && radiobutton_pp_fertigkeit->get_active()) 
  {
   spinbutton_pp_eingeben->set_value(MBE->Praxispunkte());
   spinbutton_pp_eingeben->select_region(0,-1);
   spinbutton_pp_eingeben->show();
   spinbutton_pp_eingeben->grab_focus();
   return false;
  }

 ////////////////////////////////////////////////////////////////////////
 std::list<MBEmlt> *MyList,*MyList_neu;
 if((*MBE).What()==MidgardBasicElement::FERTIGKEIT) 
   { if ((*MBE)->Name()=="KiDo" && kido_steigern_check(MBE->Erfolgswert())) return false;
     MyList     = &hauptfenster->getChar()->List_Fertigkeit(); MyList_neu = &list_Fertigkeit_neu;   }
 else if((*MBE).What()==MidgardBasicElement::WAFFE) 
   { MyList     = &hauptfenster->getChar()->List_Waffen(); MyList_neu = &list_Waffen_neu;  }
 else if((*MBE).What()==MidgardBasicElement::WAFFEGRUND) 
   { MyList     = &hauptfenster->getChar()->List_WaffenGrund(); MyList_neu = &list_WaffenGrund_neu;  }
 else if((*MBE).What()==MidgardBasicElement::ZAUBER) 
   { MyList     = &hauptfenster->getChar()->List_Zauber(); MyList_neu = &list_Zauber_neu;  }
 else if((*MBE).What()==MidgardBasicElement::ZAUBERWERK) 
   { MyList     = &hauptfenster->getChar()->List_Zauberwerk(); MyList_neu = &list_Zauberwerk_neu;  }
 else if((*MBE).What()==MidgardBasicElement::KIDO) 
   { MyList     = &hauptfenster->getChar()->List_Kido(); MyList_neu = &list_Kido_neu;  }
 else if((*MBE).What()==MidgardBasicElement::SPRACHE) 
   { MyList     = &hauptfenster->getChar()->List_Sprache(); MyList_neu = &list_Sprache_neu;  }
 else if((*MBE).What()==MidgardBasicElement::SCHRIFT) 
   { MyList     = &hauptfenster->getChar()->List_Schrift(); MyList_neu = &list_Schrift_neu;  }
 else assert(!"Fehler (alt) in midgard_CG_basic_elemente.cc");

 //////////////////////////////////////////////////////////////////////////
 std::string info;
 Abenteurer::e_wie_steigern wie=get_wie_steigern();
 Abenteurer::st_bool_steigern bool_steigern=get_bool_steigern();
 
 if (radiobutton_steigern->get_active() && MBE->Steigern(hauptfenster->getAben()))
    {
      bool ok=hauptfenster->getAben().steigere(MBE,info,wie,bool_steigern);
      hauptfenster->set_status(info);
      if(!ok) return false;
    }
 else if (radiobutton_reduzieren->get_active() && MBE->Reduzieren(hauptfenster->getAben()))
    {
      hauptfenster->getAben().reduziere(MBE,wie,bool_steigern);
    }
 else if (radiobutton_verlernen->get_active() && MBE->Verlernen(hauptfenster->getAben()))
    {
      hauptfenster->getAben().verlerne(MBE,wie,bool_steigern);
      Abenteurer::move_element(*MyList,*MyList_neu,MBE);
    }
 else if (radiobutton_verlernen->get_active() && (*MBE).What()==MidgardBasicElement::WAFFE)
    {
      Abenteurer::move_element(*MyList,*MyList_neu,MBE);
    }
 hauptfenster->undosave((*MBE)->What_str()+" "+(*MBE)->Name()+" auf "+itos(MBE->Erfolgswert())+" gesteigert");
 return true;
}

const Enums::e_wie_steigern table_steigern::get_wie_steigern()
{
 if     (radiobutton_unterweisung->get_active()) return Enums::eUnterweisung; 
 else if(radiobutton_selbst->get_active()) return Enums::eSelbststudium; 
 else if(radiobutton_praxis->get_active()) return Enums::ePraxis; 
 assert (!"never get here"); abort();
}

const Enums::st_bool_steigern table_steigern::get_bool_steigern()
{
 return Enums::st_bool_steigern(steigern_mit_EP_bool,
         hauptfenster->getOptionen()->HausregelCheck(Magus_Optionen::Gold).active,
         togglebutton_spruchrolle->get_active(),
         !radio_spruchrolle_wuerfeln->get_active(),
         radiobutton_pp_hoch_wie_geht->get_active(),
         togglebutton_pp_verfallen->get_active(),
         togglebutton_pp_aep_fuellen->get_active(),
         togglebutton_neue_sprache_pp->get_active()
      );
}

void table_steigern::lernen_von_spruchrolle_fragen(const int bonus)
{
 const Data_SimpleTree *dt=dynamic_cast<const Data_SimpleTree*>(&*(neue_zauber_tree->getSelectedRowDataBase()));
 MBEmlt &MBE = const_cast<MBEmlt&>(dt->getMBE()); 
 neu_lernen(MBE,bonus);
}

void table_steigern::MidgardBasicElement_leaf_neu(const cH_RowDataBase &d)
{
 const Data_SimpleTree *dt=dynamic_cast<const Data_SimpleTree*>(&*d);
 MBEmlt &MBE = const_cast<MBEmlt&>(dt->getMBE());
 neu_lernen(MBE);
}

void table_steigern::neu_lernen(MBEmlt &MBE,const int bonus)
{
 std::string info;
 bool ok=hauptfenster->getChar()->neu_lernen(MBE,info,get_wie_steigern(),get_bool_steigern(),bonus);
 hauptfenster->set_status(info,false);
 if(!ok) return ;
//ab hier neuer code:
 Abenteurer &A=hauptfenster->getAben();
 if     ((*MBE).What()==MidgardBasicElement::FERTIGKEIT) 
   { if((*MBE)->ZusatzEnum(hauptfenster->getChar()->getVTyp()))
      {
        neue_fert_tree->set_sensitive(false);
        MBE=MBEmlt(&*cH_Fertigkeit(MBE->getMBE()));
        fillClistZusatz(MBE);
        // Davor stellen, damit beim Kopieren dieses MBE Verschoben wird.   
        list_Fertigkeit_neu.push_front(MBE);
      }
     A.move_neues_element(MBE,&list_Fertigkeit_neu);
   }
 else if((*MBE).What()==MidgardBasicElement::WAFFE) A.move_neues_element(MBE,&list_Waffen_neu);
 else if((*MBE).What()==MidgardBasicElement::WAFFEGRUND) A.move_neues_element(MBE,&list_WaffenGrund_neu);
 else if((*MBE).What()==MidgardBasicElement::ZAUBER) 
  { if((*MBE)->ZusatzEnum(hauptfenster->getChar()->getVTyp()))
     {  
       MBE=MBEmlt(&*cH_Zauber(MBE->getMBE()));
       fillClistZusatz(MBE);
       // Davor stellen, damit beim Kopieren dieses MBE in Verschoben wird.
       list_Zauber_neu.push_front(MBE);
     }
    A.move_neues_element(MBE,&list_Zauber_neu);
  }
 else if((*MBE).What()==MidgardBasicElement::ZAUBERWERK) A.move_neues_element(MBE,&list_Zauberwerk_neu);
 else if((*MBE).What()==MidgardBasicElement::KIDO) A.move_neues_element(MBE,&list_Kido_neu);
 else if((*MBE).What()==MidgardBasicElement::SPRACHE) A.move_neues_element(MBE,&list_Sprache_neu,&(hauptfenster->getCDatabase().Sprache));
 else if((*MBE).What()==MidgardBasicElement::SCHRIFT) A.move_neues_element(MBE,&list_Schrift_neu);
 hauptfenster->undosave((*MBE)->What_str()+" "+(*MBE)->Name()+" gelernt");
} 

