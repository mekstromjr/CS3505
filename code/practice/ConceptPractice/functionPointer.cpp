#include<iostream>
using std::cout;
using std::endl;

void operation(int, int, int&, void (*op)(int,int,int&));
void multiplication(int, int, int&);
void division(int, int, int&);

int main() {
    int x(9);
    int y(3);
    int result(0);
    operation(x,y,result,multiplication);
    cout << "x * y = " << result << endl;
    operation(x,y,result,division);
    cout << "x / y = " << result << endl;

    return 0;
}


void operation(int x, int y, int& result, void (*op)(int,int, int&)) {
    (*op)(x,y,result);
}

void multiplication(int x, int y, int& result) {
    result = x * y;
}

void division(int x, int y, int& result) {
    result = x / y;
}