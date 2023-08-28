#include <iostream>

using namespace std;

//function declarations
int add(int, int);
int sub(int a, int b);
void refAdd(int&, int&, int&);
void refSub(int& a, int& b, int& result);
void square(int&);
void exp(int& num, int exp = 1);

int main() {
    int a = 10, b = 4, result = 0;
    cout << "a: " << a << " b: " << b << endl;

    cout << "a+b="  << add(a,b) << endl;
    cout << "a-b=" << sub(a,b) << endl;

    cout << "square it!" << endl;
    square(a);
    square(b);
    cout << "a: " << a << " b: " << b << endl;

    refAdd(a,b,result);
    cout << "a+b=" << result << endl;
    refSub(a,b,result);
    cout << "a-b=" << result << endl;
    exp(a);

    return 0;
}

//function definitions
int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

//Pass by reference examples
void refAdd(int& a, int& b, int& result) {
    result = a + b;
}

void refSub(int& a, int& b, int& result) {
    result = a - b;
}

void square(int& num) {
    num *= num;
}

//Default value for a parameter example.
void exp(int& num, int exp = 1) {
    if(exp == 0) {
        num = 1;
        return;
    }
    int tmp = num;
    for(int i = 1; i < exp; i++)
        num *= tmp;
}