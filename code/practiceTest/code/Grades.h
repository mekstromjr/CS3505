#ifndef GRADES_H
#define GRADES_H
class Grades {
    public:
        double grade1, grade2;
        Grades(double grades[2]);
        Grades operator+(const Grades& other);
};
#endif