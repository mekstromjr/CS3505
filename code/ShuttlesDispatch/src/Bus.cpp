
#include "Bus.h"

Bus::Bus() : Vehicle(), driver_(Driver()), route_(Route()) { }

Bus::Bus(int number) : Vehicle(number), driver_(Driver()), route_(Route()) { }

Bus::Bus(int number, std::string location) : Vehicle(number, location), driver_(Driver()), route_(Route()) { }

Bus& Bus::operator=(Bus other) {
    std::swap(number_, other.number_);
    std::swap(location_, other.location_);
    std::swap(driver_, other.driver_);
    std::swap(route_, other.route_);

    return *this;
}