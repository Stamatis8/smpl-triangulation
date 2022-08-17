# smpl_triangulation
	
- Minimal C++ library for various triangulation related tasks
- Header only
- Only dependancy is the standard library

# Current Capabilities

- Triangulation data structure 
    - supports arbitrary vertex type
    - saves connectivity information
    - determines orientability of triangulation
    - orients triangulation

- Triangulate 2D rectangles
- Create [STL](https://en.wikipedia.org/wiki/STL_(file_format)) ASCII files from triangulation

# Usage

All files that are needed to use this library are located in `src`. Move them at some `path` where you have access and then simply `#include "path/smpl_triangulation.hpp"` at the file you want access (ie copy-paste all files from `src` in your project folder and then `#include "smpl_triangulation.hpp"`). 

This library uses the `smpl_triangulation` namespace

There are examples in the `examples` folder for a quick start.

# Overview

This package is constructed around the `Triangulation<vertex type>` class located in `TriangulationClass.hpp`. The type of vertex is arbitrary, the only requirement being that is has a default constuctor `vertex()`. [This](https://doc.cgal.org/latest/TDS_2/index.html) article from CGAL's documentation was advised for the construction of the present data structure. The various other components use this class to perform various tasks.

## Simple Example
The following example is located in `examples/example_1.cpp`. The task is to triangulate the rectangle $[0,1]\times[-1,1]$ in 50 triangles and save the result to `triangles50.stl`.

    #include <vector>

    #include "../src/smpl_triangulation.hpp"

    using namespace smpl_triangulation;

    int main(){
    
	// Initialize a triangulation T whose vertices are of type std::vector<double>
	Triangulation<std::vector<double>> T;

	// Initializing rectangle
	std::vector<double> X = {0,1};
	std::vector<double> Y = {-1,1};
	
	// Triangulate plane
	T = PlanarTriangulation(X,Y,50);

	// Save to file
	make_stl(T,"rectangle50.stl");

	return 0;
    }
# Future

- Faster orientation algorithm
- Read STL files and determine connectivity
- Proper documentation 
