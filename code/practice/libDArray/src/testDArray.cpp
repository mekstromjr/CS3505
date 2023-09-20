#include "DArray.h"
#include <iostream>


int main() {
    DArray arr(100);
    DArray arr2(5);
    DArray arr3(11);
    
    for(int i = 0; i < 5; i++) 
        arr2[i] = i;
    

    
    for(int i = 0; i < 11; i++) 
        arr3[i] = i;
    

    for(int i = 0; i < 100; i++)
        arr[i] = i;
    
    arr = arr2;
    arr2 = arr3;;

    std::cout << arr << std::endl;
    std::cout << arr.size() << std::endl;

    std::cout << arr2 << std::endl;
    std::cout << arr2.size() << std::endl;

    return 0;
}