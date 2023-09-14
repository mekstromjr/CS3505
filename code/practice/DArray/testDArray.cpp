#include "DArray.h"
#include <iostream>


int main() {
    DArray arr(100);

    for(int i = 0; i < 100; i++)
        arr[i] = i;
    

    std::cout << arr << std::endl;
    std::cout << arr.size() << std::endl;

    return 0;
}