/**
* Michael Ekstrom
* CS3505
* A2: Making a Class
*/
#include "Sine.h"
#include <cmath>

    Sine::Sine(double amplitude, double wavelength, double increment) : angle(0),
        amplitude(amplitude), wavelength(wavelength), increment(increment) {
    }

    Sine::~Sine() { }

    double Sine::currentAngle() {
        return angle;
    }

    double Sine::currentHeight() {
        double height;
        height = amplitude * std::sin((2 * M_PI * convertDegreeToRadian(angle)) / convertDegreeToRadian(wavelength));
        return height;
    }

    Sine& Sine::operator++() {
        angle += increment;
        return *this;
    }

    Sine Sine::operator++(int) {
        Sine old(*this);
        operator++();
        return old;
    }

    std::ostream& operator<<(std::ostream& output, Sine s) {
        output << s.angle << ", " << s.currentHeight();
        return output;
    }

    double Sine::convertDegreeToRadian(double degree) {
        return degree * (M_PI / 180);
    }

