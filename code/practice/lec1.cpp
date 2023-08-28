#include <iostream>
using namespace std;

bool isEven(int num);

bool isOdd(int num) {
    if(num == 0) return false;
    return isEven(num-1);
}


bool isEven(int num) {
    if(num == 0) return true;
    return isOdd(num-1);
}


int main() {
    int num(0);
    cout << "Enter a number [0-inf]" << endl;
    cin >> num;
    cout << isOdd(num);
}
