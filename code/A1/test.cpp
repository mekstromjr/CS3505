#include <iostream>
#include <cmath>

using std::cout;
using std::scanf;
using std::endl;
using std::string;
using std::pow;


int main() {
    long num = pow(2, 32) - 1170312;
    cout << num << "/2"<< endl;
    int biArr[32] { };
    int index = 31;
    while(num > 0) {
        biArr[index] = num % 2;
        num /= 2;
        cout << num << "/2" << endl;
        index--;
    }

    for(int i = 0; i < 32; i++)
        cout << biArr[i];

    cout << endl;
    return 0;
}