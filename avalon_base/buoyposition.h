#ifndef AVAON_TYPE_BUOYPOS_
#define AVAON_TYPE_BUOYPOS_

#include <base/eigen.h>

namespace avalon {

struct BuoyPos
{
	//position on original image
    	int img_x;
    	int img_y;
	int img_r;
	//from camera	
	//gibtsnich
	//probability
	double p;
	//worldkoordinates
	base::Vector3d koord;

	//Konstruktor
	BuoyPos(int x, int y, int r)
	{
		img_x=x;
		img_y=y;
		img_r=r;
		p=1;
	}
};

}
#endif
