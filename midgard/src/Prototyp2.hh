// $Id: Prototyp2.hh,v 1.1 2002/10/23 15:36:31 thoma Exp $               
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

#ifndef PROTOTYP2CLASS
#define PROTOTYP2CLASS
#include <string>
#include "xml.h"
#include <Misc/Handles.h>
#include <Misc/CacheStatic.h>
#include <list>
#include <Prozente100.hh>

class cH_Prototyp2;

class Prototyp2 : public HandleContent //Copyable
{
   struct st_protolisten{std::string name; double fac;
          st_protolisten(std::string n, double f) : name(n),fac(f) {}
          bool operator==(std::string b) const {return name==b;}
          };

   std::string name;
   std::vector<st_protolisten> lzauber;
   std::vector<st_protolisten> lfertigkeiten;
          
   void get_Prototyp2();

 public:
   Prototyp2(const Tag *tag);

   std::string Name() const {return name;}
   const std::vector<st_protolisten>& LZauber() const {return lzauber;}
   const std::vector<st_protolisten>& LFertigkeiten() const {return lfertigkeiten;}

   // 'A' enth�lt eine Liste mit den Ausgew�hlten 'Info', 'Wissen', 'Natur', ...
   // 'name' ist die zu lernende Fertigkeit
   // 'art' ist 'F' oder 'Z'
   static double fac_for(const std::string &art, const std::string &name, const std::vector<cH_Prototyp2> &A);
};

class cH_Prototyp2 : public Handle<Prototyp2>
{
    typedef CacheStatic<std::string,cH_Prototyp2> cache_t;
    static cache_t cache;
    friend class std::map<std::string,cH_Prototyp2>;
    cH_Prototyp2(){};
 public:
    cH_Prototyp2(const std::string& name  ,bool create=false);
    cH_Prototyp2(const Tag *tag);
    cH_Prototyp2( Prototyp2 *s) : Handle<Prototyp2>(s) {};
};

class Prototyp2_All
{
   std::list<cH_Prototyp2> list_All;
  public:
   Prototyp2_All();
   std::list<cH_Prototyp2> get_All() const {return list_All;}
};

#endif