// generated by Fast Light User Interface Designer (fluid) version 1.0107

#include "DataOpacity.h"
#include "TBmeshWin.h"

dataOpac::dataOpac()
{
  _on = false;
  omin = 0;
  omax = 1.;
  dmin = 0;
  dmax = 0;
  ofactor = 0;
}

float dataOpac::alpha( float data )
{
  if ( data <= dmin )
    return omin;
  if ( data >= dmax )
    return omax;
  return omin+(data-dmin*ofactor);
}

bool dataOpac::on()
{
  return _on;
}

void DataOpacity::cb_minopacval_i(Fl_Value_Slider* o, void*)
{
  Object_t a=get_ot(objtype->value());
  dop[a].omin = o->value();
  dop[a].ofactor = (dop[a].omax-dop[a].omin)/(dop[a].dmax-dop[a].dmin);
  mwtb->redraw();
}
void DataOpacity::cb_minopacval(Fl_Value_Slider* o, void* v)
{
  ((DataOpacity*)(o->parent()->user_data()))->cb_minopacval_i(o,v);
}

void DataOpacity::cb_maxopacval_i(Fl_Value_Slider* o, void*)
{
  Object_t a=get_ot(objtype->value());
  dop[a].omax    = o->value();
  dop[a].ofactor = (dop[a].omax-dop[a].omin)/(dop[a].dmax-dop[a].dmin);
  mwtb->redraw();
}
void DataOpacity::cb_maxopacval(Fl_Value_Slider* o, void* v)
{
  ((DataOpacity*)(o->parent()->user_data()))->cb_maxopacval_i(o,v);
}

void DataOpacity::cb_onbut_i(Fl_Light_Button* o, void*)
{
  Object_t a=get_ot(objtype->value());
  dop[a]._on = o->value();
  dop[a].ofactor = (dop[a].omax-dop[a].omin)/(dop[a].dmax-dop[a].dmin);
  mwtb->redraw();
}
void DataOpacity::cb_onbut(Fl_Light_Button* o, void* v)
{
  ((DataOpacity*)(o->parent()->user_data()))->cb_onbut_i(o,v);
}

void DataOpacity::cb_mindatval_i(Fl_Value_Input* o, void*)
{
  Object_t a=get_ot(objtype->value());
  dop[a].dmin    = o->value();
  dop[a].ofactor = (dop[a].omax-dop[a].omin)/(dop[a].dmax-dop[a].dmin);
  mwtb->redraw();
}
void DataOpacity::cb_mindatval(Fl_Value_Input* o, void* v)
{
  ((DataOpacity*)(o->parent()->user_data()))->cb_mindatval_i(o,v);
}

void DataOpacity::cb_maxdatval_i(Fl_Value_Input* o, void*)
{
  Object_t a=get_ot(objtype->value());
  dop[a].dmax    = o->value();
  dop[a].ofactor = (dop[a].omax-dop[a].omin)/(dop[a].dmax-dop[a].dmin);
  mwtb->redraw();
}
void DataOpacity::cb_maxdatval(Fl_Value_Input* o, void* v)
{
  ((DataOpacity*)(o->parent()->user_data()))->cb_maxdatval_i(o,v);
}

void DataOpacity::cb_objtype_i(Fl_Choice*, void*)
{
  Object_t a=get_ot(objtype->value());
  minopacval->value(dop[a].omin);
  maxopacval->value(dop[a].omax);
  mindatval->value(dop[a].dmin);
  maxdatval->value(dop[a].dmax);onbut->value(dop[a]._on);
}
void DataOpacity::cb_objtype(Fl_Choice* o, void* v)
{
  ((DataOpacity*)(o->parent()->user_data()))->cb_objtype_i(o,v);
}

Fl_Menu_Item DataOpacity::menu_objtype[] = {
      {"Vertex", 0,  0, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
      {"Surface", 0,  0, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
      {"Triangle", 0,  0, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
      {"Cable", 0,  0, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
      {0,0,0,0,0,0,0,0,0}
    };

DataOpacity::DataOpacity( TBmeshWin *tbmw )
{
  Fl_Double_Window* w;
  {
    Fl_Double_Window* o = window = new Fl_Double_Window(380, 150, "Data Opacity Controls");
    w = o;
    o->user_data((void*)(this));
    {
      Fl_Value_Slider* o = minopacval = new Fl_Value_Slider(125, 55, 120, 30, "Minimum Opacity");
      o->type(3);
      o->value(0.5);
      o->callback((Fl_Callback*)cb_minopacval);
      o->align(FL_ALIGN_LEFT);
    }
    {
      Fl_Value_Slider* o = maxopacval = new Fl_Value_Slider(125, 100, 120, 30, "Maximum Opacity");
      o->type(3);
      o->value(1);
      o->callback((Fl_Callback*)cb_maxopacval);
      o->align(FL_ALIGN_LEFT);
    }
    {
      Fl_Light_Button* o = onbut = new Fl_Light_Button(225, 10, 120, 30, "Data Opacity ");
      o->labelsize(16);
      o->callback((Fl_Callback*)cb_onbut);
    }
    {
      Fl_Value_Input* o = mindatval = new Fl_Value_Input(295, 55, 80, 30, "below:");
      o->tooltip("data below this value gets minimum opacity");
      o->callback((Fl_Callback*)cb_mindatval);
    }
    {
      Fl_Value_Input* o = maxdatval = new Fl_Value_Input(295, 100, 80, 30, "above:");
      o->tooltip("data above this value gets maximum opacity");
      o->callback((Fl_Callback*)cb_maxdatval);
    }
    {
      Fl_Choice* o = objtype = new Fl_Choice(75, 10, 120, 30, "Object:");
      o->tooltip("apply to which object type");
      o->down_box(FL_BORDER_BOX);
      o->callback((Fl_Callback*)cb_objtype);
      o->menu(menu_objtype);
    }
    o->end();
  }
  mwtb = tbmw;
}

Object_t DataOpacity::get_ot( int a )
{
  if ( a==0 )
    return Vertex;
  else if ( a==1 )
    return Surface;
  else if ( a==2 )
    return SurfEle;
  else if ( a==3 )
    return Cable;
}

void DataOpacity::save(ofstream& ofs)
{
  for ( int i=0; i<NUM_OBJ; i++ ) {
    ofs << dop[i];
  }
}

void DataOpacity::read(ifstream &ifs)
{
  for ( int i=0; i<NUM_OBJ; i++ ) {
    ifs >> dop[i];
    dop[i].ofactor = (dop[i].omax-dop[i].omin)/(dop[i].dmax-dop[i].dmin);
  }

  minopacval->value(dop[Vertex].omin);
  maxopacval->value(dop[Vertex].omax);
  mindatval->value(dop[Vertex].dmin);
  maxdatval->value(dop[Vertex].dmax);
  onbut->value(dop[Vertex]._on);
}

ostream& operator<<(ostream&ofs,dataOpac&dop)
{
  ofs<<dop.dmin<<" "<<dop.dmax<<" "<<dop.omin<<" "<<dop.omax<<" "<<dop._on<<endl;
  return ofs;
}

istream& operator>>(istream&ifs,dataOpac&dop)
{
  ifs>>dop.dmin>>dop.dmax>>dop.omin>>dop.omax>>dop._on;
  return ifs;
}
