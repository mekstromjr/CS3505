#ifndef Spiral_H
#define Spiral_H
#include <math.h>

class Spiral {
    private:
        const double minRadius = 20.0;
        const float pi = 3.141592;
        double centX;
        double centY;
        double spiralX;
        double spiralY;
        double sinAngle;
        double spiralAngle;
        double radius;
        double radiusScaleFactor;

        void calculateNewPosition();

    public:
        /// @brief a 2D Spiral Constructor
        /// @param centerX - The X choordinate of the center of the spiral
        /// @param centerY - The Y choordiante of the center of the spiral
        /// @param startingAngle - The initial angle of the spiral (in degrees)
        /// @param loopScalingFactor - Value from (0,1) for the scaling of the radius.
        Spiral(double centerX, double centerY, double startingAngle, double loopScalingFactor);
        // void operator+=();
        /* Provides the X position on the page of the current spiral point (using the stored internal angle and center 
            point)*/
        double getSpiralX();
        /* Provides the Y position on the page of the current spiral point (using the stored internal angle and center 
            point)*/
        double getSpiralY();
        /* Provides the current internal angle of the spiral consistent with the coordinate system the Spiral class uses
            - that is, 0 degrees is 12 o'clock and a positive change in angle is a clockwise change.*/
        double getSpiralAngle();
        Spiral& operator+=(float);
};
#endif