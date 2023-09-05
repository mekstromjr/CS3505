#include <iostream>

class Cat {

    private:
        int lives{9};

    public:
        Cat() : lives(10) { }
        Cat(int startLives) : lives(startLives) { }

        void reportLives() {
            std::cout << "Lives Remaining: " << lives << std::endl;
        }

        void loseLife() {
            lives--;
        }

        Cat& operator+=(int increment) {
            lives += increment;
            return *this;
        }

        Cat& operator/(int amount) {
            lives /= amount;
            return *this;
        }


};


int main() {
    Cat cat;
    cat.reportLives();
    cat.loseLife();
    cat.reportLives();

    (cat += 1) += 1;
    cat.reportLives();

    Cat newCat = cat / 3;
    newCat.reportLives();
    return 0;
}