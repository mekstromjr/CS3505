/**
 * 
*/
#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>;
#include "Driver.h";

class Vehicle {
    private:
        const int number_;
        std::string location_;
        Driver driver_;
        std::string notes_;
    
    public:
        Vehicle();
        Vehicle(int number);
        Vehicle(int number, std::string location, Driver driver);
        Vehicle(int number, std::string location, Driver driver, std::string notes);
        Vehicle(const Vehicle& other);
        ~Vehicle();
        Vehicle& operator=(Vehicle other);



};

#endif