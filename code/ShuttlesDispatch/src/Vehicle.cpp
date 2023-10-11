
#include "Vehicle.h"

Vehicle::Vehicle(): number_(0), location_("Bus Lot"), notes_() { }

Vehicle::Vehicle(int number): number_(number), location_("Bus Lot"), notes_() { }

Vehicle::Vehicle(int number, std::string location): number_(number), location_(location), notes_() { }

Vehicle::Vehicle(int number, std::string location, std::string notes): number_(number), location_(location), notes_(notes) { }

Vehicle::Vehicle(const Vehicle& other) {
    number_ = other.number_;
    location_ = other.location_;
    notes_ = other.notes_;
}

Vehicle::~Vehicle() { };

Vehicle& Vehicle::operator=(Vehicle other) {
    std::swap(number_, other.number_);
    std::swap(location_, other.location_);
    std::swap(notes_, other.notes_);
    return *this;
}