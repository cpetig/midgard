// $Id: waffen_exp.cc,v 1.13 2002/01/19 14:28:11 christof Exp $
/*  Midgard Roleplaying Character Generator
 *  Copyright (C) 2001 Christof Petig
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

#include <fstream>
#include <Aux/Transaction.h>
#include <Aux/dbconnect.h>
#include "export_common.h"
#include <Aux/itos.h>

void waffen_speichern(std::ostream &o)
{  
   o << " <R�stungen>\n";

   Transaction t;
   FetchIStream is;
  {Query query("select ruestung, region, ruestung_s, lp_verlust,"
   		" min_staerke,rw_verlust,b_verlust, abwehr_bonus_verlust,"
   		" angriffs_bonus_verlust, vollruestung"
   	" from ruestung"
   	" where coalesce(region,'')='"+region+"'"
   	" order by coalesce(region,''),lp_verlust");
  while ((query>>is).good())
  {o << "  <R�stung";
   std::string ruestung=fetch_and_write_string_attrib(is, o, "Name");
   fetch_and_write_string_attrib(is, o, "Region");
   fetch_and_write_string_attrib(is, o, "Abk�rzung");
   fetch_and_write_int_attrib(is, o, "sch�tztLP");
   fetch_and_write_int_attrib(is, o, "minimaleSt�rke");
   fetch_and_write_int_attrib(is, o, "Vollr�stung");
   o << ">\n    <Verlust";
   fetch_and_write_int_attrib(is, o, "RW");
   fetch_and_write_int_attrib(is, o, "B");
   fetch_and_write_int_attrib(is, o, "Abwehrbonus");
   fetch_and_write_int_attrib(is, o, "Angriffsbonus");
   o << "/>\n";
   kaufpreis(o, "R�stungen", ruestung);
   o << "  </R�stung>\n";
  }
  }
   o << " </R�stungen>\n";

//********************** waffen ********************************************

   o << " <Waffen>\n";
  {Query query("select name, region, grundkenntnisse, schwierigkeit,"
   		"art, art_2, schaden, schaden_b, zusatz, "
   		MIDGARD3_4("angriffsrangmod,","waffenrang,")
   		"wm_abwehr_leicht, wm_abwehr_schwer, st, "
   		MIDGARD3_4("ge,","gw,gs,")
   		" reichweite_0, reichweite_n,"
   		"reichweite_m, reichweite_f"
   		MIDGARD3_4("",",lern_land,lern_stadt")
   	" from waffen"
   	" where coalesce(region,'')='"+region+"'"
   	" order by coalesce(region,''),art,name");
  while ((query>>is).good())
  {o << "  <Waffe";
   std::string waffe=fetch_and_write_string_attrib(is, o, "Name");
   fetch_and_write_string_attrib(is, o, "Region");
   std::string grund=fetch_and_write_string_attrib(is, o, "Grundkenntnisse");
   fetch_and_write_int_attrib(is, o, "Schwierigkeit",-1);
   fetch_and_write_string_attrib(is, o, "Kategorie");
   fetch_and_write_string_attrib(is, o, "Klasse");
   fetch_and_write_string_attrib(is, o, "Schaden");
   fetch_and_write_int_attrib(is, o, "Schadensbonus");
   fetch_and_write_string_attrib(is, o, "erfordert");
   o << ">\n    <Modifikationen";
#ifdef MIDGARD3   
   fetch_and_write_string_attrib(is, o, "Angriffsrang");
#else   
   fetch_and_write_string_attrib(is, o, "Waffenrang");
#endif
   fetch_and_write_string_attrib(is, o, "Abwehr-leicht");
   fetch_and_write_string_attrib(is, o, "Abwehr-schwer");
   o << "/><Voraussetzungen";
   fetch_and_write_int_attrib(is, o, "St");
#ifdef MIDGARD3   
   fetch_and_write_int_attrib(is, o, "Ge");
#else
   fetch_and_write_int_attrib(is, o, "Gw");
   fetch_and_write_int_attrib(is, o, "Gs");
#endif   
   o << "/><Reichweite";
   fetch_and_write_int_attrib(is, o, "null");
   fetch_and_write_int_attrib(is, o, "nah");
   fetch_and_write_int_attrib(is, o, "mittel");
   fetch_and_write_int_attrib(is, o, "fern");
   o << "/>";
#ifndef MIDGARD3
   o << "<Lernkosten";
   fetch_and_write_int_attrib(is, o, "Land");
   fetch_and_write_int_attrib(is, o, "Stadt");
   o << "/>";
#endif   
   o << "\n";

 //************************* waffen_region_name ************************  
   {  Query query2("select alias,region,schaden,schaden_b,angriffs_mod"
      	" from waffen_region_name"
      	" where name='"+waffe+"'"
   	" and coalesce(region,'')='"+region+"'"
      	" order by region,alias");
      FetchIStream is2;
      while ((query2>>is2).good()) 
      {  o << "    <regionaleVariante";
         std::string varian=fetch_and_write_string_attrib(is2, o, "Name");
         fetch_and_write_string_attrib(is2, o, "Region");
         fetch_and_write_string_attrib(is2, o, "Schaden");
         fetch_and_write_int_attrib(is2, o, "Schadensbonus");
	 o << "><Modifikationen";
         fetch_and_write_int_attrib(is2, o, "Angriff");
         o << "/>\n";
         kaufpreis(o, "Waffen", varian);
         o << "    </regionaleVariante>\n";
// Preis? w�re nett!
      }
     }

//*************** Waffen Typen ***************************
      grund_standard_ausnahme(o, "waffen_typen", waffe);

      //********** Lernschema **********************************
      // wert, attribut, [p+s]_element 
      lernschema(o, MIDGARD3_4("Waffe","Waffenfertigkeiten"), waffe);
      pflicht_lernen(o, waffe);
      verbot_lernen(o, waffe);
//      ausnahmen(o, "w", waffe);
      kaufpreis(o, "Waffen", waffe);
   o << "  </Waffe>\n";
  }
 }
#ifdef REGION
  if (!region.empty())
  {FetchIStream is;
   Query q("select name, region from waffen "
   	+ RegionErgaenzungQuery("waffen.name","waffen_typen","Waffe","w")
   	+ "order by coalesce(region,''),name");
  while ((q >> is).good())
  {o << "  <Waffe";
   std::string waffe=fetch_and_write_string_attrib(is, o, "Name");
   fetch_and_write_string_attrib(is, o, "Region");
   o << ">\n";

 //************************* waffen_region_name ************************  
   {  Query query2("select alias,region,schaden,schaden_b,angriffs_mod"
      	" from waffen_region_name"
      	" where name='"+waffe+"'"
   	" and coalesce(region,'')='"+region+"'"
      	" order by region,alias");
      FetchIStream is2;
      while ((query2>>is2).good()) 
      {  o << "    <regionaleVariante";
         std::string varian=fetch_and_write_string_attrib(is2, o, "Name");
         fetch_and_write_string_attrib(is2, o, "Region");
         fetch_and_write_string_attrib(is2, o, "Schaden");
         fetch_and_write_int_attrib(is2, o, "Schadensbonus");
	 o << "><Modifikationen";
         fetch_and_write_int_attrib(is2, o, "Angriff");
         o << "/>\n";
         kaufpreis(o, "Waffen", varian);
         o << "    </regionaleVariante>\n";
      }
     }

   grund_standard_ausnahme(o, "waffen_typen",waffe,"",true);
   lernschema(o, MIDGARD3_4("Waffe","Waffenfertigkeiten"), waffe,true);
   ausnahmen(o, "w", waffe,true);
   o << "  </Waffe>\n";
  }
  }
#endif 
   o << " </Waffen>\n";

//******************waffen_grund************************************************

  o << " <Waffen-Grundkenntnisse>\n";
  {Query query("select name, region, fp from waffen_grund"
   	" where coalesce(region,'')='"+region+"'"
   	" order by name");
  while ((query>>is).good())
  {o << "  <Waffen-Grundkenntnis";
   std::string grund=fetch_and_write_string_attrib(is, o, "Name");
   fetch_and_write_string_attrib(is, o, "Region");
   fetch_and_write_int_attrib(is, o, "Kosten");
   o << ">\n";
//*************** Waffen Grund Typen ***************************

   // nicht erforderlich f�r Grundkenntnisse?
      grund_standard_ausnahme(o, "waffen_grund_typen", grund);
//      lernschema(o, MIDGARD3_4("Waffe","Waffenfertigkeiten"), grund);
      pflicht_lernen(o, grund);
      verbot_lernen(o, grund);
//      ausnahmen(o, "w", grund);
   o << "  </Waffen-Grundkenntnis>\n";
  }

//*************** andere Regionen ***************************
   if (!region.empty())
   { FetchIStream is;
     Query q("select name, region from waffen_grund "
       	+ RegionErgaenzungQuery("waffen_grund.name","waffen_grund_typen","Waffengrund","g")
       	+ "order by coalesce(region,''),name");
      while ((q >> is).good())
      {o << "  <Waffen-Grundkenntnis";
       std::string grund=fetch_and_write_string_attrib(is, o, "Name");
       fetch_and_write_string_attrib(is, o, "Region");
       o << ">\n";
          grund_standard_ausnahme(o, "waffen_grund_typen", grund, "", true);
       o << "  </Waffen-Grundkenntnis>\n";
      }
   }
   o << " </Waffen-Grundkenntnisse>\n";
  }

//********************* steigern_fertigkeiten_werte ********************
 if (region.empty())
 {o << " <Waffen-Steigern>\n";
  {Query query("select " MIDGARD3_4("name,","schwierigkeit,")
      	    "coalesce(p1,0), coalesce(p2,0), coalesce(p3,0),"
      	    "coalesce(p4,0), coalesce(p5,0), coalesce(p6,0), coalesce(p7,0),"
      	    "coalesce(p8,0), coalesce(p9,0), coalesce(p10,0), coalesce(p11,0),"
      	    "coalesce(p12,0), coalesce(p13,0), coalesce(p14,0), coalesce(p15,0),"
      	    "coalesce(p16,0), coalesce(p17,0), coalesce(p18,0), coalesce(p19,0),"
      	    "coalesce(p20,0)"
       		" from waffen_steigern"
       		" order by " MIDGARD3_4("name","schwierigkeit"));
    FetchIStream is;
       while ((query>>is).good())
       {  o << "    <Kosten";
#ifdef MIDGARD3
          fetch_and_write_string_attrib(is, o, "Kategorie");
#else
	  // 0 auch ausgeben!
          fetch_and_write_int_attrib(is, o, "Schwierigkeit",-1);
#endif
          for (int i=1;i<=20;++i) 
             fetch_and_write_int_attrib(is, o, "Wert"+itos(i));
          o << "/>\n";
       }
   }

//**************************** Waffen Typen ***************************
   grund_standard_ausnahme(o, "waffen_typen", "Waffen");
   o << " </Waffen-Steigern>\n";
 }
//******************************************************************
}

