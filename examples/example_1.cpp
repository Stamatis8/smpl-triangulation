#include <vector>

#include "../src/smpl_triangulation.hpp"

using namespace smpl_triangulation;

int main(){
	/*
		This example shows how to triangulate the rectangle [0,1]x[-1,1] into 50 triangles
		and save it to rectangle50.stl
	*/


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
