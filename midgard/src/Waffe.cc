/*  Midgard Character Generator
 *  Copyright (C) 2001-2002 Malte Thoma
 *  Copyright (C) 2002      Christof Petig 
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

#include "Waffe.hh"
#include "midgard_CG.hh"
#include "Typen.hh"
#include "ProgressBar.h"
#include <Aux/itos.h>

cH_Waffe::cache_t cH_Waffe::cache;

cH_Waffe::cH_Waffe(const std::string& name IF_XML(, bool create))
{
 cH_Waffe *cached(cache.lookup(name));
 if (cached) *this=*cached;
 else
  {
  cerr << "Waffe '" << name << "' nicht im Cache\n";
  if (create)
  {  static Tag t2("Waffe"); 
     // note that this Tag is shared ... works well for now
     t2.setAttr("Name",name);
     *this=cH_Waffe(&t2);
  }
  else throw NotFound();
  }
}

cH_Waffe::cH_Waffe(const Tag *tag)
{*this=cH_Waffe(new Waffe(tag));
 cache.Register(tag->getAttr("Name"),*this);
}

void Waffe::get_Waffe()
{
   assert(tag);
   grundkenntnisse=tag->getAttr("Grundkenntnisse");
   schwierigkeit=tag->getIntAttr("Schwierigkeit");
   art=tag->getAttr("Kategorie");
   art2=tag->getAttr("Klasse");
   schaden=tag->getAttr("Schaden");
   schaden_bonus=tag->getIntAttr("Schadensbonus");
   voraussetzung=tag->getAttr("erfordert");
   region=tag->getAttr("Region");
   
   const Tag *Modifikationen=tag->find("Modifikationen");
   if (Modifikationen)
   {  waffenrang=Modifikationen->getAttr("Waffenrang");
      wm_abwehr_leicht=Modifikationen->getAttr("Abwehr-leicht");
      wm_abwehr_schwer=Modifikationen->getAttr("Abwehr-schwer");
   }

   const Tag *Voraussetzungen=tag->find("Voraussetzungen");
   if (Voraussetzungen)
   {  st=Voraussetzungen->getIntAttr("St");
      gw=Voraussetzungen->getIntAttr("Gw");
      gs=Voraussetzungen->getIntAttr("Gs");
   }

   const Tag *Reichweite=tag->find("Reichweite");
   if (Reichweite)
   {  reichweite_0=Reichweite->getIntAttr("null");
      reichweite_n=Reichweite->getIntAttr("nah");
      reichweite_m=Reichweite->getIntAttr("mittel");
      reichweite_f=Reichweite->getIntAttr("fern");
   }

   const Tag *Lernkosten=tag->find("Lernkosten");
   if (Lernkosten)
   {  lern_land=Lernkosten->getIntAttr("Land");
      lern_stadt=Lernkosten->getIntAttr("Stadt");
   }

   if(Art()=="Verteidigung") erfolgswert=1;
   else erfolgswert=4;   
}

void Waffe::get_Alias() 
{
    assert(tag);
    FOR_EACH_CONST_TAG_OF(i,*tag,"regionaleVariante")
    {  int Angriff=0;
       const Tag *Modifikationen=i->find("Modifikationen");
       if (Modifikationen) Angriff=Modifikationen->getIntAttr("Angriff");
       list_alias.push_back(st_alias(i->getAttr("Name"),i->getAttr("Region"),
       		i->getAttr("Schaden"),i->getIntAttr("Schadensbonus"),Angriff));
    }
}


bool Waffe::Grundkenntnis_vorhanden(const std::list<cH_MidgardBasicElement>& list_WaffenGrund) const
{
 for (std::list<cH_MidgardBasicElement>::const_iterator i=list_WaffenGrund.begin();i!=list_WaffenGrund.end();++i)
   if (Grundkenntnis()==(*i)->Name()) return true;
 return false;
}


bool Waffe::SG_Voraussetzung(const Grundwerte& Werte) const
{
  if ( St()<=Werte.St() && Gw()<=Werte.Gw() && Gs()<=Werte.Gs() ) return true;
  else return false ;
}



std::string WaffeBesitz::Schaden(const Grundwerte& Werte,const std::string& name) const
{
  if (waffe->Art()=="Verteidigung") return "-"+itos(waffe->Schaden_Bonus(name))+"AP";
  std::string s=waffe->Schaden(name);
  int sb=waffe->Schaden_Bonus(name) + sl_Bonus();
//cout << "WAFFE = "<<waffe->Name()<<'\t'<<waffe->Erfolgswert()<<'\n';
  if (Name()=="waffenloser Kampf" || Name()=="Faustkampf" ) 
      { s="W6";
        int w = waffe->Erfolgswert();
//cout << "Erfolgswert WAFFENLOS = "<<itos(w)<<'\n';
        if (         w <= 7) sb=-4;
        if ( 8<=w && w <=11) sb=-3;
        if (12<=w && w <=15) sb=-2;
        if (16<=w)           sb=-1;
      }
  if (waffe->Art()!="Schu�waffe" && waffe->Art()!="Wurfwaffe") 
      sb += Werte.bo_Sc();
  if     (sb == 0) return s;
  else if(sb  > 0) return s+"+"+itos(sb);
  else if(sb  < 0) return s+"-"+itos(sb);
  abort(); //Never get here
}

std::string WaffeBesitz::Bonus() const 
{ 
  if (Magisch()=="" && av_Bonus()==0 && sl_Bonus()==0 ) return "";
  return "("+itos(av_Bonus())+"/"+itos(sl_Bonus())+")";
}



std::string Waffe::Reichweite() const
{  
   if(reichweite_0==-1) return ""; // postgres
   else if (reichweite_0==0 && reichweite_n==0 && 
            reichweite_m==0 && reichweite_n==0) return ""; // xml
   return itos(reichweite_0)+"/"+itos(reichweite_n)+"/"+
               itos(reichweite_m)+"/"+itos(reichweite_f);
}

std::string Waffe::WM_Abwehr() const
{
  std::string s1=wm_abwehr_leicht, s2 = wm_abwehr_schwer;
  if (s1=="" && s2=="") return "";
  if (s1=="") s1="0";
  if (s2=="") s2="0";
  return s1+"$|$"+s2;
}


int Waffe::WM_Angriff(const std::string& name) const 
{
  if(Name()==name) return 0;
  for(list<st_alias>::const_iterator i=list_alias.begin();i!=list_alias.end();++i)
    if (name==(*i).name) return (*i).angriffs_mod;
  assert(false);
}

std::string Waffe::Schaden(const std::string& name) const 
{
  if(Name()==name) return schaden;
  for(list<st_alias>::const_iterator i=list_alias.begin();i!=list_alias.end();++i)
    if (name==(*i).name) return (*i).schaden;
  assert(false);
}

int Waffe::Schaden_Bonus(const std::string& name) const 
{
  if(Name()==name) return schaden_bonus;
  for(list<st_alias>::const_iterator i=list_alias.begin();i!=list_alias.end();++i)
    if (name==(*i).name) return (*i).schaden_bonus;
  assert(false);
}

std::string Waffe::Region(const std::string& name) const
{
  if(Name()==name) return region;
  for(list<st_alias>::const_iterator i=list_alias.begin();i!=list_alias.end();++i)
   if (name==(*i).name) return (*i).region;
  assert(false);
}


std::string Waffe::Schwierigkeit_str() const
{
  switch(Schwierigkeit()) {
    case 0: return "Verteidigung";
    case 1: return "extrem leicht";
    case 2: return "sehr leicht";          
    case 3: return "leicht";
    case 4: return "normal";
    case 5: return "schwer";
    case 6: return "sehr schwer";
    case 7: return "extrem schwer";
   }
  return itos(Schwierigkeit());
}



map<std::string,std::string> Waffe::fill_map_alias_waffe(Gtk::ProgressBar *progressbar)
{
  map<std::string,std::string> M;
 const Tag *waffen=xml_data->find("Waffen");
 if (!waffen)
    cerr << "<Waffen><Waffe/>... nicht gefunden\n";
 else
 {  Tag::const_iterator b=waffen->begin(),e=waffen->end();
    double size=e-b;
    FOR_EACH_CONST_TAG_OF_5(i,*waffen,b,e,"Waffe")
    {  ProgressBar::set_percentage(progressbar,(i-b)/size);
       
       FOR_EACH_CONST_TAG_OF(j,*i,"regionaleVariante")
          M[j->getAttr("Name")]=i->getAttr("Name");
    }
 }
  ProgressBar::set_percentage(progressbar,1);
  return M;
}


int Waffe::MaxErfolgswert(const Grundwerte& w,const vector<cH_Typen>& Typ,const Ausnahmen& ausnahmen) const
{
 assert(Typ.size()==2);
 int maxwert=0;
 double x=Standard_Faktor(Typ,ausnahmen);

 if (art == "Verteidigung")
  {
    if (Typ[0]->Zaubern() == "z" && Typ[1]->Short()!="") maxwert = 6;
    else
     {
      if     (x==1.0)  maxwert = 7;
      else if(x==0.5)  maxwert = 8;
      else if(x==2.0)  maxwert = 6;
      else assert(!"Auf Fixedpoint umstellen");
     }
  }
 else
  {
    if (Typ[0]->Zaubern() == "z" && Typ[1]->Short()!="") maxwert = 14;
    else
     {
      if     (x==1.0)  maxwert = 17;
      else if(x==0.5)  maxwert = 19;
      else if(x==2.0)  maxwert = 14;
      else assert(!"Auf Fixedpoint umstellen");
     }
  }
 return maxwert;
}


std::string Waffe::get_Verteidigungswaffe(int ohne_waffe,
   const std::list<cH_MidgardBasicElement>& list_Waffen,
   const std::list<cH_MidgardBasicElement>& list_Waffen_besitz,
   const vector<cH_Typen>& Typ,
   const Grundwerte& Werte)
{
   std::list<cH_MidgardBasicElement> Verteidigungswaffen;
   Verteidigungswaffen.push_back(new WaffeBesitz(
      cH_Waffe("waffenloser Kampf"),"waffenloser Kampf","",0,0,""));
   for (std::list<cH_MidgardBasicElement>::const_iterator i=list_Waffen_besitz.begin();
         i!=list_Waffen_besitz.end();++i)
     {
       cH_WaffeBesitz WB(*i);
       if (WB->Waffe()->Art()=="Verteidigung" || WB->Waffe()->Name()=="Kampfstab" || WB->Name()=="Sai" ||
          WB->Name()=="Tonfa" || WB->Name()=="GunSen" || WB->Name()=="BuKasa" || 
          WB->Name()=="KusariGama" || WB->Name()=="TetsuBo" ) 
         Verteidigungswaffen.push_back(*i);
     }
   std::string Vwaffewert;
   for(std::list<cH_MidgardBasicElement>::const_iterator i=Verteidigungswaffen.begin();
         i!=Verteidigungswaffen.end();/*siehe unten*/)
     {
      cH_WaffeBesitz WB(*i);
      std::vector<int> vwert;
      for (std::list<cH_MidgardBasicElement>::const_iterator j=list_Waffen.begin();j!=list_Waffen.end();++j)      
         { cH_Waffe w(*j);
            if (WB->Name() == w->Name()) 
               { 
                 int erf_wert;
                 if (WB->Name()=="Kampfstab"||WB->Name()=="Sai"||WB->Name()=="Tonfa"||WB->Name()=="KusariGama") 
                  {erf_wert = w->Erfolgswert()-5; (erf_wert<=7)?:erf_wert=7; }
                 else if (WB->Name()=="TetsuBo")
                  {erf_wert = w->Erfolgswert()-7; (erf_wert<=7)?:erf_wert=7; }
                 else if (WB->Name()=="GunSen"||WB->Name()=="BuKasa")
                  {erf_wert = w->Erfolgswert(); (erf_wert<=10)?:erf_wert=10; }
                 else if (WB->Name()=="waffenloser Kampf")
                  {if ( w->Erfolgswert()<8)              break       ;
                   if ( 8<=w->Erfolgswert()&&w->Erfolgswert()<12) erf_wert = 1;
                   if (12<=w->Erfolgswert()&&w->Erfolgswert()<16) erf_wert = 2;
                   if (16<=w->Erfolgswert())                      erf_wert = 3;
                  }
                 else erf_wert = w->Erfolgswert();
                 int ewert = Werte.Abwehr_wert()+Werte.bo_Ab() // Grundwerte
                           + erf_wert + WB->av_Bonus() ;// Waffenwerte
                 Vwaffewert += itos(ewert);
               }
         }
       ++i;
       if (i!=Verteidigungswaffen.end() && Vwaffewert!="") Vwaffewert += "$|$"; 
     }
   return Vwaffewert;
}

Waffe_All::Waffe_All(Gtk::ProgressBar *progressbar)
{
 const Tag *waffen=xml_data->find("Waffen");
 if (!waffen)
    cerr << "<Waffen><Waffe/>... nicht gefunden\n";
 else
 {  Tag::const_iterator b=waffen->begin(),e=waffen->end();
    double size=e-b;
    FOR_EACH_CONST_TAG_OF_5(i,*waffen,b,e,"Waffe")
    {  ProgressBar::set_percentage(progressbar,(i-b)/size);
// warum sowas? siehe Zauber.pgcc
       list_All.push_back(&*(cH_Waffe(&*i)));
    }
 }
 ProgressBar::set_percentage(progressbar,1);
}
