// $Id: Ruestung.hh,v 1.5 2003/09/01 06:47:57 christof Exp $               
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

#ifndef RUESTUNGCLASS
#define RUESTUNGCLASS
#include <Misc/Handles.h>
#include <Misc/CacheStatic.h>
#include <vector>
#include <string>
#include <list>
class Tag;
//#include "xml.h"

class Grundwerte;
class Ruestung  : public HandleContent // Copyable
{
   std::string name, longname, region,behinderung_wie; 
   int lp_verlust,min_staerke,rw_verlust,b_verlust,
      abwehr_bonus_verlust,angriffs_bonus_verlust;
   int vollruestungsabzug;

   std::string BehinderungWie() const {return behinderung_wie;}
  public:
//   Ruestung() {};
   Ruestung(const Tag &tag);

   std::string Name() const   {return name; }
   std::string Long() const {return longname;}
   std::string Region() const {return region;}
   int LP_Verlust() const {return lp_verlust;}
   int Min_Staerke() const {return min_staerke;}
   int RW_Verlust() const {return rw_verlust;}
//   int B_Verlust() const {return b_verlust;}
   int B_Verlust(const double &ueberlast,const Grundwerte &Werte,bool &ew) const;
   int AbwehrBonus_Verlust(int abwehr_bonus) const;
   int AngriffsBonus_Verlust(int angriffs_bonus) const;
   int VollRuestungsAbzug() const {return vollruestungsabzug;}
};

class cH_Ruestung : public Handle<const Ruestung>
{
    typedef CacheStatic<std::string,cH_Ruestung> cache_t;
    static cache_t cache;
  public:
//   cH_Ruestung() {*this=new Ruestung();}
   cH_Ruestung() {} // needed for e.g. Gtk::TreeModelColumn<cH_Ruestung>
   cH_Ruestung(const std::string& name, bool create=false);
   static cH_Ruestung load(const Tag &tag, bool &is_new);
   cH_Ruestung(const Ruestung *s) : Handle<const Ruestung>(s) {};
};

namespace Ruestung_All
{  void load(std::list<cH_Ruestung> &list, const Tag &t);
   void load(std::vector<cH_Ruestung> &list, const Tag &t);
}

#endif
