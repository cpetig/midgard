// $Id: KiDo.hh,v 1.8 2003/09/08 06:27:52 christof Exp $               
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

#ifndef KIDOCLASS
#define KIDOCLASS
#include "MidgardBasicElement.hh"
#include "Typen.hh"
//#include "Ausnahmen.hh"
#include "Fertigkeiten.hh"
#include <Misc/Tag.h>

class KiDo_Stile
{
      std::vector<std::string> Vkido;
   public:
      KiDo_Stile() ;
      bool ist_gelernt(std::string s);
      bool ist_sanft(std::string s);
      bool ist_hart(std::string s);
      bool ist_gemischt(std::string s);
      std::string sanft() {return Vkido[1];}
      std::string hart() {return Vkido[2];}
      std::string gemischt() {return Vkido[3];}
      std::vector<std::string> getVStile() const {return Vkido;}
};



class KiDo : public MidgardBasicElement
{
   std::string deutsch,stufe;
   int ap;
   std::string stil, effekt;

   void get_KiDo(const Tag &tag);
 public:
   KiDo(const Tag &tag);

 enum MBEE What() const {return MidgardBasicElement::KIDO;}
 std::string What_str() const {return "KiDo";}

 std::string HoHo() const {  return Name(); }
 std::string Deutsch() const {  return deutsch; }
 int Kosten(const Abenteurer &A) const 
         { cH_Fertigkeit F("KiDo");
           return  (int)(F->Standard_Faktor(A) * kosten) ; }
 std::string Stufe() const {  return stufe; }
 int Ap() const {  return ap; }
 std::string Stil() const {  return stil; }
 std::string Effekt() const {  return effekt; }

 static int get_erfolgswert_kido(const std::list<MBEmlt>& L);
 static std::map<std::string,int> maxkidostil(const std::list<MBEmlt>& list_Kido);
 int MaxErfolgswert(const Abenteurer &A) const 
         {return 0;} //wg. virtueller Funktion

};

class cH_KiDo : public Handle<const KiDo>
{
    typedef CacheStatic<std::string,cH_KiDo> cache_t;
    static cache_t cache;
    cH_KiDo(const KiDo *s) : Handle<const KiDo>(s) {};
    friend class std::map<std::string,cH_KiDo>;
    cH_KiDo(){};
 public:
    cH_KiDo(const std::string& name ,bool create=false);
    cH_KiDo(const cH_MidgardBasicElement &x) : Handle<const KiDo>
      (dynamic_cast<const KiDo *>(&*x)){}
    static cH_KiDo load(const Tag &t,bool &is_new);

 class sort {
      public:
         enum esort {HOHO,NAME,STUFE,AP,STIL};
      private: 
         esort es;
      public:
         sort(enum esort _es):es(_es) {}
         bool operator() (MBEmlt _x,MBEmlt _y) const;
    };
};

namespace KiDo_All
{  void load(std::list<cH_MidgardBasicElement> &list, const Tag &t);
}

#endif
