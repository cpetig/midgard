/*  Midgard Character Generator
 *  Copyright (C) 2001-2002 Malte Thoma
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
#include "table_ausruestung.hh"
#include "midgard_CG.hh"
#include <Gtk_OStream.h>
#include <Misc/EntryValueIntString.h>
#include <fstream>
#include <Misc/itos.h>
#include "dtos1.h"

void table_ausruestung::init(midgard_CG *h)
{
   besitz=0;
   hauptfenster=h;
   zeige_werte();
   ausruestung_laden();
   table_gruppe->hide();
   table_artikel->hide();      
   togglebutton_gruppe_neu->hide(); // nicht implementiert
   fill_new_preise();
}
   
   
void table_ausruestung::ausruestung_laden()
{
  sichtbarConnection=checkbutton_sichtbar->toggled.connect(SigC::slot(static_cast<class table_ausruestung*>(this), &table_ausruestung::on_checkbutton_sichtbar_toggled));
  showAusruestung();
}


void table_ausruestung::showAusruestung()
{
  hauptfenster->getAben().setStandardAusruestung();

  besitz=0;
  std::vector<std::string> title;
  title.push_back("Titel");
  title.push_back("Material");
  title.push_back("Sichtbar");
  Ausruestung_tree=manage(new Gtk::CTree(title));

  Ausruestung_tree->drag_data_received.connect(slot(this,&(table_ausruestung::tree_drag_data_received)));
  Ausruestung_tree->drag_dest_set ( GTK_DEST_DEFAULT_ALL,
         target_table, n_targets - 1, /* no rootwin */
         static_cast < GdkDragAction > ( GDK_ACTION_COPY | GDK_ACTION_MOVE) );
  
  Gtk::CTree_Helpers::RowList::iterator r;
  AusruestungBaum be=hauptfenster->getChar()->getBesitz();
  for(AusruestungBaum::const_iterator i=be.begin();i!=be.end();++i)
   {
     std::vector <string> v;
     v.push_back(i->getAusruestung().Name());
     v.push_back(i->getAusruestung().Material());
     v.push_back(i->getAusruestung().SichtbarStr());
     Ausruestung_tree->rows().push_back(Gtk::CTree_Helpers::Element(v));
     r=--(Ausruestung_tree->rows().end());
     r->set_data(gpointer(&*i));
cout << "show "<<v[0]<<'\t'<<&*i<<'\t'<<i->getAusruestung().Name()<<'\n';
     showChildren(r,i->getChildren());
   }

  r->expand_recursive();
  Ausruestung_tree->show(); 
  Ausruestung_tree->tree_select_row.connect(SigC::slot(static_cast<class table_ausruestung*>(this), &table_ausruestung::on_Ausruestung_tree_select_row));
  Ausruestung_tree->tree_unselect_row.connect(SigC::slot(static_cast<class table_ausruestung*>(this), &table_ausruestung::on_Ausruestung_tree_unselect_row));
  for (unsigned int i=0;i<Ausruestung_tree->columns().size();++i)
         Ausruestung_tree->set_column_auto_resize(i,true);
            
  viewport_ausruestung->remove();
  viewport_ausruestung->add(*Ausruestung_tree);
  button_ausruestung_loeschen->set_sensitive(false);
}


void table_ausruestung::showChildren(Gtk::CTree_Helpers::RowList::iterator r,const list<AusruestungBaum> &AB)
{
  Gtk::CTree_Helpers::RowList::iterator n;
  for(std::list<AusruestungBaum>::const_iterator i=AB.begin();i!=AB.end();++i)
   {
     std::vector <string> v;
     v.push_back(i->getAusruestung().Name());
     v.push_back(i->getAusruestung().Material());
     v.push_back(i->getAusruestung().SichtbarStr());
     r->subtree().push_back(Gtk::CTree_Helpers::Element(v));
     n=--(r->subtree().end());
     n->set_data(gpointer(&*i));
     showChildren(n,i->getChildren());
   }  
}



bool table_ausruestung::tree_valid(Gtk::CTree_Helpers::SelectionList &selectionList)
{
  if(selectionList.empty())
   {
      cout<< "Keine Zeile gew�hlt\n";
      button_ausruestung_loeschen->set_sensitive(true);
      return false;
   }
  if(selectionList.size()>1)
   {
      cout<< "Zuviele Zeilen gew�hlt\n";
      button_ausruestung_loeschen->set_sensitive(true);
      return false;
   }
  return true;
}

void table_ausruestung::on_Ausruestung_tree_unselect_row(Gtk::CTree::Row row,gint column)
{
  button_ausruestung_loeschen->set_sensitive(false);
  besitz=0;
}

void table_ausruestung::on_Ausruestung_tree_select_row(Gtk::CTree::Row row,gint column)
{
  Gtk::CTree_Helpers::SelectionList selectionList = Ausruestung_tree->selection();
  if(!tree_valid(selectionList)) return;
  AusruestungBaum *A=static_cast<AusruestungBaum*>(selectionList.begin()->get_data());
  sichtbarConnection.disconnect();
  checkbutton_sichtbar->set_active(A->getAusruestung().Sichtbar());
  sichtbarConnection=checkbutton_sichtbar->toggled.connect(SigC::slot(static_cast<class table_ausruestung*>(this), &table_ausruestung::on_checkbutton_sichtbar_toggled));
  button_ausruestung_loeschen->set_sensitive(true);
cout << "SEL: "<<' '<<A<<'\t'<<  besitz<<'\t'<<A->getAusruestung().Sichtbar()<<'\n';
  besitz=A;
cout << "SEL: "<<' '<<A<<'\t'<<  besitz<<'\t'<<besitz->getAusruestung().Material()<<'#'<<'\n';
//  cout << "SEL: "<<' '<<A<<'\t'<<A->getAusruestung().Name()<<'\n';


//  cout << "SEL: "<<' '<<besitz<<'\t'<<besitz->getAusruestung().Name()<<'\n';
}


void table_ausruestung::on_checkbutton_sichtbar_toggled()
{
/*
  Gtk::CTree_Helpers::SelectionList selectionList = Ausruestung_tree->selection();
  if(!tree_valid(selectionList)) return;

  AusruestungBaum &A=*static_cast<AusruestungBaum*>(selectionList.begin()->get_data());
  const_cast<Ausruestung&>(A.getAusruestung()).setSichtbar(checkbutton_sichtbar->get_active());
*/
  if(!besitz) return;
cout << "Sichtbar 1: "<<'\t'<<  besitz<<'\t'<<besitz->getAusruestung().Sichtbar()<<'\n';
  const_cast<Ausruestung&>(besitz->getAusruestung()).setSichtbar(checkbutton_sichtbar->get_active());
cout << "Sichtbar 2: "<<'\t'<<  besitz<<'\t'<<besitz->getAusruestung().Sichtbar()<<'\n';
  showAusruestung();
}


void table_ausruestung::on_ausruestung_loeschen_clicked()
{
/*
  Gtk::CTree_Helpers::SelectionList selectionList = Ausruestung_tree->selection();
  if(!tree_valid(selectionList)) return;
  AusruestungBaum &A=*static_cast<AusruestungBaum*>(selectionList.begin()->get_data());
  AusruestungBaum *Parent = A.getParent();
*/
  if(!besitz) return;
  AusruestungBaum *Parent = besitz->getParent();
//  if(Parent)  Parent->remove(A);  
  if(Parent)  Parent->remove(*besitz);  
  else cerr << "Keine Herkunftsnode gesetzt\n";

/*
  Gtk::CTree_Helpers::Row parent = selectionList.begin()->get_parent();  
  for(Gtk::CTree_Helpers::Row::iterator i=parent.begin();i!=parent.end();++i)
   {
     Gtk::CTree_Helpers::Cell& cell = *i;   
cout <<"Cell: " <<cell.get_text()<<'\n';
//cout <<i->get_data()<<'\n';
//     if ((*i)->get_data() == A);// { parent.remove(i); break;}
   }
*/
  showAusruestung();
}

void table_ausruestung::on_checkbutton_ausruestung_geld_toggled()
{
}

/*
  if(checkbutton_ausruestung_geld->get_active())
   {
     int g=0,s=0,k=0;
     if(einheit=="GS") g=atoi(kosten.c_str());
     if(einheit=="SS") s=atoi(kosten.c_str());
     if(einheit=="KS") k=atoi(kosten.c_str());
     hauptfenster->getWerte().addGold(-g);
     hauptfenster->getWerte().addSilber(-s);
     hauptfenster->getWerte().addKupfer(-k);
     zeige_werte();
   }

 AusruestungBaum &B=A.push_back(Ausruestung(name,bez,checkbutton_sichtbar->get_active()));
 B.setParent(&A);
*/


void table_ausruestung::zeige_werte()
{
  label_golda->set_text(itos(hauptfenster->getWerte().Gold()));
  label_silbera->set_text(itos(hauptfenster->getWerte().Silber()));
  label_kupfera->set_text(itos(hauptfenster->getWerte().Kupfer()));
}

/*
AusruestungBaum &table_ausruestung::setStandardAusruestung(AusruestungBaum &besitz)
{
  AusruestungBaum *Koerper = &besitz.push_back(Ausruestung("K�rper"));
  Koerper->setParent(&besitz);
  AusruestungBaum *Hose=&Koerper->push_back(Ausruestung("Hose"));
  Hose->setParent(Koerper);
  AusruestungBaum *Hemd=&Koerper->push_back(Ausruestung("Hemd"));
  Hemd->setParent(Koerper);
  AusruestungBaum *Guertel=&Koerper->push_back(Ausruestung("G�rtel"));
  Guertel->setParent(Koerper);
  AusruestungBaum *Schuhe=&Koerper->push_back(Ausruestung("Schuhe"));
  Schuhe->setParent(Koerper);
  AusruestungBaum *Rucksack=&Koerper->push_back(Ausruestung("Rucksack","Leder",true));
  Rucksack->setParent(Koerper);
  AusruestungBaum *Decke=&Rucksack->push_back(Ausruestung("Decke","warm",false));
  Decke->setParent(Rucksack);
  AusruestungBaum *Lederbeutel=&Rucksack->push_back(Ausruestung("Lederbeutel"));
  Lederbeutel->setParent(Guertel);
  AusruestungBaum *Geld=&Rucksack->push_back(Ausruestung("Geld","",false));
  Geld->setParent(Lederbeutel);

  return *Rucksack;
//  setFertigkeitenAusruestung(Rucksack);
}

*/
////////////////////////////////////////////////////////////////////////
//Neueingeben
//von hier 
void table_ausruestung::on_togglebutton_artikel_neu_toggled()
{
 if(togglebutton_artikel_neu->get_active())
  {
    table_artikel->show();
    entry_name->grab_focus();
  }
 else 
    table_artikel->hide();
}
void table_ausruestung::on_togglebutton_gruppe_neu_toggled()
{
 if(togglebutton_gruppe_neu->get_active())
  table_gruppe->show();
 else 
  table_gruppe->hide();
}
void table_ausruestung::on_entry_art_activate()
{
  entry_typ->grab_focus();
}
void table_ausruestung::on_entry_typ_activate()
{
  entry_eigenschaft->grab_focus();
}
void table_ausruestung::on_entry_eigenschaft_activate()
{
 std::string art = entry_art->get_text();
 std::string typ = entry_typ->get_text();
 std::string eigenschaft = entry_eigenschaft->get_text();
 table_gruppe->hide();
}
// bis hier ist es nicht implementiert


//Neueingeben eines Artikels:
void table_ausruestung::on_entry_artikel_art_activate()
{
 entry_artikel_art2->grab_focus();
}
void table_ausruestung::on_entry_artikel_art2_activate()
{
 entry_name->grab_focus();
}
void table_ausruestung::on_entry_name_activate()
{
 spinbutton_preis->grab_focus();
}
void table_ausruestung::on_spinbutton_preis_activate()
{
 optionmenu_einheit->grab_focus();
}
void table_ausruestung::on_optionmenu_einheit_deactivate()
{
 spinbutton_gewicht->grab_focus();
}
void table_ausruestung::on_spinbutton_gewicht_activate()
{
 std::string art = entry_artikel_art->get_text();
 std::string art2 = entry_artikel_art2->get_text();
 std::string name = entry_name->get_text();
 std::string einheit;
 int ieinheit = int(optionmenu_einheit->get_menu()->get_active()->get_user_data()); 
 if(ieinheit==optionmenu_einheit::GS) einheit="GS";
 if(ieinheit==optionmenu_einheit::SS) einheit="SS";
 if(ieinheit==optionmenu_einheit::KS) einheit="KS";
 double preis = atof( spinbutton_preis->get_text().c_str());
 double gewicht = atof( spinbutton_gewicht->get_text().c_str());

  Preise::saveArtikel(art,art2,name,preis,einheit,gewicht);
  hauptfenster->getDatabase().preise.push_back(cH_Preise(name));
  ausruestung_laden();
// table_artikel->hide();
}

gint table_ausruestung::on_button_ausruestung_druck_release_event(GdkEventButton *event)
{
  if (event->button==1) hauptfenster->on_auch_unsichtbares_drucken();
  if (event->button==3) hauptfenster->on_nur_sichtbares_drucken();
  return false;
}
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
