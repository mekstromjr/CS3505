#ifndef Car_H
#define Car_H

class Car {
    double speed;
    
    
    public:    
        Car(double speed);

        void speedUp();
        void slow();
        void drive();

};
#endif