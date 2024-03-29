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
#include <base/time.h>
#include <base/float.h>

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
	double validation;  //double

        /** timestamp */
        base::Time time;
	
        /** real world coordinates of the buoy */
	base::Vector3d world_coord;	//x=vorne,y=links,z=oben

        Buoy()
        : image_x(0), image_y(0), image_radius(0), probability(0), validation(0), time(base::Time::now()) {}

	Buoy(int x, int y, int r)
	: image_x(x), image_y(y), image_radius(r), probability(1), validation(0), time(base::Time::now()) {}

        //derzeit falsch herum definiert um das sortieren im filter um zu drehen
        inline friend bool operator< (const Buoy &a, const Buoy &b)
        {
            return a.validation<b.validation;
        }
        inline friend bool operator> (const Buoy &a, const Buoy& b)
        {
            return a.validation>b.validation;
        }

        static bool timeComparison(Buoy const& b0, Buoy const& b1)
        {
            return b0.time > b1.time;
        }
        static bool validityComparison(Buoy const& b0, Buoy const& b1)
        {
            return b0.validation < b1.validation;
        }
        static bool probabilityComparison(Buoy const& b0, Buoy const& b1)
        {
            return b0.probability < b1.probability;
        }
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

struct WhiteLightSettings{
    double roi_X;
    double roi_Y;
    double roi_width;
    double roi_height;
    int val_Binary_Threshold;
    int sat_Binary_Threshold;
	WhiteLightSettings(double x,double y, double w, double h, int val, int sat)
	: roi_X(x), roi_Y(y), roi_width(w), roi_height(h), val_Binary_Threshold(val), sat_Binary_Threshold(sat) {}
	WhiteLightSettings()
	: roi_X(base::unknown<double>()), roi_Y(base::unknown<double>()), roi_width(base::unknown<double>()), roi_height(base::unknown<double>()), val_Binary_Threshold(base::unknown<int>()), sat_Binary_Threshold(base::unknown<int>()) {}
};


}} // namespace avalon::feature

#endif // AVALON_BASE__FEATURE_H_

