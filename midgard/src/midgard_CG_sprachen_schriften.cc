// $Id: midgard_CG_sprachen_schriften.cc,v 1.16 2001/06/26 05:20:29 thoma Exp $
/*  Midgard Character Generator
 *  Copyright (C) 2001 Malte Thoma
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

#include "midgard_CG.hh"

void midgard_CG::sprache_uebernehmen(const string& s,int wert)
{
   vec_Sprachen.push_back(new Data_sprache(s,"",wert,0));
   midgard_CG::sprachen_schrift();
}

void midgard_CG::schrift_uebernehmen(const string& s, const string& t)
{
   vec_Schriften.push_back(new Data_schrift(s,t));
   midgard_CG::sprachen_schrift();
}
