#include <Misc/FetchIStream.h>
#include <vector>

class Gruppe
{  std::vector<std::string> typen;
   std::string name;
public:
   Gruppe(const std::string &n);
   bool member(const std::string &b) const
   {  return std::find(
};

Gruppe::Gruppe(const std::string &n)
 : name(n)
{  typen=Query("select typ from typen_gruppe where gruppe='"+n+"' order by typ")
	.FetchArray<std::string>();
}

class Gruppen
{  std::vector<Gruppe> gruppen;
public:
   Gruppen();
};

Gruppen::Gruppen()
 : name(n)
{  typen=Query("select typ from typen_gruppe where gruppe='"+n+"' order by typ")
	.FetchArray<std::string>();
}

enum gsan_t { Grund, Standard, Ausnahme, Nicht, GsanAnz, Illegal=-1 };

struct Schnitt
{  int gsan[GsanAnz];
   
   int Wieviel(gsan_t wo);
   gsan_t Maximum() const; // gibt wo zur�ck oder -1
};

class Fertigkeit
{  std::vector<std::string> gsan[GsanAnz];
   bool nicht_notwendig;
   std::vector<std::string> &get_vec(gsan_t wo) { return gsan[wo]; }
public:
   Fertigkeit(const std::string &name);
   Schnitt schneiden(const Gruppe &g) const;
   void ersetze(gsan_t wo, const Gruppe &g);
};
