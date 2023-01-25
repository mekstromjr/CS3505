#include "./Carlib/include/Car.h"
// #include <iostream>
// using namespace std;

int main() {
  Car myCar(10.0);
  myCar.drive();
  myCar.slow();
  myCar.drive();
  return 0;
}