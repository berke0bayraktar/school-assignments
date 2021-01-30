//
// Created by berke on 7.12.2020.
//

#ifndef ASSIGNMENT3_ROUTER_H
#define ASSIGNMENT3_ROUTER_H

#include <vector>
#include <unordered_map>
#include "City.h"
#include <algorithm>
#include "List.h"

class Router {
private:
    void StartStation(City *startCity, int numAddedPackagesStart, List<Package> *truck);

    void MidwayStation(City *midwayCity, int numAddedPackagesMidway,
                       Queue<int> *packagesToLeaveMidway, List<Package> *truck);

    void TargetStation(City *targetCity, List<Package> *truck);


public:
    std::vector<City*> cities;

    void ExecuteMission(std::string start, std::string midway, std::string target,
                        int numAddedPackagesStart, int numAddedPackagesMidway,
                        Queue<int>* packagesToLeaveMidway);
    City* FindCityByName(std::string& cityName);
    std::string Report();
};


#endif //ASSIGNMENT3_ROUTER_H
