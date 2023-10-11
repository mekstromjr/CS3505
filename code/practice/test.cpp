#include <iostream>
#include <cmath>
#include <map>
#include <vector>
using namespace std;

class Resource { 
public:
    int* val;
    Resource(int number) : val(new int(number)) {

    }

    Resource(const Resource& other) {
        val = new int(*other.val);
    }

    ~Resource() {
        delete val;
    }

    Resource operator+(const Resource& other) {
        return Resource((*other.val) + (*val));
    }

    Resource doubleIt(Resource input) {
        return input + input;
    }

    void print() {
        cout << *val << endl;
    }
};



int main() {
    int *z = new int;
    (*z) = 1;
    int *y = z;
    (*z) = (*z) + 1;
    int x = (*y);
    x++;
    (*y) = (*y) + 1;

    cout << "x: " << x << " y: " << *y << " z: " << *z << endl;
    delete z;
    return 0;
}
