#include <iostream>
#include <cmath>

using std::pow;
using std::cout;
using std::cin;
using std::endl;

int main() {
    double num(0);
    cout << "Enter highest power of 2 to start sumation: ";
    int maxPow2(0);
    cin >> maxPow2;
    cout << maxPow2 << endl;
    int powsOf2(maxPow2);
    int bin[11] { };
    for(int i = 0; i < powsOf2; i++) {
        if(i == 11) {
            cout << "--end of fraction bits--" << endl;
            for(int j = 0; j < 11; j++)
                cout << bin[j] << " ";
            cout << endl;
        }
        cout << "+2^" << maxPow2 << "\t";
        if(num + pow(2, maxPow2) <= 10000) {
            num += pow(2,maxPow2);
            if(i < 11) {
                bin[i] = 1;
            }
            cout << "1\t";
        } else {
            cout << "0\t";
        }
        maxPow2--;
        cout << num << endl;
    }


    cout << endl;

    return 0;
}