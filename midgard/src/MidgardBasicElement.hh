#ifndef MIDGARDBASICELEMENT
#define MIDGARDBASICELEMENT
#include <Aux/Handles.h>
#include <Aux/CacheStatic.h>
#include <string>
#include <vector>
#include <list>

class H_Data_typen;
class Grundwerte;
class Ausnahmen;
class H_Data_beruf;
//class cH_Zauber;
class cH_MidgardBasicElement;
class SimpleTree;

class MidgardBasicElement : public HandleContent
{
   public:
      enum MBEE {FERTIGKEIT,WAFFEN,ZAUBER,ZAUBERWERK,KIDO,SPRACHE,SCHRIFT} ;
      enum TREE {OLD,NEW};
//      TREE& operator++(TREE& t) {return t+1;}

      virtual std::string Name() const=0;
      virtual int Erfolgswert(const vector<H_Data_typen>& Typ,const Grundwerte& Werte,const Ausnahmen& ausnahmen) const {return 99;}
      virtual std::string Region() const {return "";}
      virtual enum MBEE What() const=0;
      virtual std::string What_str() const=0; // zum speichern
      virtual map<std::string,std::string> get_MapTyp() const=0;
      bool ist_lernbar(const vector<H_Data_typen>& Typ,const map<std::string,std::string>& map_typ) const;
      bool ist_gelernt(const std::list<cH_MidgardBasicElement>& L) const;
      
      virtual bool operator == (const MidgardBasicElement& b) const 
         {return Name()==b.Name();}


      static void move_element(std::list<cH_MidgardBasicElement>& von,std::list<cH_MidgardBasicElement>& nach,const std::string& name);
      static void show_list_in_tree(
            const std::list<cH_MidgardBasicElement>& BasicList,
            SimpleTree *Tree, 
            const Grundwerte& Werte, const vector<H_Data_typen>& Typ,
            const Ausnahmen& ausnahmen, 
            char variante='0', bool b=false);
      static void saveElementliste(const std::list<cH_MidgardBasicElement>& b,
                                   const Grundwerte& Werte,
                                   const vector<H_Data_typen>& Typ,
                                   const Ausnahmen& ausnahmen);

};

class cH_MidgardBasicElement : public Handle<const MidgardBasicElement>
{
      typedef CacheStatic<std::string,cH_MidgardBasicElement> cache_t;
      static cache_t cache;
//      cH_MidgardBasicElement(MidgardBasicElement *s) : Handle<const MidgardBasicElement>(s) {};
      friend class std::map<std::string,cH_MidgardBasicElement>;
      cH_MidgardBasicElement(){}
   public:
//        cH_MidgardBasicElement(const std::string& name);
      cH_MidgardBasicElement(const MidgardBasicElement *r) 
            : Handle<const MidgardBasicElement>(r){}
//      bool operator== (const cH_MidgardBasicElement b) 
//         {return b==(*this);)

//      cH_MidgardBasicElement(const cH_Zauber *r) 
//            : Handle<const cH_Zauber>(r){}

//      const std::list<cH_MidgardBasicElement>& (cH_Zauber(std::string n));


};
   

#endif
