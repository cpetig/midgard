// generated 2002/10/27 13:58:21 CET by thoma@Tiger.(none)
// using glademm V1.1.1c_cvs
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- /home/thoma/rollenspiel/midgard/programme/gcc_3.0/midgard/midgard.glade
// for gtk 1.2.10 and gtkmm 1.2.10
//
// Please modify the corresponding derived classes in ./src/xml_fileselection.cc

#include "config.h"
#include "xml_fileselection.hh"
#include <gdk/gdkkeysyms.h>
#include <gtk--/accelgroup.h>
#include <gtk--/button.h>

xml_fileselection_glade::xml_fileselection_glade(
) : Gtk::FileSelection("XML-Datei ausw�hlen")
{  
   
   Gtk::FileSelection *xml_fileselection = this;
   Gtk::AccelGroup *xml_fileselection_accgrp = Gtk::AccelGroup::create();
   _data = new GlademmData(xml_fileselection_accgrp);
   xml_fileselection->get_ok_button()->set_flags(GTK_CAN_FOCUS);
   xml_fileselection->get_ok_button()->set_relief(GTK_RELIEF_NORMAL);
   xml_fileselection->get_cancel_button()->set_flags(GTK_CAN_FOCUS);
   xml_fileselection->get_cancel_button()->set_relief(GTK_RELIEF_NORMAL);
   xml_fileselection->set_border_width(10);
   xml_fileselection->set_title("XML-Datei ausw�hlen");
   xml_fileselection->set_modal(true);
   xml_fileselection->set_position(GTK_WIN_POS_NONE);
   xml_fileselection->add_accel_group(*(_data->getAccelGroup()));
   xml_fileselection->show_fileop_buttons();
   xml_fileselection->show();
   xml_fileselection->get_ok_button()->clicked.connect(SigC::slot(static_cast<class xml_fileselection*>(this), &xml_fileselection::on_ok_button1_clicked));
   xml_fileselection->get_cancel_button()->clicked.connect(SigC::slot(static_cast<class xml_fileselection*>(this), &xml_fileselection::on_cancel_button1_clicked));
}

xml_fileselection_glade::~xml_fileselection_glade()
{  delete _data;
}
