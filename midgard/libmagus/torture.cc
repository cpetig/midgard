/*  Midgard Character Generator
 *  Copyright (C) 2003 Christof Petig 
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

#include "Datenbank.hh"
#include "magustrace.h"
#include <Misc/Trace.h>
#include "magus_paths.h"
#include <fstream>
#include "Abenteurer.hh"
#include <Misc/TagStream.h>
#include "NotFound.h"
#include "Ausgabe.hh"
#include <Misc/itos.h>
#include "Zufall.hh"
#include "LaTeX_drucken.hh"
#include "spielleiter_export.hh"

void progress(double d)
{  Ausgabe(Ausgabe::Warning, "Progress " +itos(int(d*100))+ "%");
}

int main(int argc,char **argv)
{  ManuProC::Tracer::Enable(LibMagus::trace_channel,true);
//   Datenbank db;
   if (argc>1) TagStream::host_encoding=argv[1];
   magus_paths::init(argv[0]);
 try {  
   Datenbank::init(&progress); // db.load(&progress);
   
   Abenteurer a;
   Zufall z(a);
   z.Voll();
   
   { std::ofstream datei("torture.magus");
     if (!datei.good()) Ausgabe(Ausgabe::Error,"Kann torture.magus nicht beschreiben");
     else a.speicherstream(datei);
   }
   
   LaTeX_drucken dr;
   dr.Ausdrucken(a);
   
   spielleiter_export_save(a,"torture.txt");
 } catch (NotFound &e)
 {  Ausgabe(Ausgabe::Error, "NotFound "+ e.Name());  }
}
