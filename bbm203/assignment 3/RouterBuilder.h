//
// Created by berke on 7.12.2020.
//

#ifndef ASSIGNMENT3_ROUTERBUILDER_H
#define ASSIGNMENT3_ROUTERBUILDER_H

#include "Router.h"

class RouterBuilder {
private:
    static void ImportCities(Router& router, std::string CITY_PATH);
    static void ImportPackages(Router& router, std::string PACKAGE_PATH);
    static void ImportTrucks(Router& router, std::string TRUCK_PATH);
public:
    static void Build(Router& router, std::string CITY_PATH, std::string PACKAGE_PATH, std::string TRUCK_PATH);
};


#endif //ASSIGNMENT3_ROUTERBUILDER_H
