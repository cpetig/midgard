/*  Midgard Character Generator
 *  Copyright (C) 2001-2002 Malte Thoma
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

#ifndef _CLASS_SIMPLELERN_HH
#  define _CLASS_SIMPLELERN_HH

#include <rowdata.h>   
#include "Land.hh"
#include <Misc/EntryValueIntString.h>
#include "MidgardBasicElement.hh"
#include "Region.hh"
#include "Datenbank.hh"

class Data_Herkunft : public RowDataBase
{
      cH_Land Land;
      bool erlaubt;

   public:
      Data_Herkunft(const cH_Land l,bool e)
         : Land(l),erlaubt(e) {}

      enum Spalten {LAND,KONTINENT,SPRACHEN};
      virtual const cH_EntryValue Value(guint seqnr,gpointer gp) const
        {
         switch((Spalten)seqnr) 
           {
            case LAND      : return cH_EntryValueIntString(Land->Name());
            case KONTINENT : return cH_EntryValueIntString(Land->Kontinent());
            case SPRACHEN  : 
              { std::string s;
                vector<std::string> VS=Land->Sprachen();
                for(vector<std::string>::const_iterator i=VS.begin();i!=VS.end();++i)
                  s+= *i + " ";
                return cH_EntryValueIntString(s);
              }
           }
          return cH_EntryValueIntString();
        }
      cH_Land getLand() const {return Land;}
      bool Erlaubt() const {return erlaubt;}
};

class cH_Data_Herkunft : public Handle<Data_Herkunft>
{
public:
 cH_Data_Herkunft(Data_Herkunft *r) : Handle<Data_Herkunft>(r) {}
};

////////////////////////////////////////////////////////////////
class Data_Zusatz : public RowDataBase
{
      MidgardBasicElement_mutable MBE;
      MidgardBasicElement::st_zusatz zusatz;
      Datenbank Database;
   public:
      Data_Zusatz(const MidgardBasicElement_mutable &mbe,MidgardBasicElement::st_zusatz z)
         : MBE(mbe),zusatz(z){}

/*
      Data_Zusatz(const MidgardBasicElement_mutable &mbe,MidgardBasicElement::st_zusatz z,bool e,const Datenbank &D)
         : MBE(mbe),zusatz(z),erlaubt(e),Database(D) {}

      Data_Zusatz(const MidgardBasicElement_mutable &mbe,std::string z,bool e,const Datenbank &D)
         : MBE(mbe),zusatz(z),erlaubt(e),Database(D) {}
*/
      enum Spalten {NAME,TYP,REGION};
      virtual const cH_EntryValue Value(guint seqnr,gpointer gp) const
        {
         switch((Spalten)seqnr) 
           {
            case NAME : return cH_EntryValueIntString(zusatz.name);
            case TYP : return cH_EntryValueIntString(zusatz.typ);
            case REGION : return cH_EntryValueIntString(zusatz.long_region);
//            case REGION : return cH_EntryValueIntString(
//               Regionen_All::getRegionfromAbk(Database.Regionen,zusatz.region)->Name()+" "+zusatz.region_zusatz);
            default : return cH_EntryValueIntString("");
           }
          return cH_EntryValueIntString();
        }
      const MidgardBasicElement_mutable &getMBE() const {return MBE;}
      MidgardBasicElement::st_zusatz getZusatz() const {return zusatz;}
      bool Erlaubt() const {return zusatz.erlaubt;}
};

class cH_Data_Zusatz : public Handle<Data_Zusatz>
{
public:
 cH_Data_Zusatz(Data_Zusatz *r) : Handle<Data_Zusatz>(r) {}
};


  
#endif
