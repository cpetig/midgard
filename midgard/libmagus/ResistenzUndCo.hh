// $Id: ResistenzUndCo.hh,v 1.5 2006/01/31 23:52:47 christof Exp $               
/*  Midgard Character Generator
 *  Copyright (C) 2004 Christof Petig
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

#ifndef _3934FD0E_F6A4_4B6E_9EC2_BDECC4C29EBE
#define _3934FD0E_F6A4_4B6E_9EC2_BDECC4C29EBE
#include "MidgardBasicElement.hh"

/* Diese Klasse dient nur dazu, um diese speziellen Werte ebenfalls
   über ein MBE(mlt) steigern zu können */

class ResistenzUndCo : public MidgardBasicElement
{public:
   enum was_t { eAusdauer,eAbwehr,eZaubern,eResistenz };
private:
   was_t was_ist_es;
   
   ResistenzUndCo(was_t w) : MidgardBasicElement(What_str(w)), was_ist_es(w) {}
   static std::string What_str(was_t w);
public:
   // Zaubern könnte auch cH_Fertigkeit("Zaubern") werden!
   static Handle<const ResistenzUndCo> Ausdauer,Abwehr,Zaubern,Resistenz;
   static Handle<const ResistenzUndCo> getMBE(was_t w);
   
   enum MBEE What() const {return MidgardBasicElement::RESISTENZ_UND_CO;}
   std::string What_str() const { return name; }
   was_t WasIstEs() const { return was_ist_es; }
   // Kosten errechnen hier hinein (aus get_ausdauer & get_ab_re_za heraus)
   // ebenso MaxWert
};

typedef Handle<const ResistenzUndCo> cH_ResistenzUndCo;

#endif
