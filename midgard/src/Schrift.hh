// $Id: Schrift.hh,v 1.11 2002/01/16 16:08:36 thoma Exp $               
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

#ifndef SCHRIFTCLASS
#define SCHRIFTCLASS
#include "MidgardBasicElement.hh"
#include "Typen.hh"
#include "Ausnahmen.hh"
#include "Fertigkeiten.hh"
#include <gtk--/progressbar.h>


class Schrift : public MidgardBasicElement
{
    std::string art_der_schrift;
    bool alt,kult;

     void get_Schrift();
     int Grundkosten() const {return kosten;}
  
  public:
#ifdef USE_XML
   Schrift(const Tag *t) : MidgardBasicElement(t,t->getAttr("Name"))
      { get_Schrift();get_map_typ(); get_Steigern_Kosten_map();
        EP_steigern("Schreiben");
      }
#else
   Schrift(const std::string& n) : MidgardBasicElement(n)
      { get_Schrift();get_map_typ(); get_Steigern_Kosten_map();
        EP_steigern("Schreiben");
      }
#endif
   enum MBEE What() const {return MidgardBasicElement::SCHRIFT;}
   std::string What_str() const {return "Urschrift";}

   std::string Art_der_Schrift() const   {return art_der_schrift; }

   bool Kult() const {return kult;}
   bool Alt() const {return alt;}
   bool kann_Sprache(const std::list<cH_MidgardBasicElement>& sprache) const;
   int Schrift::MaxErfolgswert(const Grundwerte& w,const vector<cH_Typen>& Typ) const;
   int Kosten(const vector<cH_Typen>& Typ,const Ausnahmen& ausnahmen) const
        { cH_Fertigkeit F("Lesen/Schreiben");
             return  (int)(F->Standard_Faktor(Typ,ausnahmen) * kosten) ; }
   std::list<cH_MidgardBasicElement> gleicheSchrift(const std::list<cH_MidgardBasicElement>& listSchrift) const;
};

class cH_Schrift : public Handle<const Schrift>
{
    typedef CacheStatic<std::string,cH_Schrift> cache_t;
    static cache_t cache;
    cH_Schrift(Schrift *s) : Handle<const Schrift>(s) {};
    friend class std::map<std::string,cH_Schrift>;
    cH_Schrift(){};
  public:
   cH_Schrift(const std::string& name);
#ifdef USE_XML
   cH_Schrift(const Tag *tag);
#endif

   cH_Schrift(const cH_MidgardBasicElement &x) : Handle<const Schrift>
      (dynamic_cast<const Schrift *>(&*x)){}
/*
   class sort {
      public:
         enum esort {NAME,ERFOLGSWERT};
      private: 
         esort es;
      public:
         sort(enum esort _es):es(_es) {}
         bool operator() (cH_Schrift x,cH_Schrift y) const
           { switch(es) {
               case(NAME) : return x->Name() < y->Name()  ;
               case(ERFOLGSWERT): return x->Erfolgswert() < y->Erfolgswert();
           }}
    };
*/
};

class Schriften_All
{
   std::list<cH_MidgardBasicElement> list_All;
  public:
   Schriften_All(Gtk::ProgressBar *progressbar);
   std::list<cH_MidgardBasicElement> get_All() const {return list_All;}
};

#endif
