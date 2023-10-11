/**
 * 
*/
#ifndef ROUTE_H
#define ROUTE_H

#include <string>
#include "Driver.h"
#include "ScheduleEntry.h"

class Route {
    private:
        std::string routeName_;
        int routeNumber_;
        Driver driver_;
        Bus bus_;
    
    public:
        Route(); // Default Route - ie. none
        Route(std::string name, int number);
        Route(std::string name, int number, Bus bus);
        Route(std::string name, int number, Bus bus, Driver driver);
        Route(const Route& other);
        ~Route();
        Route& operator=(Route other);
        /// @brief Assign a new bus to this route
        /// @param newBus 
        /// @return A schedule entry with the start and stop time of the switch
        ScheduleEntry changeBus(Bus newBus); 
        bool changeDriver(Driver newDriver);
        


};

#endif