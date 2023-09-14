#include <iostream>

using namespace std;

void print(int t0,int t1, int t2, int t3, int t4, int s0, int s1) {
    cout << "t0: " << t0 << endl;
    cout << "t1: " << t1 << endl;
    cout << "t2: " << t2 << endl;
    cout << "t3: " << t3 << endl;
    cout << "t4: " << t4 << endl;
    cout << "s0: " << s0 << endl;
    cout << "s1: " << s1 << endl;
    cout << "----------" << endl;
    
}

int main() {
    int uid = 18;

    int t0, t1, t2, t3, t4, s0, s1;
    t0 = t1 = t2 = t3 = t4 = s0 = s1 = 0;
    s0 = uid;
    t1 = 6;
    t2 = 1;
    t3 = 0;
    print(t0,t1,t2,t3,t4,s0,s1);
    t4 = s0 + t1;
    t3 = t3 - t2;
    s0 = s0 + s0;
    print(t0,t1,t2,t3,t4,s0,s1);
    int count = 0;
    loop:
        count++;
        t3 = t3 + t2;
        s0 = s0 - t1;
        (s0 < 0) ? t0 = 1: t0 = 0;
        print(t0,t1,t2,t3,t4,s0,s1);
        if(t0 == 0) {
            // cout << "loop" << endl;
            goto loop;
        }

    s1 = t3;
    print(t0,t1,t2,t3,t4,s0,s1);
    // cout << "count: " << count << endl;
    cout << "s1: " << s1;
    return 0;
}