// $Id: LernListen.hh,v 1.7 2002/09/10 19:55:46 thoma Exp $
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

#ifndef _LERNLISTEN_HH
#  define _LERNLISTEN_HH

#include "Datenbank.hh"

class midgard_CG;
class VAbenteurer;
class WaffeBesitz;

class LernListen
{
      const Datenbank D;
  public:
      enum eMBE{MutterSprache,GastlandSprache,NachbarlandSprache,AlteSprache,
                lFach,lAllg,lUnge,lWaff,lZaub };
//      enum eZusatz{UeberlebenHeimat};

      LernListen(const Datenbank& d) : D(d){}   

      bool nsc_check(bool nsc_allowed,bool nsc_only) const ;
      bool region_check(const std::string& region) const;

      static bool SpracheSchrift(const cH_MidgardBasicElement& MBE);                
      
      std::vector<cH_Spezies> getSpezies(bool nsc_allowed) const ;
      std::vector<pair<cH_Typen,bool> > getTypen(const VAbenteurer& A,bool nsc_allowed) const ;
      std::vector<pair<cH_Land,bool> > getHerkunft(const VAbenteurer& A) const;
      std::vector<MidgardBasicElement::st_zusatz> getLandZusatz() const;
      std::vector<MidgardBasicElement::st_zusatz> getMBEZusatz(const MidgardBasicElement_mutable& MBE) const;
      std::vector<MidgardBasicElement::st_zusatz> getUeberlebenZusatz() const; 
      static std::vector<MidgardBasicElement::st_zusatz> getWaffenZusatz(const std::list<MidgardBasicElement_mutable>& WL); 
      std::vector<MidgardBasicElement::st_zusatz> getSprachenZusatz(const MidgardBasicElement_mutable &MBE,const VAbenteurer& Aben,bool nachbarland) const;
      std::vector<MidgardBasicElement::st_zusatz> getSchriftenZusatz(const MidgardBasicElement_mutable &MBE,const VAbenteurer& Aben) const;

      std::list<WaffeBesitz> getWaffenBesitz(const VAbenteurer& Aben) const;      

      std::list<MidgardBasicElement_mutable> getMBEm(const VAbenteurer& A,eMBE was, int erfolgswert=0,
                     int lernpunkte=0,std::string lernart="") const;

};


#endif
