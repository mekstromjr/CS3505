#include <iostream>

using namespace std;

int* getIntPtr() {
    int number = 5;
    int* ptr = &number;
    return ptr;
}

int main() {
  int* val = new int[4];
  val[0] = 0;
  val[1] = 1;
  val[2] = 2;
  val[3] = 3;
  
  int* same_mem = val;

  cout << "val/same_mem: " << val << " " << same_mem << endl;


  int* ptr = getIntPtr();
  cout << "ptr: " << ptr << " " << *ptr << endl;

  delete [] val;
}

