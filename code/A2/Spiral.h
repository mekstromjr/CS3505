#include <math.h>
class Spiral {
    private:
        const double minRadius = 1.0;
        const float pi = 3.141592;
        double centX;
        double centY;
        double angle;
        double radius;
        double scaleFactor;

    public:
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
};