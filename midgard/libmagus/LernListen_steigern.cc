// $Id: LernListen_steigern.cc,v 1.7 2004/11/29 17:26:50 christof Exp $
/*  Midgard Character Generator
 *  Copyright (C) 2001 Malte Thoma
 *  Copyright (C) 2003 Christof Petig
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

#include "LernListen.hh"
#include "Abenteurer.hh"
#include "WaffeGrund.hh"
#include "Schrift.hh"
#include "Zauber.hh"
#include "Zauberwerk.hh"
#include "Datenbank.hh"

std::list<MBEmlt> LernListen::get_steigern_MBEm(const Abenteurer& A,MidgardBasicElement::MBEE was)
{
  std::list<cH_MidgardBasicElement> V_;
  switch(was) {
     case MidgardBasicElement::FERTIGKEIT: V_=Datenbank.Fertigkeit; break;
     case MidgardBasicElement::WAFFE: V_=Datenbank.Waffe; break;
     case MidgardBasicElement::ZAUBER: V_=Datenbank.Zauber; break;
     case MidgardBasicElement::SPRACHE: V_=Datenbank.Sprache; break;
     case MidgardBasicElement::SCHRIFT: V_=Datenbank.Schrift; break;
     case MidgardBasicElement::WAFFEGRUND: V_=Datenbank.WaffeGrund; break;
     case MidgardBasicElement::ZAUBERWERK:V_=Datenbank.Zauberwerk; break; 
     default : assert(!"never get here\n");
   }
  std::list<MBEmlt> V;
  for(std::list<cH_MidgardBasicElement>::const_iterator i=V_.begin();i!=V_.end();++i)
   {
     if ((*i)->Name()=="Sprache" || (*i)->Name()=="Schreiben" || (*i)->Name()=="KiDo-Technik") continue;
     if(A.Spezies()->istVerboten(*i)) continue;
     if ((*i)->Name()=="Zaubern" && A.is_mage() ) continue;
     if (!(*i)->ist_lernbar(A.getVTyp(),(*i)->get_MapTyp())) continue;
     if (!region_check(A,(*i)->Region()) ) continue;
     if (!nsc_check(A,(*i)->NSC_only())) continue;
     MBEmlt MBEm(*i);
     switch(was) {
       case MidgardBasicElement::FERTIGKEIT: { const cH_Fertigkeit f(*i);
          if (MBEmlt(*i)->ist_gelernt(A.List_Fertigkeit()) && 
              (*i)->ZusatzEnum(A.getVTyp())==MidgardBasicElement::ZNone) continue ;
          if (!f->Voraussetzung(A)) continue;
          MBEm->setErfolgswert(f->Anfangswert());
          break;
         }
       case MidgardBasicElement::WAFFE: { const cH_Waffe w(*i);
          if (MBEm->ist_gelernt(A.List_Waffen()) && 
              (*i)->ZusatzEnum(A.getVTyp())==MidgardBasicElement::ZNone) continue ;
          if (!w->Grundkenntnis_vorhanden(A.List_WaffenGrund())) continue;
          if (!w->Voraussetzung(A)) continue;
          if (w->Art()=="Verteidigung") MBEm->setErfolgswert(1);
          else MBEm->setErfolgswert(4);
          break;
         }
       case MidgardBasicElement::WAFFEGRUND: {
          if(!cH_WaffeGrund(*i)->is_sinnvoll(Datenbank.Waffe,A)) continue;
          if (MBEm->ist_gelernt(A.List_WaffenGrund()) && 
              (*i)->ZusatzEnum(A.getVTyp())==MidgardBasicElement::ZNone) continue ;
          break;
         }
       case MidgardBasicElement::SPRACHE: {
          if (MBEm->ist_gelernt(A.List_Sprache()) && 
              (*i)->ZusatzEnum(A.getVTyp())==MidgardBasicElement::ZNone) continue ;
          MBEm->setErfolgswert(cH_Fertigkeit("Sprache")->Anfangswert());
          break;
         }
       case MidgardBasicElement::SCHRIFT: {
          if (MBEm->ist_gelernt(A.List_Schrift()) && 
              (*i)->ZusatzEnum(A.getVTyp())==MidgardBasicElement::ZNone) continue ;
          if (!cH_Schrift(*i)->kann_Sprache(A.List_Sprache())) continue;
          MBEm->setErfolgswert(cH_Fertigkeit("Schreiben")->Anfangswert());
          break;
         }
       case MidgardBasicElement::ZAUBER: { 
          if (MBEm->ist_gelernt(A.List_Zauber()) && 
              (*i)->ZusatzEnum(A.getVTyp())==MidgardBasicElement::ZNone) continue ;
          break;
         }
       case MidgardBasicElement::ZAUBERWERK: { 
          if (MBEm->ist_gelernt(A.List_Zauberwerk()) && 
              (*i)->ZusatzEnum(A.getVTyp())==MidgardBasicElement::ZNone) continue ;
          break;
         }
       default : assert(!"never get here\n");
      }
     V.push_back(MBEm);
   }
  return V;
}

std::list<MBEmlt> LernListen::get_steigern_Zauberliste(const Abenteurer& A,
      bool salz,bool beschwoerung, bool alle,bool spruchrolle)
{
  std::list<MBEmlt> L_=get_steigern_MBEm(A,MidgardBasicElement::ZAUBER);
  std::list<MBEmlt> L;
  for(std::list<MBEmlt>::const_iterator i=L_.begin();i!=L_.end();++i)
   {
     cH_Zauber z((*i)->getMBE());
     if (z->Spruchrolle()) z->setSpruchrolleFaktor(0.1);
     else z->setSpruchrolleFaktor(1);
     if(alle) L.push_back(*i);
     else
      {
        if (z->Zauberart()=="Zaubersalz"   && !salz ) continue;
        if (z->Zauberart()=="Beschwörung"  && !beschwoerung) continue;
        if (!z->Spruchrolle()              && spruchrolle) continue;
        L.push_back(*i);
      }
   }
 return L;
}

std::list<MBEmlt> LernListen::get_steigern_ZauberWerkliste(const Abenteurer& A,
     bool alle)
{
  std::list<MBEmlt> L_=get_steigern_MBEm(A,MidgardBasicElement::ZAUBERWERK);
  std::list<MBEmlt> L;
  for(std::list<MBEmlt>::const_iterator i=L_.begin();i!=L_.end();++i)
   { const cH_Zauberwerk z((*i)->getMBE());
     if(alle) L.push_back(*i); 
     else
      {  if (!z->Voraussetzungen(A.List_Zauber())) continue;
         if (!z->Voraussetzungen_Fertigkeit(A.List_Fertigkeit())) continue;
         L.push_back(*i); 
      }
   }
 return L;
}


void LernListen::shorten_for_GFP(std::list<MBEmlt> &L_,const Abenteurer& A,const int gfp)
{
  std::list<MBEmlt> L;
  for(std::list<MBEmlt>::const_iterator i=L_.begin();i!=L_.end();++i)
   {
     if((*(*i))->Kosten(A) > gfp) continue;
     L.push_back(*i);
   }
  L_=L;
}

