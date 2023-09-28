#include "Animal.h"

Animal::Animal(int age): age_(age) {

}

void Animal::talk() {
    std::cout << "Animal Noise" << std::endl;
}