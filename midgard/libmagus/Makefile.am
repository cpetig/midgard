# $Id: Makefile.am,v 1.59 2006/08/11 10:22:04 thoma Exp $

SIGC_MAJOR=2

SUBDIRS=tests

if WINDOWS
PORT_FILES=registry.cc TeX.cc
WIN_LDFLAGS=-no-undefined -export-symbols libmagus_sigc$(SIGC_MAJOR).def \
		-Wl,--enable-runtime-pseudo-reloc
DLL_LDADD=@COMMONXX_LIBS@ @SIGC_LIBS@ libmagus_res.lo
DLL_DEF=libmagus_sigc$(SIGC_MAJOR).def
else
PORT_FILES=
WIN_LDFLAGS=
DLL_LDADD=
DLL_DEF=
endif

libmagus_sigc$(SIGC_MAJOR).def: libmagus.def libmagus_sigc$(SIGC_MAJOR).defadd
	cat >$@ $^

libmagus_res.lo: libmagus.rc
	WINDRES=i586-mingw32msvc-windres $(top_srcdir)/../ManuProC_Base/build/win32/lt-compile-resource $< $@

AM_CPPFLAGS = @COMMONXX_INCLUDES@ $(WIN_INCLUDES) -I.. \
	@COMMONGTK2_INCLUDES@ -Dlibmagus_COMPILATION
#	@XMLPP_CFLAGS@ 

AM_LDFLAGS = @COMMONXX_LDFLAGS@ @COMMONGTK2_LDFLAGS@ $(WIN_LDFLAGS)

CLEANFILES = *~

bin_PROGRAMS= Zufallscharakter magus2txt magus2pdf

EXTRA_PROGRAMS= test readxml readxml2 model_test \
	model_test2 OptionenTest model_test3 test_spec test_Undo

registry.h: ../win32/registry.h ; ln -sf ../win32/$@ .
registry.cc: ../win32/registry.cc ; ln -sf ../win32/$@ .

test_SOURCES=test.cc
Zufallscharakter_SOURCES=Zufallscharakter.cc
magus2txt_SOURCES=magus2txt.cc
magus2pdf_SOURCES=magus2pdf.cc
OptionenTest_SOURCES=OptionenTest.cc
readxml_SOURCES=readxml.cc
readxml2_SOURCES=readxml2.cc
model_test_SOURCES=model_test.cc
model_test2_SOURCES=model_test2.cc
model_test3_SOURCES=model_test3.cc
test_spec_SOURCES=test_spec.cc
test_Undo_SOURCES=test_Undo.cc

lib_LTLIBRARIES=libmagus.la

libmagus_la_LIBADD=$(DLL_LDADD)

EXTRA_QUELLEN=Abenteurer_steigern.cc LernListen_steigern.cc KI.cc \
	LaTeX_drucken_ausruestung.cc LaTeX_drucken.cc \
	LaTeX_drucken_beschreibung.cc LaTeX_drucken_spielleiterbogen.cc \
	grundwerte_abge_werte.cc grundwerte_gw_wuerfeln.cc \
	Zufall.cc Zufall_Lernschema.cc Zufall_Spezies_Typ.cc \
	spielleiter_export.cc Magus_Optionen.cc AbenteurerLernpunkte.cc \
	VAbenteurer.cc zufall_steigern.cc VAbentModelProxy.cc \
	Wizard.cc ResistenzUndCo.cc

libmagus_la_SOURCES=MidgardBasicElement.cc Zauber.cc KiDo.cc \
	Zauberwerk.cc Land.cc Waffe.cc WaffeGrund.cc Sinne.cc \
	Typen.cc Schrift.cc Ruestung.cc Beruf.cc Fertigkeiten_angeboren.cc \
	Fertigkeiten.cc Sprache.cc Spezies.cc Abenteurer_besitz.cc \
	Ausruestung.cc dtos1.cc Windows_Linux.cc magus_paths.cc \
	Datenbank.cc Grad_anstieg.cc \
	Grundwerte.cc LernListen.cc Preise.cc Prototyp2.cc \
	Prototyp.cc Prozente100.cc  Spezialgebiet.cc \
	xml.cc Region.cc Optionen.cc Abenteurer.cc magustrace.cc \
	Lernschema.cc Ausgabe.cc snprintf.c $(PORT_FILES) \
	$(EXTRA_QUELLEN) Random.cc libmagus.cc CopyFile.cc

test_LDADD = libmagus.la @COMMONGTK2_ONLY@ @COMMONXX_LIBS@ @SIGC_LIBS@
Zufallscharakter_LDADD = libmagus.la @COMMONGTK2_ONLY@ @COMMONXX_LIBS@ @SIGC_LIBS@ 
magus2txt_LDADD= $(Zufallscharakter_LDADD)
magus2pdf_LDADD= $(Zufallscharakter_LDADD)
OptionenTest_LDADD = $(Zufallscharakter_LDADD)
readxml_LDADD = @COMMONXX_LIBS@ @SIGC_LIBS@
#readxml2_LDADD = @XMLPP_LIBS@
model_test_LDADD = $(Zufallscharakter_LDADD)
model_test2_LDADD = $(Zufallscharakter_LDADD)
model_test3_LDADD = $(Zufallscharakter_LDADD)
test_spec_LDADD = $(Zufallscharakter_LDADD)
test_Undo_LDADD= $(Zufallscharakter_LDADD)

BUILT_SOURCES= registry.h TeX.cc libmagus_sigc$(SIGC_MAJOR).def

TeX.cc: ../../GtkmmAddons/src/TeX.cc
	ln -sf $^ $@

def: libmagus.la
	OBJS=`for i in $(libmagus_la_SOURCES) ; do case $$i in \
		*.cc) echo .libs/$$i.o | sed -e 's/\.cc//' ;; esac ; done` ; \
	i586-mingw32msvc-dlltool $$OBJS --export-all-symbols --output-def /dev/stdout \
		| grep -v '^;' | sed -e 's|@ .* DATA$$| DATA|' -e 's|@ .*$$||' \
		| sort >.libmagus.def.tmp
	fgrep -v sigc .libmagus.def.tmp > libmagus.def.new
	fgrep sigc .libmagus.def.tmp > libmagus_sigc2.defadd.new
