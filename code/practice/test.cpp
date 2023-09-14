#include <iostream>
#include <cmath>
using namespace std;


int main() {
    cout << "Enter a Number" << endl;
    int i(0);
    if((cin >> i)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}
