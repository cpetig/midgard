#include <Misc/FetchIStream.h>
#include <vector>
#include <algorithm>
#include <Misc/dbconnect.h>

class Gruppe
{  std::vector<std::string> typen;
   std::string name;
public:
   Gruppe(const std::string &n);
   bool member(const std::string &b) const
   {  return std::find(typen.begin(),typen.end(),b)!=typen.end(); }
};

Gruppe::Gruppe(const std::string &n)
 : name(n)
{  (Query("select typ from typen_gruppe where gruppe=? order by typ")
	<< n)
	.FetchArray(typen);
}

class Gruppen
{  std::vector<Gruppe> gruppen;
public:
   Gruppen();
};

Gruppen::Gruppen() // oder by count
{  std::vector<std::string> typen;
   Query("select distinct gruppe from typen_gruppe order by gruppe")
	.FetchArray(typen);
   std::copy(typen.begin(),typen.end(),std::back_insert_iterator<std::vector<Gruppe> >(gruppen));
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

int main()
{  ManuProC::Connection conn;
   conn.setDbase("midgard");
   ManuProC::dbconnect(conn);
   Gruppen g;
   ManuProC::dbdisconnect();
}
