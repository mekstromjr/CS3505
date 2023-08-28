#include <iostream>
#include <cmath>
using namespace std;


int main() {
    


}

class myClass {
    public:
    int count;
    myClass() {
        count = 0;
    }
    bool changeIt(int delta) {
        count += delta;
        return true;
    }
};