/* $Id: zufall.h,v 1.6 2003/08/02 22:27:43 christof Exp $ */
/*  Midgard Character Generator
 *  Copyright (C) 2001 Malte Thoma
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
#ifndef _ZUFALL_H
#  define _ZUFALL_H 

// nicht übermäßig glücklich, das in einem h File zu machen ...
#include <stdlib.h>

// namespace erzeugt warnungen ... ohne static sind sie mehrmals definiert
struct Random {
        static int integer(int min, int max)
        {return min + int(((max-min+1.)*rand())/(RAND_MAX+1.0)); }
        static int W3() { return integer(1,3); }
        static int W6() { return integer(1,6); }
        static int W10() { return integer(1,10); }
        static int W20() { return integer(1,20); }
        static int W100() { return integer(1,100); }
};
#endif
