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

#include "Spezies.hh"
#include "ProgressBar.h"
#include "MidgardBasicElement.hh"
#include "Grundwerte.hh"
#include "Zauber.hh"
#include "Fertigkeiten_angeboren.hh"

cH_Spezies::cache_t cH_Spezies::cache;

cH_Spezies::cH_Spezies(const std::string& name IF_XML(,bool create))
{
 cH_Spezies *cached(cache.lookup(name));
 if (cached) *this=*cached;
 else
  {
  cerr << "Spezies '" << name << "' nicht im Cache\n";
  const Tag *t=find_Tag("SpeziesListe","Spezies","Name",name);
  if (t) *this=cH_Spezies(t);
  else if (create || !xml_data) // !xml_data = vor Einlesen der Daten
  {  static Tag t2("Spezies"); 
     // note that this Tag is shared ... works well for now
     t2.setAttr("Name",name);
     *this=cH_Spezies(&t2);
  }
  else throw NotFound();
  }
}

cH_Spezies::cH_Spezies(const Tag *tag)
{*this=cH_Spezies(new Spezies(tag));
 cache.Register(tag->getAttr("Name"),*this);
}

Spezies::Spezies(const Tag *tag) 
: name(tag->getAttr("Name"))
{
 nr=tag->getIntAttr("MAGUS-Index",tag->getIntAttr("MCG-Index"));
 land=tag->getBoolAttr("Land");
 hand_bonus=tag->getIntAttr("HandBonus");
 raufen=tag->getIntAttr("RaufenBonus");

 const Tag *Alter=tag->find("Alter");
 if (Alter) alter_fak=Alter->getIntAttr("Faktor");
 else alter_fak=1;

 const Tag *Groesse=tag->find("Gr��e");
 groesse_bonus=Groesse->getIntAttr("Addiere");
 groesse_wanz=Groesse->getIntAttr("AnzahlW�rfel");
 groesse_wuerfel=Groesse->getIntAttr("W�rfel");

 const Tag *Gewicht=tag->find("Gewicht");
 gewicht_bonus=Gewicht->getIntAttr("Addiere");
 gewicht_wanz=Gewicht->getIntAttr("AnzahlW�rfel");

 const Tag *Bewegungsweite=tag->find("Bewegungsweite");
 b_bonus=Bewegungsweite->getIntAttr("AnzahlW�rfel");
 b_wanz=Bewegungsweite->getIntAttr("Addiere");

 const Tag *Modifikation=tag->find("Modifikation");
 if (!Modifikation) Modifikation=tag;
 lp=Modifikation->getIntAttr("LP_Bonus");
 ap_bonus=Modifikation->getIntAttr("AP_Bonus");
 ap_grad_fak=Modifikation->getIntAttr("AP_GradFaktor");

 const Tag *Resistenzen=Modifikation->find("Resistenzen");
 if (!Resistenzen) Resistenzen=tag;
 psy=Resistenzen->getIntAttr("psy");
 phs=Resistenzen->getIntAttr("phs");
 phk=Resistenzen->getIntAttr("phk");
 psy100=Resistenzen->getIntAttr("psy100");
 phs100=Resistenzen->getIntAttr("phs100");
 phk100=Resistenzen->getIntAttr("phk100");

 const Tag *Grundwerte=tag->find("Grundwerte");
 if (!Grundwerte) Grundwerte=tag;
 st=Grundwerte->getIntAttr("St");
 gw=Grundwerte->getIntAttr("Gw");
 gs=Grundwerte->getIntAttr("Gs");
 ko=Grundwerte->getIntAttr("Ko");
 in=Grundwerte->getIntAttr("In");
 zt=Grundwerte->getIntAttr("Zt");
 sb=Grundwerte->getIntAttr("Sb");
 au=Grundwerte->getIntAttr("Au");
 
 FOR_EACH_CONST_TAG_OF(i,*tag,"Typ")
    vec_typen.push_back(st_spez(i->getAttr("Name"),i->getIntAttr("MaximalerGrad")));
 FOR_EACH_CONST_TAG_OF(i,*tag,"Typ")
    vec_angebfert.push_back(st_angebfert(i->getAttr("Art"),i->getAttr("Name"),i->getIntAttr("Erfolgswert")));
}


Spezies_All::Spezies_All(Gtk::ProgressBar *progressbar)
{
 const Tag *spezies=xml_data->find("SpeziesListe");
 if (spezies)
 {  Tag::const_iterator b=spezies->begin(),e=spezies->end();
    double size=e-b;
    FOR_EACH_CONST_TAG_OF_5(i,*spezies,b,e,"Spezies")
    {  ProgressBar::set_percentage(progressbar,(i-b)/size);
       list_All.push_back(cH_Spezies(&*i));
    }
 }   
 ProgressBar::set_percentage(progressbar,1);
}

bool Spezies::Typ_erlaubt(std::string typ) const
{
  for(std::vector<st_spez>::const_iterator i=vec_typen.begin();i!=vec_typen.end();++i)
    if(i->typen == typ) return true ;
  return false;
}

int Spezies::Psy(const Grundwerte &W) const
{
  if(W.Zt()<100) return psy;
  else return psy100;
}
int Spezies::Phs(const Grundwerte &W) const
{
  if(W.Zt()<100) return phs;
  else return phs100;
}
int Spezies::Phk(const Grundwerte &W) const
{
  if(W.Zt()<100) return phk;
  else return phk100;
}

std::list<cH_MidgardBasicElement> Spezies::getZauber() const
{
  std::list<cH_MidgardBasicElement> L;
  for(std::vector<st_angebfert>::const_iterator i=vec_angebfert.begin();i!=vec_angebfert.end();++i)
   {
    if(!(i->art=="z")) continue;
    cH_MidgardBasicElement z(&*cH_Zauber(i->name)); 
    L.push_back(z);
   }
 return L;
}

std::list<cH_MidgardBasicElement> Spezies::getAngFertigkeiten() const
{
  std::list<cH_MidgardBasicElement> L;
  for(std::vector<st_angebfert>::const_iterator i=vec_angebfert.begin();i!=vec_angebfert.end();++i)
   {
    if(!(i->art=="af")) continue;
    cH_MidgardBasicElement f(&*cH_Fertigkeit_angeborene(i->name)); 
    f->set_Erfolgswert(i->erfolgswert);
    L.push_back(f);
   }
 return L;
}

std::list<pair<std::string,int> > Spezies::getSinne() const
{
  std::list<pair<std::string,int> > S;
  for(std::vector<st_angebfert>::const_iterator i=vec_angebfert.begin();i!=vec_angebfert.end();++i)
   {
    if(!(i->art=="s")) continue;
    S.push_back(pair<std::string,int>(i->name,i->erfolgswert));
   }
 return S;
}


bool operator==(gpointer data,const cH_Spezies &s)
{  return *(static_cast<Spezies*>(data))==*s;
}