
#ifndef DISPATCH_MODEL_H
#define DISPATCH_MODEL_H

#include <vector>
#include "Bus.h"
#include "Driver.h"
#include "Route.h"
#include "Vehicle.h"


class DispatchModel {
        std::vector<Route> routes_;
        std::vector<Vehicle> vehicles_;
        std::vector<Driver> drivers_;

    public:
        DispatchModel(std::vector<Route> routes, std::vector<Vehicle> vehicles, std::vector<Driver> drivers);
        std::vector<Vehicle> getAllVehicles(); 
        std::vector<Bus> getAllBuses();
        std::vector<Bus> getActiveBuses(); // Buses on Route
        std::vector<Route> getAllRoutes();
        std::vector<Route> getActiveRoute(); // Routes currently running
        std::vector<Driver> getAllDrivers();
        std::vector<Driver> getActiveDrivers(); // Drivers on Route
        bool changeDriver(Route route, Driver newDriver);
        bool changeBus(Route route, Bus newBus);


};
#endif