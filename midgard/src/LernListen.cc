// $Id: LernListen.cc,v 1.10 2002/09/12 15:01:14 thoma Exp $
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

#include "LernListen.hh"
#include "midgard_CG.hh"
#include "Sprache.hh"
#include "Schrift.hh"


std::list<MidgardBasicElement_mutable> LernListen::getMBEm(const VAbenteurer& A,eMBE was,
                        int erfolgswert,int lernpunkte,std::string lernart) const
{
   std::list<cH_MidgardBasicElement> V_;
   std::list<MidgardBasicElement_mutable> Vm;
   std::vector<Lernschema::st_index> VI;
   switch(was) {
      case MutterSprache: 
      case GastlandSprache: 
      case NachbarlandSprache: 
      case AlteSprache:
                            V_=D.Sprache; break;
      case lFach:           Vm=D.lernschema.get_List("Fachkenntnisse",A.getVTyp(),A.List_Fertigkeit());break;
      case lAllg: 
      case lUnge:           V_=D.Fertigkeit; break;
      case lWaff:           Vm=D.lernschema.get_List("Waffenfertigkeiten",A.getVTyp(),A.List_Waffen());break;
      case lZaub:           Vm=D.lernschema.get_List("Zauberk�nste",A.getVTyp(),A.List_Waffen());break;
      case lAngebFert:      V_=D.Fertigkeit_ang; break;
    }  
   std::list<MidgardBasicElement_mutable> V;
   if(!V_.empty())
   {
    for(std::list<cH_MidgardBasicElement>::const_iterator i=V_.begin();i!=V_.end();++i)
     {
      if((*i)->Name()=="Muttersprache") continue; // Muttersprache wird vorher gelernt
      bool erlaubt=false;
      if(was==MutterSprache || was==NachbarlandSprache)
       {
         if(cH_Sprache(*i)->Alte_Sprache()) continue;
         if(cH_Sprache(*i)->ist_erlaubt(A,was==NachbarlandSprache)) 
               erlaubt=true;
       }
      else if(was==AlteSprache)
         if(cH_Sprache(*i)->Alte_Sprache()) erlaubt=true;
         else continue;
      else erlaubt=true;
      MidgardBasicElement_mutable M(&**i);
      M.setLernArt(lernart+"_"+(*i)->Name());
      M.setErlaubt(erlaubt);

      int lp;
      if(was==lUnge) lp = cH_Fertigkeit(*i)->LernUnge();
      else if (was==lAllg)
       {
         if     (A.getWerte().Stadt_Land()==Enums::Land  ) lp=cH_Fertigkeit(*i)->LernLand();
         else if(A.getWerte().Stadt_Land()==Enums::Stadt ) lp=cH_Fertigkeit(*i)->LernStadt();
       }
      M.setLernpunkte(lp);

      if(was==lUnge || was==lAllg)
           M.setErfolgswert((*i)->Anfangswert()+cH_Fertigkeit(*i)->AttributBonus(A.getWerte()));
      else M.setErfolgswert(erfolgswert);
      if(!region_check((*i)->Region())) continue;
      V.push_back(M);
     }
    }
   else if(!Vm.empty())
   {
    for(std::list<MidgardBasicElement_mutable>::iterator i=Vm.begin();i!=Vm.end();++i)
     {
      if(was==lFach)
       {
         VI=Lernschema::getIndex(A.getVTyp(),"Fachkenntnisse",(*i)->Name());
         i->setErfolgswert(cH_Fertigkeit(*i)->Anfangswert0()+cH_Fertigkeit(*i)->AttributBonus(A.getWerte()));
         i->setPflicht(D.lernschema.get_Pflicht(VI));
//cout << (*i)->Name()<<"  ?: "<<i->Erfolgswert()<<'\t'<<i->Pflicht()<<'\n';
       }
      if(was==lWaff)
         VI=Lernschema::getIndex(A.getVTyp(),"Waffenfertigkeiten",(*i)->Name());
      if(was==lZaub)
         VI=Lernschema::getIndex(A.getVTyp(),"Zauberk�nste",(*i)->Name());
      int lp=D.lernschema.get_Lernpunkte(VI);
      i->setLernpunkte(lp);
      if(!region_check((*i)->Region())) continue;
//cout << (*i)->Name()<<"Region: "<<region_check((*i)->Region())<<' '<<i->Lernpunkte()<<' '<<i->Erfolgswert()<<'\n';
      V.push_back(*i);
     }     
   }
//  else assert(!"never get here\n");
  return V;
}




std::vector<cH_Spezies> LernListen::getSpezies(bool nsc_allowed) const
{
 std::vector<cH_Spezies> V,S=D.Spezies;
 for(std::vector<cH_Spezies>::const_iterator i=S.begin();i!=S.end();++i)                                   
   {
     if (!nsc_check(nsc_allowed,(*i)->NSC_only())) continue;
     V.push_back(*i);
   }
 return V;
}


std::vector<pair<cH_Typen,bool> > LernListen::getTypen(const VAbenteurer& A,bool nsc_allowed) const
{
  std::vector<cH_Typen> T=D.Typen;
  std::vector<pair<cH_Typen,bool> > V;
  for(std::vector<cH_Typen>::const_iterator i=T.begin();i!=T.end();++i)
   {
     if (A.getWerte().Spezies()->Name()=="Mensch" || A.getWerte().Spezies()->Typ_erlaubt((*i)->Short()))
      if (region_check((*i)->Region()) && nsc_check(nsc_allowed,(*i)->NSC_only()))       
       {
         if((*i)->Mindestwerte(A.getWerte()))
            V.push_back(pair<cH_Typen,bool>(*i,true));
         else 
            V.push_back(pair<cH_Typen,bool>(*i,false));
       }
   }
  return V;
}



std::vector<pair<cH_Land,bool> > LernListen::getHerkunft(const VAbenteurer& A) const
{
  std::vector<cH_Land> L=D.Laender;
  std::vector<pair<cH_Land,bool> > V;
  for (std::vector<cH_Land>::const_iterator i=L.begin();i!=L.end();++i)
   {
     V.push_back(pair<cH_Land,bool>(*i,(*i)->ist_erlaubt(A)));
   }
  return V;
}

std::vector<MidgardBasicElement::st_zusatz> LernListen::getLandZusatz() const
{
  std::vector<MidgardBasicElement::st_zusatz> B;
  std::vector<cH_Land> L=D.Laender;
  for(std::vector<cH_Land>::const_iterator i=L.begin();i!=L.end();++i)
     B.push_back(MidgardBasicElement::st_zusatz((*i)->Name()));
  return B;
}


std::vector<MidgardBasicElement::st_zusatz> LernListen::getMBEZusatz(const MidgardBasicElement_mutable& MBE) const
{
  std::vector<MidgardBasicElement::st_zusatz> B;
  std::vector<MidgardBasicElement::st_zusatz> V=MBE->VZusatz();
  for (std::vector<MidgardBasicElement::st_zusatz>::const_iterator i=V.begin();i!=V.end();++i)
   {
     MidgardBasicElement::st_zusatz z=*i;
     z.long_region=Regionen_All::getRegionfromAbk(D.Regionen,i->region)->Name()+" "+i->region_zusatz;
     if(region_check(i->region)) B.push_back(z);
   }
  return B;
}

std::vector<MidgardBasicElement::st_zusatz> LernListen::getUeberlebenZusatz() const
{
   std::vector<MidgardBasicElement::st_zusatz> B;
   for(std::list<cH_MidgardBasicElement>::const_iterator i=D.Fertigkeit.begin();i!=D.Fertigkeit.end();++i)
    {
      if((*i)->Name().find("�berleben")!=std::string::npos)
         B.push_back(MidgardBasicElement::st_zusatz((*i)->Name()));
    }
   return B;
}

std::vector<MidgardBasicElement::st_zusatz> LernListen::getWaffenZusatz(const std::list<MidgardBasicElement_mutable> &WL)
{
   std::vector<MidgardBasicElement::st_zusatz> B;
   for(std::list<MidgardBasicElement_mutable>::const_iterator i=WL.begin();i!=WL.end();++i)
    {
      if (cH_Waffe(*i)->Art()=="Schu�waffe" || cH_Waffe(*i)->Art()=="Wurfwaffe")
        B.push_back(MidgardBasicElement::st_zusatz((*i)->Name()));
    }
  return B;
}

std::vector<MidgardBasicElement::st_zusatz> LernListen::getSprachenZusatz(const MidgardBasicElement_mutable &MBE,const VAbenteurer& Aben,bool nachbarland) const
{
  std::vector<MidgardBasicElement::st_zusatz> B;
  for(std::list<cH_MidgardBasicElement>::const_iterator i=D.Sprache.begin();i!=D.Sprache.end();++i)
   {
     if(MidgardBasicElement_mutable(&**i).ist_gelernt(Aben.List_Sprache())) continue;

     bool erlaubt=true;
     if(MBE->Name()=="Muttersprache" || MBE->Name()=="Gastlandsprache")
      {
        if(cH_Sprache(*i)->Alte_Sprache()) continue;                  
        if(MBE->Name()=="Muttersprache") // mu� im Heimatland gesprochen werden
          if(!cH_Sprache(*i)->ist_erlaubt(Aben))
             erlaubt=false;
      }
     else if(MBE->Name()=="Sprechen: Alte Sprache" && !cH_Sprache(*i)->Alte_Sprache())
         continue;
     else if(nachbarland && !cH_Sprache(*i)->ist_erlaubt(Aben,nachbarland))
         erlaubt=false;
     B.push_back(MidgardBasicElement::st_zusatz((*i)->Name(),erlaubt));
   }
 return B;
}

std::vector<MidgardBasicElement::st_zusatz> LernListen::getSchriftenZusatz(const MidgardBasicElement_mutable &MBE,const VAbenteurer& Aben) const
{
  std::vector<MidgardBasicElement::st_zusatz> B;
  for(std::list<cH_MidgardBasicElement>::const_iterator i=D.Schrift.begin();i!=D.Schrift.end();++i)
   {
     if(MidgardBasicElement_mutable(&**i).ist_gelernt(Aben.List_Schrift())) continue;
     if(!cH_Schrift(*i)->kann_Sprache(Aben.List_Sprache())) continue;
     bool erlaubt=true;
     if( MBE->Name().find("Muttersprache") != std::string::npos)
       if(!cH_Schrift(*i)->Mutterschrift(Aben)) erlaubt=false;
     else if ( MBE->Name().find("Alte Sprache") != std::string::npos)
       if(!cH_Sprache((*i)->Name())->Alte_Sprache()) continue;
     B.push_back(MidgardBasicElement::st_zusatz((*i)->Name(),erlaubt));
   }
  return B;
}




bool LernListen::region_check(const std::string& region) const
{
  if (region=="") return true;
  for(std::vector<cH_Region>::const_iterator i=D.Regionen.begin();i!=D.Regionen.end();++i)
   {
     if( (region==(*i)->Abkuerzung() || region==(*i)->Name() ) &&
         (*i)->Active()) return true;
   }
  return false;
}

bool LernListen::nsc_check(bool nsc_allowd,bool nsc_only) const
{
  if (nsc_only && !nsc_allowd) return false;
  return true;
}

bool LernListen::SpracheSchrift(const cH_MidgardBasicElement& MBE)
{
 bool back=false;  
 std::string fert=MBE->Name();

 if(fert=="Schreiben: Muttersprache(+12)" ||
         fert=="Schreiben: Muttersprache(+9)" ||
         fert=="Schreiben: Muttersprache(+4)" ||
         fert=="Schreiben: Alte Sprache(+12)" ||
         fert=="Schreiben" )
    { back=true;   }   
 else if(fert=="Muttersprache")
    { back=true; }  
 else if(fert=="Gastlandsprache" ||
         fert=="Sprechen: Sprache(+4)" ||
         fert=="Sprechen: Sprache(+9)" ||
         fert=="Sprechen: Sprache(+12)") 
    { back=true;  }  
 else if(fert=="Sprechen: Alte Sprache")
    { back=true; }  
 return back;  
}

std::list<WaffeBesitz> LernListen::getWaffenBesitz(const VAbenteurer& Aben) const
{
  std::list<cH_MidgardBasicElement> V=D.Waffe;
  std::list<WaffeBesitz> L;
  for(std::list<cH_MidgardBasicElement>::const_iterator i=V.begin();i!=V.end();++i)
   {
     if(Aben.getWerte().Spezies()->istVerbotenSpielbegin(*i)) continue;
     const cH_Waffe w(*i);
     if (w->Grundkenntnis() == "Kampf ohne Waffen") continue;
     if (!MidgardBasicElement_mutable(&*w).ist_gelernt(Aben.List_Waffen())) continue;
     L.push_back(WaffeBesitz(w,w->Name(),0,0,"","")); 
     for(std::list<Waffe::st_alias>::const_iterator j=cH_Waffe(w)->Alias().begin();j!=cH_Waffe(w)->Alias().end();++j)
      {
        if(region_check(j->region))
           L.push_back(WaffeBesitz(w,j->name,0,0,"",j->region)); 
      }
   }
 return L;
}

std::vector<std::string> LernListen::getSpezialgebiet(const VAbenteurer& A) const
{
  std::vector<std::string> L;
  for(std::vector<cH_Spezialgebiet>::const_iterator i=D.Spezialgebiet.begin();i!=D.Spezialgebiet.end();++i) 
   {
    if((*i)->Typ() != A.Typ1()->Short() && 
       (*i)->Typ() != A.Typ2()->Short() ) continue;
    L.push_back((*i)->Name());
   }
  return L;
}
