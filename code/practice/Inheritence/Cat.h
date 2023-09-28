#ifndef CAT_H
#define CAT_H

#include "Animal.h"

class Cat : public Animal {
    private:
        int lives_;

    public:
        Cat(int lives, int age);
        virtual void talk();
};

#endif