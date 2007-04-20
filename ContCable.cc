/** \file ContCables are cables defined by contiguously numbered points.
 * The cables are defined by two integers, the first is the node number of
 * the first point in the cable and the second is one more than the index of
 * the last point in the cable. The length of the _node array is the number
 * of cables plus 1. Cable i is defined by _node[i] and _node[i+1]
 */
#include "DrawingObjects.h"

/** draw many ContCables
 *  
 *  \param p0       first index of cable to draw
 *  \param p1       last index of cable to draw
 *  \param colour   colour to use if no data
 *  \param data     data associated with nodes (NULL for no data display)
 *  \param stride   draw every n'th point
 */
void ContCable::draw( int p0, int p1, GLfloat *colour, Colourscale* cs,
					 DATA_TYPE* data, int stride, dataOpac* dataopac )
{
  if( p0>=_n || p1>=_n ) return;
  
  for( int i=p0; i<=p1; i+=stride ){
	glBegin(GL_LINE_STRIP);
	if( data!=NULL ) {
	  if( dataopac->on() ){		// data opacity
		for( int j=_node[i]; j<_node[i+1]; j++ ){
		  if( !_pt->vis(j) ) continue;
		  cs->colourize( data[j], dataopac->alpha( data[j]) );
		  glVertex3fv( _pt->pt(j) );
		} 
	  } else {		// no data opacity
		for( int j=_node[i]; j<_node[i+1]; j++ ){
		  if( !_pt->vis(j) ) continue;
		  cs->colourize( data[j], colour[3] );
		  glVertex3fv( _pt->pt(j) );
		} 
	  }
	} else {							// no data on cables
	  glColor4fv( colour );
	  for( int j=_node[i]; j<_node[i+1]; j++ ) {
		if( !_pt->vis(j) ) continue;
		glVertex3fv( _pt->pt(j) );
	  }
	}
	glEnd();
  }
}


/** highlight a vertex
 *
 *  \param p      node to highlight
 *  \param colour colour to use
 *  \param size   size of point
 */
void ContCable :: draw( int p, GLfloat *colour, float size )
{
  if( p<_n ) {
	glColor3fv( colour );
	glLineWidth(size);
	glBegin( GL_LINE_STRIP );
	  for( int j=_node[p]; j<_node[p+1]; j++ ) {
		if( !_pt->vis(j) ) continue;
		glVertex3fv( _pt->pt(j) );
	  }
	glEnd();
	glLineWidth(1);
  }
}


/** read in the point file */
bool ContCable :: read( const char *fname )
{
  gzFile in;
  
  try {
    in = openFile( fname, "cables" );
  }
  catch(...) { return false; }

  const int bufsize=1024;
  char      buff[bufsize];
  if( gzgets(in, buff, bufsize) == Z_NULL ) return false;
  if( sscanf( buff, "%d", &_n ) != 1 ) return false;
  _node = new int[_n+1];
  for( int i=0; i<=_n; i++ ) {
	gzgets(in, buff, bufsize);
	sscanf( buff, "%d", _node+i );
  }
  gzclose(in);
  return true;
}


/** register vertices so that they can be picked
 *
 * \param p0      start index
 * \param p1      stop  index
 * \param ptDrawn list of points drawn
 */
void ContCable::register_vertices( int p0, int p1, vector<bool>& ptDrawn )
{
  for( int i=p0; i<=p1; i++ ) {
	int p = i;
	for( int j=_node[p]; j<_node[p+1]; j++ )
	  if( _pt->vis( j ) )
		continue;
	for( int j=_node[p]; j<_node[p+1]; j++ )
	  if( !ptDrawn[j] ) {
		ptDrawn[j] = true;
		glLoadName( j );
		glBegin(GL_POINTS);
		  glVertex3fv( _pt->pt(j) );
		glEnd();
	  }
  }
}

