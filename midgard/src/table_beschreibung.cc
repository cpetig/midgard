// generated 2002/5/13 20:46:12 CEST by thoma@Tiger.(none)
// using glademm V0.6.4b_cvs
//
// newer (non customized) versions of this file go to table_beschreibung.cc_new

// This file is for your program, I won't touch it again!

#include "config.h"
#include "table_beschreibung.hh"
#include "midgard_CG.hh"
#include "xml_fileselection.hh"

void table_beschreibung::init(midgard_CG *h)
{
  hauptfenster=h;
  show_beschreibung();
}

gint table_beschreibung::on_text_charakter_beschreibung_focus_out_event(GdkEventFocus *ev)
{  
  std::string b=text_charakter_beschreibung->get_chars(0,text_charakter_beschreibung->get_length());
  hauptfenster->getWerte().setBeschreibung(b);
  hauptfenster->undosave("Beschreibung ge�ndert");
  return 0;
}

void table_beschreibung::on_button_beschreibung_drucken_clicked()
{  
  hauptfenster->on_beschreibung_drucken();
}

void table_beschreibung::on_button_grafik_clicked()
{  
#ifndef __MINGW32__
  manage 
#else    
  delete 
#endif   
  (new xml_fileselection(hauptfenster,xml_fileselection::Pix,&(hauptfenster->getWerte())));
  hauptfenster->undosave("Bild ge�ndert");
}

gint table_beschreibung::on_spinbutton_pix_breite_focus_out_event(GdkEventFocus *ev)
{ 
 hauptfenster->getWerte().setBeschreibungPixSize(spinbutton_pix_breite->get_value_as_int());
 hauptfenster->undosave("Bildgr��e ge�ndert");
 return 0;
}

gint table_beschreibung::on_spinbutton_pix_breite_focus_in_event(GdkEventFocus *ev)
{  
  spinbutton_pix_breite->select_region(0,-1);   
  return 0;
}

void table_beschreibung::show_beschreibung()
{
  text_charakter_beschreibung->delete_text(0,text_charakter_beschreibung->get_length());
  gint pos=0;
  text_charakter_beschreibung->insert_text(hauptfenster->getWerte().Beschreibung().c_str()
      , hauptfenster->getWerte().Beschreibung().size(), &pos);

  std::string s="Bild";
  if(hauptfenster->getWerte().BeschreibungPix()!="")
    s+=":\n"+hauptfenster->getWerte().BeschreibungPix();
  label_grafik->set_text(s);

  spinbutton_pix_breite->set_value(hauptfenster->getWerte().BeschreibungPixSize());
}
