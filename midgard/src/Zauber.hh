#ifndef ZAUBERCLASS
#define ZAUBERCLASS
#include <string>
#include <list>
#include <vector>
#include <Aux/Handles.h>
//Y#include "MidgardBasic.hh"
#include <Aux/CacheStatic.h>
#include "class_Grundwerte.hh"
#include "class_typen.hh"
#include "class_Ausnahmen.hh"

class Zauber : public HandleContent
//Yclass Zauber : public MidgardBasic
{
   std::string ap, name;
   int erfolgswert;
   vector<std::string> standard;
   std::string  art, stufe, zauberdauer, reichweite,
      wirkungsziel, wirkungsbereich, wirkungsdauer, ursprung,
      material, agens, prozess, reagens, beschreibung,spruchrolle,
      zauberart,p_element,s_element,region; 
   int kosten;
   int lernpunkte;
   Ausnahmen ausnahmen;

   void get_Zauber();
   int GrundKosten() const {  return kosten; }
   void set_Standard(const vector<H_Data_typen>& Typ) ;
 public: 
   Zauber(const std::string& n,const vector<H_Data_typen>& Typ,const Ausnahmen& a,int l=0) 
      : name(n),lernpunkte(l), ausnahmen(a) {get_Zauber();set_Standard(Typ);} 

//Y   cH_MidgardBasic operator cH_MidgardBasic() const {return cH_MidgardBasic(&*this);}
//Y   int Wert() return 0;
//Y   std::string What() {return "Zauber";}


   std::string Ap() const { return ap;}
   std::string Name() const {  return name; }
   std::string Standard__() const { return standard[0]+' '+standard[1];}
   std::string Art() const { return art;}
   std::string Stufe() const {  return stufe; }
   int iStufe() const {  if (Stufe()=="gro�") return 6; else return atoi(Stufe().c_str()); }
   std::string Zauberdauer() const { return zauberdauer;}
   std::string Zauberart() const { return zauberart;}
   std::string Reichweite() const {return reichweite;}   
   std::string Wirkungsziel() const {return wirkungsziel;}
   std::string Wirkungsdauer() const {return wirkungsdauer;}
   std::string Wirkungsbereich() const {return wirkungsbereich;}
   std::string Ursprung() const {return ursprung;}
   std::string Material() const { return material;}
   std::string Agens() const { return agens;}
   std::string Prozess() const { return prozess;}
   std::string Reagens() const { return reagens;}
   std::string Beschreibung() const { return beschreibung;}
   std::string P_Element() const {return p_element;}
   std::string S_Element() const {return s_element;}
   const vector<std::string>& Standard() const {return standard;}
   std::string Region() const {return region;}
   int Kosten() const;
   int Kosten_eBe(const std::string& pe,const std::string& se) const;
   int Lernpunkte() const {  return lernpunkte; }
   bool Spruchrolle() const 
      { if (spruchrolle=="nicht") return false; 
        else return true; }
   int Erfolgswert(const vector<H_Data_typen>& Typ,const Grundwerte& Werte) const;
   int get_spezial_zauber_for_magier(const Grundwerte& Werte) const;

   static bool zauberwerk_voraussetzung(const std::string& name,const Grundwerte& Werte);
};

class cH_Zauber : public Handle<const Zauber>
{
   struct st_index {std::string name; vector<H_Data_typen> Typ; int lernpunkte;
      bool operator == (const st_index& b) const
         {return (name==b.name && Typ[0]->Short() == b.Typ[0]->Short() && lernpunkte==b.lernpunkte);}
      bool operator <  (const st_index& b) const
         { return name < b.name || 
             (name==b.name && Typ[0]->Short()<b.Typ[0]->Short()) ||
             (name==b.name && Typ[0]->Short()==b.Typ[0]->Short() &&
               lernpunkte<b.lernpunkte ); }
      st_index(std::string n, vector<H_Data_typen> T,int l):name(n),Typ(T),lernpunkte(l){}
      st_index(){}
      };

    typedef CacheStatic<st_index,cH_Zauber> cache_t;
    static cache_t cache;
    cH_Zauber(Zauber *s) : Handle<const Zauber>(s) {};
    friend class std::map<st_index,cH_Zauber>;
    cH_Zauber(){};
 public:
   cH_Zauber(const std::string& name,const vector<H_Data_typen>& Typ,const Ausnahmen& a,int lernpunkte=0) ;
//Y   cH_Zauber(const cH_MidgardBasic &x) : Handle<const Zauber> 
//Y (dynamic_cast<const Zauber *>(&*x)){}
};


class Zauber_sort_name
{ public: bool operator() (cH_Zauber x,cH_Zauber y) const
   {return x->Name() < y->Name(); }};
class Zauber_sort_stufe
{ public: bool operator() (cH_Zauber x,cH_Zauber y) const
   {return x->Stufe()<y->Stufe(); }};
//class Data_zauber_sort_art
//{ public: bool operator() (cH_Data_zauber x,cH_Data_zauber y) const
//   {return x->Art()<y->Art(); }};
class Zauber_sort_ursprung
{ public: bool operator() (cH_Zauber x,cH_Zauber y) const
   {return x->Ursprung()<y->Ursprung(); }};

#endif
