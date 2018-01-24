# meshalyzer

Meshalyzer is a graphical program for display time dependent data on 3D finite elment meshes. Of course, it can show static data on fewer dimensions as well. 
It is developed to be compatible with the cardiac simulation environment [carpEntry](http://carp.medunigraz.at/carputils). 

It uses its own file formats which are simple and easily converted to/from more popiular formats like VTK.

## Features

* can work with very large data files (TB)
* offscreen rendering
* isosurfaces/lines
* cutting planes
* output images (with metadata) or sequences of images to make movies
* can save state
* link multiple instances to maintain view, colour scale, etc. across them
* can display time-dependent scalar and vector data
* display auxiliary grids
