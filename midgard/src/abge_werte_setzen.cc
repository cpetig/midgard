// $Id: abge_werte_setzen.cc,v 1.35 2001/12/27 09:39:52 thoma Exp $
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

#include "midgard_CG.hh"

void midgard_CG::on_abge_werte_setzen_clicked()
{
  Werte.set_Sinn("Sechster Sinn",Werte.Zt()/25);

  int grad =1;
  //////////////////////////////////////////////////////////////////////
  // Aussehn
  int au = constraint_aw(random,Werte.Spezies()->Au());
  // pers. Ausstrahlung
  int pa = random.integer(1,100)-30 + 3*(Werte.In()/10. + Werte.Au()/10.) ;
  // Bewegungsweite
  int b = Werte.Spezies()->B_s();
  for (int i=0;i<Werte.Spezies()->B_f();++i) b+=random.integer(1,3);

  // Willenskraft & Selbstbeherrschung
  int wk = random.integer(1,100)-40 + 3*(Werte.In()/10. + Werte.Ko()/10.) ;
//  int sb = constraint_aw(random,Werte.Spezies()->Sb()) 
  int sb = random.integer(1,100) + 3*(Werte.In()/10. + wk/10.) - 30;
  //////////////////////////////////////////////////////////////////////
  // Boni f�r Selbstbeherrschung
  // Assassine, Beschw�rer & Druide
  sb += Typ[0]->Sb() + Typ[1]->Sb();
  // Saddhu
  if (Typ[0]->Short() == "Sa") sb = 80+random.integer(1,20);

  grundwerte_boni_setzen();
  ////////////////////////////////////////////////////////////////////////
  // Was mit den Boni zusammenh�gt:
  // Raufen
  Werte.set_Raufen((Werte.St()+Werte.Gw())/20+Werte.bo_An() );
  if(Werte.Spezies()->Name()=="Zwerg") Werte.set_Raufen(Werte.Raufen()+1);  
  // Abwehr
  int abwehr_wert=11 ;
  // Zaubern:
  //Barde,Ordenskrieger,Zauberer
  int zaubern_wert=2;
  if (Typ[0]->Zaubern() == "j" || Typ[0]->Zaubern() == "z" || Typ[1]->Zaubern() == "j" || Typ[1]->Zaubern() == "z" ) 
     zaubern_wert = 10 ;
  
  int resistenz = 10;

  ////////////////////////////////////////////////////////////////////////
  // LP und AP
  int bo_au_typ;  
  // Ausdauerbonus f�r Typen
  if      (Typ[0]->Ausdauer() == "k" || Typ[1]->Ausdauer() == "k" ) bo_au_typ = 4 ;
  else if (Typ[0]->Ausdauer() == "ak"|| Typ[1]->Ausdauer() == "ak" ) bo_au_typ = 3 ;
  else bo_au_typ = 2 ;
  // Werte w�rfeln und setzen
  int lp = random.integer(1,6)+Werte.Ko()/10.+4+Werte.Spezies()->LPBasis() ;
  int ap = random.integer(1,6)+Werte.bo_Au()+bo_au_typ + Werte.Grad()*Werte.Spezies()->AP_Grad() ;
  if (ap<1) ap=1;

  /////////////////////////////////////////////////////////////////////////
  // K�rper und Stand
  int groesse = Werte.Spezies()->Groesse_s() + Werte.St()/10.;
  for (int i=0;i<Werte.Spezies()->Groesse_f();++i) 
      groesse += random.integer(1,Werte.Spezies()->Groesse_w()) ;
  if (Werte.Spezies()->Name()=="Mensch" && Werte.Geschlecht()=="w")
    groesse-=10;   

//  int ges=random.integer(1,6) + Werte.Spezies()->Gestalt();
  int gewicht=0,ganz=0;
  if(Werte.Spezies()->Name()=="Mensch" || Werte.Spezies()->Name()=="Elf" || Werte.Spezies()->Name()=="Zwerg")
      ganz=4;
  else ganz=3;
  for (int i=0;i<ganz;++i) gewicht+=random.integer(1,6) ;
  if (Werte.Spezies()->Name()=="Mensch" && Werte.Geschlecht()=="w")
   gewicht-=4;
  gewicht += Werte.St()/10. + groesse;
  if(Werte.Spezies()->Name()=="Mensch" || Werte.Spezies()->Name()=="Elf")
      gewicht-=120;
  else gewicht -=90;

  std::string gestalt;
  int g=groesse-100;
  double ge=gewicht/g;
  if(ge>1.1) gestalt="breit";
  else if(ge<0.9) gestalt="schlank";
  else gestalt="normal";

  int ihand=random.integer(1,20);
  std::string shand;
  if(ihand<=15) shand="Rechtsh�nder";
  else if (16<=ihand && ihand<=19) shand="Linksh�nder";
  else shand="Beidh�ndig";
  if (Werte.Spezies()->Name()=="Waldgnom" || Werte.Spezies()->Name()=="Berggnom")
      shand="Beidh�ndig";

  int istand=random.integer(1,100);
  int typstand = Typ[0]->Stand();
  (typstand<Typ[1]->Stand())?typstand=Typ[1]->Stand():
  istand += typstand;
//std::cout << "typstand\t"<<typstand<<"\n";
  std::string stand;  
  if(Werte.Spezies()->Name()=="Mensch")
   {
     if (istand<=10) stand = "Unfrei";
     if (11<=istand&&istand<=50) stand = "Volk";
     if (51<=istand&&istand<=90) stand = "Mittelschicht";
     if (istand>=91) stand = "Adel";
   }
  else if(Werte.Spezies()->Name()=="Halbling" ||
          Werte.Spezies()->Name()=="Waldgnom" ||
          Werte.Spezies()->Name()=="Berggnom")
   {
     if (istand<=50) stand = "Volk";
     if (51<=istand) stand = "Mittelschicht";
   }
  else
   {
     if (            istand<=50) stand = "Volk";
     if (51<=istand&&istand<=90) stand = "Mittelschicht";
     if (istand>=91) stand = "Adel";
   }
  Werte.set_Abgeleitetewerte(au,pa,sb,wk,b,lp,ap,abwehr_wert,zaubern_wert,
   resistenz,gestalt,shand,gewicht,groesse,grad,stand);

  if (Originalbool) original_midgard_check() ;
  zeige_werte(Werte);
  button_herkunft->set_sensitive(true);
  button_sprache->set_sensitive(true);
  button_beschreibung->set_sensitive(true);
//  frame_steigern->show();  
//  table_lernschema->set_sensetive(true);
  frame_lernschema->set_sensitive(true);
}


void midgard_CG::grundwerte_boni_setzen()
{
  int bo_au  = Werte.Ko()/10. + Werte.St()/20. - 7 ;
  int bo_sc  = Werte.St()/20. + Werte.Gs()/30. - 3 ;;

  //Angriff
  int bo_an  =0;
  int ist=Werte.Gs();
  if (1<=ist&&ist<=5) { bo_an-=2; }
  if (6<=ist&&ist<=20) { bo_an-=1; }
  if (81<=ist&&ist<=95) { bo_an+=1;}
  if (96<=ist) {bo_an+=2;}

  //Abwehr
  int bo_ab  =0;
  ist=Werte.Gw();
  if (1<=ist&&ist<=5) { bo_ab-=2;}
  if (6<=ist&&ist<=20) { bo_ab-=1; }
  if (81<=ist&&ist<=95) { bo_ab+=1;}
  if (96<=ist) { bo_ab+=2;}

  //Zaubern
  int bo_za  =0;
  ist=Werte.Zt();
  if (ist<=5)           {bo_za-=3; }
  if (6<=ist&&ist<=20)  {bo_za-=2; }
  if (21<=ist&&ist<=40) {bo_za-=1; }
  if (61<=ist&&ist<=80) {bo_za+=1; }
  if (81<=ist&&ist<=95) {bo_za+=2; }
  if (96<=ist&&ist<=99) {bo_za+=3; }
  if (ist>=100)         {bo_za+=4; }

  // Geistesmagie
  ist=Werte.Zt();
  int bo_psyZt =0;
  if (ist<=5)           {bo_psyZt-=2; }
  if (6<=ist&&ist<=20)  {bo_psyZt-=1; }
  if (81<=ist&&ist<=95) {bo_psyZt+=1; }
  if (96<=ist&&ist<=99) {bo_psyZt+=2; }
  if (ist>=100)         {bo_psyZt+=3; }
  ist=Werte.In();
  int bo_psyIn =0;
  if (ist<=5)           { bo_psyIn-=2; }
  if (6<=ist&&ist<=20)  { bo_psyIn-=1; }
  if (81<=ist&&ist<=95) { bo_psyIn+=1; }
  if (96<=ist)          { bo_psyIn+=2; }
  int bo_psy = (bo_psyZt>bo_psyIn) ? bo_psyZt : bo_psyIn ;
  if (Werte.Spezies()->Name()=="Elf" && Werte.Zt() <= 100 ) { bo_psy+=2;}
  if (Werte.Spezies()->Name()=="Elf" && Werte.Zt() >= 100 ) { bo_psy+=3;}
  if (Werte.Spezies()->Name()=="Berggnom") { bo_psy+=5;}
  if (Werte.Spezies()->Name()=="Waldgnom") { bo_psy+=5;}
  if (Werte.Spezies()->Name()=="Halbling") { bo_psy+=5;}
  if (Werte.Spezies()->Name()=="Zwerg")    { bo_psy+=4;}
  // K�rpermagie
  ist=Werte.Zt();
  int bo_phsZt =0;
  if (ist<=5)           {bo_phsZt-=2; }
  if (6<=ist&&ist<=20)  {bo_phsZt-=1; }
  if (81<=ist&&ist<=95) {bo_phsZt+=1; }
  if (96<=ist&&ist<=99) {bo_phsZt+=2; }
  if (ist>=100)         {bo_phsZt+=3; }
  ist=Werte.Ko();
  int bo_phsKo =0;
  if (ist<=5)           { bo_phsKo-=2; }
  if (6<=ist&&ist<=20)  { bo_phsKo-=1; }
  if (81<=ist&&ist<=95) { bo_phsKo+=1; }
  if (96<=ist)          { bo_phsKo+=2; }
  int bo_phs = (bo_phsZt>bo_phsKo) ? bo_phsZt : bo_phsKo ;
  if (Werte.Spezies()->Name()=="Elf" && Werte.Zt() <= 100 ) { bo_phs+=2;}
  if (Werte.Spezies()->Name()=="Elf" && Werte.Zt() >= 100 ) { bo_phs+=3;}
  if (Werte.Spezies()->Name()=="Berggnom") { bo_phs+=5;}
  if (Werte.Spezies()->Name()=="Waldgnom") { bo_phs+=5;}
  if (Werte.Spezies()->Name()=="Halbling") { bo_phs+=5;}
  if (Werte.Spezies()->Name()=="Zwerg")    { bo_phs+=4;}
  // Umgebungsmagie
  ist=Werte.Gw();
  int bo_phk =0;
  if (ist<=5)           {bo_phk-=2; }
  if (6<=ist&&ist<=20)  {bo_phk-=1; }
  if (81<=ist&&ist<=95) {bo_phk+=1; }
  if (96<=ist)          {bo_phk+=2; }
  if (Werte.Spezies()->Name()=="Elf") { bo_phs+=2;}
  if (Werte.Spezies()->Name()=="Berggnom") { bo_phs+=5;}
  if (Werte.Spezies()->Name()=="Waldgnom") { bo_phs+=5;}
  if (Werte.Spezies()->Name()=="Halbling") { bo_phs+=5;}

/*
  // Speziesspezifische Boni
//  if (bo_ab <Werte.Spezies()->Abb()) bo_ab =Werte.Spezies()->Abb();
  if (bo_psy<Werte.Spezies()->Psy()) bo_psy=Werte.Spezies()->Psy();
  if (bo_phs<Werte.Spezies()->Phs()) bo_phs=Werte.Spezies()->Phs();
  if (bo_phk<Werte.Spezies()->Phk()) bo_phk=Werte.Spezies()->Phk();
*/

  // Grundlegende Resistenz
  if (Typ[0]->Zaubern()=="z" || Typ[1]->Zaubern()=="z" ) 
      { bo_phs+=3; bo_psy+=3; bo_phk+=3; }
  else
      { bo_phs+=2; }

  Werte.set_Abgeleitetewerte_Boni(bo_au,bo_sc,bo_an,bo_ab,bo_za,bo_psy,bo_phs,
   bo_phk);
}

void midgard_CG::original_midgard_check()
{
   int st=Werte.St(),gw=Werte.Gw(),gs=Werte.Gs(),ko=Werte.Ko(),in=Werte.In(),zt=Werte.Zt();
   if (st>100) st=100;
   if (st<1)  st=1;
   if (gw>100) gw=100;
   if (gw<1)   gw=1;
   if (gs>100) gs=100;
   if (gs<1)   gs=1;
   if (ko>100) ko=100;
   if (ko<1)   ko=1;
   if (in>100) in=100;
   if (in<1)   in=1;
   if (zt>100) zt=100;
   if (zt<1)   zt=1;
   Werte.set_Basiswerte(st,gw,gs,ko,in,zt);

   int au=Werte.Au(),pa=Werte.pA(),sb=Werte.Sb(),wk=Werte.Wk();
   if (au>100) au=100;
   if (au<1)   au=1;
   if (pa>100) pa=100;
   if (pa<1)   pa=1;
   if (sb>100) sb=100;
   if (sb<1)   sb=1;
   if (wk>100) wk=100;
   if (wk<1)   wk=1;
   Werte.set_Abgeleitetewerte_small(au,pa,sb,wk);
}
