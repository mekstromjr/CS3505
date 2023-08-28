#include <iostream>

using std::cout;
using std::scanf;
using std::endl;
using std::string;


int main() {
    int num = 19;
    int biArr[8] { };
    int index = 7;
    while(num > 0) {
        biArr[index] = num % 2;
        num /= 2;
        index--;
    }

    for(int i = 0; i < 8; i++)
        cout << biArr[i];

    cout << endl;
    return 0;
}