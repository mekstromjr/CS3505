
#ifndef THREE_TUPLE_H
#define THREE_TUPLE_H

class ThreeTuple {
    public:
        int distanceAtStart; // in miles
        int distanceAtEnd; // in miles
        int avgSpeed; // In mph
        ThreeTuple(int fromStart, int fromEnd, int avgSpd);
        ThreeTuple(const ThreeTuple& other);
        ~ThreeTuple();

};

#endif