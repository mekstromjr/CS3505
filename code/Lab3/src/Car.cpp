#include <iostream>
#include "Car.h"

Car::Car(double speed): speed(speed) {}

void Car::drive() {
    std::cout << "Boostin' " << speed << " mph." << std::endl;
}

void Car::slow() {
    speed /= 2;
}

void Car::speedUp() {
    speed *= 1.5;
}

