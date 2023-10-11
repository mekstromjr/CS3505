/**
 * 
*/
#ifndef DRIVER_H
#define DRIVER_H

#include <string>
#include <iostream>

class Driver {
    private:
        std::string driverID_; //ie. seiara number
        std::string name_;

    public:
        Driver();
        Driver(std::string driverID, std::string name);
        Driver(const Driver& other);
        Driver& operator=(Driver other);
        ~Driver();
        friend std::ostream& operator<<(std::ostream& output, Driver s);

};

#endif