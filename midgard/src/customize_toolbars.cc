// $Id: customize_toolbars.cc,v 1.7 2002/05/16 06:34:07 christof Exp $
/*  Midgard Roleplaying Character Generator
 *  Copyright (C) 2001-2002 Christof Petig
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

#include "customize_toolbars.h"
#include <gtk--/toolbar.h>
#include <gtk--/label.h>
#include <gtk--/table.h>
#include <gtk--/pixmap.h>
#include <gtk--/button.h>
#include <gtk--/box.h>
#include <gtk--/notebook.h>
#include <typeinfo>
// bin + container sind schon dabei

void Gtk::CustomizeToolbars(Gtk::Widget *w, bool show_icons, bool show_text)
{  cout << '+' << typeid(*w).name() << '-' << w->get_name() << '\n';
   if (Gtk::Button::isA(w))
   {  Gtk::Widget *child=dynamic_cast<Gtk::Bin*>(w)->get_child();
      if (child && Gtk::Box::isA(child))
      {  
#if 1 // gtk-1.2 bug         
         Gtk::Box_Helpers::BoxList &ch=dynamic_cast<Gtk::Box*>(child)->children();
         Gtk::Box_Helpers::BoxList::iterator i=ch.begin(),j=i;
         
         if (i!=ch.end() && ++j!=ch.end() && (*i)->get_widget() && (*j)->get_widget())
         {  Gtk::Widget *w1=(*i)->get_widget();
            Gtk::Widget *w2=(*j)->get_widget();
#else
         GList *list=GTK_BOX(child->gtkobj())->children;
         if (list && list->next && !list->next->next)
         {  Gtk::Widget *w1=Gtk::wrap(((GtkBoxChild*)(list->data))->widget);
            Gtk::Widget *w2=Gtk::wrap(((GtkBoxChild*)(list->next->data))->widget);
#endif            
            
            if (Gtk::Pixmap::isA(w1) && Gtk::Label::isA(w2))
            {  if (show_icons) w1->show();
               else w1->hide();
               if (show_text) w2->show();
               else w2->hide();
            }
            else if (Gtk::Label::isA(w1) && Gtk::Pixmap::isA(w2))
            {  if (show_icons) w2->show();
               else w2->hide();
               if (show_text) w1->show();
               else w1->hide();
            }
         }
         
      }
   }
   else if (Gtk::Toolbar::isA(w))
   {  Gtk::Toolbar *tb=dynamic_cast<Gtk::Toolbar*>(w);
      tb->set_style(show_icons ? (show_text?GTK_TOOLBAR_BOTH:GTK_TOOLBAR_ICONS)
      		:GTK_TOOLBAR_TEXT);
      // recurse ?
   }
   else if (Gtk::Bin::isA(w))
   {  Gtk::Widget *child=dynamic_cast<Gtk::Bin*>(w)->get_child();
      if (child) CustomizeToolbars(child,show_icons,show_text);
   }
   else if (Gtk::Table::isA(w))
   {  
#if 0   // a bug in gtkmm-1.2
      Gtk::Table_Helpers::TableList &ch=dynamic_cast<Gtk::Table*>(w)->children();
      for (Gtk::Table_Helpers::TableList::const_iterator i=ch.begin();
      		i!=ch.end();++i)
         CustomizeToolbars(*i,show_icons,show_text);
#endif
      // G_ListWrap<GtkTableChild*>
      for (GList *list=GTK_TABLE(w->gtkobj())->children;list;
      		list=list->next)
      {  CustomizeToolbars(Gtk::wrap(((GtkTableChild*)(list->data))->widget),
      		show_icons,show_text);
      }
   }
   else if (Gtk::Notebook::isA(w))
   {  Gtk::Notebook_Helpers::PageList &ch=dynamic_cast<Gtk::Notebook*>(w)->pages();
      for (Gtk::Notebook_Helpers::PageList::const_iterator i=ch.begin();
      		i!=ch.end();++i)
         CustomizeToolbars((*i)->get_child(),show_icons,show_text);
      // what about the tab?
   }
   else if (Gtk::Container::isA(w))
   {  // und nun ?
      cout << typeid(*w).name() << '\n';
   }
}
