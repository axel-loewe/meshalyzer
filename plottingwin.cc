// generated by Fast Light User Interface Designer (fluid) version 1.0300

#include "plottingwin.h"
#include "Graph.h"
using namespace std;

void PlotWin::cb_window_i(Fl_Double_Window*, void*) {
  this->window->hide();
}
void PlotWin::cb_window(Fl_Double_Window* o, void* v) {
  ((PlotWin*)(o->user_data()))->cb_window_i(o,v);
}

void PlotWin::cb_Close_i(Fl_Return_Button*, void*) {
  this->window->hide();
}
void PlotWin::cb_Close(Fl_Return_Button* o, void* v) {
  ((PlotWin*)(o->parent()->parent()->user_data()))->cb_Close_i(o,v);
}

void PlotWin::cb_Write_i(Fl_Button*, void*) {
  writedata();
}
void PlotWin::cb_Write(Fl_Button* o, void* v) {
  ((PlotWin*)(o->parent()->parent()->user_data()))->cb_Write_i(o,v);
}

void PlotWin::cb_rotbut_i(Fl_Light_Button* o, void*) {
  rotate(o->value());
}
void PlotWin::cb_rotbut(Fl_Light_Button* o, void* v) {
  ((PlotWin*)(o->parent()->parent()->user_data()))->cb_rotbut_i(o,v);
}

void PlotWin::cb_autoscalebut_i(Fl_Light_Button* o, void*) {
  autoscale(o->value());
}
void PlotWin::cb_autoscalebut(Fl_Light_Button* o, void* v) {
  ((PlotWin*)(o->parent()->parent()->user_data()))->cb_autoscalebut_i(o,v);
}

void PlotWin::cb_Hold_i(Fl_Button*, void*) {
  graph->copy_curve(0);
}
void PlotWin::cb_Hold(Fl_Button* o, void* v) {
  ((PlotWin*)(o->parent()->parent()->user_data()))->cb_Hold_i(o,v);
}

PlotWin::PlotWin(  string title ) {
  { window = new Fl_Double_Window(525, 195, "Time plot");
    window->box(FL_UP_BOX);
    window->callback((Fl_Callback*)cb_window, (void*)(this));
    { graph = new Graph(5, 5, 515, 165);
      graph->box(FL_NO_BOX);
      graph->color(FL_BACKGROUND_COLOR);
      graph->selection_color(FL_BACKGROUND_COLOR);
      graph->labeltype(FL_NORMAL_LABEL);
      graph->labelfont(0);
      graph->labelsize(14);
      graph->labelcolor(FL_FOREGROUND_COLOR);
      graph->align(FL_ALIGN_CENTER);
      graph->when(FL_WHEN_RELEASE);
      Fl_Group::current()->resizable(graph);
    } // Graph* graph
    { button_grp = new Fl_Group(5, 170, 515, 30);
      button_grp->box(FL_ENGRAVED_BOX);
      button_grp->color(FL_LIGHT2);
      { Fl_Return_Button* o = new Fl_Return_Button(15, 175, 75, 15, "Close");
        o->labelsize(10);
        o->callback((Fl_Callback*)cb_Close);
      } // Fl_Return_Button* o
      { Fl_Button* o = new Fl_Button(275, 175, 70, 15, "Write");
        o->labelsize(10);
        o->callback((Fl_Callback*)cb_Write);
      } // Fl_Button* o
      { rotbut = new Fl_Light_Button(105, 175, 70, 15, "Rotate");
        rotbut->labelsize(10);
        rotbut->callback((Fl_Callback*)cb_rotbut);
      } // Fl_Light_Button* rotbut
      { Fl_Button* o = new Fl_Button(190, 175, 70, 15, "Pop");
        o->labelsize(10);
      } // Fl_Button* o
      { autoscalebut = new Fl_Light_Button(440, 175, 70, 15, "Autoscale");
        autoscalebut->value(1);
        autoscalebut->labelsize(10);
        autoscalebut->callback((Fl_Callback*)cb_autoscalebut);
      } // Fl_Light_Button* autoscalebut
      { Fl_Button* o = new Fl_Button(360, 175, 70, 15, "Hold");
        o->labelsize(10);
        o->callback((Fl_Callback*)cb_Hold);
      } // Fl_Button* o
      button_grp->end();
    } // Fl_Group* button_grp
    window->end();
  } // Fl_Double_Window* window
  xv = new double[1];
data = new double[1];
tm = 0;
datasize = -1;
rotated = false;
window->label(strdup(title.c_str()));
window->user_data(this);
}

void PlotWin::autoscale(int a) {
  graph->autoscale(a);
}
