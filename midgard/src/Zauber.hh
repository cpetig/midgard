#ifndef ZAUBERCLASS
#define ZAUBERCLASS
#include "MidgardBasicElement.hh"
#include "Typen.hh"
#include "Ausnahmen.hh"
class cH_Zauber;
#include <gtk--/progressbar.h>


class Zauber : public MidgardBasicElement
{
   std::string ap;//, name;
   std::string  art, stufe, zauberdauer, reichweite,
      wirkungsziel, wirkungsbereich, wirkungsdauer, ursprung,
      material, agens, prozess, reagens, beschreibung,
      zauberart,element;//,region; 
   bool spruchrolle;

   void get_Zauber();
 public: 
#ifdef USE_XML
   Zauber(const Tag *t) 
      : MidgardBasicElement(t,t->getAttr("Name"))
   { get_Zauber();get_map_typ();EP_steigern("Zauber");} 
#else
   Zauber(const std::string& n) 
      : MidgardBasicElement(n)
   {get_Zauber();get_map_typ();EP_steigern("Zauber");} 
#endif   

   enum MBEE What() const {return MidgardBasicElement::ZAUBER;}
   std::string What_str() const {return "Zauber";}

   std::string Ap() const { return ap;}

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
   std::string Element() const {return element;}
//   std::string Region() const {return region;}
   bool Spruchrolle() const {return spruchrolle;}
//   void set_Spruchrolle(bool s) const {spruchrolle=s;}
   int Kosten_eBe(const std::string& pe,const std::string& se) const;
   int Erfolgswert_Z(const vector<cH_Typen>& Typ,const Grundwerte& Werte,const Ausnahmen& ausnahmen) const;
   int MaxErfolgswert(const Grundwerte& w,const vector<cH_Typen>& Typ) const 
         {return 0;} //wg. virtueller Funktion
   int get_spezial_zauber_for_magier(const Grundwerte& Werte,const std::string& standard) const;

//   static void set_Spruchrolle(std::list<cH_MidgardBasicElement>&,bool sp) const;
};

class cH_Zauber : public Handle<const Zauber>
{
/*
   struct st_index {std::string name; int lernpunkte;
      bool operator == (const st_index& b) const
         {return (name==b.name  && lernpunkte==b.lernpunkte);}
      bool operator <  (const st_index& b) const
         { return name < b.name || 
             (name==b.name && lernpunkte<b.lernpunkte ); }
      st_index(std::string n,int l):name(n),lernpunkte(l){}
      st_index(){}
      };
*/
    typedef CacheStatic<std::string,cH_Zauber> cache_t;
    static cache_t cache;
    cH_Zauber(Zauber *s) : Handle<const Zauber>(s) {};
    friend class std::map<std::string,cH_Zauber>;
    cH_Zauber(){};
 public:
   cH_Zauber(const std::string& name) ;
#ifdef USE_XML
   cH_Zauber(const Tag *tag);
#endif

   cH_Zauber(const cH_MidgardBasicElement &x) : Handle<const Zauber> 
      (dynamic_cast<const Zauber *>(&*x)){}

 class sort {
      public:
         enum esort {NAME,STUFE,URSPRUNG};
      private: 
         esort es;
      public:
         sort(enum esort _es):es(_es) {}
         bool operator() (cH_Zauber x,cH_Zauber y) const
           { switch(es) {
               case(NAME) : return x->Name() < y->Name()  ;
               case(STUFE): return x->Stufe() < y->Stufe();
               case(URSPRUNG): return x->Ursprung() < y->Ursprung() ;
           }}
    };

};


class Zauber_All
{
   std::list<cH_MidgardBasicElement> list_All;
  public:
   Zauber_All(Gtk::ProgressBar *progressbar);
   std::list<cH_MidgardBasicElement> get_All() const {return list_All;}
};

#endif
