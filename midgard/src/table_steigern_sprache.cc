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
#include "table_steigern.hh"
#include "Sprache.hh"
#include "Schrift.hh"
#include "class_SimpleTree.hh"

void table_steigern::on_schrift_laden_clicked()
{   
   list_Schrift_neu.clear();
   for (std::list<cH_MidgardBasicElement>::const_iterator i=hauptfenster->getCDatabase().Schrift.begin();i!=hauptfenster->getCDatabase().Schrift.end();++i)
    { cH_Schrift s(*i);
      if((*i)->ist_gelernt(hauptfenster->getCChar().CList_Schrift())) continue;
      if (hauptfenster->region_check(s->Region()) )  
         if(s->kann_Sprache(hauptfenster->getCChar().CList_Sprache()))
           { s->setErfolgswert(cH_Fertigkeit("Schreiben")->Anfangswert());
             list_Schrift_neu.push_back(*i) ;
           }
    }
   schriften_zeigen();
}

void table_steigern::on_sprache_laden_clicked()
{   
   list_Sprache_neu.clear();
   for (std::list<cH_MidgardBasicElement>::const_iterator i=hauptfenster->getCDatabase().Sprache.begin();i!=hauptfenster->getCDatabase().Sprache.end();++i)
    { cH_Sprache s(*i);
      if((*i)->ist_gelernt(hauptfenster->getCChar().CList_Sprache())) continue;
      if (hauptfenster->region_check(s->Region()) )  
        {  s->setErfolgswert(cH_Fertigkeit("Sprache")->Anfangswert());
           list_Sprache_neu.push_back(*i) ;
        }
    }
   sprachen_zeigen();
   on_schrift_laden_clicked();
}   

void table_steigern::schriften_zeigen()
{
   zeige_werte();
   MidgardBasicElement::show_list_in_tree(hauptfenster->getCChar().CList_Schrift()    ,alte_schrift_tree,hauptfenster);
   MidgardBasicElement::show_list_in_tree(list_Schrift_neu,neue_schrift_tree,hauptfenster);
}

void table_steigern::sprachen_zeigen()
{
   zeige_werte();
   MidgardBasicElement::show_list_in_tree(hauptfenster->getCChar().CList_Sprache()    ,alte_sprache_tree,hauptfenster);
   MidgardBasicElement::show_list_in_tree(list_Sprache_neu,neue_sprache_tree,hauptfenster);
}


void table_steigern::on_leaf_selected_neue_sprache(cH_RowDataBase d)
{  
  MidgardBasicElement_leaf_neu(d);
  sprachen_zeigen();
  on_schrift_laden_clicked();
}
    
void table_steigern::on_leaf_selected_alte_sprache(cH_RowDataBase d)
{  
  const Data_SimpleTree *dt=dynamic_cast<const Data_SimpleTree*>(&*d);
  if(dt->getMBE()->What()==MidgardBasicElement::SPRACHE)
   {
     cH_Fertigkeit F("Sprache");
     if( radiobutton_unterweisung->get_active() &&
         dt->getMBE()->Erfolgswert() >= F->MaxUnterweisung())
      {
        hauptfenster->set_status("Weitere Steigerung des Erfolgswertes ist NICHT mit Unterweisung m�glich.");
        return;
      }
   }
  if(MidgardBasicElement_leaf_alt(d))
   {
     neue_schrift_wegen_sprache();
     on_sprache_laden_clicked();
   }
}
    
void table_steigern::on_alte_sprache_reorder()
{
  std::deque<guint> seq = alte_sprache_tree->get_seq();
  switch((Data_SimpleTree::Spalten_LONG_ALT)seq[0]) {
      case Data_SimpleTree::NAMEa : hauptfenster->getChar().List_Sprache().sort(cH_MidgardBasicElement::sort(cH_MidgardBasicElement::sort::NAME)); ;break;
      case Data_SimpleTree::WERTa : hauptfenster->getChar().List_Sprache().sort(cH_MidgardBasicElement::sort(cH_MidgardBasicElement::sort::ERFOLGSWERT)); ;break;
      default : hauptfenster->set_status("Sortieren nach diesem Parameter\n ist nicht m�glich");
   }
}


void table_steigern::on_leaf_selected_alte_schrift(cH_RowDataBase d)
{  
  const Data_SimpleTree *dt=dynamic_cast<const Data_SimpleTree*>(&*d);
  if(dt->getMBE()->What()==MidgardBasicElement::SCHRIFT)
   {
     cH_Fertigkeit F("Schreiben");
     if( radiobutton_unterweisung->get_active() &&
         dt->getMBE()->Erfolgswert() >= F->MaxUnterweisung())
      {
        hauptfenster->set_status("Weitere Steigerung des Erfolgswertes ist NICHT mit Unterweisung m�glich.");
        return;
      }
   }
  if(MidgardBasicElement_leaf_alt(d))
   {
     neue_schrift_wegen_sprache();
     on_sprache_laden_clicked();
   }
}   
    
void table_steigern::on_leaf_selected_neue_schrift(cH_RowDataBase d)
{  
  MidgardBasicElement_leaf_neu(d);
  on_sprache_laden_clicked();
}   



void table_steigern::neue_schrift_wegen_sprache()
{
  // Alle gelernten Sprachen testen
  for(std::list<cH_MidgardBasicElement>::const_iterator i=hauptfenster->getCChar().CList_Sprache().begin();i!=hauptfenster->getCChar().CList_Sprache().end();++i)
   {
     if((*i)->Erfolgswert()<10) continue;
     // welche Schriften geh�ren zu dieser Sprache?
     std::vector<std::string> VS=cH_Sprache(*i)->Schrift();
     for(std::vector<std::string>::const_iterator j=VS.begin();j!=VS.end();++j)
      {
       try{
        cH_Schrift s(*j);
        if(s->ist_gelernt(hauptfenster->getCChar().CList_Schrift())) continue;
        std::list<cH_MidgardBasicElement> gS=s->gleicheSchrift(hauptfenster->getCDatabase().Schrift);
        for(std::list<cH_MidgardBasicElement>::const_iterator k=gS.begin();k!=gS.end();++k)
         {
           if(s->Name()!=(*k)->Name()) continue;
           int e=andereSprache_gleicheSchriftart(s->Art_der_Schrift());
           if(e>=12) 
            {
              (*k)->setErfolgswert(8);   
              hauptfenster->getChar().List_Schrift().push_back(*k); 
            }
         }
        }catch(NotFound) {hauptfenster->set_status("FEHLER: Schrift "+*j+" ist unbekannt.");}
      }
   }  
}

int table_steigern::andereSprache_gleicheSchriftart(std::string art)
{
  int e=0;
  for(std::list<cH_MidgardBasicElement>::const_iterator i=hauptfenster->getCChar().CList_Schrift().begin();i!=hauptfenster->getCChar().CList_Schrift().end();++i)
   {
     if (cH_Schrift(*i)->Art_der_Schrift()==art)
        if( (*i)->Erfolgswert() > e ) 
           e = (*i)->Erfolgswert();
   }
  return e;
}