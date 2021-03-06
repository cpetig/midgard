/*  Midgard Character Generator
 *  Copyright (C) 2006 Christof Petig 
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

#include <libmagus/Zauber.hh>
#include "test_header.cc"
   VAbenteurer::iterator ch=AbenteurerAuswahl::Chars->load("Hl.magus");
   ch->begin_undo();
   ch->getAbenteurer().wie_steigern=Abenteurer::ws_Praxispunkte;
   ch->getAbenteurer().wie_steigern_variante=Abenteurer::wsv_PraxispunkteFP;
   ch->getAbenteurer().setSpezialPP(1);
   MBEmlt zau=ch->getAbenteurer().get_unknown(cH_Zauber("Reinigen"));
   ch->getAbenteurer().Erlernen(zau);
   ch->name_undo("Zauber mit PP erlernen");
   { std::ofstream out("test7.magus");
     ch->getAbenteurer().speichern(out);
   }
TEST_FOOTER
