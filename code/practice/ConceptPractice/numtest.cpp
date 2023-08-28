#include <iostream>

using namespace std;

int main() {

    int a = 1,b = 2,c = 3;
    cout << a << "\t" << b << "\t" << c << endl;
    a = b = c;
    cout << a << "\t" << b << "\t" << c << endl;

    return 0;
}