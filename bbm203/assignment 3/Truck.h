//
// Created by berke on 7.12.2020.
//

#ifndef ASSIGNMENT3_TRUCK_H
#define ASSIGNMENT3_TRUCK_H


#include "Package.h"

class Truck : public Package {
private:
    std::string _weight;
public:
    Truck(std::string id, std::string weight);
    Truck();
    std::string Weight();
};


#endif //ASSIGNMENT3_TRUCK_H
