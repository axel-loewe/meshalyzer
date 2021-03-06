#ifndef SURFACES_H
#define SURFACES_H

#include <stdio.h>
#include <stdlib.h>
#include "DrawingObjects.h"
#include <string>
#include <fstream>


struct vtx_z {
  int   i;     //!< point index
  float z;     //!< z depth
  short s;     //!< surface
};

#define  CSET(V,C,A)  V[0]=C;V[1]=C;V[2]=C;V[3]=A;
class Surfaces
{
  public:
    Surfaces( PPoint *pl=NULL ): _p(pl){}
    GLfloat* fillcolor( ){ return _fillcolor; }
    void     fillcolor(float r, float g, float b, float a=1);
    GLfloat* outlinecolor( ){ return _outlinecolor; }
    void     outlinecolor(float r, float g, float b, float a=1);
    inline bool visible(){return is_visible;}
    inline void visible(bool a){ is_visible=a; }
    inline bool filled( void ){  return _filled; }
    inline void filled( bool a ){ _filled=a; }
    inline bool outline( void ){  return _outline; }
    inline void outline( bool a ){ _outline=a; }
    void get_vert_norms( GLfloat *&vn ){ vn = _vertnorm; }
    void determine_vert_norms( PPoint & );
    SurfaceElement*& ele( int a ){ return _ele[a]; }
    void addele(int a,SurfaceElement*e){_ele[a]=e;}
    int  num() const {return _ele.size();}
    void num(int a){_ele.resize(a);}
    vector<SurfaceElement*>& ele(){return _ele;}
    void draw(GLfloat*,Colourscale*,DATA_TYPE*,
              dataOpac*,const GLfloat*);
    void draw_elem(int, GLfloat*,Colourscale*,DATA_TYPE*,
              dataOpac*,const GLfloat*, bool &);
    void sort( int, bool, short s=0 );
    void   register_vertices( vector<bool>& );
    void   label( string s ){ _label=s; }
    string label( void ) { return _label; }
    void   flip_norms();
    void   correct_branch_elements( GLdouble *, DATA_TYPE *, 
                          Colourscale *, int, dataOpac * );
    void  to_file( ofstream &of );
    void diffuse( GLfloat c, GLfloat a=1. ) { CSET(_diffuse,c,a) }
    void specular( GLfloat c, GLfloat a=1. ) { CSET(_specular,c,a) }
    void shiny( GLfloat s ) { _shiny=s; }
    void backlight( GLfloat b ) { _backlight=b; }
    GLfloat diffuse( void ){ return _diffuse[0]; }
    GLfloat specular( void ){ return _specular[0]; }
    GLfloat shiny( void ) { return _shiny; }
    GLfloat backlight( void ) { return _backlight; }
    void set_material( void );
    vector<vtx_z>::iterator zl_begin() { return _zlist.begin(); }
    vector<vtx_z>::iterator zl_end() { return _zlist.end(); }
    int  zl_sz(void){ return _zlist.size();}
  protected:
    PPoint   *_p;
    GLfloat  _fillcolor[4]    = { 1., 0.5, 0.1, 1 };
    GLfloat  _outlinecolor[4] = { 0.125, 0.8, 0.7, 1 };
    bool      is_visible      = true;
    bool     _filled          = true;   //!< draw filled
    bool     _outline         = false;  //!< draw the outline
    GLfloat* _vertnorm        = NULL;   //!< vertex normals
    vector<int>_vert;                   //!< vertices for which normals are computed
    vector<SurfaceElement*> _ele;       //!< list of elelments to draw
    string   _label       = "";
    GLfloat  _diffuse[4]  = {0.6,0.6,0.6,1.};
    GLfloat  _specular[4] = {0.75,0.75,0.75,1.};
    GLfloat  _shiny       = {80.};
    GLfloat  _backlight   = 0.5;
    int      _oldstride   = 0;
    GLfloat  _oldmvp[4]{};
    vector<vtx_z> _zlist;
};

#endif
