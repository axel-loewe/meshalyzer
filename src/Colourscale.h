/*
 * Class for a colour map which returns a vector suitable for a glColor()
 * call
 */

#ifndef COLOURSCALE_INC
#define COLOURSCALE_INC
#include <FL/gl.h>
#include <math.h>
#include "PNGwrite.h"

typedef enum {
  CS_HOT, CS_GREY, CS_RGREY, CS_GGREY, CS_BGREY, CS_RAINBOW, CS_BL_RAINBOW, 
  CS_COLD_HOT, CS_CG, CS_MATLAB_REV, CS_MATLAB, CS_ACID, CS_P2G, CS_VIRIDIS,
  CS_VIRIDIS_LIGHT, CS_MAGMA, CS_INFERNO, CS_DISTINCT
} CScale_t;

typedef enum {
  NO_DEAD=0, DEAD_MIN=1, DEAD_MAX=2, DEAD_NaN=4
} DeadRange;

class Colourscale
{
  public:
    Colourscale(int ts=64, CScale_t tcs=CS_BL_RAINBOW );
    void   scale( CScale_t );				// set scale
    inline CScale_t scale(void){ return scaletype; }
    void   calibrate( double, double ); 	// set range
    inline float min(){return mindat;}		// return minimum data value
    inline float max(){return maxdat;}		// return maximum data value
    void colourize( float c ){glColor3fv(colorvec(c));}   // colour vector for data value
    void colourize( float, float );			// same as above, specify alpha
    inline int size(){ return n; }			// get the size
    void     size( int );	    				// set the size
    inline   GLfloat* entry(int a){return cmap[a];}	// return an entry
    GLfloat *colorvec( double, float alpha=1 );
    void     output_png( const char * );            // output the map
    void     deadColour( GLfloat *, GLfloat );
    GLfloat *deadColour(){return _deadColour;}
    void     deadRange( double min, double max, bool nan, DeadRange dr );
    void     deadRange( void ){_deadRange=NO_DEAD;};
    void     get_deadRange( double &min, double &max, DeadRange &dr )
                          { min=_deadMin;max=_deadMax;dr=_deadRange;}
  private:
    GLfloat** cmap;							// the map
    int       n = 0;				  	    // size of map
    double    a, b;							// map data to colour map
    CScale_t  scaletype;
    double    mindat=0., maxdat=1.;
    DeadRange _deadRange=NO_DEAD;             // what to ignore
    double    _deadMin=0, _deadMax=1.;        // ignore below and above these values
    bool      _deadNaN=false;                 // ignore NaN's
    GLfloat   _deadColour[4]={0.,0.,0.,1.};   // how to colour dead data
};

#endif

