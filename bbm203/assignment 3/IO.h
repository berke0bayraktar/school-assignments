//
// Created by berke on 7.12.2020.
//

#ifndef ASSIGNMENT3_IO_H
#define ASSIGNMENT3_IO_H

#include <string>
#include <sstream>
#include <fstream>
#include "Queue.h"

class IO {
    std::ifstream missionFile;
public:
    void Start(std::string MISSION_PATH);
    int GetMission(std::string* start, std::string* midway, std::string* target, int* numAddedPackagesStart, int* numAddedPackagesMidway, Queue<int>* packagesToLeaveMidway);
    void End(std::string report, std::string RESULT_PATH);

    static void GetCities(Queue<std::string>* cities, std::string CITY_PATH);
    static void GetPackages(Queue<std::string>* packages, Queue<std::string>* cities, std::string PACKAGE_PATH);
    static void GetTrucks(Queue<std::string>* trucks, Queue<std::string>* cities, Queue<std::string>* weights, std::string TRUCK_PATH);
};


#endif //ASSIGNMENT3_IO_H
