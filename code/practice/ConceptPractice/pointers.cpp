#include<iostream>

using std::cout;
using std::endl;
//Const pointer - Can be modified, but when dereferenced, the data cannot be modified.
//  ie. You can change where the pointer is pointing, but you can't change what's at that location.
int main() {
    int x,y;
    int* xPtr = &x;
    int* yPtr = &y;
    *xPtr = 10;
    (*xPtr++)++;//??????
    *yPtr = 11;
    
    int arr[10]; 
    int* arrPtr = arr;

    for (int i = 0; i < 10; i++) 
        arrPtr[i] = i;
    
    cout << "xPtr = " <<  xPtr << "\t->\t" << *xPtr << endl;
    cout << "yPtr = " << yPtr << "\t->\t" << *yPtr << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    return 0;
}


/*
int x;
      int *       p1 = &x;  // non-const pointer to non-const int
const int *       p2 = &x;  // non-const pointer to const int
      int * const p3 = &x;  // const pointer to non-const int
const int * const p4 = &x;  // const pointer to const int 
*/