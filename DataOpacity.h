// generated by Fast Light User Interface Designer (fluid) version 1.0107

#ifndef DataOpacity_h
#define DataOpacity_h
#include <FL/Fl.H>
#include<iostream>
#include "objects.h"
using namespace std;
#define NUM_OBJ 7
class TBmeshWin;

class dataOpac {
public:
  dataOpac();
  float ofactor;
  float dmin;
  float dmax;
  float omin;
  float omax;
  bool _on;
  float alpha( float data );
  bool on();
};
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Value_Slider.H>
#include <FL/Fl_Light_Button.H>
#include <FL/Fl_Value_Input.H>
#include <FL/Fl_Choice.H>

class DataOpacity {
public:
  DataOpacity( TBmeshWin *tbmw );
  Fl_Double_Window *window;
  Fl_Value_Slider *minopacval;
private:
  void cb_minopacval_i(Fl_Value_Slider*, void*);
  static void cb_minopacval(Fl_Value_Slider*, void*);
public:
  Fl_Value_Slider *maxopacval;
private:
  void cb_maxopacval_i(Fl_Value_Slider*, void*);
  static void cb_maxopacval(Fl_Value_Slider*, void*);
public:
  Fl_Light_Button *onbut;
private:
  void cb_onbut_i(Fl_Light_Button*, void*);
  static void cb_onbut(Fl_Light_Button*, void*);
public:
  Fl_Value_Input *mindatval;
private:
  void cb_mindatval_i(Fl_Value_Input*, void*);
  static void cb_mindatval(Fl_Value_Input*, void*);
public:
  Fl_Value_Input *maxdatval;
private:
  void cb_maxdatval_i(Fl_Value_Input*, void*);
  static void cb_maxdatval(Fl_Value_Input*, void*);
public:
  Fl_Choice *objtype;
private:
  void cb_objtype_i(Fl_Choice*, void*);
  static void cb_objtype(Fl_Choice*, void*);
  static Fl_Menu_Item menu_objtype[];
  TBmeshWin *mwtb;
public:
  dataOpac dop[NUM_OBJ];
  Object_t get_ot( int a );
  void save(ofstream& ofs);
  void read(ifstream &ifs);
};
ostream& operator<<(ostream&ofs,dataOpac&dop);
istream& operator>>(istream&ifs,dataOpac&dop);
#endif
