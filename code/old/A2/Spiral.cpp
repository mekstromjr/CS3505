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
    
    radius = startingAngle * radiusScalingFactor;

    if(radius < minRadius)
        radius = minRadius;

    spiralX = centerX;
    spiralY = centerY;

    //Enforce a non-negative starting angle
    if(startingAngle < 0)
        startingAngle = -startingAngle;
    
    //Scale starting angle to be [0-360] and convert spiral angle to a sin/cos angle
    spiralAngle = startingAngle;

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
    spiralAngle += deltaAngle;

    radius = spiralAngle * radiusScaleFactor;
    calculateNewPosition();
    return *this;
}


void Spiral::calculateNewPosition() {
    float radianAngle = -(spiralAngle - 90) / 180 * pi;
    spiralX = centX + cos(radianAngle) * radius;
    spiralY = centY + sin(radianAngle) * radius;
}
