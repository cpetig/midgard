// generated 2002/5/16 18:55:17 CEST by thoma@Tiger.(none)
// using glademm V0.6.4b_cvs
//
// newer (non customized) versions of this file go to table_lernschema.cc_new

// This file is for your program, I won't touch it again!

#include "config.h"
#include "table_lernschema.hh"
#include "midgard_CG.hh"
#include "class_SimpleTree.hh"
#include "Fertigkeiten.hh"
#include <Aux/itos.h>
#include "WaffeGrund.hh"
#include "Window_Geld_eingeben.hh"
#include "Window_ruestung.hh"
#include <SelectMatching.h>


void table_lernschema::init(midgard_CG *h)
{
  hauptfenster=h;
  maxkido=0;
  show_gelerntes();
  zeige_werte();
  
  vbox_berufsname->hide();
  button_kido_auswahl->set_sensitive(false);
  button_angeborene_fert->set_sensitive(false);
}


void table_lernschema::on_button_waffe_trans_clicked()
{  
 if(lernpunkte.Waffen()>0)
   {
     lernpunkte.addWaffen(-1);
     lernpunkte.addUnge(+1);  
   }
 zeige_lernpunkte();
}

void table_lernschema::on_button_fach_trans_clicked()
{  
   if(lernpunkte.Fach()>0)
   {
     lernpunkte.addFach(-1);
     lernpunkte.addUnge(+1);
   }
 zeige_lernpunkte();
}

gint table_lernschema::on_spinbutton_fach_focus_out_event(GdkEventFocus *ev)
{  set_lernpunkte(); return 0;}
gint table_lernschema::on_spinbutton_allgemein_focus_out_event(GdkEventFocus *ev)
{  set_lernpunkte(); return 0;}
gint table_lernschema::on_spinbutton_waffen_focus_out_event(GdkEventFocus *ev)
{  set_lernpunkte(); return 0;}
gint table_lernschema::on_spinbutton_zaubern_focus_out_event(GdkEventFocus *ev)
{  set_lernpunkte(); return 0; }
gint table_lernschema::on_spinbutton_unge_focus_out_event(GdkEventFocus *ev)
{  set_lernpunkte(); return 0; }

gint table_lernschema::on_spinbutton_fach_focus_in_event(GdkEventFocus *ev)
{ spinbutton_fach->select_region(0,-1);   return false;}
gint table_lernschema::on_spinbutton_allgemein_focus_in_event(GdkEventFocus *ev)
{ spinbutton_allgemein->select_region(0,-1);   return false;}
gint table_lernschema::on_spinbutton_unge_focus_in_event(GdkEventFocus *ev)
{ spinbutton_unge->select_region(0,-1);   return false;}
gint table_lernschema::on_spinbutton_waffen_focus_in_event(GdkEventFocus *ev)
{ spinbutton_waffen->select_region(0,-1);   return false;}
gint table_lernschema::on_spinbutton_zaubern_focus_in_event(GdkEventFocus *ev)
{ spinbutton_zauber->select_region(0,-1);   return false;}

void table_lernschema::on_spinbutton_fach_activate()
{ set_lernpunkte(); spinbutton_allgemein->grab_focus();}
void table_lernschema::on_spinbutton_allgemein_activate()
{ set_lernpunkte(); spinbutton_unge->grab_focus();}
void table_lernschema::on_spinbutton_unge_activate()
{ set_lernpunkte(); spinbutton_waffen->grab_focus();}
void table_lernschema::on_spinbutton_waffen_activate()
{ set_lernpunkte(); spinbutton_zauber->grab_focus();}
void table_lernschema::on_spinbutton_zaubern_activate()
{ set_lernpunkte(); togglebutton_lernpunkte_edit->set_active(false);}

void table_lernschema::set_lernpunkte()
{
  gtk_spin_button_update(spinbutton_unge->gtkobj());
  lernpunkte.setUnge(spinbutton_unge->get_value_as_int());
  gtk_spin_button_update(spinbutton_fach->gtkobj());
  lernpunkte.setFach(spinbutton_fach->get_value_as_int());
  gtk_spin_button_update(spinbutton_allgemein->gtkobj());
  lernpunkte.setAllgemein(spinbutton_allgemein->get_value_as_int());
  gtk_spin_button_update(spinbutton_waffen->gtkobj());   
  lernpunkte.setWaffen(spinbutton_waffen->get_value_as_int());
  gtk_spin_button_update(spinbutton_zauber->gtkobj());
  lernpunkte.setZauber(spinbutton_zauber->get_value_as_int());
  on_lernliste_wahl_toggled();
  zeige_werte();
}



void table_lernschema::on_lernliste_wahl_toggled()
{  
   if(button_zauber->get_active())
   {
     if (hauptfenster->getCWerte().Spezialgebiet()->Spezial2()=="" && 
         hauptfenster->getCChar().CTyp1()->Short()=="eBe")
      {
         hauptfenster->set_status("Erst Prim�r- und Sekund�relement w�hlen");
         return;
      }
   }
 show_lernschema();
}



void table_lernschema::on_button_waffen_clicked()
{  
  if(hauptfenster->getCChar().CTyp1()->Kultwaffe() &&hauptfenster->getCChar().CList_Waffen().empty())
   {
     hauptfenster->set_status(hauptfenster->getCChar().CTyp1()->Name(hauptfenster->getCWerte().Geschlecht())+" m�ssen als erstes ihre Kultwaffe w�hlen; fehlende Lernpunkte werden geschenkt.",false);
     togglebutton_teure_anzeigen->set_active(true);
   }
  button_lernschema_waffen->set_sensitive(true);
}



void table_lernschema::on_tree_gelerntes_leaf_selected(cH_RowDataBase d)
{  
  const Data_SimpleTree *dt=dynamic_cast<const Data_SimpleTree*>(&*d);
  cH_MidgardBasicElement MBE = dt->getMBE();
  if(togglebutton_spezialwaffe->get_active() && MBE->What()!= MidgardBasicElement::WAFFE)
      {
        hauptfenster->set_status(MBE->What_str()+" kann nicht als Spezialwaffe verwendet werden.");
        return;         
      }
  switch(MBE->What()) {
     case MidgardBasicElement::WAFFE :
         { 
           if(togglebutton_spezialwaffe->get_active() )
            { 
              if(cH_Waffe(MBE)->Verteidigung())
               hauptfenster->set_status("Eine Verteidingungswaffe kann keine Spezialwaffe werden.");
             else
              {  
               hauptfenster->getWerte().setSpezialisierung(MBE->Name());
               Waffe::setSpezialWaffe(hauptfenster->getCWerte().Spezialisierung(),hauptfenster->getCChar().CList_Waffen());
               togglebutton_spezialwaffe->set_active(false);
               if(hauptfenster->wizard) hauptfenster->wizard->next_step(Wizard::SPEZIALWAFFE);
              }
            }  
           else
            {  
             hauptfenster->getChar().List_Waffen().remove(MBE);
              lernpunkte.addWaffen(MBE->Lernpunkte());
            }
           break;
         }
     case MidgardBasicElement::WAFFEBESITZ :
         {hauptfenster->getChar().List_Waffen_besitz().remove(MBE);  
           std::string art=cH_WaffeBesitz(MBE)->Waffe()->Art2();
           if(art=="E" || art=="W" || art=="V") waffebesitzlernen.add_EWaffe(1);
           else waffebesitzlernen.add_AWaffe(1);
           break;
         }
     case MidgardBasicElement::ZAUBER :
         {hauptfenster->getChar().List_Zauber().remove(MBE);
           lernpunkte.addZauber(MBE->Lernpunkte());
           break;
         }
     case MidgardBasicElement::KIDO :
         {hauptfenster->getChar().List_Kido().remove(MBE);
           ++maxkido;
           fill_kido_lernschema();
           break;
         }
     case MidgardBasicElement::FERTIGKEIT_ANG :
         {hauptfenster->getChar().List_Fertigkeit_ang().remove(MBE);
           break;
         }
     case MidgardBasicElement::FERTIGKEIT :
         {hauptfenster->getChar().List_Fertigkeit().remove(MBE);
           list_FertigkeitZusaetze.remove(MBE->Name());
           if(cH_Fertigkeit(MBE)->LernArt()=="Fach")      lernpunkte.addFach( MBE->Lernpunkte());
           else if(cH_Fertigkeit(MBE)->LernArt()=="Allg") lernpunkte.addAllgemein( MBE->Lernpunkte());
           else if(cH_Fertigkeit(MBE)->LernArt()=="Unge") lernpunkte.addUnge( MBE->Lernpunkte());
           else hauptfenster->set_info("Fehler beim Lernpunkte zur�ckstellen");
           std::string::size_type st = MBE->Name().find("KiDo-Technik");
           if(st!=std::string::npos)  --maxkido;
           break;
         }
     case MidgardBasicElement::SPRACHE :
          hauptfenster->getChar().List_Sprache().remove(MBE);
           // KEIN break 
     case MidgardBasicElement::SCHRIFT :
          hauptfenster->getChar().List_Schrift().remove(MBE);

           if(button_fachkenntnisse->get_active())
                lernpunkte.addFach(MBE->Lernpunkte());
           else if(button_allgemeinwissen->get_active())
                lernpunkte.addAllgemein(MBE->Lernpunkte());
           else if(button_untyp_fertigkeiten->get_active())
                lernpunkte.addUnge(MBE->Lernpunkte());
           else hauptfenster->set_info("Da kein Fertigkeiten-Auswahl-Knopf gew�hlt wurde konnten die Lernpunkte ("
                  +itos(MBE->Lernpunkte())+") f�r das Verlernen dieser Sprache nicht gut geschrieben werden.");
           break;

     default : break;
   }
  if(MBE->What()==MidgardBasicElement::WAFFEBESITZ)
    show_WaffenBesitz_lernschema();
  else 
     show_lernschema();
  show_gelerntes();
  if(MBE->What()==MidgardBasicElement::WAFFE && togglebutton_spezialwaffe->get_active())
     hauptfenster->undosave("Spezialwaffe "+MBE->Name()+" gew�hlt");
  else
     hauptfenster->undosave(MBE->Name()+" verlernt");
}
 
void table_lernschema::on_tree_lernschema_leaf_selected(cH_RowDataBase d)
{
  const Data_SimpleTree *dt=dynamic_cast<const Data_SimpleTree*>(&*d);
  cH_MidgardBasicElement MBE = dt->getMBE();
  if(MBE->Gelernt()) 
   { 
     hauptfenster->set_status("Diese Fertigkeit ist schon gelernt");
     tree_lernschema->unselect_all();
     return;
   }
  switch(MBE->What()) {
    case MidgardBasicElement::WAFFE:
      { 
        int lp=MBE->Lernpunkte();
        if(hauptfenster->getCChar().CTyp1()->Kultwaffe() &&hauptfenster->getCChar().CList_Waffen().empty())
          {
            // F�r eine Kultwaffe werden fehlende Lernpunkte geschenkt
            if( lp>lernpunkte.Waffen() ) lp=lernpunkte.Waffen();
            hauptfenster->set_status(MBE->Name()+" als Kultwaffe gew�hlt");
          }
        else if(MBE->Lernpunkte()>lernpunkte.Waffen())
          { hauptfenster->set_status("Nicht genug Lernpunkte");
            tree_lernschema->unselect_all();
            return;
          }
       hauptfenster->getChar().List_Waffen().push_back(MBE);
       hauptfenster->getChar().List_WaffenGrund().push_back(&*cH_WaffeGrund(cH_Waffe(MBE)->Grundkenntnis()));
       hauptfenster->getChar().List_WaffenGrund().sort(cH_MidgardBasicElement::sort(cH_MidgardBasicElement::sort::NAME));
       hauptfenster->getChar().List_WaffenGrund().unique();
        lernpunkte.addWaffen(-lp);
        break; }
    case MidgardBasicElement::ZAUBER:
      { 
        if(MBE->Lernpunkte()>lernpunkte.Zauber())
          { hauptfenster->set_status("Nicht genug Lernpunkte");
            tree_lernschema->unselect_all();
            return;
          }
        if(!MBE->ZusatzEnum(hauptfenster->getCChar().getVTyp())) // Das macht 'lernen_zusatz' automatisch
           hauptfenster->getChar().List_Zauber().push_back(MBE); 
        else lernen_zusatz(MBE->ZusatzEnum(hauptfenster->getCChar().getVTyp()),MBE);
        lernpunkte.addZauber(- MBE->Lernpunkte());   
        break; }
    case MidgardBasicElement::FERTIGKEIT:
      { 
        if( (cH_Fertigkeit(MBE)->LernArt()=="Fach" &&
             MBE->Lernpunkte() > lernpunkte.Fach()) ||
             (cH_Fertigkeit(MBE)->LernArt()=="Allg" &&
             MBE->Lernpunkte() > lernpunkte.Allgemein()) ||
             (cH_Fertigkeit(MBE)->LernArt()=="Unge" && 
             MBE->Lernpunkte() > lernpunkte.Unge()) )  
          { hauptfenster->set_status("Nicht genug Lernpunkte");      
            tree_lernschema->unselect_all();
            return;
          }
        if(!SpracheSchrift(MBE))
          { 
            std::string::size_type st = MBE->Name().find("KiDo-Technik");
            if(st!=std::string::npos) 
               { ++maxkido; list_FertigkeitZusaetze.push_back(MBE->Name());}
            if(!MBE->ZusatzEnum(hauptfenster->getCChar().getVTyp()) && st==std::string::npos)// Das macht 'lernen_zusatz' automatisch
                 hauptfenster->getChar().List_Fertigkeit().push_back(MBE); 
            if(MBE->Name()=="KiDo" && hauptfenster->getCChar().CTyp1()->Short()=="Kd") maxkido+=2;
            if(maxkido>0 && cH_Fertigkeit("KiDo")->ist_gelernt(hauptfenster->getCChar().CList_Fertigkeit()))
               zeige_werte();
         }
        else
          { // Damit Sprachen und Schriften nicht doppelt angezeigt werden
            // sp�ter: nach einhelliger Meinung sollen sie das doch 
//            list_FertigkeitZusaetze.push_back(MBE->Name());
          }
        if(MBE->ZusatzEnum(hauptfenster->getCChar().getVTyp())) lernen_zusatz(MBE->ZusatzEnum(hauptfenster->getCChar().getVTyp()),MBE);

        if(cH_Fertigkeit(MBE)->LernArt()=="Fach")
           lernpunkte.addFach(-MBE->Lernpunkte());
        else if(cH_Fertigkeit(MBE)->LernArt()=="Allg")
           lernpunkte.addAllgemein(- MBE->Lernpunkte());
        else if(cH_Fertigkeit(MBE)->LernArt()=="Unge")  
           lernpunkte.addUnge(- MBE->Lernpunkte());     
        break; }
    default : break;
   }
  hauptfenster->undosave(MBE->Name()+" gelernt");
  show_lernschema();
  show_gelerntes(); 
  if(frame_lernschema_zusatz->is_visible()) scrolledwindow_lernen->set_sensitive(false);
//  if(MBE->ZusatzEnum(hauptfenster->getCChar().getVTyp())) scrolledwindow_lernen->set_sensitive(false);
}



void table_lernschema::on_herkunftsland_clicked()
{  
  cH_MidgardBasicElement Dummy=new Fertigkeit(*cH_Fertigkeit("",true));
  lernen_zusatz(MidgardBasicElement::ZHerkunft,Dummy);
}

void table_lernschema::on_lernpunkte_wuerfeln_clicked()
{  
  if(hauptfenster->wizard) hauptfenster->wizard->next_step(Wizard::LERNPUNKTE);
  //Speziesspezifische Fertigkeiten
  int lpspezies=0;
  hauptfenster->getChar().List_Fertigkeit()=hauptfenster->getCWerte().Spezies()->getFertigkeiten(lpspezies,hauptfenster->getCWerte());
  show_gelerntes();

  int fachlern=hauptfenster->random.integer(1,6)+hauptfenster->random.integer(1,6);
  if(!hauptfenster->getChar().List_Fertigkeit().empty())
    hauptfenster->set_status("Die Lernpunkte ("+itos(lpspezies)+") f�r die Pflichtfertigkeiten"
      " f�r die Spezies "+hauptfenster->getCWerte().Spezies()->Name()+" wurden von den erf�rfelten"
      " Lernpunkten ("+itos(fachlern)+") abgezogen.");
  lernpunkte.setFach(fachlern - lpspezies);
  lernpunkte.setAllgemein(hauptfenster->random.integer(1,6)+1);
  lernpunkte.setUnge(hauptfenster->random.integer(1,6));
  if (hauptfenster->getCChar().CTyp2()->Short()=="") lernpunkte.setWaffen(hauptfenster->random.integer(1,6)+hauptfenster->random.integer(1,6));
  else                     lernpunkte.setWaffen(hauptfenster->random.integer(1,6)+1); // Doppelcharakter
  if (hauptfenster->getCChar().CTyp1()->is_mage() && hauptfenster->getCChar().CTyp2()->Short()=="")
      lernpunkte.setZauber(hauptfenster->random.integer(1,6)+hauptfenster->random.integer(1,6));
  if (hauptfenster->getCChar().CTyp2()->is_mage() && hauptfenster->getCChar().CTyp2()->Short()!="")
      lernpunkte.setZauber(hauptfenster->random.integer(1,6)+1);

  int age = (lernpunkte.Allgemein() + lernpunkte.Unge()
             + lernpunkte.Fach()
             + lernpunkte.Waffen() + lernpunkte.Zauber())/4+16;

  hauptfenster->getWerte().setAlter( age * hauptfenster->getCWerte().Spezies()->AlterFaktor());
//  spinbutton_alter->set_value(hauptfenster->getCWerte().Alter());
  zeige_lernpunkte();

  if(!hauptfenster->getOptionen()->OptionenCheck(Midgard_Optionen::NSC_only).active)
     button_lernpunkte->set_sensitive(false);
  button_fachkenntnisse->set_sensitive(true);
  button_allgemeinwissen->set_sensitive(true);
  button_untyp_fertigkeiten->set_sensitive(true);
  button_waffen->set_sensitive(true);
  if(hauptfenster->getCChar().is_mage())
      button_zauber->set_sensitive(true);
  button_beruf->set_sensitive(true);
  button_lernschema_geld->set_sensitive(true);
  button_lernschema_waffen->set_sensitive(true);
  button_ruestung->set_sensitive(true);

  on_lernliste_wahl_toggled();

}

void table_lernschema::on_togglebutton_lernpunkte_edit_toggled()
{  
  edit_lernpunkte(togglebutton_lernpunkte_edit->get_active());
}

void table_lernschema::edit_lernpunkte(bool b)
{
 spinbutton_fach->set_sensitive(b);
 spinbutton_allgemein->set_sensitive(b);
 spinbutton_unge->set_sensitive(b);
 spinbutton_waffen->set_sensitive(b);
 spinbutton_zauber->set_sensitive(b);
// spinbutton_beruf->set_sensitive(b);
 if(b) 
    table_berufsprozent->show();
 else 
    table_berufsprozent->hide();
// frame_berufswahl->set_sensitive(true); 
}


gint table_lernschema::on_button_lernschema_geld_button_release_event(GdkEventButton *ev)
{  
  if(hauptfenster->wizard) hauptfenster->wizard->next_step(Wizard::GELD);
  if(!hauptfenster->getOptionen()->OptionenCheck(Midgard_Optionen::NSC_only).active)
     button_lernschema_geld->set_sensitive(false);
  hauptfenster->getWerte().setGeld(0,0,0);
  if      (ev->button==1)  lernschema_geld_wuerfeln();
  else if (ev->button==3)  manage (new Window_Geld_eingeben(hauptfenster,hauptfenster->getWerte()));;
  return 0;
}

void table_lernschema::lernschema_geld_wuerfeln()
{
 int igold=0;  
 vector<int> V;
 for(int i=0;i<3;++i) V.push_back(hauptfenster->random.integer(1,6));
 igold=V[0]+V[1]+V[2];
 if      (hauptfenster->getCChar().CTyp1()->Geld() == 1) igold-=3;
 else if (hauptfenster->getCChar().CTyp1()->Geld() == 2) igold+=0;
 else if (hauptfenster->getCChar().CTyp1()->Geld() == 3) igold+=6;
 else if (hauptfenster->getCChar().CTyp1()->Geld() == 4) igold+=3;

 if(hauptfenster->getCWerte().Stand()=="Adel" ) igold*=2;  
 if(hauptfenster->getCWerte().Stand()=="Unfrei" ) igold/=2;
 if(V[0]==V[1] && V[1]==V[2]) igold += 100;

 std::string strinfo ="Beim Ausw�rfeln von Geld wurden "
   +itos(V[0])+"  "+itos(V[1])+"  "+itos(V[2])+" gew�rfelt ==> "
   +itos(igold)+" Gold";
 hauptfenster->set_status(strinfo);   
 hauptfenster->getWerte().addGold(igold);  
 zeige_werte();
// Geld_uebernehmen();
}


gint table_lernschema::on_button_ruestung_button_release_event(GdkEventButton *ev)
{  
  if(hauptfenster->wizard) hauptfenster->wizard->next_step(Wizard::RUESTUNG);
  if(!hauptfenster->getOptionen()->OptionenCheck(Midgard_Optionen::NSC_only).active)
     button_ruestung->set_sensitive(false);
  if      (ev->button==1)  on_button_ruestung_clicked();
  else if (ev->button==3)  manage (new Window_ruestung(hauptfenster->getWerte(),hauptfenster,hauptfenster->getDatabase()));
  return 0;
}

void table_lernschema::on_button_ruestung_clicked()
{
  std::string rue;
  int wurf = hauptfenster->random.integer(1,100);
  if (hauptfenster->getCChar().CTyp1()->Ruestung() == 1)
   {
      if ( 1 <= wurf && wurf  <= 10 ) rue = "OR" ;
      if (11 <= wurf && wurf  <= 20 ) rue = "TR" ;
      if (21 <= wurf && wurf  <= 30 ) rue = "TR" ;
      if (31 <= wurf && wurf  <= 60 ) rue = "LR" ;
      if (61 <= wurf && wurf  <= 80 ) rue = "LR" ;
      if (81 <= wurf && wurf  <= 95 ) rue = "LR" ;
      if (96 <= wurf && wurf  <= 100) rue = "LR" ;
   }
  if (hauptfenster->getCChar().CTyp1()->Ruestung()== 2)
   {
      if ( 1 <= wurf && wurf  <= 10 ) rue = "OR" ;
      if (11 <= wurf && wurf  <= 20 ) rue = "TR" ;
      if (21 <= wurf && wurf  <= 30 ) rue = "LR" ;
      if (31 <= wurf && wurf  <= 60 ) rue = "LR" ;
      if (61 <= wurf && wurf  <= 80 ) rue = "KR" ;
      if (81 <= wurf && wurf  <= 95 ) rue = "KR" ;
      if (96 <= wurf && wurf  <= 100) rue = "KR" ;
   }
  if (hauptfenster->getCChar().CTyp1()->Ruestung()== 3)
   {
      if ( 1 <= wurf && wurf  <= 10 ) rue = "OR" ;
      if (11 <= wurf && wurf  <= 20 ) rue = "TR" ;
      if (21 <= wurf && wurf  <= 30 ) rue = "LR" ;
      if (31 <= wurf && wurf  <= 60 ) rue = "KR" ;
      if (61 <= wurf && wurf  <= 80 ) rue = "KR" ;
      if (81 <= wurf && wurf  <= 95 ) rue = "KR" ;
      if (96 <= wurf && wurf  <= 100) rue = "PR" ;
   }
  if (hauptfenster->getCChar().CTyp1()->Ruestung()== 4)
   {
      if ( 1 <= wurf && wurf  <= 10 ) rue = "OR" ;
      if (11 <= wurf && wurf  <= 20 ) rue = "OR" ;
      if (21 <= wurf && wurf  <= 30 ) rue = "OR" ;
      if (31 <= wurf && wurf  <= 60 ) rue = "TR" ;
      if (61 <= wurf && wurf  <= 80 ) rue = "TR" ;
      if (81 <= wurf && wurf  <= 95 ) rue = "LR" ;
      if (96 <= wurf && wurf  <= 100) rue = "LR" ;
   }
//  hauptfenster->getWerte().clearRuestung();
  hauptfenster->getWerte().setRuestung1(cH_Ruestung(rue));
  hauptfenster->set_status("Beim Ausw�rfeln der R�stung wurde eine "+itos(wurf)+" gew�rfelt "
             "==> " + hauptfenster->getCWerte().Ruestung()->Long());
  zeige_werte();
}



void table_lernschema::on_togglebutton_teure_anzeigen_toggled()
{  
 on_lernliste_wahl_toggled();
}

void table_lernschema::on_togglebutton_gelernte_anzeigen_toggled()
{  
 on_lernliste_wahl_toggled();
}

void table_lernschema::zeige_werte()
{
  zeige_lernpunkte();
  label_ruestung_lernschema->set_text(hauptfenster->getCWerte().Ruestung()->Long()); 
  label_herkunft_lernschema->set_text(hauptfenster->getCWerte().Herkunft()->Name());
  fertig_typ->set_text(hauptfenster->getCChar().CTyp1()->Name(hauptfenster->getCWerte().Geschlecht()));
  if (hauptfenster->getCChar().CTyp2()->Name(hauptfenster->getCWerte().Geschlecht())!="")
   fertig_typ->set_text(hauptfenster->getCChar().CTyp1()->Name(hauptfenster->getCWerte().Geschlecht())+"/"+hauptfenster->getCChar().CTyp2()->Name(hauptfenster->getCWerte().Geschlecht()));

  // Spezialwaffe anzeigen?
 if (hauptfenster->getCChar().CTyp1()->Spezialwaffe() || hauptfenster->getCChar().CTyp2()->Spezialwaffe())
    togglebutton_spezialwaffe->show(); 
 else 
   { togglebutton_spezialwaffe->set_active(false);
     togglebutton_spezialwaffe->hide(); }


 // Magie anzeigen?
 if (hauptfenster->getCChar().is_mage())
   { if ( hauptfenster->getCChar().CTyp1()->Spezialgebiet() || 
          hauptfenster->getCChar().CTyp2()->Spezialgebiet() ) 
     show_magier_spezialgebiet(true);
     else show_magier_spezialgebiet(false);
     if(hauptfenster->getCWerte().Spezialgebiet()->Name()!="")
        Gtk::Menu_Helpers::SelectMatching(*option_magier_spezialgebiet,hauptfenster->getCWerte().Spezialgebiet());
     button_zauber->set_sensitive(true);   
   }
 else
   { 
     show_magier_spezialgebiet(false);   
     button_zauber->set_sensitive(false);
   }
 // KiDo anzeigen?
 if(cH_Fertigkeit("KiDo")->ist_gelernt(hauptfenster->getCChar().CList_Fertigkeit()))
   { 
     optionmenu_KiDo_Stile->show();
     frame_KiDo_lernschema->show();
   }  
 else 
   { 
     optionmenu_KiDo_Stile->hide();
     frame_KiDo_lernschema->hide();
//     table_kido_steigern->hide();
   }
 // KiDo Stil setzen
#warning TODO
// Gtk::Menu_Helpers::SelectMatching(*optionmenu_KiDo_Stile,hauptfenster->getCWerte().Spezialisierung());
 
/*
 int kido_stil_nr=0;
 if (hauptfenster->getCWerte().Spezialisierung()==Vkido[2]) kido_stil_nr = 1;
 if (hauptfenster->getCWerte().Spezialisierung()==Vkido[1]) kido_stil_nr = 2;
 if (hauptfenster->getCWerte().Spezialisierung()==Vkido[3]) kido_stil_nr = 3;
 if (kido_stil_nr!=0)
  {   
    optionmenu_KiDo_Stile->set_history(kido_stil_nr);
  }
*/
}

void table_lernschema::zeige_lernpunkte()
{
 spinbutton_fach->set_value(lernpunkte.Fach());
 spinbutton_allgemein->set_value(lernpunkte.Allgemein());
 spinbutton_unge->set_value(lernpunkte.Unge());
 spinbutton_waffen->set_value(lernpunkte.Waffen());
 spinbutton_zauber->set_value(lernpunkte.Zauber());
}

void table_lernschema::show_gelerntes()
{
  zeige_lernpunkte();
  
  std::list<cH_MidgardBasicElement> FL;
  std::list<std::list<cH_MidgardBasicElement> > LL;
  LL.push_back(hauptfenster->getCChar().CList_Fertigkeit_ang());
  LL.push_back(hauptfenster->getCChar().CList_Fertigkeit());
  LL.push_back(hauptfenster->getCChar().CList_Waffen());
  LL.push_back(hauptfenster->getCChar().CList_Zauber());
  LL.push_back(hauptfenster->getCChar().CList_Zauberwerk());
  LL.push_back(hauptfenster->getCChar().CList_Kido());
  LL.push_back(hauptfenster->getCChar().CList_WaffenGrund());
  LL.push_back(hauptfenster->getCChar().CList_Waffen_besitz());
  LL.push_back(hauptfenster->getCChar().CList_Sprache());
  LL.push_back(hauptfenster->getCChar().CList_Schrift());
  LL.push_back(hauptfenster->getCChar().CList_Beruf());  
  LL.push_back(hauptfenster->getCWerte().Sinne());

  for(std::list<std::list<cH_MidgardBasicElement> >::const_iterator i=LL.begin();i!=LL.end();++i)
    for (std::list<cH_MidgardBasicElement>::const_iterator j=i->begin();j!=i->end();++j)
      FL.push_back(*j);
  MidgardBasicElement::show_list_in_tree(FL,tree_gelerntes,hauptfenster);
  tree_gelerntes->Expand_recursively();
  scrolledwindow_lernen->set_sensitive(true);
}
 

void table_lernschema::show_lernschema()
{
  if(button_kido_auswahl->get_active()) return;
  clean_lernschema_trees();
  tree_lernschema = manage(new MidgardBasicTree(MidgardBasicTree::LERNSCHEMA));
  tree_lernschema->leaf_selected.connect(SigC::slot(static_cast<class table_lernschema*>(this), &table_lernschema::on_tree_lernschema_leaf_selected));
  
  MidgardBasicElement::MBEE what;
  std::string fert;
  if(button_waffen->get_active())
    {  what=MidgardBasicElement::WAFFE;
       label_lernschma_titel->set_text("Waffen");
    }
  else if(button_zauber->get_active())
    {  what=MidgardBasicElement::ZAUBER;
       label_lernschma_titel->set_text("Zauber");
    }
  else
    {  what=MidgardBasicElement::FERTIGKEIT;
       if(button_fachkenntnisse->get_active())
         {  fert="Fach";
            label_lernschma_titel->set_text("Fachkenntnisse");
         }
        else if(button_untyp_fertigkeiten->get_active())
         {  fert="Unge";
            label_lernschma_titel->set_text("Ungew�hnliche Fertigkeiten");
         }
        else
         {  fert="Allg";
            label_lernschma_titel->set_text("Allgemeinwissen");
         }
   }

  std::list<cH_MidgardBasicElement> newlist;
  std::list<cH_MidgardBasicElement> LW;
  if(fert=="Unge" || fert=="Allg") 
   {
    for(std::list<cH_MidgardBasicElement>::const_iterator i=hauptfenster->getDatabase().Fertigkeit.begin();i!=hauptfenster->getDatabase().Fertigkeit.end();++i)
     {
      cH_Fertigkeit f(*i);
      int lp=0;
      f->setLernArt(fert);
      if(fert=="Allg")
       {
         if     (hauptfenster->getCWerte().Stadt_Land()=="Land"  ) lp=f->LernLand();
         else if(hauptfenster->getCWerte().Stadt_Land()=="Stadt" ) lp=f->LernStadt();
         else {hauptfenster->set_status("Stadt oder Land w�hlen"); return;}
         if(!togglebutton_teure_anzeigen->get_active() && lp>lernpunkte.Allgemein())
            continue;
       }
      else if(fert=="Unge")
        {
          lp = f->LernUnge();
          if(!togglebutton_teure_anzeigen->get_active() && lp>lernpunkte.Unge())
            continue;
        }
      if(lp == 99  ) continue;


      if(!(*i)->ist_gelernt(hauptfenster->getCChar().CList_Fertigkeit()))
        {
         if     (f->Name()=="Muttersprache"   && 30<hauptfenster->getCWerte().In()&&hauptfenster->getCWerte().In()<=60) f->setErfolgswert(14);
         else if(f->Name()=="Muttersprache"   && hauptfenster->getCWerte().In()>60) f->setErfolgswert(18+f->AttributBonus(hauptfenster->getCWerte()));
         else if(f->Name()=="Gastlandsprache" && hauptfenster->getCWerte().In()>30) f->setErfolgswert(12);
         else f->setErfolgswert(f->Anfangswert()+f->AttributBonus(hauptfenster->getCWerte()));
         f->setLernpunkte(lp);
        }
      if(!hauptfenster->region_check((*i)->Region())) continue;
      if(!f->Voraussetzungen(hauptfenster->getCWerte(),hauptfenster->getCChar().CList_Fertigkeit())) continue;
      if ((*i)->ist_gelernt(list_FertigkeitZusaetze)) (*i)->setGelernt(true);
      else {(*i)->setGelernt(false);(*i)->setZusatz("");}
      if((*i)->Name()=="Landeskunde (Heimat)" && (*i)->ist_gelernt(list_FertigkeitZusaetze)) (*i)->setGelernt(true);
      if ((*i)->ist_gelernt(hauptfenster->getCChar().CList_Fertigkeit())) (*i)->setGelernt(true); 
      if((*i)->Gelernt()&&!togglebutton_gelernte_anzeigen->get_active()) continue;
      if(hauptfenster->getCWerte().Spezies()->istVerbotenSpielbegin(*i)) continue;
//if((*i)->Gelernt())
//cout << "Was ist gelernt? "<<(*i)->Name()<<' '   
//<<(*i)->ist_gelernt(list_FertigkeitZusaetze)<<' '
//<<(*i)->ist_gelernt(hauptfenster->getCChar().List_Fertigkeit)<<'\n';
      newlist.push_back(*i);
     }
   }
  if(fert=="Fach") // Freiwillige Speziesfertigkeiten
   {
     std::list<cH_MidgardBasicElement> LW=hauptfenster->getCWerte().Spezies()->getFreiwilligeFertigkeiten(hauptfenster->getCWerte());
     for(std::list<cH_MidgardBasicElement>::const_iterator i=LW.begin();i!=LW.end();++i)
      {
       cH_Fertigkeit(*i)->setLernArt("Fach");
       bool gelernt=false;
       bool zuteuer=false;
       if ((*i)->ist_gelernt(hauptfenster->getCChar().CList_Fertigkeit())) gelernt=true;
       if ((*i)->ist_gelernt(list_FertigkeitZusaetze)) gelernt=true;
       if((*i)->Lernpunkte() > lernpunkte.Fach() ) zuteuer=true;
       if(zuteuer && !togglebutton_teure_anzeigen->get_active()) continue;
       if(gelernt && !togglebutton_gelernte_anzeigen->get_active()) continue;
       if(gelernt) (*i)->setGelernt(true); 
       newlist.push_back(*i);
     }
   }
  if(fert!="Unge" && fert!="Allg" )
    {
      if(what==MidgardBasicElement::WAFFE)
         LW=hauptfenster->getDatabase().lernschema.get_List("Waffenfertigkeiten",hauptfenster->getCChar().getVTyp(),hauptfenster->getCChar().CList_Waffen());
      if(what==MidgardBasicElement::ZAUBER)
         LW=hauptfenster->getDatabase().lernschema.get_List("Zauberk�nste",hauptfenster->getCChar().getVTyp(),hauptfenster->getCChar().CList_Zauber());
      if(what==MidgardBasicElement::FERTIGKEIT)
         LW=hauptfenster->getDatabase().lernschema.get_List("Fachkenntnisse",hauptfenster->getCChar().getVTyp(),hauptfenster->getCChar().CList_Fertigkeit());
      for(std::list<cH_MidgardBasicElement>::const_iterator i=LW.begin();i!=LW.end();++i)
        {
          bool gelernt=false;
          if((*i)->What()==MidgardBasicElement::FERTIGKEIT)
               cH_Fertigkeit(*i)->setLernArt("Fach");
          if(hauptfenster->getCWerte().Spezies()->istVerbotenSpielbegin(*i)) continue;
          if(what==MidgardBasicElement::WAFFE)  
               if (!hauptfenster->region_check(cH_Waffe(*i)->Region((*i)->Name()))) continue;
          else if (!hauptfenster->region_check((*i)->Region())) continue;

          if((*i)->Lernpunkte() == 99  ) continue;

          std::vector<Lernschema::st_index> VI;
          if(what==MidgardBasicElement::WAFFE) 
           {
             if ((*i)->ist_gelernt(hauptfenster->getCChar().CList_Waffen())) gelernt=true;
             if (!cH_Waffe(*i)->SG_Voraussetzung(hauptfenster->getCWerte(),hauptfenster->getCChar().CList_Fertigkeit(),hauptfenster->getCChar().CList_Waffen())) continue ;
             if(hauptfenster->getCWerte().Spezies()->istVerbotenSpielbegin(*i)) continue;
             VI=Lernschema::getIndex(hauptfenster->getCChar().getVTyp(),"Waffenfertigkeiten",(*i)->Name());
             if(hauptfenster->getCChar().CTyp1()->Kultwaffe() &&hauptfenster->getCChar().CList_Waffen().empty())
               hauptfenster->set_status(hauptfenster->getCChar().CTyp1()->Name(hauptfenster->getCWerte().Geschlecht())+" m�ssen als erstes ihre Kultwaffe w�hlen; fehlende Lernpunkte werden geschenkt.");
            }
           else if(what==MidgardBasicElement::ZAUBER)
            {
             if(hauptfenster->getCWerte().Spezies()->istVerbotenSpielbegin(*i)) continue;
             if ((*i)->ist_gelernt(hauptfenster->getCChar().CList_Zauber()) )  gelernt=true;
//             if ((*i)->ist_gelernt(list_FertigkeitZusaetze)) gelernt=true;
             VI=Lernschema::getIndex(hauptfenster->getCChar().getVTyp(),"Zauberk�nste",(*i)->Name());
            }
           else if(what==MidgardBasicElement::FERTIGKEIT)
            {
             if ((*i)->ist_gelernt(newlist)) continue ; // Speziesfertigkeiten
             if (!cH_Fertigkeit(*i)->Voraussetzungen(hauptfenster->getCWerte(),hauptfenster->getCChar().CList_Fertigkeit())) continue ;
             if(hauptfenster->getCWerte().Spezies()->istVerbotenSpielbegin(*i)) continue;
             if ((*i)->ist_gelernt(hauptfenster->getCChar().CList_Fertigkeit())) gelernt=true;   
             if ((*i)->ist_gelernt(list_FertigkeitZusaetze)) gelernt=true;
             VI=Lernschema::getIndex(hauptfenster->getCChar().getVTyp(),"Fachkenntnisse",(*i)->Name());  
             cH_Fertigkeit(*i)->setErfolgswert(cH_Fertigkeit(*i)->Anfangswert0()+cH_Fertigkeit(*i)->AttributBonus(hauptfenster->getCWerte()));
             cH_Fertigkeit(*i)->setPflicht(hauptfenster->getDatabase().lernschema.get_Pflicht(VI));
           }
        (*i)->setLernpunkte(hauptfenster->getDatabase().lernschema.get_Lernpunkte(VI));

        bool zuteuer=false;
         if(what==MidgardBasicElement::WAFFE)
          { if((*i)->Lernpunkte() > lernpunkte.Waffen() ) zuteuer=true;}
         else if(what==MidgardBasicElement::ZAUBER)
          { if((*i)->Lernpunkte() > lernpunkte.Zauber() ) zuteuer=true; }
         else if(what==MidgardBasicElement::FERTIGKEIT)
          { if((*i)->Lernpunkte() > lernpunkte.Fach() ) zuteuer=true; }

         if(zuteuer && !togglebutton_teure_anzeigen->get_active()) continue;
         if(gelernt && !togglebutton_gelernte_anzeigen->get_active()) continue;
         if(gelernt) (*i)->setGelernt(true); 

         newlist.push_back(*i);
        }
     }   
  MidgardBasicElement::show_list_in_tree(newlist,tree_lernschema,hauptfenster);
  tree_lernschema->show();
  viewport_lernen->add(*tree_lernschema);

  setTitels_for_Lernschema(what,fert);
  tree_lernschema->Expand_recursively();

  scrolledwindow_lernen->show();
}
 
void table_lernschema::setTitels_for_Lernschema(const MidgardBasicElement::MBEE& what,const std::string& fert)
{
 vector<std::string> vs;
 vs.push_back("LP");
 switch (what) {
   case MidgardBasicElement::WAFFE:
     {
       vs.push_back("Grundkenntnnis"); // PFLICHTg
       vs.push_back("Waffe");
       vs.push_back("Wert"); 
       vs.push_back(""); // EIGENSCHAFTg
       vs.push_back("Voraussetzung");   
       vs.push_back("Schwierigkeit");   
       break;
     }
   case MidgardBasicElement::FERTIGKEIT:
     {
       vs.push_back("Pflicht");
       vs.push_back("Fertigkeit");
       vs.push_back("Wert");  
       vs.push_back("L.E.");  
       vs.push_back("Voraussetzung");
       vs.push_back("Kosten");       
       break;
     }
   case MidgardBasicElement::ZAUBER:
     {
       vs.push_back("");
       vs.push_back("Zauber");
       vs.push_back("AP"); // WERTg
       vs.push_back("");
       vs.push_back("");
       vs.push_back("Kosten");
       break;
     }
   default: break;
   }
 vs.push_back("Art");
 vs.push_back("Gelernt");
 tree_lernschema->setTitles(vs);

 switch (what) {
   case MidgardBasicElement::WAFFE:
     {
       tree_lernschema->set_column_visibility(Data_SimpleTree::PFLICHTg,true);
       tree_lernschema->set_column_visibility(Data_SimpleTree::EIGENSCHAFTg,false);
       tree_lernschema->set_column_visibility(Data_SimpleTree::VORAUSSETZUNGg,true);
       tree_lernschema->set_column_visibility(Data_SimpleTree::KOSTENg,true);
       break;
     }
   case MidgardBasicElement::FERTIGKEIT:
     {
       if(fert=="Fach") tree_lernschema->set_column_visibility(Data_SimpleTree::PFLICHTg,true);
       else tree_lernschema->set_column_visibility(Data_SimpleTree::PFLICHTg,false);
       tree_lernschema->set_column_visibility(Data_SimpleTree::EIGENSCHAFTg,true);
       tree_lernschema->set_column_visibility(Data_SimpleTree::VORAUSSETZUNGg,true);
       tree_lernschema->set_column_visibility(Data_SimpleTree::KOSTENg,true);
       break;
     }
   case MidgardBasicElement::ZAUBER:
     {
       tree_lernschema->set_column_visibility(Data_SimpleTree::PFLICHTg,false);
       tree_lernschema->set_column_visibility(Data_SimpleTree::EIGENSCHAFTg,false);
       tree_lernschema->set_column_visibility(Data_SimpleTree::VORAUSSETZUNGg,false);
       tree_lernschema->set_column_visibility(Data_SimpleTree::KOSTENg,true);
       break;
     }
    default : break;
   }
}

void table_lernschema::clean_lernschema_trees()
{
  if(tree_lernschema) {tree_lernschema->destroy(); tree_lernschema=0;}
  if(Beruf_tree) {Beruf_tree->destroy(); Beruf_tree=0;}
  if(tree_angeb_fert) {tree_angeb_fert->destroy(); tree_angeb_fert=0;}
  if(tree_kido_lernschema) {tree_kido_lernschema->destroy(); tree_kido_lernschema=0;}
  if(tree_waffen_lernschema) {tree_waffen_lernschema->destroy(); tree_waffen_lernschema=0;}
  viewport_lernen->remove();
}

bool table_lernschema::SpracheSchrift(const cH_MidgardBasicElement& MBE)
{
 bool launch=false;
 std::string fert=MBE->Name();

 if(fert=="Schreiben: Muttersprache(+12)" ||
         fert=="Schreiben: Muttersprache(+9)" ||
         fert=="Schreiben: Muttersprache(+4)" ||
         fert=="Schreiben: Alte Sprache(+12)" ||
         fert=="Schreiben" )
    { launch=true;   }
 else if(fert=="Muttersprache")
    { launch=true; }
 else if(fert=="Gastlandsprache" ||
         fert=="Sprechen: Sprache(+4)" ||
         fert=="Sprechen: Sprache(+9)" ||
         fert=="Sprechen: Sprache(+12)") 
    { launch=true;  }
 else if(fert=="Sprechen: Alte Sprache")
    { launch=true; }
 return launch;
}