// $Id: Data_waffenbesitz.hh,v 1.1 2002/05/24 14:06:52 thoma Exp $
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

#ifndef _WINDOW_DATA_WAFFENBESITZ_HH
#  define _WINDOW_DATA_WAFFENBESITZ_HH

//#include <list>
//#include <string>
#include <Aux/EntryValueIntString.h>
#include <Waffe.hh>

#include "MidgardBasicElement.hh"
//class Grundwerte;
//class Typen;
#include "midgard_CG.hh"

class Data_waffenbesitz :  public RowDataBase
{
      cH_MidgardBasicElement waffe;
      const midgard_CG *hauptfenster;
  public:
      Data_waffenbesitz(const cH_MidgardBasicElement& w,const midgard_CG *h)
         : waffe(w), hauptfenster(h) {}

      enum SPALTEN_A {NAME_A,SCHADEN_A,REGION,MAGBONUS,MAGTEXT};
      virtual const cH_EntryValue Value(guint seqnr,gpointer gp) const
       {
         cH_WaffeBesitz W(waffe);
          switch(seqnr) {
            case NAME_A : return cH_EntryValueIntString(W->Name());
            case SCHADEN_A : return cH_EntryValueIntString(W->Schaden(hauptfenster->getCWerte(),waffe->Name()));
            case REGION : return cH_EntryValueIntString(Regionen_All::getRegionfromAbk(hauptfenster->getCDatabase().Regionen,W->Waffe()->Region(W->Name()))->Name());
            case MAGBONUS : return cH_EntryValueIntString(W->Bonus());
            case MAGTEXT : return cH_EntryValueIntString(W->Magisch());
           }
         return cH_EntryValueIntString("?");
       }
      cH_MidgardBasicElement get_Waffe() const {return waffe;}
};

class cH_Data_waffenbesitz : public Handle<const Data_waffenbesitz>
{
protected:
 cH_Data_waffenbesitz() {}
public:
 cH_Data_waffenbesitz(const Data_waffenbesitz *r) : Handle<const Data_waffenbesitz>(r){}
};

#endif
