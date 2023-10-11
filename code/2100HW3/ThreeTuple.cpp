
#include "ThreeTuple.h"

ThreeTuple::ThreeTuple(int fromStart, int fromEnd, int avgSpd) : distanceAtStart(fromStart), distanceAtEnd(fromEnd), avgSpeed(avgSpd) {

}

ThreeTuple::ThreeTuple(const ThreeTuple& other) {
    distanceAtStart = other.distanceAtStart;
    distanceAtEnd = other.distanceAtEnd;
    avgSpeed = other.avgSpeed;
}

ThreeTuple::~ThreeTuple() {
    
}