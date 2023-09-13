#include <iostream>
#include <cmath>

using std::pow;
using std::cout;
using std::cin;
using std::endl;

int main() {
    float f = 0;
    int i = 0;

    while(true) {
        
        if((int)f != i) {
            cout << "f: " << f << "\ti: " << i << endl;
            break;
        }

        i++;
        f++;
    }

    return 0;
}