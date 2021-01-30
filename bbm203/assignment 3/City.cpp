//
// Created by berke on 7.12.2020.
//

#include "City.h"

City::City(std::string name) : packages(), trucks(), _name(name) {

}

std::string City::Name() {
    return _name;
}
