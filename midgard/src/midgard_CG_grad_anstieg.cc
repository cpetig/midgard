// $Id: midgard_CG_grad_anstieg.cc,v 1.33 2001/12/21 22:46:15 thoma Exp $
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
#include "WindowInfo.hh"

void midgard_CG::on_grad_anstieg_clicked()
{
 int old_grad=Werte.Grad();
 Werte.set_Grad(Database.GradAnstieg.get_Grad(Werte.GFP()));
 get_ausdauer(Werte.Grad());
 while(old_grad<=Werte.Grad())
  {
//cout << "F�r Grad "<<old_grad<<"\n";
    get_ab_re_za("Abwehr");
    get_ab_re_za("Resistenz");
    get_ab_re_za("Zaubern");
    get_grundwerte();
    ++old_grad;
  }
 zeige_werte(Werte);
}

void midgard_CG::on_button_grad_clicked()
{   
  Werte.set_Grad(Database.GradAnstieg.get_Grad(Werte.GFP()));
  zeige_werte(Werte);
}
void midgard_CG::on_button_grad_ausdauer_clicked()
{   
  get_ausdauer(Werte.Grad());
  zeige_werte(Werte);
}
void midgard_CG::on_button_grad_abwehr_clicked()
{   
 get_ab_re_za("Abwehr");
 zeige_werte(Werte);
}
void midgard_CG::on_button_grad_zaubern_clicked()
{   
 get_ab_re_za("Zaubern");
 zeige_werte(Werte);
}
void midgard_CG::on_button_grad_resistenz_clicked()
{   
 get_ab_re_za("Resistenz");
 zeige_werte(Werte);
}
void midgard_CG::on_button_grad_basiswerte_clicked()
{   
  get_grundwerte();
  zeige_werte(Werte);
}


void midgard_CG::get_grundwerte()
{
  if(Werte.Grad() <= Database.GradAnstieg.get_Grad_Basiswerte()) 
   {
      std::string strinfo = "F�r Grad "+itos(Database.GradAnstieg.get_Grad_Basiswerte())+" wurde schon gew�rfelt";
      manage(new WindowInfo(strinfo));
      return;
   }
  int z=random.integer(1,100);
  std::string stinfo="Beim W�rfeln zur Erh�hung einer Eigenschaft\nf�r Grad "
      + itos(Database.GradAnstieg.get_Grad_Basiswerte()+1) + " wurde eine ";
  stinfo += itos(z);
  stinfo +=" gew�rfelt --> ";
  std::string was = "keine Erh�hung";

  int erh = random.integer(1,6)+1;
  if( 81<=z && z>=83 ) { was="St�rke";           Werte.add_St(erh); }
  if( 84<=z && z>=86 ) { was="Geschicklichkeit"; Werte.add_Gw(erh); }
  if( 87<=z && z>=89 ) { was="Konstitution"; Werte.add_Ko(erh); }
  if( 90<=z && z>=92 ) { was="Intelligenz"; Werte.add_In(erh); }
  if( 93<=z && z>=95 ) { was="Zaubertalent"; Werte.add_Zt(erh); }
  if (z==96)   { was="Aussehn"; Werte.add_Au(erh); }
  if (z==97)   { was="pers�nliche Ausstrahlung"; Werte.add_pA(erh); }
  if (z==98)   { was="Selbstbeherrschung"; Werte.add_Sb(erh); }
//  if (z==99)   { was="Reaktionswert"; Werte.add_RW(erh); }
//  if (z==100)  { was="Handgemengewert"; Werte.add_HGW(erh); }

  stinfo += was;
  if (was != "keine Erh�hung" )
    {
       stinfo += " um "; stinfo += itos(erh); stinfo+=" erh�ht.\n";
       midgard_CG::grundwerte_boni_setzen();
    }
  manage(new WindowInfo(stinfo,true));
  if (Originalbool) original_midgard_check() ;
  Database.GradAnstieg.set_Grad_Basiswerte(1+Database.GradAnstieg.get_Grad_Basiswerte());
}

void midgard_CG::get_ausdauer(int grad)
{
   int bonus_K, bonus_aK, bonus_Z, kosten=0;
   if (grad == 1)  { bonus_K =  4, bonus_aK =  3; bonus_Z =  2; kosten =    20;}
   if (grad == 2)  { bonus_K =  6, bonus_aK =  4; bonus_Z =  2; kosten =    20;}
   if (grad == 3)  { bonus_K =  9, bonus_aK =  6; bonus_Z =  3; kosten =    20;}
   if (grad == 4)  { bonus_K = 12, bonus_aK =  8; bonus_Z =  4; kosten =    40;}
   if (grad == 5)  { bonus_K = 15, bonus_aK = 10; bonus_Z =  5; kosten =    70;}
   if (grad == 6)  { bonus_K = 18, bonus_aK = 12; bonus_Z =  6; kosten =   150;}
   if (grad == 7)  { bonus_K = 21, bonus_aK = 14; bonus_Z =  7; kosten =   300;}
   if (grad == 8)  { bonus_K = 24, bonus_aK = 16; bonus_Z =  8; kosten =   600;}
   if (grad == 9)  { bonus_K = 27, bonus_aK = 18; bonus_Z =  9; kosten =  1200;}
   if (grad ==10)  { bonus_K = 30, bonus_aK = 20; bonus_Z = 10; kosten =  1500;}
   if (grad >=11)  { bonus_K = 30, bonus_aK = 20; bonus_Z = 10; kosten =  2000;}
//   if (!steigern(kosten,"Ausdauer")) return;
   if (!steigern(kosten)) return;
   Werte.add_GFP(kosten);
   int ap=0;
   for (int i=0;i<grad;++i) ap += random.integer(1,6);

  int nab, nap;
  if      (Typ[0]->Ausdauer() == "k" || Typ[1]->Ausdauer() == "k")  nab = bonus_K ;
  else if (Typ[0]->Ausdauer() == "ak"|| Typ[1]->Ausdauer() == "ak") nab = bonus_aK ;
  else  nab = bonus_Z ;
  nap = ap + nab + Werte.bo_Au() ;
  int nspez = Werte.Grad()*Werte.Spezies()->AP_Grad();
  nap += nspez;
//  std::cout << "Ausdauerpunkte: "<<ap<<" + " <<nab<<" + "<<Werte.bo()_au<<" + "<<nspez<<" = "<<nap<<"\n";
  std::string stinfo="Ausdauerpunkte: Gew�rfelt + Bonus f�r Typ + Pers�nlichen Bonus + Spezies-Bonus\n";
   stinfo+=itos(ap);stinfo+="+";stinfo+=itos(nab);
   stinfo+="+";stinfo+=itos(Werte.bo_Au());stinfo+="=";stinfo+=itos(nap);
  manage(new WindowInfo(stinfo,true));
   // F�r alle ist die AP-anzahel mind. = Grad
  if (Werte.AP()<Werte.Grad()) Werte.set_AP(Werte.Grad()); 
   // Neue AP h�her als alte?
  if (nap>Werte.AP())  Werte.set_AP(nap)  ;
}

void midgard_CG::get_ab_re_za(const string& was)
{
  int alter_wert, max_wert;
  int kosten;
  int grad=Werte.Grad();
  if      (was=="Abwehr")    
    { 
      max_wert = Database.GradAnstieg.get_Abwehr(grad); 
      kosten   = Database.GradAnstieg.get_Abwehr_Kosten(grad+1);
      alter_wert = Werte.Abwehr_wert(); 
    } 
  else if (was=="Resistenz") 
    { 
      max_wert = Database.GradAnstieg.get_Resistenz(grad);
      kosten   = Database.GradAnstieg.get_Resistenz_Kosten(grad+1);
      alter_wert = Werte.Resistenz(); 
    } 
  else if (was=="Zaubern") 
    { 
      if ( Typ[0]->Zaubern()  == "z" || Typ[0]->Zaubern()  == "j" ||
           Typ[1]->Zaubern() == "z" || Typ[1]->Zaubern() == "j" ) 
       { 
         max_wert = Database.GradAnstieg.get_Zauber(grad);
         kosten   = Database.GradAnstieg.get_Zauber_Kosten(grad+1);
         alter_wert = Werte.Zaubern_wert(); 
       } 
      else return; }
  else abort();
  if (alter_wert >= max_wert)
      {manage(new WindowInfo("F�r Grad "+itos(Werte.Grad())+" ist der Maximalwert erreicht!")) ;return;}
  
  Werte.add_GFP(kosten);
  if (was=="Abwehr") Werte.set_Abwehr_wert(alter_wert+1);
  if (was=="Resistenz") Werte.set_Resistenz(alter_wert+1); 
  if (was=="Zaubern") Werte.set_Zaubern_wert(alter_wert+1); 

}
