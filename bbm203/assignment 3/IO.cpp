//
// Created by berke on 7.12.2020.
//

#include "IO.h"

void IO::GetCities(Queue<std::string>* cities, std::string CITY_PATH) {
    std::ifstream cityFile(CITY_PATH);
    std::string cityName;

    while (getline(cityFile, cityName)) {
        cities->enqueue(cityName);
    }
}

void IO::GetPackages(Queue<std::string>* packages, Queue<std::string>* cities, std::string PACKAGE_PATH) {
    std::ifstream cityFile(PACKAGE_PATH);
    std::string package_city;

    while (getline(cityFile, package_city)) {
        std::istringstream iss(package_city);

        std::string package, city;
        iss >> package >> city;

        packages->enqueue(package);
        cities->enqueue(city);
    }
}

void IO::GetTrucks(Queue<std::string>* trucks, Queue<std::string>* cities, Queue<std::string>* weights, std::string TRUCK_PATH) {
    std::ifstream cityFile(TRUCK_PATH);
    std::string truck_city_weight;

    while (getline(cityFile, truck_city_weight)) {
        std::istringstream iss(truck_city_weight);

        std::string truck, city, weight;
        iss >> truck >> city >> weight;

        trucks->enqueue(truck);
        cities->enqueue(city);
        weights->enqueue(weight);
    }
}

void IO::Start(std::string MISSION_PATH) {
    missionFile.open(MISSION_PATH);
}

int IO::GetMission(std::string *start, std::string *midway, std::string *target, int *numAddedPackagesStart,
                   int *numAddedPackagesMidway, Queue<int> *packagesToLeaveMidway) {
    std::string mission;
    if (getline(missionFile, mission)) {
        std::istringstream params(mission);
        std::string param;
        int i=0;
        while(getline(params, param, '-')) {
            switch (i) {
                case 0:
                    *start = param;
                    break;
                case 1:
                    *midway = param;
                    break;
                case 2:
                    *target = param;
                    break;
                case 3:
                    *numAddedPackagesStart = std::stoi(param);
                    break;
                case 4:
                    *numAddedPackagesMidway = std::stoi(param);
                    break;
                case 5:
                    std::istringstream iss(param);
                    std::string indexStr;
                    while (getline(iss, indexStr, ',')) {
                        int index = std::stoi(indexStr);
                        packagesToLeaveMidway->enqueue(index);
                    }
                    break;
            }
            i++;
        }
        return 1;
    }
    return 0;
}

void IO::End(std::string report, std::string RESULT_PATH) {
    std::ofstream outputFile(RESULT_PATH);
    outputFile << report;
    outputFile.close();
    missionFile.close();
}
