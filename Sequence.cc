// generated by Fast Light User Interface Designer (fluid) version 1.0300

#include "Sequence.h"

void Sequence::cb_Start_i(Fl_Return_Button*, void*) {
  mwtb->output_png( fname->value(), this );
}
void Sequence::cb_Start(Fl_Return_Button* o, void* v) {
  ((Sequence*)(o->parent()->user_data()))->cb_Start_i(o,v);
}

void Sequence::cb_browse_i(Fl_Button*, void*) {
  const char* fn=fl_file_chooser("Choose output file name base", "*.png",fname->value() );
if( fn != NULL ) fname->value(fn);
}
void Sequence::cb_browse(Fl_Button* o, void* v) {
  ((Sequence*)(o->parent()->user_data()))->cb_browse_i(o,v);
}

Sequence::Sequence( TBmeshWin *tb ) {
  { window = new Fl_Double_Window(295, 190, "Write PNG Sequence");
    window->user_data((void*)(this));
    { movieprog = new Fl_Progress(15, 10, 265, 35);
      movieprog->selection_color((Fl_Color)91);
    } // Fl_Progress* movieprog
    { Fl_Return_Button* o = new Fl_Return_Button(15, 145, 265, 35, "Start sequence");
      o->callback((Fl_Callback*)cb_Start);
    } // Fl_Return_Button* o
    { fname = new Fl_File_Input(15, 65, 215, 35, "output file base name:");
      fname->align(Fl_Align(FL_ALIGN_TOP));
    } // Fl_File_Input* fname
    { Fl_Button* o = new Fl_Button(240, 65, 40, 35, "browse");
      o->labelsize(10);
      o->callback((Fl_Callback*)cb_browse);
    } // Fl_Button* o
    { lastFrameNum = new Fl_Value_Input(160, 110, 55, 25, "End Frame:");
      lastFrameNum->step(1);
    } // Fl_Value_Input* lastFrameNum
    window->end();
  } // Fl_Double_Window* window
  mwtb = tb;
fname->value("image.png");
lastFrameNum->value( mwtb->numframes-1 );
lastFrameNum->maximum( mwtb->numframes-1 );
}
