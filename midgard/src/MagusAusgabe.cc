// $Id: MagusAusgabe.cc,v 1.5 2006/02/06 07:26:53 christof Exp $
/*  Midgard Character Generator
 *  Copyright (C) 2003-2004 Christof Petig
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

#include <MagusAusgabe.hh>
#include <WindowInfo.hh>

std::vector<Magus_Ausgabe::entry> Magus_Ausgabe::remembered;

static WindowInfo *fenster;

void Magus_Ausgabe::attach(WindowInfo *w)
{  fenster=w;
   for (std::vector<entry>::const_iterator i=remembered.begin();i!=remembered.end();++i)
      replay(*i);
   remembered.clear();
}

// auch im Hauptfenster anzeigen ...
void Magus_Ausgabe::callback(Ausgabe::Level l,const std::string &text)
{  if (fenster) replay(entry(l,text));
   else 
      remembered.push_back(entry(l,text));
   sig_ausgabe(l,text);
}

void Magus_Ausgabe::replay(const entry &e)
{  fenster->AppendShow(e.text,e.l);
}

void Magus_Ausgabe::register_Ausgabe()
{  Ausgabe::set(&Magus_Ausgabe::callback);
}

SigC::Signal2<void,Ausgabe::Level,std::string> Magus_Ausgabe::sig_ausgabe;
