#ifndef AVAON_TYPE_CONTROL_H__
#define AVAON_TYPE_CONTROL_H__

namespace avalon {

struct buoypos
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
	base::Vector2D koord;
};

}
