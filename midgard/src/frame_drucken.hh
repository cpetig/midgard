// generated 2002/4/14 11:16:16 CEST by thoma@Tiger.(none)
// using glademm V0.6.4b_cvs
//
// newer (non customized) versions of this file go to frame_drucken.hh_new

// you might replace
//    class foo : public foo_glade { ... };
// by
//    typedef foo_glade foo;
// if you didn't make any modifications to the widget

#ifndef _FRAME_DRUCKEN_HH
#  include "frame_drucken_glade.hh"
#  define _FRAME_DRUCKEN_HH

class midgard_CG;
#include "Optionen.hh"
#include <gtk--/radiobutton.h>


class frame_drucken : public frame_drucken_glade
{  
        
        friend class frame_drucken_glade;
        midgard_CG *hauptfenster;
        void element_activate(Gtk::RadioButton *rb,Midgard_Optionen::pdfViewerIndex index);
        void entry_changed();
        gint entry_focus_out(GdkEventFocus *ev);
        Gtk::Entry *entry;
        bool bool_changed;

public:
        frame_drucken(GlademmData *_data) : frame_drucken_glade(_data)
        {  
        }
      void init();
      void set_Hauptfenster(midgard_CG *h);


};
#endif