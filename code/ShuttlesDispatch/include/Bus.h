/**
 * 
*/
#ifndef BUS_H
#define BUS_H

#include "Vehicle.h";
#include "Driver.h";
#include "Route.h";

class Bus : Vehicle {
    private:
        Route route_;
        Driver driver_;

    public:
        Bus();
        Bus(int number);
        Bus(int number, std::string location);
        Bus(int number, std::string location, std::string notes);
        Bus(const Bus& other);
        ~Bus();
        Bus& operator=(Bus other);


};

#endif