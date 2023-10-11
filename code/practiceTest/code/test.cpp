#include "Grades.h"
#include <iostream>
using std::cout;
using std::endl;

void printGrades(Grades g) {
    cout << g.grade1 << " " << g.grade2 << endl;
}

void negate(int* input) {
    (*input) *= -1;
}

int main() {
    int val = 5;
    negate(&val);
    cout << val << endl;
    double startG1[2] {1.0, 2.0};
    double startG2[2] = {3.0, 4.0};
    Grades g1(startG1);
    Grades g2(startG2);
    Grades g3 = g1 + g2;
    printGrades(g1);
    printGrades(g2);
    printGrades(g3);
    return 0;
}