// $Id: midgard_CG_typ_2.cc,v 1.12 2001/06/27 10:10:16 thoma Exp $
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

bool midgard_CG::get_typ_s(const string& mod,const Data_typen& t)
{
  if (mod=="Magie")
   {
     if (t.Zaubern()=="z" || t.Zaubern()=="j") return true;
     else return false;
   }
  else abort();
}
