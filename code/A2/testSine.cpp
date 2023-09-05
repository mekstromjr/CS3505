/**
* Michael Ekstrom
* CS3505
* A2: Making a Class
*/

#include "Sine.h"
#include <iostream>

using std::cout;
using std::endl;

const double ITERATIONS = 360;
const double AMPLITUDE = 36;
const double WAVELENGTH = 180;
const double INCREMENT = 0.5;

int main() {
    Sine sin(AMPLITUDE, WAVELENGTH, INCREMENT);
    for(int i = 0; i <= ITERATIONS; i++) {
        cout << sin++ << endl;
    }

    return 0;
}