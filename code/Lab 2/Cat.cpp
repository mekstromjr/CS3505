#include <iostream>

class Cat {

    private:
        int lives = 9000;
        int myVar = 10;

    public:
        Cat(int startLives, int more) : lives(startLives), myVar(more) { }

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


};


int main() {
    Cat cat(9, 10);
    cat.reportLives();
    cat.loseLife();
    cat.reportLives();

    (cat += 1) += 1;
    cat.reportLives();
    return 0;
}