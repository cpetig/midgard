// generated 2001/4/12 9:43:51 CEST by thoma@ig23.
// using glademm V0.5_11f_cvs
//
// some glademm convenience functions
//
// DO NOT EDIT THIS FILE !

#ifndef GLADEMM_SUPPORT_HH
#define GLADEMM_SUPPORT_HH
#include <string>
#include <map>
#include <gtk--/widget.h>

Gtk::Widget * glademm_get_Widget(const __STD::string &name);
void glademm_set_Widget(const __STD::string &name, Gtk::Widget *w);

template <class T> T * glademm_get(const __STD::string &name)
{   return reinterpret_cast<T*>(glademm_get_Widget(name));
   // 2do: testen ... geht aber nicht ohne Methode gleichen Namens
}
#endif /* GLADEMM_SUPPORT_HH */
