#include <iostream>
using namespace std;
//Practicing with c++ variable initialization types
class myObject {
    public :
        int a, b;

        myObject() : a(0), b(0) { }
        myObject(int num1, int num2) {
            a = num1;
            b = num2;
        }
};


int main() {
    //c-like initialization
    myObject cLike = myObject(1,2);
    cout << cLike.a << "\t" << cLike.b << endl;

    //Constructor initialization
    myObject constructor(1,2);
    cout << constructor.a << "\t" << constructor.b << endl;

    //Uniform Initialization
    myObject uniform{1,2};
    cout << uniform.a << "\t" << uniform.b << endl;
    return 0;
}