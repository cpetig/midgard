#ifndef CLASS_TYPEN
#define CLASS_TYPEN


class Data_typen : public HandleContent
{
   int nr,nr_in_optionmenu; //nr= Datenbanknr
   std::string name;

   std::string name_s,zaubern,ausdauer;
   int stand,sb,ruestung;

public:
   Data_typen():nr(0),nr_in_optionmenu(0),stand(0),sb(0),ruestung(0) {}
   Data_typen(int n, int no, const std::string& na,const std::string& s,const std::string& z,
         int st,int _sb,const std::string& a,int r) 
      : nr(n),nr_in_optionmenu(no),name(na),name_s(s),zaubern(z),ausdauer(a),stand(st),sb(_sb),ruestung(r) {}
   void clear() { nr=0;nr_in_optionmenu=0;name="";name_s="";zaubern="";
         ausdauer="";stand=0;sb=0;ruestung=0 ;}

   
//   int Nr() const {return nr;}
   int Nr_Optionmenu() const {return nr_in_optionmenu;}
   std::string Name() const {return name;}
   std::string Short() const {return name_s;}
   std::string Zaubern() const {return zaubern;}
   std::string Ausdauer() const {return ausdauer;}
   int Stand() const {return stand;}
   int Sb() const {return sb;}
   int Ruestung() const {return ruestung;}

//   int Nr() const {return nr;}
   void set_Nr_Optionmenu(int i) {nr_in_optionmenu = i;}
   void set_Name(const std::string &s)  {name=s;}
   void set_Short(const std::string& s)  {name_s=s;}
   void set_Zaubern(const std::string& s)  {zaubern=s;}
   void set_Ausdauer(const std::string& s) {ausdauer=s;}
   void set_Stand(int i) {stand=i;}
   void set_Sb(int i) {sb=i;}
   void set_Ruestung(int i) {ruestung=i;}
};

class cH_Data_typen : public const_Handle<Data_typen>    
{
protected:
 cH_Data_typen() {}
public:
 cH_Data_typen(Data_typen *r) : const_Handle<Data_typen>(r){}
};

#endif
