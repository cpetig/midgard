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
#include "class_SimpleTree.hh"
#include "KiDo.hh"

void midgard_CG::on_kido_laden_clicked()
{   
  list_Kido_neu.clear();
  int erfolgswert_kido = KiDo::get_erfolgswert_kido(Char.CList_Fertigkeit());
  KiDo_Stile kido_stil;
  if (!kido_stil.ist_gelernt(getCWerte().Spezialisierung())) 
     {
       set_status("Erst einen KiDo-Stil w�hlen\n(unter 'Lernschema'->'KiDo')");
       return;
     }
  for (std::list<cH_MidgardBasicElement>::const_iterator i=Database.Kido.begin();i!=Database.Kido.end();++i)
   { cH_KiDo kd(*i);
     if ((*i)->ist_gelernt(Char.CList_Kido())) continue ;
     // Stufe
     if (getCWerte().Grad()<4 || erfolgswert_kido+getCWerte().bo_Za() <15)
      if(kd->Stufe()=="Eingeweihter") continue;
     if (getCWerte().Grad()<6 || erfolgswert_kido+getCWerte().bo_Za() <18)
      if(kd->Stufe()=="Meister") continue;
     // Stil
     if (kido_stil.ist_hart(getCWerte().Spezialisierung()))
       if(kido_stil.ist_sanft(kd->Stil())) continue;
     if (kido_stil.ist_sanft(getCWerte().Spezialisierung()))
       if(kido_stil.ist_hart(kd->Stil())) continue;
   
     // Anzahl
     bool gem_technik = (kido_stil.ist_gemischt(getCWerte().Spezialisierung()));
     std::map<std::string,int> MK = KiDo::maxkidostil(Char.CList_Kido());  
     int maxS = MK["Sch�ler"];
     int maxE = MK["Eingeweihter"];
     int maxM = MK["Meister"];
     if((kd->Stufe()=="Sch�ler"     && gem_technik && maxS <11)||
        (kd->Stufe()=="Sch�ler"     &&!gem_technik && maxS <12)||
        (kd->Stufe()=="Eingeweihter"&& gem_technik && maxE < 6)||
        (kd->Stufe()=="Eingeweihter"&&!gem_technik && maxE < 7)||
        (kd->Stufe()=="Meister"     && gem_technik && maxM < 2)||
        (kd->Stufe()=="Meister"     &&!gem_technik && maxM < 3) )
    list_Kido_neu.push_back(*i);
    }
 kido_zeigen();
}

void midgard_CG::kido_zeigen()
{
 zeige_werte();
 MidgardBasicElement::show_list_in_tree(Char.List_Kido()    ,alte_kido_tree,this);
 MidgardBasicElement::show_list_in_tree(list_Kido_neu,neue_kido_tree,this);
}

void midgard_CG::on_leaf_selected_alte_kido(cH_RowDataBase d)
{  
  if(MidgardBasicElement_leaf_alt(d))
     on_kido_laden_clicked();
}

void midgard_CG::on_leaf_selected_neue_kido(cH_RowDataBase d)
{  
  MidgardBasicElement_leaf_neu(d);
  on_kido_laden_clicked();
}

void midgard_CG::on_alte_kido_reorder()
{
  std::deque<guint> seq = alte_kido_tree->get_seq();
  switch((Data_SimpleTree::Spalten_KIDO)seq[0]) {
      case Data_SimpleTree::HOHOa_K  : Char.List_Kido().sort(cH_KiDo::sort(cH_KiDo::sort::HOHO)) ;break;
      case Data_SimpleTree::NAMEa_K  : Char.List_Kido().sort(cH_KiDo::sort(cH_KiDo::sort::NAME)) ;break;
      case Data_SimpleTree::STUFEa_K : Char.List_Kido().sort(cH_KiDo::sort(cH_KiDo::sort::STUFE)) ;break;
      case Data_SimpleTree::APa_K    : Char.List_Kido().sort(cH_KiDo::sort(cH_KiDo::sort::AP)); break;
      case Data_SimpleTree::STILa_K  : Char.List_Kido().sort(cH_KiDo::sort(cH_KiDo::sort::STIL)) ;break;
      default : set_status("Sortieren nach diesem Parameter\n ist nicht m�glich");
   }
}
