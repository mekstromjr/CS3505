/**
 * 
*/
#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>;
#include "Driver.h";

class Vehicle {
    protected:
        int number_;
        std::string location_;
        std::string notes_;
    
    public:
        Vehicle();
        Vehicle(int number);
        Vehicle(int number, std::string location);
        Vehicle(int number, std::string location, std::string notes);
        Vehicle(const Vehicle& other);
        ~Vehicle();
        virtual Vehicle& operator=(Vehicle other);



};

#endif