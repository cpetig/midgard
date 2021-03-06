/*  libMagus: Library zum Verwalten von Midgard Abenteurern
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


#include "config.h"
#include "Wizard.hh"
#include <Misc/inbetween.h>
#include "Abenteurer.hh"
#include <Misc/TraceNV.h>

static const UniqueValue::value_t trace_channel=ManuProC::Tracer::channels.get();
static ManuProC::Tracer::Environment trace_channel_e("DEBUG_WIZARD",trace_channel);

void Wizard::set(esteps was)
{  ManuProC::Trace _t(trace_channel,__FUNCTION__,this,was);
   act_step=was;
}

void Wizard::next_step()
{  ManuProC::Trace _t(trace_channel,__FUNCTION__,this,act_step.Value());
   if (act_step.Value()==FERTIG) return;
   act_step=esteps(int(act_step.Value())+1);
}

bool Wizard::can_skip(const Abenteurer &A)
{  ManuProC::Trace _t(trace_channel,__FUNCTION__,this,act_step.Value());
   switch (act_step.Value())
   {  case SPEZIALWAFFE:
   	 return (!A.Typ1()->Spezialwaffe() && !A.Typ2()->Spezialwaffe())
   	     || !A.Spezialisierung().empty();
      case SPEZIALGEBIET:
         return (!A.Typ1()->Spezialgebiet() && !A.Typ2()->Spezialgebiet())
             || !A.Spezialgebiet()->Name().empty();
      case LERNSCHEMA_SEITE:
         return false;
      case SPEZIES:
         return A.Spezies()->Name()!="Mensch" || A.St()>1 || A.Gw()>1;
      case GRUNDWERTE:
         return A.St()>1 || A.Gw()>1 || A.Gs()>1 || A.Ko()>1 || A.In()>1;
      case GESCHLECHT:
         return A.Geschlecht()!=Enums::Mann || A.Typ1()->Valid();
      case TYP:
         return A.Typ1()->Valid();
      case STADTLAND: // !=Enums::Stadt
      case ABGELEITETEWERTE:
//std::cerr << A.Sb() << ' ' << A.Wk() << ' ' << A.B() << '\n';
         return A.Sb()>1 || A.Wk()>1 || A.B()>0; // A.Au()>1 || A.pA()>1;
      case HERKUNFT:
         return !A.Herkunft()->Name().empty();
      case KIDO_STIL:
#warning KiDo fehlt noch      
	 { // KiDo_Stile kido_stil;
	   // if(kido_stil.ist_gelernt(A.Spezialisierung())) return true;
	 }
         return false;
#warning ...
      case BERUF: return !A.List_Beruf().empty();
      case GELD: return A.Gold() || A.Silber() || A.Kupfer();
      case WAFFEN: return !A.List_Waffen_besitz().empty();
      case RUESTUNG: return A.Ruestung(0)->Name()!="OR";
      case AUSRUESTUNG: // @@
         return false;
      case NAMEN: return A.Name_Abenteurer().substr(0,4)!="Neu ";
      case SPEICHERN: return false;
      case ZWEITER_TYP: return A.Typ2()->Valid();
      case UEBERLEBEN: return (*A.Ueberleben())->Name()!="Überleben Heimat";
      case ANGEBORENEFERTIGKEITEN: return !A.List_Fertigkeit_ang().empty();
      case LERNPUNKTE: return !A.List_Fertigkeit().empty();
      default:
         return false;
   }
}

void Wizard::set(esteps was,const Abenteurer &A)
{  ManuProC::Trace _t(trace_channel,__FUNCTION__,this,was,"Abent");
   set(was);
   skip_if_possible(A);
}

void Wizard::next_step(const Abenteurer &A)
{  ManuProC::Trace _t(trace_channel,__FUNCTION__,this,act_step.Value());
   next_step();
   skip_if_possible(A);
}

void Wizard::done(esteps was,const Abenteurer &A)
{  ManuProC::Trace _t(trace_channel,__FUNCTION__,this,was,NV("act_step",act_step.Value()));
   if (act_step.Value()==FERTIG) return;
   // schauen ob das sinnvoll war - reicht das schon?
   if (was<act_step.Value()) set(was);
   else if (was==act_step.Value()) next_step();
   skip_if_possible(A);
}

void Wizard::skip_if_possible(const Abenteurer &A)
{  ManuProC::Trace _t(trace_channel,__FUNCTION__,this,act_step.Value());
   while (can_skip(A)) next_step();
}

Wizard::Wizard()
 : act_step(SPEZIES), act_mode(Sensitive)
{}
