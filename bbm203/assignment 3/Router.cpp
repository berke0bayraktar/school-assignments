//
// Created by berke on 7.12.2020.
//

#include "Router.h"


void Router::ExecuteMission(std::string start, std::string midway, std::string target,
                            int numAddedPackagesStart,
                            int numAddedPackagesMidway, Queue<int> *packagesToLeaveMidway) {

    // alias required cities
    City* startCity = FindCityByName(start);
    City* midwayCity = FindCityByName(midway);
    City* targetCity = FindCityByName(target);

    List<Package> truck;

    StartStation(startCity, numAddedPackagesStart, &truck);
    MidwayStation(midwayCity, numAddedPackagesMidway, packagesToLeaveMidway, &truck);
    TargetStation(targetCity, &truck);


}

void Router::StartStation(City* startCity, int numAddedPackagesStart, List<Package>* truck) {
    // decide which truck we should use when starting
    Truck t;
    startCity->trucks.getFront(t);
    startCity->trucks.dequeue();

    // append the truck it self as first element
    truck->append(t);

    // take all the needed packages from start
    for(int i=0; i<numAddedPackagesStart; i++) {
        Package p;
        startCity->packages.getTop(p);
        startCity->packages.pop();
        truck->append(p);
    }
}

void Router::MidwayStation(City* midwayCity, int numAddedPackagesMidway,
                           Queue<int>* packagesToLeaveMidway, List<Package>* truck) {

    // take all the needed packages from midway
    for(int i=0; i < numAddedPackagesMidway; i++) {
        Package p;
        midwayCity->packages.getTop(p);
        midwayCity->packages.pop();
        truck->append(p);
    }

    // drop the specified packages
    int numPackagesToBeDropped = packagesToLeaveMidway->size();

    int indexesToRemove[numPackagesToBeDropped];

    for(int i=0; i<numPackagesToBeDropped; i++) {
        int idx;
        packagesToLeaveMidway->getFront(idx);
        packagesToLeaveMidway->dequeue();
        Package p;
        truck->at(idx+1, &p);
        indexesToRemove[i] = idx+1;
        midwayCity->packages.push(p);
    }

    std::sort(indexesToRemove, indexesToRemove+numPackagesToBeDropped);

    for(int i=numPackagesToBeDropped-1; i>=0; i--) {
        int indexToRemove = indexesToRemove[i];
        truck->remove(indexToRemove);
    }
}

void Router::TargetStation(City* targetCity, List<Package>* truck) {
    // leave all left packages to target city

    int numPackagesLeft = truck->size()-1;
    for(int i=0; i<numPackagesLeft; i++) {
        Package p;
        truck->at(1, &p);
        truck->remove(1);
        targetCity->packages.push(p);
    }

    // leave truck
    Truck head;
    truck->at(0, &head);
    Truck* truckNode = dynamic_cast<Truck*>(&head);
    targetCity->trucks.enqueue(*truckNode);
}

std::string Router::Report() {
    std::string report;

    for (int i=0; i < cities.size(); i++) {
        std::string cityName = cities[i]->Name();

        report.append(cityName).append("\n")
        .append("Packages:").append("\n");

        City* currCity = FindCityByName(cityName);

        while (!currCity->packages.isEmpty()) {
            Package p;
            currCity->packages.getTop(p);
            report.append(p.Id()).append("\n");
            currCity->packages.pop();
        }

        report.append("Trucks:").append("\n");

        while (!currCity->trucks.isEmpty()) {
            Truck t;
            currCity->trucks.getFront(t);
            report.append(t.Id()).append("\n");
            currCity->trucks.dequeue();
        }
        report.append("-------------").append("\n");
    }
    return report;
}

City *Router::FindCityByName(std::string& cityName) {
    for(int i=0; i < cities.size(); i++) {
        City* currCity = cities[i];
        if (currCity->Name() == cityName) {
            return currCity;
        }
    }
    return nullptr;
}
