#include "Grades.h"


Grades::Grades(double grades[2]) : grade1(grades[0]), grade2(grades[1]) {

}


Grades Grades::operator+(const Grades& other) {
    double grades[2] { };
    grades[0] = grade1 + other.grade1;
    grades[1] = grade2 + other.grade2;
    return Grades(grades);
}