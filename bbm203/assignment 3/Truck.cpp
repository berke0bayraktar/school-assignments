//
// Created by berke on 7.12.2020.
//

#include "Truck.h"

std::string Truck::Weight() {
    return _weight;
}

Truck::Truck(std::string id, std::string weight) : Package(id), _weight(weight) {

}

Truck::Truck() : Package(), _weight() {

}
