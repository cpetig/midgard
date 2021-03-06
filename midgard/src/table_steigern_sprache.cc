/*  Midgard Character Generator
 *  Copyright (C) 2001 Malte Thoma
 *  Copyright (C) 2005 Christof Petig
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

#include <Misc/create_parse.h>
#include "midgard_CG.hh"
#include "table_steigern.hh"
#include "Sprache.hh"
#include "Schrift.hh"
#include "class_SimpleTree.hh"
#include <libmagus/Ausgabe.hh>
#include <libmagus/NotFound.h>
#include <libmagus/LernListen.hh>
#include <libmagus/Datenbank.hh>

void table_steigern::schriften_zeigen()
{  if (notebook_lernen->get_current_page()!=PAGE_SPRACHE) return;
   alte_schrift_zeigen();
   neue_schrift_zeigen();   
   zeige_werte();
}

void table_steigern::alte_schrift_zeigen()
{
  MidgardBasicTree::show_list_in_tree(hauptfenster->getAben().List_Schrift(),alte_schrift_tree,hauptfenster->getChar().actualIterator());
}

void table_steigern::neue_schrift_zeigen()
{
  list_Schrift_neu=LernListen::get_steigern_MBEm(hauptfenster->getAben(),MidgardBasicElement::SCHRIFT);
  MidgardBasicTree::show_list_in_tree(list_Schrift_neu,neue_schrift_tree,hauptfenster->getChar().actualIterator());
}

void table_steigern::sprachen_zeigen()
{  if (notebook_lernen->get_current_page()!=PAGE_SPRACHE) return;
   neue_sprache_zeigen();
   alte_sprache_zeigen();
   zeige_werte();
}

void table_steigern::alte_sprache_zeigen()
{
  MidgardBasicTree::show_list_in_tree(hauptfenster->getAben().List_Sprache()    ,alte_sprache_tree,hauptfenster->getChar().actualIterator());
}

void table_steigern::neue_sprache_zeigen()
{   
  Abenteurer &A=hauptfenster->getAben();
  list_Sprache_neu=LernListen::get_steigern_MBEm(A,MidgardBasicElement::SPRACHE);
   MidgardBasicTree::show_list_in_tree(list_Sprache_neu,neue_sprache_tree,hauptfenster->getChar().actualIterator());
//  on_schrift_laden_clicked();
}   



void table_steigern::on_leaf_selected_neue_sprache(cH_RowDataBase d)
{  
//  sprachen_zeigen();
//  schriften_zeigen();
}
    
void table_steigern::on_leaf_selected_alte_sprache(cH_RowDataBase d)
{  
}
    
void table_steigern::on_alte_sprache_reorder()
{
  std::deque<guint> seq = alte_sprache_tree->get_seq();
  switch((Data_SimpleTree::Spalten_LONG_ALT)seq[0]) {
      case Data_SimpleTree::NAMEa : hauptfenster->getAben().List_Sprache().sort(MBEmlt::sort(MBEmlt::sort::NAME)); ;break;
      case Data_SimpleTree::WERTa : hauptfenster->getAben().List_Sprache().sort(MBEmlt::sort(MBEmlt::sort::ERFOLGSWERT)); ;break;
      default : Ausgabe(Ausgabe::Error,"Sortieren nach diesem Parameter ist nicht möglich");
   }
}


void table_steigern::on_leaf_selected_alte_schrift(cH_RowDataBase d)
{  

}   
    
void table_steigern::on_leaf_selected_neue_schrift(cH_RowDataBase d)
{  
//  MidgardBasicElement_leaf_neu(d);
//  schriften_zeigen();
//  on_sprache_laden_clicked();
}   

void table_steigern::neue_schrift_wegen_sprache()
{
  // Alle gelernten Sprachen testen
  for(std::list<MBEmlt>::const_iterator i=hauptfenster->getAben().List_Sprache().begin();i!=hauptfenster->getAben().List_Sprache().end();++i)
   {
     if((*i)->Erfolgswert()<10) continue;
     // welche Schriften gehören zu dieser Sprache?
     std::vector<std::string> VS=cH_Sprache((*i)->getMBE())->Schrift();
     for(std::vector<std::string>::const_iterator j=VS.begin();j!=VS.end();++j)
      {
       try{
        cH_Schrift s(*j);
        MBEmlt m(&*s);
        if(m->ist_gelernt(hauptfenster->getAben().List_Schrift())) continue;
        std::list<cH_MidgardBasicElement> gS=s->gleicheSchrift(Datenbank.Schrift);
        for(std::list<cH_MidgardBasicElement>::const_iterator k=gS.begin();k!=gS.end();++k)
         {
           if(s->Name()!=(*k)->Name()) continue;
           int e=andereSprache_gleicheSchriftart(s->Art_der_Schrift());
           if(e>=12) 
            {
              MBEmlt S(*k);
              S->setErfolgswert(8);   
              hauptfenster->getAben().List_Schrift().push_back(S); 
            }
         }
        }catch(NotFound) {Ausgabe(Ausgabe::Error,"Schrift "+*j+" ist unbekannt.");}
      }
   }  
}

int table_steigern::andereSprache_gleicheSchriftart(std::string art)
{
  int e=0;
  for(std::list<MBEmlt>::const_iterator i=hauptfenster->getAben().List_Schrift().begin();i!=hauptfenster->getAben().List_Schrift().end();++i)
   {
     if (cH_Schrift((*i)->getMBE())->Art_der_Schrift()==art)
        if( (*i)->Erfolgswert() > e ) 
           e = (*i)->Erfolgswert();
   }
  return e;
}

void table_steigern::on_alte_sprache_clicked(cH_RowDataBase row,bool &handled)
{ if (button_was_tun->get_index()!=Button_PP_eingeben)
  { 
    if(MidgardBasicElement_leaf_alt(row))
     {
       neue_schrift_wegen_sprache();
       neue_sprache_zeigen();
       schriften_zeigen();
       if(hauptfenster->getAben().reduzieren) alte_sprache_zeigen();
       else dynamic_cast<const Data_SimpleTree*>(&*row)->redisplay(alte_sprache_tree);
       handled=true;
     }
  }
}

void table_steigern::on_neue_sprache_clicked(cH_RowDataBase row,bool &handled)
{ if (button_was_tun->get_index()!=Button_PP_eingeben)
  { MidgardBasicElement_leaf_neu(row);
    handled=true;
  }
}
void table_steigern::on_alte_schrift_clicked(cH_RowDataBase row,bool &handled)
{ if (button_was_tun->get_index()!=Button_PP_eingeben)
  { if(MidgardBasicElement_leaf_alt(row))
     {
       neue_schrift_wegen_sprache();
       schriften_zeigen();
  //???     on_sprache_laden_clicked();
       handled=true;
     }
  }
}
void table_steigern::on_neue_schrift_clicked(cH_RowDataBase row,bool &handled)
{ if (button_was_tun->get_index()!=Button_PP_eingeben)
  { MidgardBasicElement_leaf_neu(row);
    handled=true;
  }
}

