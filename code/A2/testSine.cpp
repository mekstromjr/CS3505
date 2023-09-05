
#ifndef SINE_H
#define SINE_H
    #include "Sine.h"
#endif

#ifndef IO_STREAM
#define IO_STREAM
    #include <iostream>
#endif

using std::cout;
using std::endl;
using std::string;

const int ITERATIONS = 360;
const int AMPLITUDE = 1;
const int WAVELENGTH = 360;
const int INCREMENT = 1;

int main() {
    Sine s(AMPLITUDE, WAVELENGTH, INCREMENT);
    cout << "(x, y)" << endl;
    for(int i = 0; i < ITERATIONS; i++) {
        cout << s << endl;
        s++;
    }

    cout << s << endl;

    return 0;
}