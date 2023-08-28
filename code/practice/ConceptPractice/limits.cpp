#include <limits>
#include <iostream>

using namespace std;

int main() {
    cout << "Numeric Limits of C++ Fundemental Types" << endl;
    cout << "Type\tLimit" << endl;
    cout << "char\t " << (int)numeric_limits<char>::max() << endl;
    cout << "char32_t \t" << numeric_limits<char32_t>::max() << endl;
    cout << "short\t " << numeric_limits<short>::max() << endl;
    cout << "int\t " << numeric_limits<int>::max() << endl;
    cout << "long\t " << numeric_limits<long>::max() << endl;
    cout << "long long\t " << numeric_limits<long long>::max() << endl;
    cout << "float\t " << numeric_limits<float>::max() << endl;
    cout << "double\t " << numeric_limits<double>::max() << endl;
    cout << "long double\t " << numeric_limits<long double>::max() << endl;
    cout << "bool\t " << numeric_limits<bool>::max() << endl;

    return 0;
}