// $Id: midgard_CG_optionen.cc,v 1.40 2002/01/29 16:02:24 thoma Exp $
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

void midgard_CG::on_checkbutton_original_menu()
{
  if (OptionMenu.menu_original->get_active()) OptionBool.Original=true;
  else OptionBool.Original=false;

  if(OptionBool.Original) 
    { togglebutton_alle_zauber->set_sensitive(false); 
      if(haus_menuitem)
       {
         Hausregeln_setzen(false);
         if(haus_menuitem) haus_menuitem->set_sensitive(false);
       }
      pixmap_logo->show();
    }      
  else 
    { togglebutton_alle_zauber->set_sensitive(true); 
      pixmap_logo->hide();
      if(haus_menuitem) haus_menuitem->set_sensitive(true);
    }      
//  menu_init(); //wg. Hausregeln
}

void midgard_CG::on_checkbutton_info_fenster_menu()
{
  if (OptionMenu.menu_info->get_active()) OptionBool.Info=true;
  else OptionBool.Info=false;
  OptionMenu.menu_info->set_active(OptionBool.Info);
}

void midgard_CG::on_checkbutton_pics_menu()
{
  if (OptionMenu.menu_pics->get_active()) OptionBool.Pics=true;
  else OptionBool.Pics=false;
  OptionMenu.menu_pics->set_active(OptionBool.Pics);
  Pics(OptionBool.Pics);
}

void midgard_CG::on_lernschema_sensitive_menu()
{
   button_beschreibung->set_sensitive(true);
   frame_steigern->set_sensitive(true);
   frame_lernschema->set_sensitive(true);
   button_lernpunkte->set_sensitive(true);
   togglebutton_lernpunkte_edit->set_sensitive(true);
   button_geld_waffen->set_sensitive(true);
   button_ruestung->set_sensitive(true);   
   hbox_beruf->set_sensitive(true);
   table_beruf->set_sensitive(true);
   hbox_fertigkeit->set_sensitive(true);
   table_fertigkeit->set_sensitive(true);
   hbox_waffen->set_sensitive(true);
   table_waffen->set_sensitive(true);
   hbox_zauber->set_sensitive(true); 
   table_magier_lernen->set_sensitive(true);     
   hbox_kido->set_sensitive(true);
   table_kido_lernen->set_sensitive(true);
   button_fertigkeiten->set_sensitive(true);
   button_kido_auswahl->set_sensitive(true);
}



void midgard_CG::on_checkbutton_version_menu()
{
  if (OptionMenu.menu_version->get_active()) OptionBool.version=true;
  else OptionBool.version=false;
  OptionMenu.menu_version->set_active(OptionBool.version);
}



void midgard_CG::Pics(bool b)
{
 if(b)
  {
    pixmap_dfr4->show();
    pixmap_dfr3->show();
    pixmap_Wald->show();
    pixmap_kurai->show();
    toolbar_steigern_lang->show();
    toolbar_steigern_lang2->show();
    toolbar_steigern_kurz->hide();
  }
 else
  {
    pixmap_dfr4->hide();
    pixmap_dfr3->hide();
    pixmap_Wald->hide();
    pixmap_kurai->hide();
    toolbar_steigern_lang->hide();
    toolbar_steigern_lang2->hide();
    toolbar_steigern_kurz->show();
  }
}

      

void midgard_CG::on_checkbutton_Regionen_menu(Gtk::CheckMenuItem *menu_item,cH_Region region)
{
 if(menu_item->get_active()) region->setActive(true);
 else region->setActive(false);

 on_radiobutton_mann_toggled(); // zum Neuaufbau des Typmen�s
 if(notebook_main->get_current_page_num()==PAGE_STEIGERN)
    load_for_page(notebook_lernen->get_current_page_num());

 pixmap_logo->show();
 for(std::vector<cH_Region>::const_iterator i=Database.Regionen.begin();i!=Database.Regionen.end();++i)
  {
   if(!(*i)->Offiziell() && (*i)->Active()) 
     { pixmap_logo->hide();
       break;
     }
  }
}

void midgard_CG::Hausregeln_setzen_from_menu()
{
  for(list<st_Haus>::iterator i=list_Hausregeln.begin();i!=list_Hausregeln.end();++i)
     i->active = i->menu->get_active();
}

void midgard_CG::Hausregeln_setzen(bool b)
{
  for(list<st_Haus>::iterator i=list_Hausregeln.begin();i!=list_Hausregeln.end();++i)
   {
     i->active = b;
     i->menu->set_active(b);
   }
}



void midgard_CG::regnot(std::string sadd)
{
  manage(new WindowInfo(sadd));
}
