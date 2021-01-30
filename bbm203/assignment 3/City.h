//
// Created by berke on 7.12.2020.
//

#ifndef ASSIGNMENT3_CITY_H
#define ASSIGNMENT3_CITY_H


#include "Stack.h"
#include "Package.h"
#include "Queue.h"
#include "Truck.h"

class City {
private:
    std::string _name;
public:
    Stack<Package> packages;
    Queue<Truck> trucks;
    City(std::string name);
    std::string Name();
};


#endif //ASSIGNMENT3_CITY_H
