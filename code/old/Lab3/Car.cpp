#include "Car.h"
#include <iostream>
using namespace std;

  Car::Car(double startSpeed) {
    speed = startSpeed;
  }

  void Car::drive() {
    std::cout << "Zooming " << speed << " mph."<< std::endl;
  }

  void Car::slow() {
    speed = speed / 2;
  }

  void Car::speedUp() {
    speed = speed * 1.5;
  }