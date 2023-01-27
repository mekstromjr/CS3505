#include "Spiral.h"
#include <math.h>


Spiral::Spiral(double centerX, double centerY, double startingAngle, double loopScalingFactor) {
    centX = centerX;
    centY = centerY;
    radius = minRadius;
    //Enforce a positive starting angle
    if(startingAngle < 0) {
        angle = -startingAngle;
    } else {
        angle = startingAngle;
    }
    scaleFactor = loopScalingFactor;
}
