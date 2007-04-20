// generated by Fast Light User Interface Designer (fluid) version 1.0105

#include "HiLiteWinInfo.h"
#include "TBmeshWin.h"

inline void HiLiteInfoWin::cb_window_i(Fl_Double_Window*, void*) {
  this->window->hide();
}
void HiLiteInfoWin::cb_window(Fl_Double_Window* o, void* v) {
  ((HiLiteInfoWin*)(o->user_data()))->cb_window_i(o,v);
}

inline void HiLiteInfoWin::cb_hilighttext_i(Fl_Browser* o, void*) {
  mw->select_hi(o->value());
}
void HiLiteInfoWin::cb_hilighttext(Fl_Browser* o, void* v) {
  ((HiLiteInfoWin*)(o->parent()->user_data()))->cb_hilighttext_i(o,v);
}

inline void HiLiteInfoWin::cb_Close_i(Fl_Button*, void*) {
  window->hide();
}
void HiLiteInfoWin::cb_Close(Fl_Button* o, void* v) {
  ((HiLiteInfoWin*)(o->parent()->user_data()))->cb_Close_i(o,v);
}

HiLiteInfoWin::HiLiteInfoWin(TBmeshWin *a) {
  Fl_Double_Window* w;
  mw = a;
  { Fl_Double_Window* o = window = new Fl_Double_Window(265, 665, "Highlighted information");
    w = o;
    o->callback((Fl_Callback*)cb_window, (void*)(this));
    { Fl_Browser* o = hilighttext = new Fl_Browser(0, 0, 265, 645);
      o->type(1);
      o->callback((Fl_Callback*)cb_hilighttext);
      Fl_Group::current()->resizable(o);
    }
    { Fl_Button* o = new Fl_Button(0, 645, 265, 20, "Close");
      o->callback((Fl_Callback*)cb_Close);
    }
    o->end();
  }
}

void HiLiteInfoWin::clear() {
  hilighttext->clear();
}

void HiLiteInfoWin::add(const char *s, void *d) {
  hilighttext->add( s, d );
}

const char * HiLiteInfoWin::text(int n) {
  return hilighttext->text(n);
}

void HiLiteInfoWin::topline( int a ) {
  hilighttext->topline( a );
}

int HiLiteInfoWin::topline( void ) {
  return hilighttext->topline();
}
