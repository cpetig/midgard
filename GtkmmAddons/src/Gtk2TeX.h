/*  Gtk--addons: a collection of gtk-- addons
 *  Copyright (C) 2001 Adolf Petig GmbH & Co. KG, written by Christof Petig
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Library General Public License for more details.
 *
 *  You should have received a copy of the GNU Library General Public
 *  License along with this library; if not, write to the Free
 *  Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

// $Id: Gtk2TeX.h,v 1.13 2002/07/26 06:28:30 christof Exp $

#include <iostream>
#include <TeX.h>
#include <gtk--/clist.h>

namespace Gtk2TeX
{	using namespace TeX;

	typedef std::string (*ColumnType_cb)(int col,const std::string &typ,const std::string &title,gpointer user_data);
	typedef std::string (*ColumnTitle_cb)(int col,const std::string &title,gpointer user_data);
	typedef std::string (*Element_cb)(const Gtk::CList::Row &r,int col,const std::string &text,gpointer user_data);
	typedef void (*Row_cb)(std::ostream &o,const Gtk::CList::Row &r,gpointer user_data);
	struct TableFlags
	{	bool longtable:1;
		bool headline:1; // output ...\endhead
		bool environment:1; // output \begin{}{}...\end{}
		bool multicolumn:1; // let columns grow into next ones if empty
		ColumnType_cb columntype_cb;
		Row_cb preline_cb,postline_cb;
		Simple_cb prehead_cb,posthead_cb,postlist_cb;
		Gtk::CList::SelectionList *selection;
		// there's no selection ctor ... so 
		gint first_line,last_line;
		gpointer user_data;
		ColumnTitle_cb columntitle_cb;
		Element_cb element_cb;
	
		TableFlags()
		: longtable(true), headline(true), environment(true),
		  multicolumn(0),
		  columntype_cb(0), preline_cb(0), postline_cb(0),
		  prehead_cb(0), posthead_cb(0), postlist_cb(0),
		  selection(0), first_line(0), last_line(-1),
		  user_data(0), columntitle_cb(0),
		  element_cb(0)
		{}
	};
	
	std::ostream &CList2Table(std::ostream &os,const Gtk::CList *cl,const TableFlags &fl=TableFlags());
};
