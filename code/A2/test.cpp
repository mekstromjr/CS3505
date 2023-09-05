#include <iostream>
#include <cmath>

using std::cout;
using std::endl;
using std::sin;



double degreeToRadian(double degree) {
        return degree * (M_PI / 180);
}

double getHeight(double angle) {
    double height(0), amplitude(1), wavelength(360), tmp(0);
    tmp = (2 * M_PI * degreeToRadian(angle)) / degreeToRadian(wavelength);
    height = amplitude * sin(tmp);
    return height;
}

int main() {
    for(int i = 0; i < 181; i++)
        cout << i << " " << getHeight(i) << endl;

    return 0;
}