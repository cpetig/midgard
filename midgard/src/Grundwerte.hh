// $Id: Grundwerte.hh,v 1.26 2002/03/09 22:06:57 thoma Exp $               
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

#ifndef CLASS_GRUND
#define CLASS_GRUND
#include "Land.hh"
#include "Ruestung.hh"
#include "Spezies.hh"
#include "Spezialgebiet.hh"
#include "Typen.hh"

class Grundwerte
{
   struct st_grund{int st;int gw;int gs;int ko;int in;int zt;
          st_grund() :st(0),gw(0),gs(0),ko(0),in(0),zt(0) {}
          st_grund(int _st,int _gw,int _gs,int _ko,int _in,int _zt)
             :  st(_st),gw(_gw),gs(_gs),ko(_ko),in(_in),zt(_zt) {}
         };         
   st_grund grund;
   std::map<std::string,int> sinnmap;
   int raufen;

   int au,pa,sb,wk,b,lp,ap;
   int gg,sg;
   int abwehr_wert,abwehr_pp,zaubern_wert,zauber_pp;
   int resistenz,resistenz_pp;
   int alter;
   std::string geschlecht;
   int gewicht,groesse,grad;
   std::string stand,spezialisierung,hand,
      glaube,name_abenteurer,name_spieler,version,beschreibung,beschreibung_pix;
   int gfp;
   float steigertage;
   int gold,silber,kupfer,aep,kep,zep;
   cH_Land herkunft;
   cH_Ruestung ruestung; 
   cH_Spezies spezies;
   cH_Spezialgebiet spezialgebiet;
   std::string stadt_land;

public:
   Grundwerte() : raufen(0),au(0),pa(0),sb(0), wk(0),
             b(0),lp(0),ap(0),gg(0),sg(0),abwehr_wert(0),abwehr_pp(0),
             zaubern_wert(0),zauber_pp(0),resistenz(0),resistenz_pp(0),
             alter(0),geschlecht("m"),gewicht(0),groesse(0),grad(1),
             stand(""),glaube(""),name_abenteurer(""),version("Erschaffung"),
             gfp(0),steigertage(0),gold(0), silber(0), kupfer(0),
             aep(0),kep(0),zep(0),ruestung("OR"),spezies("Mensch"),
             stadt_land("Stadt") 
         { resetSinne(); }
   void clear() {*this=Grundwerte();}
   void resetSinne() ;
   void setSt(int i) {grund.st=i;}
   void setGw(int i) {grund.gw=i;}
   void setGs(int i) {grund.gs=i;}
   void setKo(int i) {grund.ko=i;}
   void setIn(int i) {grund.in=i;}
   void setZt(int i) {grund.zt=i;}
   int St() const {return grund.st;}
   int Gw() const {return grund.gw;}
   int Gs() const {return grund.gs;}
   int Ko() const {return grund.ko;}
   int In() const {return grund.in;}
   int Zt() const {return grund.zt;}
   int Au() const {return au;}
   int pA() const {return pa;}
   int Sb() const {return sb;}
   int Wk() const {return wk;}
   int B() const {return b;}
   int LP() const {return lp;}
   int AP() const {return ap;}
   std::map<std::string,int> Sinne() const {return sinnmap;}
   int Raufen() const;
   int Abwehr_wert() const {return abwehr_wert;}
   int AbwehrPP() const {return abwehr_pp;}
   int Zaubern_wert() const { return zaubern_wert;}
   int ZaubernPP() const { return zauber_pp;}
   int Resistenz() const {return resistenz;}
   int ResistenzPP() const {return resistenz_pp;}
   int bo_Au() const;
   int bo_Sc() const;
   int bo_An() const; 
   int bo_Ab() const;
   int bo_Za() const;
   int bo_Psy(const vector<cH_Typen>& Typ) const;
   int bo_Phs(const vector<cH_Typen>& Typ) const;
   int bo_Phk(const vector<cH_Typen>& Typ) const;
   int KAW() const {return St()/10;}
   int WLW() const {return 40+Ko()/2;}
   int Geistesblitz() const {return In()/10;}
   int Gift() const {if(Ko()) return 30 + Ko()/2; else return 0;}
   int Alter() const {return alter;}
   std::string Gestalt() const ;
   std::string Geschlecht() const {return geschlecht;}
   std::string Hand() const {return hand;}
   int Gewicht() const {return gewicht;}
   int Groesse() const {return groesse;}
   std::string GroesseBez() const ;
   int Grad() const {return grad;}
   int SG() const {return sg;}
   int GG() const {return gg;}
   cH_Spezialgebiet Spezialgebiet() const {return spezialgebiet;}
   std::string Spezialisierung() const {return spezialisierung;}
//   std::string Spezial2() const {return spezial2;}
   std::string Stand() const {return stand;}
   cH_Land Herkunft() const {return herkunft;}
   cH_Spezies Spezies() const {return spezies;}
   std::string Glaube() const {return glaube;}
   std::string Name_Abenteurer() const {return name_abenteurer;}
   std::string Name_Spieler() const {return name_spieler;}
   std::string Version() const;
   std::string Beschreibung() const {return beschreibung;}
   std::string BeschreibungPix() const {return beschreibung_pix;}
   std::string Stadt_Land() const {return stadt_land;}
   cH_Ruestung Ruestung() const {return ruestung;}
   int GFP() const {return gfp;}
   float Steigertage() const {return steigertage;}
   int Gold() const {return gold;}
   int Silber() const {return silber;}
   int Kupfer() const {return kupfer;}
   int AEP() const {return aep;}
   int KEP() const {return kep;}
   int ZEP() const {return zep;}

   void add_St(int i) {grund.st+=i;}
   void add_Gw(int i) {grund.gw+=i;}
   void add_Gs(int i) {grund.gs+=i;}
   void add_Ko(int i) {grund.ko+=i;}
   void add_In(int i) {grund.in+=i;}
   void add_Zt(int i) {grund.zt+=i;}
   void add_Au(int i) {au+=i;}
   void add_pA(int i) {pa+=i;}
   void add_Sb(int i) {sb+=i;}
   void add_Wk(int i) {wk+=i;}

   void setLP(int i) {lp=i;}
   void setBasiswerte(int st,int gw,int gs,int ko,int in, int zt)
         {grund=st_grund(st,gw,gs,ko,in,zt);}
   void setGewicht(int i) {gewicht=i;}
   void setGroesse(int i) {groesse=i;}
   void setHand(std::string s) {hand=s;}
   void setStand(std::string s) {stand=s;}
   void setAu(int i) {au=i;}
   void setpA(int i) {pa=i;}
   void setSb(int i) {sb=i;}
   void setWk(int i) {wk=i;}
   void setB(int i) {b=i;}
   void setAbgeleitetewerte_small(int _au,int _pa,int _sb,int _wk)
      { au=_au ;pa=_pa ;sb=_sb; wk=_wk; }

   void setSinn(const std::string &name,int wert) {sinnmap[name]=wert;}
   void setSinnCheck(const std::string &name,int wert); // wg. Speziessinnen

   int Sehen() const {return const_cast<std::map<std::string,int>&>(sinnmap)["Sehen"];}
   int Hoeren() const {return const_cast<std::map<std::string,int>&>(sinnmap)["H�ren"];}
   int Riechen() const {return const_cast<std::map<std::string,int>&>(sinnmap)["Riechen"];}
   int Schmecken() const {return const_cast<std::map<std::string,int>&>(sinnmap)["Schmecken"];}
   int Tasten() const {return const_cast<std::map<std::string,int>&>(sinnmap)["Tasten"];}
   int SechsterSinn() const {return const_cast<std::map<std::string,int>&>(sinnmap)["Sechster Sinn"];}

   void setGrad1Werte(const vector<cH_Typen>& Typ);

   void setZaubern_wert(int i){zaubern_wert=i;}
   void setAbwehr_wert(int i){abwehr_wert=i;}
   void setResistenz(int i){resistenz=i;}
   void setZaubernPP(int i){zauber_pp=i;}
   void setAbwehrPP(int i){abwehr_pp=i;}
   void setResistenzPP(int i){resistenz_pp=i;}
   void addZaubernPP(int i){zauber_pp+=i;}
   void addAbwehrPP(int i){abwehr_pp+=i;}
   void addResistenzPP(int i){resistenz_pp+=i;}
   void setGrad(int i){grad=i;}
   void setAP(int i){ap=i;}
   void setSG(int i){sg=i;}
   void add_SG(int i){sg+=i;}
   void setGG(int i){gg=i;}
   void setAlter(int _alter){alter=_alter;}
   void setGeschlecht(const std::string& _geschlecht){geschlecht=_geschlecht;}
   void setSpezialisierung(const std::string& _spezialisierung){spezialisierung=_spezialisierung;}   
   void setSpezialgebiet(const cH_Spezialgebiet& s) {spezialgebiet=s;}
//   void setSpezial(const std::string& _spezial,std::string _spezial2){spezial=_spezial;spezial2=_spezial2;}
   void setHerkunft(const cH_Land& _herkunft){herkunft=_herkunft;}
   void setSpezies(const cH_Spezies& _spezies){spezies=_spezies;}
   void setGlaube(const std::string& _glaube){glaube=_glaube;}
   void setAbenteurername(const std::string& s) {name_abenteurer=s;}
   void setNamen(const std::string& _name_abenteurer,std::string _name_spieler, std::string _version)
      {name_abenteurer=_name_abenteurer;name_spieler=_name_spieler;version=_version;}
   void setNameC(const std::string& s) {name_abenteurer=s;}
   void setNameS(const std::string& s) { name_spieler=s;}
   void setVersion(const std::string& s) { version=s;}

   void setBeschreibung(const std::string& _b){beschreibung=_b;}
   void setBeschreibungPix(const std::string& _b){beschreibung_pix=_b;}
   void setRuestung(const cH_Ruestung _ruestung){ruestung=_ruestung;}
   void setStadt_Land(const std::string& sl) {stadt_land=sl;}
   void setGFP(int _gfp){gfp=_gfp;}
   void addGFP(int _gfp){gfp += _gfp;}
   void setSteigertage(float i){steigertage=i;}
   void addSteigertage(float i){steigertage+=i;}
   void setGeld(int g,int s,int k){gold=g;silber=s;kupfer=k;}
   void addGold(int g)  {gold+=g;}
   void addSilber(int s) {silber+=s;}
   void addKupfer(int k) {kupfer+=k;}
   void setEP(int a, int k, int z) {aep=a;kep=k;zep=z;}
   void addAEP(int a) {aep+=a;}
   void addKEP(int a) {kep+=a;}
   void addZEP(int a) {zep+=a;}
   void setKEP(int a) {kep=a;}
   void setZEP(int a) {zep=a;}

};
/*
class H_Grundwerte : public Handle<Grundwerte>    
{
protected:
 H_Grundwerte() {}
public:
 H_Grundwerte(Grundwerte *r) : Handle<Grundwerte>(r){}
};
*/
#endif
