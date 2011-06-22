/*
 * Avalon base - feature.h
 * definition for feature representation for several visual computervision algorithm
 * 
 * created by: 
 *      Thomas Grassow <deshalb@informatik.uni-bremen.de>
 *      Christoph Mueller <christoph.mueller@dfki.de>
 */

#ifndef AVALON_BASE__FEATURE_H_
#define AVALON_BASE__FEATURE_H_

#include <base/eigen.h>

namespace avalon {
namespace feature {

/**
 * Simple structure for representing a buoy found in an image 
 */
struct Buoy
{
        /** x-position of the buoy in image in pixel */
    	int image_x;

        /** y-position of the buoy in image in pixel */
    	int image_y;

        /** radius of the buoy in in image in pixel */
	int image_radius;
	
        /** propability that this is a real buoy in image */
        double probability;

	/** a variable used by the filter */
	double validation;
	
        /** real world coordinates of the buoy */
	base::Vector3d world_coord;	//x=vorne,y=links,z=oben

        Buoy()
        : image_x(0), image_y(0), image_radius(0), probability(0), validation(0) {}

	Buoy(int x, int y, int r)
	: image_x(x), image_y(y), image_radius(r), probability(1), validation(0) {}
};


/**
 * Simple structure for representing a gate detected in an image
 */

struct Gate
{
    /** dummy value */
    int dummy;

    Gate() {}
};

}} // namespace avalon::feature

#endif // AVALON_BASE__FEATURE_H_

