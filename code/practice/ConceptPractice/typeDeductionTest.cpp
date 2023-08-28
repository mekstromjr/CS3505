#include <iostream>

using namespace std;
//Practicing using the type deduction keywords
int main() {

    string s("abcd");
    auto d(s);

    cout << "s: " << s << endl;
    cout << "d: " << d << endl;

    decltype(s) v("haha");
    cout << "v: " << v << endl;

    return 0;
}