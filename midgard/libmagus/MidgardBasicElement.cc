/*  Midgard Character Generator
 *  Copyright (C) 2001-2002 Malte Thoma
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

#include "MidgardBasicElement.hh"
#include "Typen.hh"
#include "Grundwerte.hh"
#include "Fertigkeiten.hh"
#include "Waffe.hh"
#include "WaffeGrund.hh"
#include "KiDo.hh"
#include "Zauber.hh"
#include "Zauberwerk.hh"
#include "Sprache.hh"
#include "Schrift.hh"
//#include "class_SimpleTree.hh"
//#include "SimpleTree.hh"
#include <Misc/itos.h>
#include "xml.h"
#include "Datenbank.hh"
#include "Abenteurer.hh"
#include <iostream>
#include <Misc/germanstring.h>

bool H_MidgardBasicElement_mutable::sort::operator() (H_MidgardBasicElement_mutable x,H_MidgardBasicElement_mutable y) const
{ switch(es) {
               case(LERNPUNKTEPFLICHT) : return x->Pflicht() > y->Pflicht() ||
                  (x->Pflicht() == y->Pflicht()  &&  x->Lernpunkte() < y->Lernpunkte() ) ;
               case(NAME) : return germanstring((*x)->Name()) < germanstring((*y)->Name())  ;
               case(ERFOLGSWERT): return x->Erfolgswert() > y->Erfolgswert();
               
           }abort();
}

#if 0
bool MidgardBasicElement_mutable::sort::operator() (MidgardBasicElement_mutable x,MidgardBasicElement_mutable y) const
{ switch(es) {
               case(LERNPUNKTEPFLICHT) : return x.Pflicht() > y.Pflicht() ||
                  (x.Pflicht() == y.Pflicht()  &&  x.Lernpunkte() < y.Lernpunkte() ) ;
               case(NAME) : return germanstring(x->Name()) < germanstring(y->Name())  ;
               case(ERFOLGSWERT): return x.Erfolgswert() > y.Erfolgswert();
  }
  return false;
}
#endif

bool MidgardBasicElement::Voraussetzung(const Abenteurer& A,bool anzeigen) const
{std::cerr<<"ERROR in Voraussetzung\n";return false;}

std::string MidgardBasicElement::RegionString(const Datenbank &D) const
{
  std::vector<cH_Region> V=D.Regionen;
  std::string s=Regionen_All::getRegionfromAbk(V,region)->Name();
  if(!RegionZusatz().empty()) s+=" ("+RegionZusatz()+")";
  return s;
}

bool MidgardBasicElement::ist_lernbar(const std::vector<cH_Typen>& Typ,const std::map<std::string,std::string>& map_typ) const
{
  for (std::vector<cH_Typen>::const_iterator i=Typ.begin();i!=Typ.end();++i)
    if (const_cast<std::map<std::string,std::string>& >(map_typ)[(*i)->Short()]!="") 
      return true;
  return false;
}

bool MidgardBasicElement_mutable::ist_gelernt(const std::list<MBEmlt>& L) const
{
 for (std::list<MBEmlt>::const_iterator i=L.begin();i!=L.end();++i)
   {
     if(**i==*this) return true;
/*
     if((*i)->What()==MidgardBasicElement::ZAUBERWERK)
      {
        if((*i)->Name()==(*this)->Name() &&
           cH_Zauberwerk(*i)->Art()==cH_Zauberwerk(*this)->Art() &&
              (*i)->Stufe()==(*this)->Stufe())  
               return true ;
      }
     else 
      {  
     if((*i)->Name()==(*this)->Name() && (*i).Zusatz()==Zusatz()) return true;}
*/
   }
 return false;
}

bool MidgardBasicElement::ist_gelernt(const std::list<std::string>& L) const
{
 for (std::list<std::string>::const_iterator i=L.begin();i!=L.end();++i)
   {
//cout <<"Ist gelernt? " << (*i)<<'\t'<<Name()<<'\n';
     if((*i)==Name()) return true;
     if(Name()=="Muttersprache" && 
         (*i).find("_Muttersprache")!=std::string::npos) return true;
     if(Name()=="Gastlandsprache" && 
         (*i).find("_Gastlandsprache")!=std::string::npos) return true;
   }
 return false;
}

std::string MidgardBasicElement::Standard__(const Abenteurer &A) const
{
 std::vector<std::string> s = Standard(A);
 std::string s2=s[0];
 if(A.Typ1()->Short()!="" && A.Typ2()->Short()!="") s2+="/";
 if(A.Typ2()->Short()!="") s2+=s[1];
 return s2;
}

std::vector<std::string> MidgardBasicElement::Standard(const Abenteurer &A) const
{
 assert(A.getVTyp().size()==2);
 std::vector<std::string> s(2);
 for(std::map<std::string,std::string>::const_iterator i=map_typ.begin();i!=map_typ.end();++i)
   if(A.Typ1()->Short()==i->first) {s[0]=i->second; break;}
 for(std::map<std::string,std::string>::const_iterator i=map_typ.begin();i!=map_typ.end();++i)
   if(A.Typ2()->Short()==i->first) {s[1]=i->second; break;}

 s[0]=AusnahmenString(A.getWerte(),A.Typ1(),s[0]);
 s[1]=AusnahmenString(A.getWerte(),A.Typ2(),s[1]);

 return s;
}

bool MidgardBasicElement::Grundfertigkeit(const Abenteurer &A) const
{
  if      (standard_one_G(Standard(A)) ) return true;
  return false;
/*
  std::string standard=Standard__(A);
  std::string::size_type st=standard.find("G");
  if(st==std::string::npos) return false;
  return true;
*/
}
bool MidgardBasicElement::Standardfertigkeit(const Abenteurer &A) const
{
  if (standard_all_S(Standard(A)) ) return true;
  return false;
}


std::string MidgardBasicElement::AusnahmenString(const Grundwerte &Werte,const cH_Typen& Typ,const std::string s) const
{
  if(Region()=="") return s;
  for(std::vector<st_ausnahmen>::const_iterator i=VAusnahmen.begin();i!=VAusnahmen.end();++i)
   {
     if( (i->herkunft==""|| i->herkunft==Werte.Herkunft()->Name()) &&
         (i->spezies ==""|| i->spezies ==Werte.Spezies()->Name())  &&
         (i->stand   ==""|| i->stand==Werte.Stand())  &&
         (i->typ     ==""|| i->typ==Typ->Short() ))
      {
       return i->standard;
      }
   }
  return s;
}


double MidgardBasicElement::Standard_Faktor(const Abenteurer &A) const
{
  double fac;
  if      (standard_one_G(Standard(A)) ) fac = 0.5;
  else if (standard_all_S(Standard(A)) ) fac = 1.0;
  else 
    { 
      fac = 2.0; 
      if (What()==ZAUBER || What()==ZAUBERWERK) fac=5.0;
    }
//cout <<Name()<<' ' <<"StandardFaktor = "<<fac<<"  Grundkosten= "<<GrundKosten()<<'\n';
  return fac;
}

bool MidgardBasicElement::standard_one_G(const std::vector<std::string>& s) const 
{
 assert(s.size()==2);
 if (s[0] == "G" || s[1] =="G" ) return true;
 return false;
}

bool MidgardBasicElement::standard_all_S(const std::vector<std::string>& s) const 
{
 assert(s.size()==2);
 if (s[0] == "S" && (s[1] =="S" || s[1]=="" )) return true;
 if (s[1] == "S" && (s[0] =="S" || s[0]=="" )) return true;
 return false;
}


int MidgardBasicElement::get_Steigern_Kosten(int erfolgswert) const
{
//cout << erfolgswert<<'\t'<<const_cast<std::map<int,int>& >(map_erfolgswert_kosten)[erfolgswert]<<'\t';
//cout << map_erfolgswert_kosten.size()<<'\n';
/*
for(std::map<int,int>::const_iterator i=map_erfolgswert_kosten.begin();i!=map_erfolgswert_kosten.end();++i)
{
std::cout << What()<<'\t'<<i->first<<'\t'<<i->second<<'\n';
}
*/
 return const_cast<std::map<int,int>& >(map_erfolgswert_kosten)[erfolgswert];
}

int MidgardBasicElement_mutable::Steigern(const Abenteurer &A) const 
{ 
   int kosten=0;
   if(Erfolgswert()>0)
      kosten = (*this)->get_Steigern_Kosten(Erfolgswert()+1);
   else 
      kosten = (*this)->get_Steigern_Kosten(abs(Erfolgswert())-1);
   int back = int((*this)->Standard_Faktor(A)*kosten);
   return back;
}

int MidgardBasicElement_mutable::Reduzieren(const Abenteurer &A) const 
{
   int kosten=0;
   if(Erfolgswert()>0)
      kosten = (*this)->get_Steigern_Kosten(Erfolgswert());
   else 
      kosten = (*this)->get_Steigern_Kosten(abs(Erfolgswert()));
   int back = int((*this)->Standard_Faktor(A)*kosten);
   return back;
}

int MidgardBasicElement_mutable::Verlernen(const Abenteurer &A) const
{
//cout << "MidgardBasicElement::Verlernen "<<Name()<<' ' << Reduzieren(Typ,ausnahmen)<<'\n';
   if(Reduzieren(A)==0)
    {
        return (*this)->Kosten(A);
    }      
   else return 0;
}


void MidgardBasicElement::get_map_typ()
{  
 const Tag *tag=this->tag;
 
 if(What()==SPRACHE) 
    tag=cH_Fertigkeit("Sprache")->tag;
 else if(What()==SCHRIFT)
    tag=cH_Fertigkeit("Schreiben")->tag;
 else if(What()==KIDO)
    tag=cH_Fertigkeit("KiDo")->tag;
 else assert(tag);

 if (tag)
 {  FOR_EACH_CONST_TAG(i,*tag)
    {  if (i->Type()=="Grund") map_typ[i->getAttr("Typ")]="G";
       else if (i->Type()=="Standard") map_typ[i->getAttr("Typ")]="S";
       else if (i->Type()=="Ausnahme") map_typ[i->getAttr("Typ")]="A";
    }
 }
}
 

void MidgardBasicElement::get_Steigern_Kosten_map()
{
 const Tag *tag=this->tag;
 const Tag *kosten=0;
 std::string steigern_wie=Name();
 
 if(What()==WAFFE) 
 {  assert(tag);
    typedef std::map<int,const Tag *> map_int_tag_t;
    static map_int_tag_t waffen_schwierigkeit;
    int schwierigkeit=tag->getIntAttr("Schwierigkeit");
    
    map_int_tag_t::const_iterator i=waffen_schwierigkeit.find(schwierigkeit);
    if (i==waffen_schwierigkeit.end())
    {  kosten=find_Tag("Waffen-Steigern","Kosten","Schwierigkeit",itos(schwierigkeit));
       waffen_schwierigkeit[schwierigkeit]=kosten;
    }
    else kosten=i->second;
 }
 else if(What()==SPRACHE) 
 { tag=cH_Fertigkeit("Sprache")->tag; steigern_wie="Sprache"; }
 else if(What()==SCHRIFT) 
 { tag=cH_Fertigkeit("Schreiben")->tag; steigern_wie="Schreiben"; }
 else assert(tag);

 if (!kosten)
 {  // steigern_wie herausfinden
    const Tag *steigern_wie_t=tag->find("steigern_wie");
    if (steigern_wie_t) steigern_wie=steigern_wie_t->getAttr("Fertigkeit");
    
    // Kosten für steigern_wie suchen: 
    // lokaler Cache, cH_Fertigkeit, dann SteigernKosten
    typedef std::map<std::string,const Tag *> map_string_tag_t;
    static map_string_tag_t steigern_kosten;

    try
    {  if (steigern_wie==Name()) steigern_wie_t=this->tag;
       else
       {  // zuerst in lokalen Cache (schneller)
          map_string_tag_t::const_iterator i=steigern_kosten.find(steigern_wie);
          if (i!=steigern_kosten.end()) kosten=i->second;
          // Fertigkeit suchen, wenn nicht gefunden wirft es NotFound
          else
             steigern_wie_t=cH_Fertigkeit(steigern_wie)->tag;
       }
          
       if (!kosten)
       {  if (steigern_wie_t)
             kosten=steigern_wie_t->find("Kosten");
          else std::cerr << "!steigern_wie_t: " << Name() << ',' << What() << '\n';
       }
    } 
    catch (const NotFound &e) // keine Fertigkeit
    {  kosten=find_Tag("SteigernKosten","Kosten","Fertigkeit",steigern_wie);
       steigern_kosten[steigern_wie]=kosten;
    }
 }
 if (!kosten) 
 { std::cerr << "keine Kosten für '" << steigern_wie << "' gefunden\n";
   return;
 }
 for (int i=1;i<=22;++i)
    map_erfolgswert_kosten[i]=kosten->getIntAttr("Wert"+itos(i),0/*??*/);
}

#ifdef __MINGW__
std::string utf82iso(const std::string &s);
# define Internal2Latin(x) utf82iso(x)
#else
# define Internal2Latin(x) (x)
#endif

void MidgardBasicElement::saveElementliste(Tag &datei,
			   const std::list<MBEmlt>& b,
                           const Grundwerte& Werte,
                           const std::vector<cH_Typen>& Typ)
{
  if(b.size()==0) return;
  for (std::list<MBEmlt>::const_iterator i=b.begin();i!=b.end();++i)
   {
      // oder <Beruf Wert=12>Arzt</Beruf> ?
      std::string type=(*(*i))->What_str();
      if (type.find('.')!=std::string::npos)
         type.replace(type.find('.'),1,"-");
      Tag &t=datei.push_back(Tag(type));
      t.setAttr("Bezeichnung", (*(*i))->Name());
      t.setIntAttr_nn("Wert", (*i)->Erfolgswert());
      t.setIntAttr_nn("Praxispunkte", (*i)->Praxispunkte());

      if ((*(*i))->What()==ZAUBERWERK)
      {  
        t.setAttr("Art", cH_Zauberwerk((*i)->getMBE())->Art());
        t.setAttr("Stufe", cH_Zauberwerk((*i)->getMBE())->Stufe());
      }
      if ((*(*i))->ZusatzEnum(Typ))
         t.setAttr("Zusatz", (*i)->Zusatz());
   }
}

  //////////////////////////////////////////////////////////////////////
  //Steigern von Fertigkeiten  
void MidgardBasicElement::EP_steigern(const std::string fert)
{
 const Tag *steigern=0;
 
 if (tag)
    // Fertigkeit gefunden
    steigern=tag->find("EP-Typ");
 else 
    // globale Liste: Ausdauer, Waffen, Zauber
  {
    steigern=find_Tag("verwendbareEP","EP-Typ","Fertigkeit",fert);
#warning Christof: Das funktioniert nicht :-(
std::cout << "\n\n\nverwendbareEP "<<fert<<' '<<steigern<<'\n';
  }

 int back=0;
 if (steigern)
 {  if (steigern->getBoolAttr("KEP")) back+=1;
    if (steigern->getBoolAttr("ZEP")) back+=2;
 }
 steigern_mit_EP=back;
}


std::string MidgardBasicElement_mutable::Pflicht_str() const
{
  if (Pflicht()) return "X";
  else return "";
}

int MidgardBasicElement::FErfolgswert(const Abenteurer &abenteurer,const MBEmlt &mbem) const
{  return 0;
}

int MidgardBasicElement::Kosten(const Abenteurer &A) const 
{return (int)(Standard_Faktor(A)*GrundKosten());}
