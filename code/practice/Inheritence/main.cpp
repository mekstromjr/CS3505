
#include "Animal.h"
#include "Cat.h"
int main() {
    Animal animal {10};
    Cat cat {9, 1};
    animal.talk();
    cat.talk();

    //Slicing, lives is lost and implementation of cat.talk() is also lost
    animal = cat;
    animal.talk();

    //Avoid slicing, pass the reference and have the functions declared as virtual. Virtual means
    //c++ uses a v-table to determine the behavior of the function at runtime.
    Animal* animalptr = &cat;
    animalptr->talk();
    
    return 0;
}