#ifndef AVAON_TYPE_BUOYPOS_
#define AVAON_TYPE_BUOYPOS_

#include <base/eigen.h>

namespace avalon {

struct BuoyPos
{
	//position on original image
    	int image_x;
    	int image_y;
	int image_radius;
	
        double propability;
	
	base::Vector3d world_coord;

	//Konstruktor
	BuoyPos(int x, int y, int r)
	: image_x(x), image_y(y), image_r(r), propability(1) {}
};

}
#endif
