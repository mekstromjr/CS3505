#include <iostream>

using std::cout;
using std::endl;


int main() {
    int* val = new int[4] { };
    int* same_mem = val;

    std::cout << val << " " << same_mem << std::endl;
    delete [] val;
}