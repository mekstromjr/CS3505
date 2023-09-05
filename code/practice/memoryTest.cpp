#include <iostream>

using std::cout;
using std::endl;

int* getArrayPointer(int arrSize) {
    int arrPtr[arrSize];
    for(int i = 0; i < arrSize; i++)
        arrPtr[i] = i;
    return arrPtr;
}


int main() {
    int arrSize(10);
    int* ptr = getArrayPointer(arrSize);
    int arr[arrSize] { };
    for(int i = 0; i < arrSize; i++)
        cout << ptr[i] << " ";

    for(int i = 0; i < arrSize; i++)
        cout << arr[i] << " ";
    

    return 0;
}