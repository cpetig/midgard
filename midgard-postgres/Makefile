# $Id: Makefile,v 1.73 2006/03/01 18:03:42 christof Exp $
#PG_DUMP=pg_dump
PG_DUMP=/usr/local/bin/pg_dump_sort


INSTALLED_TABLES=$(shell psql -t -q -c "select tablename from pg_tables where \
		tablename not like 'pg_%' and tablename not like 'pga_%' \
		and tablename not like 'sql_%';" midgard)
SYSTEM_TABLES=angeborene_fertigkeiten zauber ausnahmen \
	berufe_voraussetzung_4 berufe_vorteile_4 \
	fertigkeiten fertigkeiten_voraussetzung fertigkeiten_voraussetzungen_2 \
	fertigkeiten_besitz fertigkeiten_typen fz_zusaetze kido ki_prototyp \
	land \
	land_nachbarland lernschema_4 \
	pflicht_lernen preise preise_modifikation preise_mod preise_mod_spez \
	spezies spezies_herkunft spezies_typen regionen ruestung \
	schrift sprachen sprache_schrift \
	steigern_fertigkeiten steigern_fertigkeiten_mit \
	steigern_fertigkeiten_werte typen typen_gruppe typen_herkunft \
	waffen waffen_grund waffen_region_name \
	waffen_steigern waffen_typen waffen_grund_typen \
	zauber_beschreibung zauberwerk zauberwerk_typen \
	zauberwerk_voraussetzung spezialgebiete grad_anstieg zauber_typen \
	spezies_angeborene_fert waffen_voraussetzung regionen_lernen \
	prototyp2

OBSELETE_TABLES=berufe_voraussetzung berufe_vorteile berufe_stand \
	arkanum_zauber lernschema praxispunkte pflicht_lernen

TABLES=$(SYSTEM_TABLES) 

VERSION=0.8beta2
PACKAGE=midgard-postgres
DIST_FILES=Makefile $(TABLES)

PGDUMP_FLAGS= -c -O -R -i -T

all:
	@echo $(PACKAGE) Version $(VERSION)
	@echo "make dump: make a dump of your database (without user data)"
	@echo "make dist: make a .tar.gz"
	@echo "make install: install tables (preserving user data)"
	@echo "make diff: compare your tables with these files"
	@echo "make dbclean: drop tables from old versions"

# extract all tables with all data
dump:
	@for i in $(INSTALLED_TABLES) ; \
	do \
	  echo "dumping $$i with data" ; \
	  $(PG_DUMP) $(PGDUMP_FLAGS) -t "$$i" midgard | ./drop_all_varying >"$$i" ; \
	done

# (re)drop varying parts from data
cleanup:
	@for i in $(INSTALLED_TABLES) ; \
	do \
	  ./drop_all_varying <"$$i" >"$$i".novar ;\
	  if cmp -s "$$i" "$$i".novar ; then rm "$$i".novar ; \
	  else mv "$$i".novar "$$i" ; echo "$$i cleaned" ; \
	  fi ; \
	done
	
# extract tables for dist or cvs (user tables without data)

# make distribution tar archive
dist: $(DIST_FILES)
	mkdir $(PACKAGE)-$(VERSION)
	cp $(DIST_FILES) $(PACKAGE)-$(VERSION)
	tar cvzf $(PACKAGE)-$(VERSION).tar.gz $(PACKAGE)-$(VERSION)
	rm -r $(PACKAGE)-$(VERSION)

# install system tables unconditionally, user tables if missing
install:
	-dropdb midgard
	createdb -E utf8 midgard
	# update pg_database set encoding=pg_char_to_encoding('latin1') where datname='midgard';
	@for i in $(SYSTEM_TABLES) ; \
	do \
	  echo "loading $$i" ; \
	  psql midgard <"$$i" ; \
	done
	psql midgard -c "vacuum analyze"

clean:
	rm *~

# compare your tables with these files
diff:
	@for i in $(SYSTEM_TABLES) ; \
	do \
	  $(PG_DUMP) $(PGDUMP_FLAGS) -t "$$i" midgard | ./drop_all_varying | \
		diff -B -I '--.*' -u - "$$i" ; \
	done ; true
dbclean:
	@for i in $(OBSELETE_TABLES) ; \
	do \
	  psql midgard -c "drop table $$i;" ; \
	done ; true
	