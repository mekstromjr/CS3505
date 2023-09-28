
#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>
class Animal {
    private:
        int age_;
    public:
        Animal(int age);
        virtual void talk();
};
#endif