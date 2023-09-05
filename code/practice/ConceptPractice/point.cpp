#include <iostream>

using std::cout;
using std::endl;

class Point;

int main() {
    Point p1(1,2);// Note Point p1() the compiller thinks you are pre-declaring a function p1 with no params and returns a point.
    Point* p1Ptr = &p1;
    p1.print();
    Point p2 = *p1Ptr * 3.0;
    p2.print();
    return 0;
}

class Point {
    private:
        double x,y;
    public:
        Point() : x(0), y(0){
        }
        Point(double initX, double initY) : x(initX), y(initY) {
        }

        double getX() { return x; }
        double getY() { return y; }
        void setX(double newX) { x = newX; }
        void setY(double newY) { y = newY; }

        void print() {
            cout << "(" << this->x << ", " << this->y << ")" << endl; 
        }

        Point operator*(double scaler) {
            return Point(this->x * scaler, this->y * scaler);
        }
 
}; //Don't forget the ';'
