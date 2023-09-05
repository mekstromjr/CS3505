/*
* Michael Ekstrom
* CS3505
* A2: Making a Class
*/
#ifndef SINE_H
#define SINE_H
    #include "Sine.h"
#endif

#ifndef C_MATH
#define C_MATH
    #include <cmath>
#endif

    Sine::Sine(double amplitude, double wavelength, double increment) : 
        amplitude(amplitude), wavelength(wavelength), increment(increment), angle(0) {

    }

    // Sine::~Sine() {
    //     delete this
    // }

    double Sine::currentAngle() {
        return angle;
    }

    double Sine::currentHeight() {
        double height;
        height = amplitude * std::sin((2 * M_PI * degreeToRadian(angle)) / degreeToRadian(wavelength));
        return height;
    }

    Sine& Sine::operator++() {
        angle += increment;
        return *this;
    }

    //SEGMENTATION FAULT WHEN USED IN LINE ie. cout << s++ << endl
    Sine& Sine::operator++(int) {
        Sine old = *this;
        operator++();
        return old;
    }

    std::ostream& operator<<(std::ostream& output, Sine s) {
        output << s.angle << ", " << s.currentHeight();
        return output;
    }

    double Sine::degreeToRadian(double degree) {
        return degree * (M_PI / 180);
    }

