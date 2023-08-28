#include <iostream>
using std::cout;
using std::cin;
using std::endl;


void changeIt(int* num) {
    *num *= 2;
}

void changeIt(int num) {
    num *= 2;
}

int main() {
    const int num = 1;
    changeIt(num);
}