// generated 2002/8/26 14:40:04 CEST by thoma@Tiger.(none)
// using glademm V1.1.1c_cvs
//
// newer (non customized) versions of this file go to frame_icons.cc_new

// This file is for your program, I won't touch it again!

#include "config.h"
#include "frame_icons.hh"

#include "midgard_CG.hh"
#include <bool_CheckButton.hh>

void frame_icons::set_Hauptfenster(midgard_CG *h)
{
 hauptfenster=h;
}

void frame_icons::init() 
{
 if(!hauptfenster) assert(!"");
 if(!(hauptfenster->getOptionen())) assert(!"");
 Gtk::Table *table=manage(new Gtk::Table(0,0,false));
 std::list<Midgard_Optionen::st_Icon> &L=hauptfenster->getOptionen()->getIcon();
 int count=0;
 for(std::list<Midgard_Optionen::st_Icon>::iterator i=L.begin();i!=L.end();++i)
  {
    bool_CheckButton *cb = manage(new bool_CheckButton(i->active,i->text,0,0.5));
    i->active.signal_changed().connect(SigC::bind(SigC::slot(*this,&frame_icons::element_activate),i->index));
    table->attach(*cb,0,1,count,count+1,Gtk::FILL,0,0,0);
    ++count;
  }
 table->show_all();
 add(*table);
}

void frame_icons::element_activate(gpointer gp,Midgard_Optionen::IconIndex index)
{
  hauptfenster->getOptionen()->Icon_setzen_from_menu(index);
}

