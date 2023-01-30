 /* 
 *  Michael Ekstrom 
 *  CS3505 
 *  A2: Spiral
 */
#ifndef Spiral_H
#define Spiral_H
#include <math.h>

/// @brief Spiral Class for giving the position of points along a spiral curve.
class Spiral {
    private:
        //Anything less than 20.0 tends have text overlap
        const double minRadius = 20.0;
        const float pi = 3.141592;
        //Center Position of the spiral
        double centX;
        double centY;
        //Current Position on spiral curve
        double spiralX;
        double spiralY;
        double sinAngle;
        double spiralAngle;
        double radius;
        double radiusScaleFactor;

        /// @brief Recalculates the current position along the curve
        void calculateNewPosition();

    public:
        /// @brief a 2D Spiral Constructor
        /// @param centerX - The X choordinate of the center of the spiral
        /// @param centerY - The Y choordiante of the center of the spiral
        /// @param startingAngle - The initial angle of the spiral (in degrees)
        /// @param loopScalingFactor - Value from (0,1) for the scaling of the radius.
        Spiral(double centerX, double centerY, double startingAngle, double loopScalingFactor);
        
        /// @brief Provides the X position on the page of the current spiral point (using the stored internal angle and center 
        ///        point)
        /// @return 
        double getSpiralX();

        /// @brief Provides the Y position on the page of the current spiral point (using the stored internal angle and center 
        ///        point)    
        /// @return
        double getSpiralY();

        /// @brief Provides the current internal angle of the spiral consistent with the coordinate system the Spiral class uses
        ///        - that is, 0 degrees is 12 o'clock and a positive change in angle is a clockwise change.
        /// @return 
        double getSpiralAngle();

        /// @breif Increments the angle of the spiral by the given amount
        /// @return a reference to the object that was changed.
        Spiral& operator+=(float deltaAngle);
};
#endif