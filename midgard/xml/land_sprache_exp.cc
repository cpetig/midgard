// $Id: land_sprache_exp.cc,v 1.46 2002/07/04 09:33:22 thoma Exp $
/*  Midgard Roleplaying Character Generator
 *  Copyright (C) 2001-2002 Christof Petig
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

#include <Misc/Transaction.h>
#include <Misc/dbconnect.h>
#include "export_common.h"

void land_speichern(Tag &o)
{  
   Transaction t;
   FetchIStream is;

  if (region.empty())
  {Tag &Laender=o.push_back(Tag("L�nder"));
  {Query query("select distinct kontinent from land"
   	" order by kontinent");
  while ((query>>is).good())
  {Tag &Kontinent=Laender.push_back(Tag("Kontinent"));
   string kontinent=fetch_and_set_string_attrib(is, Kontinent, "Name");
   Query query2("select distinct land from land"
   	" where kontinent='"+kontinent+"'"
   	" order by land");
   FetchIStream is2;
   while ((query2>>is2).good())
   {Tag &Land=Kontinent.push_back(Tag("Land"));
    string land=fetch_and_set_string_attrib(is2, Land, "Name");
    Query query3("select sprache from land"
   	" where kontinent='"+kontinent+"'"
   	" and land='"+land+"'"
   	" order by sprache");
    FetchIStream is3;
    while ((query3>>is3).good())
    { Land.push_back(Tag("Sprache")).setAttr("Name", fetch_string(is3));
    }
   }
  }
 }
  }

//******************************************************************
   Tag &Schriften=o.push_back(Tag("Schriften"));
  {Query query("select name, region,region_zusatz, typ, kosten, alt, kult"
   	" from schrift"
   	" where coalesce(region,'')='"+region+"'"
   	" order by coalesce(region,''),name");
  while ((query>>is).good())
  {Tag &Schrift=Schriften.push_back(Tag("Schrift"));
   string schrift=fetch_and_set_string_attrib(is, Schrift, "Name");
   fetch_and_set_string_attrib(is, Schrift, "Region");
   fetch_and_set_string_attrib(is, Schrift, "RegionZusatz");
   fetch_and_set_string_attrib(is, Schrift, "Typ");
   fetch_and_set_int_attrib(is, Schrift, "Kosten");
   fetch_and_set_bool_attrib(is, Schrift, "alte_Schrift");
   fetch_and_set_bool_attrib(is, Schrift, "Kultschrift");
   Query query2("select schrift from sprache_schrift"
   	" where art_der_schrift="+toSQL(schrift)+" order by schrift");
   FetchIStream is2;
   while ((query2>>is2).good())
   {  Schrift.push_back(Tag("Variante")).setAttr("Name", fetch_string(is2));
   }
  }
  }

//******************************************************************
   Tag &Sprachen=o.push_back(Tag("Sprachen"));
  {Query query("select name, region,region_zusatz, fp, max_wert, alt,"
  	" gruppe_1, gruppe_2, minderheit"
   	" from sprachen"
   	" where coalesce(region,'')='"+region+"'"
   	" order by coalesce(region,''),name");
  while ((query>>is).good())
  {Tag &Sprache=Sprachen.push_back(Tag("Sprache"));
   std::string sprache=fetch_and_set_string_attrib(is, Sprache, "Name");
   fetch_and_set_string_attrib(is, Sprache, "Region");
   fetch_and_set_string_attrib(is, Sprache, "RegionZusatz");
   fetch_and_set_int_attrib(is, Sprache, "Kosten");
   fetch_and_set_int_attrib(is, Sprache, "Maximalwert");
//   fetch_and_set_string_attrib(is, Sprache, "Schrift");
   fetch_and_set_bool_attrib(is, Sprache, "alteSprache");
   fetch_and_set_int_attrib(is, Sprache, "Gruppe");
   fetch_and_set_int_attrib(is, Sprache, "Gruppe2");
   fetch_and_set_bool_attrib(is, Sprache, "Minderheit");

   Query query2("select schrift from sprache_schrift"
   	" where sprache="+toSQL(sprache)+" order by schrift");
   FetchIStream is2;
   while ((query2>>is2).good())
   {  Tag &s=Sprache.push_back(Tag("Schrift"));
      std::string sn=fetch_string(is2);
      if (sn!=sprache) s.setAttr("Name", sn);
   }
  }
  }

//******************************************************************
  if (region.empty())
  {Tag &SpeziesListe=o.push_back(Tag("SpeziesListe"));
   Query query("select spezies, nr, only_nsc, land, hand_bonus, raufen,alter_fak, "
         " groesse_wanz, groesse_wuerfel, groesse_bonus, gewicht_wanz, gewicht_bonus, normgestalt, "
         " b_wanz, b_bonus, lp, ap_bonus, ap_grad_fak, "
         " psy, psy100, phs, phs100, phk, phk100, "
   		" st,gs,gw,ko,\"in\",zt,sb,au "
      	" from spezies"
      	" order by spezies");
  while ((query>>is).good())
  {Tag &Spezies=SpeziesListe.push_back(Tag("Spezies"));
   std::string name=fetch_and_set_string_attrib(is, Spezies, "Name");
   fetch_and_set_int_attrib(is, Spezies, "MAGUS-Index");
   fetch_and_set_bool_attrib(is, Spezies, "only_NSC");
   fetch_and_set_bool_attrib(is, Spezies, "Land");
   fetch_and_set_int_attrib(is, Spezies, "HandBonus");
   fetch_and_set_int_attrib(is, Spezies, "RaufenBonus");
   fetch_and_set_int_attrib(is, Spezies.push_back(Tag("Alter")), "Faktor");
   Tag &Groesse=Spezies.push_back(Tag("Gr��e"));
   fetch_and_set_int_attrib(is, Groesse, "AnzahlW�rfel");
   fetch_and_set_int_attrib(is, Groesse, "W�rfel");
   fetch_and_set_int_attrib(is, Groesse, "Addiere");
   Tag &Gewicht=Spezies.push_back(Tag("Gewicht"));
   fetch_and_set_int_attrib(is, Gewicht, "AnzahlW�rfel");
   fetch_and_set_int_attrib(is, Gewicht, "Addiere");
   fetch_and_set_int_attrib(is, Spezies.push_back(Tag("Normgestalt")), "Wert");
   Tag &Bewegungsweite=Spezies.push_back(Tag("Bewegungsweite"));
   fetch_and_set_int_attrib(is, Bewegungsweite, "AnzahlW�rfel");
   fetch_and_set_int_attrib(is, Bewegungsweite, "Addiere");
   Tag &Modifikation=Spezies.push_back(Tag("Modifikation"));
   fetch_and_set_int_attrib(is, Modifikation, "LP_Bonus");
   fetch_and_set_int_attrib(is, Modifikation, "AP_Bonus");
   fetch_and_set_int_attrib(is, Modifikation, "AP_GradFaktor");
   Tag &Resistenzen=Modifikation.push_back(Tag("Resistenzen"));
   fetch_and_set_int_attrib(is, Resistenzen, "psy");
   fetch_and_set_int_attrib(is, Resistenzen, "psy100");
   fetch_and_set_int_attrib(is, Resistenzen, "phs");
   fetch_and_set_int_attrib(is, Resistenzen, "phs100");
   fetch_and_set_int_attrib(is, Resistenzen, "phk");
   fetch_and_set_int_attrib(is, Resistenzen, "phk100");
   Tag &Grundwerte=Modifikation.push_back(Tag("Grundwerte"));
   fetch_and_set_int_attrib(is, Grundwerte, "St");
   fetch_and_set_int_attrib(is, Grundwerte, "Gs");
   fetch_and_set_int_attrib(is, Grundwerte, "Gw");
   fetch_and_set_int_attrib(is, Grundwerte, "Ko");
   fetch_and_set_int_attrib(is, Grundwerte, "In");
   fetch_and_set_int_attrib(is, Grundwerte, "Zt");
   fetch_and_set_int_attrib(is, Grundwerte, "Sb");
   fetch_and_set_int_attrib(is, Grundwerte, "Au");

   {  Query query2("select typen,maxgrad from spezies_typen"
      	" where spezies='"+name+"'"
      	" order by spezies,typen");
      FetchIStream is2;
      std::string typen;
      while ((query2>>is2).good()) 
      {  Tag &t=Spezies.push_back(Tag("Typ"));
         fetch_and_set_string_attrib(is2, t, "Name");
         fetch_and_set_int_attrib(is2, t, "MaximalerGrad");
      }
   }
   {  Query query3("select art,name,erfolgswert,lp from spezies_angeborene_fert"
      	" where spezies='"+name+"'");
      FetchIStream is3;
      std::string typen;
      while ((query3>>is3).good()) 
      {  Tag &a=Spezies.push_back(Tag("angeboreneFertigkeit"));
         fetch_and_set_string_attrib(is3, a, "Art");
         fetch_and_set_string_attrib(is3, a, "Name");
         fetch_and_set_int_attrib(is3, a, "Erfolgswert");
         fetch_and_set_int_attrib(is3, a, "LP");
      }
   }
   {  Query query3("select land from spezies_herkunft"
      	" where spezies='"+name+"' and land is not null");
      FetchIStream is3;
      while ((query3>>is3).good()) 
         Spezies.push_back(Tag("Land")).setAttr("Name",fetch_string(is3));
   }
   {  Query query3("select sprache from spezies_herkunft"
      	" where spezies='"+name+"' and sprache is not null");
      FetchIStream is3;
      while ((query3>>is3).good()) 
        Spezies.push_back(Tag("Sprache")).setAttr("Name",fetch_string(is3));
   }
  }
  }

//******************************************************************
  if (region.empty())
  {Tag &Gradanstieg=o.push_back(Tag("Gradanstieg"));
   Query query("select grad, gfp, abwehr, resistenz, zaubern, schicksalsgunst,"
   	" ap_kosten, abwehr_kosten, resistenz_kosten, zaubern_kosten"
   	" from grad_anstieg"
   	" order by grad");
  while ((query>>is).good())
  {Tag &g=Gradanstieg.push_back(Tag("Grad"));
   fetch_and_set_int_attrib(is, g, "Grad");
   fetch_and_set_int_attrib(is, g, "GFP");
   fetch_and_set_int_attrib(is, g, "Abwehr");
   fetch_and_set_int_attrib(is, g, "Resistenz");
   fetch_and_set_int_attrib(is, g, "Zaubern");
   fetch_and_set_int_attrib(is, g, "Schicksalsgunst");
   Tag &k=g.push_back(Tag("Kosten"));
   fetch_and_set_int_attrib(is, k, "Ausdauer");
   fetch_and_set_int_attrib(is, k, "Abwehr");
   fetch_and_set_int_attrib(is, k, "Resistenz");
   fetch_and_set_int_attrib(is, k, "Zaubern");
  }
 }

//********************** typen ****************************************
   Tag &Typen=o.push_back(Tag("Typen"));
  {Query query("select typs, region, typnr, typl, typlw, "
  		"typz, sprueche_mit_pp, nsc_only,kultwaffe,lernpflichten, st,gw,gs,\"in\",pa ,beruf, "
  		"stadt_land, ausdauer, stand, sb, ruestung, geld "
   	" from typen"
   	" where coalesce(region,'')='"+region+"'"
   	" order by typnr,coalesce(region,''),typs");
  while ((query>>is).good())
  {Tag &Typ=Typen.push_back(Tag("Typ"));
   std::string typ=fetch_and_set_string_attrib(is, Typ, "Abk�rzung");
   fetch_and_set_string_attrib(is, Typ, "Region");
   fetch_and_set_int_attrib(is, Typ, "MAGUS-Index");
   fetch_and_set_string_attrib(is, Typ, "Bezeichnung-Mann");
   fetch_and_set_string_attrib(is, Typ, "Bezeichnung-Frau");
   char zauberer=fetch_string(is,"n")[0];
   if (zauberer=='z') Typ.setBoolAttr("Zauberer",zauberer=='z');
   if (zauberer=='z'||zauberer=='j') Typ.setBoolAttr("kannZaubern",zauberer=='z'||zauberer=='j');
   fetch_and_set_string_attrib(is, Typ, "Spr�cheMitPraxisPunkten");
   fetch_and_set_bool_attrib(is, Typ, "NSC_only");
   fetch_and_set_bool_attrib(is, Typ, "Kultwaffe");
   fetch_and_set_string_attrib(is, Typ, "Lernpflichten");
   fetch_and_set_int_attrib(is, Typ, "MinSt");
   fetch_and_set_int_attrib(is, Typ, "MinGw");
   fetch_and_set_int_attrib(is, Typ, "MinGs");
   fetch_and_set_int_attrib(is, Typ, "MinIn");
   fetch_and_set_int_attrib(is, Typ, "MinpA");
   fetch_and_set_string_attrib(is, Typ, "Berufswahl");
   string stadt_land=fetch_string(is);
   if (stadt_land=="s") Typ.setBoolAttr("Land", false);
   else if (stadt_land=="l") Typ.setBoolAttr("Stadt", false);
   fetch_and_set_string_attrib(is, Typ, "Ausdauer");
   Tag &Mod=Typ.push_back(Tag("Modifikation"));
   fetch_and_set_int_attrib(is, Mod, "Stand");
   fetch_and_set_int_attrib(is, Mod, "Sb");
   fetch_and_set_int_attrib(is, Mod, "R�stung");
   fetch_and_set_int_attrib(is, Mod, "Geld");
   { 
#warning HACK until typen_gruppe works (here for priests)
     std::string S=typ;
     if(S[0]=='P') S="PRI";
     Query query1("select land from typen_herkunft where typ='"+typ+"'"
   		" order by land");
     FetchIStream is1;
     while ((query1>>is1).good())
     {  Typ.push_back(Tag("Herkunft")).setAttr("Name",fetch_string(is1));
     }
   }
   { Query queryg("select gruppe from typen_gruppe where typ='"+typ+"'"
   		" order by gruppe");
     FetchIStream isg;
     while ((queryg>>isg).good())
     {  Typ.push_back(Tag("Gruppe")).setAttr("Name",fetch_string(isg));
     }
   }
  }
  }
   
// ******************** preise ***********************
  
  if (region.empty())
  {Tag &Preise=o.push_back(Tag("Preise"));
  {Query query("select name, art, art2, kosten, einheit"MIDGARD3_4("",",gewicht")
   	" from preise"
   	" where not exists (select true from waffen"
   		" where waffen.name=preise.name)"
   	" and not exists (select true from ruestung"
   		" where ruestung.ruestung=preise.name)"
   	" order by art,art2,name");
  while ((query>>is).good())
  {Tag &Kaufpreis=Preise.push_back(Tag("Kaufpreis"));
   fetch_and_set_string_attrib(is, Kaufpreis, "Ware");
   fetch_and_set_string_attrib(is, Kaufpreis, "Art");
   fetch_and_set_string_attrib(is, Kaufpreis, "Art2");
   fetch_and_set_float_attrib(is, Kaufpreis, "Preis");
   fetch_and_set_string_attrib(is, Kaufpreis, "W�hrung");
#ifndef MIDGARD3   
   fetch_and_set_float_attrib(is, Kaufpreis, "Gewicht");
#endif
  }
  }

  {Query query("select name, art, art2, faktor, typ, nr" 
  		// min, einheit?
   	" from preise_modifikation"
   	" order by art,art2,typ,name");
  while ((query>>is).good())
  {Tag &Modifikation=Preise.push_back(Tag("Modifikation"));
   fetch_and_set_string_attrib(is, Modifikation, "Bezeichnung");
   fetch_and_set_string_attrib(is, Modifikation, "Art");
   fetch_and_set_string_attrib(is, Modifikation, "Art2");
   fetch_and_set_float_attrib(is, Modifikation, "Faktor");
//   fetch_and_set_int_attrib(is, Modifikation, "Mindestpreis");
//   fetch_and_set_string_attrib(is, Modifikation, "Einheit");
   fetch_and_set_string_attrib(is, Modifikation, "Typ");
   fetch_and_set_int_attrib(is, Modifikation, "MAGUS-Nr");
  }
  }
  }

//******************************************************************
}

