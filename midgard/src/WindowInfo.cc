// generated 2001/2/27 13:32:15 CET by thoma@ig23.
// using glademm V0.5_11f_cvs
//
// newer (non customized) versions of this file go to WindowInfo.cc_new

// This file is for your program, I won't touch it again!

#include "config.h"
#include "WindowInfo.hh"
#include <gtk--/main.h>
#include "midgard_CG.hh"

void WindowInfo::on_button_info_ok_clicked()
{   
 destroy();
}

WindowInfo::WindowInfo(string s)
{
   if (Infobool) infotext->set_text(s.c_str());
   else destroy();
//XXX   Gtk::Main::timeout.connect(WindowInfo::WindowInfo.destroy().slot(),1000);
}
