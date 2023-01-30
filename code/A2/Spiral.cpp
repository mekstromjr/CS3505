 /* 
 *  Michael Ekstrom 
 *  CS3505 
 *  A2: Spiral
 */
#include <math.h>
#include "Spiral.h"

Spiral::Spiral(double centerX, double centerY, double startingAngle, double radiusScalingFactor) {
    centX = centerX;
    centY = centerY;
    radius = minRadius;
    spiralX = centerX;
    spiralY = centerY;

    //Enforce a non-negative starting angle
    if(startingAngle < 0)
        startingAngle = -startingAngle;
    
    //Scale starting angle to be [0-360] and convert spiral angle to a sin/cos angle
    spiralAngle = ((int)startingAngle%360);
    sinAngle = 90 - startingAngle;

    radiusScaleFactor = radiusScalingFactor;

    calculateNewPosition();
}


double Spiral::getSpiralAngle() {
    return spiralAngle;
}

double Spiral::getSpiralX() {
    return spiralX;
}

double Spiral::getSpiralY() {
    return spiralY;
}

Spiral& Spiral::operator+=(float deltaAngle) {
    sinAngle -= deltaAngle;
    spiralAngle += deltaAngle;
    calculateNewPosition();
    return *this;
}


void Spiral::calculateNewPosition() {
    float radianAngle = (sinAngle / 180 * pi);
    radius = minRadius + (-sinAngle * radiusScaleFactor);

    spiralX = centX + cos(radianAngle) * radius;
    spiralY = centY + sin(radianAngle) * radius;
}
