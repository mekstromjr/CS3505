#include "Cat.h"

Cat::Cat(int lives, int age): Animal(age), lives_(lives) {

}

void Cat::talk() {
    std::cout << "I am your supreme overlord" << std::endl;
}