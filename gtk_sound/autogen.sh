#!/bin/sh
# generated 2001/8/25 19:23:23 CEST by thoma@Tiger.
# using glademm V0.6.2_cvs

if test ! -f install-sh ; then touch install-sh ; fi

MAKE=`which gnumake`
if test ! -x "$MAKE" ; then MAKE=`which gmake` ; fi
if test ! -x "$MAKE" ; then MAKE=`which make` ; fi
HAVE_GNU_MAKE=`$MAKE --version|grep -c "Free Software Foundation"`

if test "$HAVE_GNU_MAKE" != "1"; then 
echo Using non GNU Make at $MAKE
else
echo Found GNU Make at $MAKE ... good.
fi

echo This script runs configure and make...
echo You did remember necessary arguments for configure, right?

if test ! -x `which aclocal`  
then echo you need autoconfig and automake to generate the Makefile
fi
if test ! -x `which automake`  
then echo you need automake to generate the Makefile
fi

libtoolize --force --copy
autoheader
aclocal
automake --add-missing --copy --gnu
autoconf
./configure $* && $MAKE
