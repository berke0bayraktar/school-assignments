//
// Created by berke on 7.12.2020.
//

#include "Package.h"

std::string Package::Id() {
    return _id;
}

Package::Package(std::string id) : _id(id) {

}

Package::Package() : _id(std::string()) {

}
