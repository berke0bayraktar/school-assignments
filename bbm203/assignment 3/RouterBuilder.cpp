//
// Created by berke on 7.12.2020.
//

#include "RouterBuilder.h"
#include "IO.h"

void RouterBuilder::Build(Router& router, std::string CITY_PATH, std::string PACKAGE_PATH, std::string TRUCK_PATH) {
    /* this function will need:
     * 1 - cities
     * 2 - packages at cities
     * 3 - trucks at cities */

    ImportCities(router, CITY_PATH);
    ImportPackages(router, PACKAGE_PATH);
    ImportTrucks(router,TRUCK_PATH);

}

void RouterBuilder::ImportCities(Router& router, std::string CITY_PATH) {
    Queue<std::string> cities;
    IO::GetCities(&cities, CITY_PATH);

    while (!cities.isEmpty()) {
        std::string city;
        cities.getFront(city);

        City* newCity = new City(city);
        //router.insertionOrder.enqueue(city);
        //router.cities.insert({city, newCity});
        router.cities.push_back(newCity);
        cities.dequeue();
    }
}

void RouterBuilder::ImportPackages(Router &router, std::string PACKAGE_PATH) {
    Queue<std::string> packages, cities;
    IO::GetPackages(&packages, &cities, PACKAGE_PATH);

    while (!packages.isEmpty()) {
        std::string package, city;
        packages.getFront(package);
        cities.getFront(city);

        Package newPackage(package);

        //router.cities[city]->packages.push(newPackage);
        router.FindCityByName(city)->packages.push(newPackage);
        packages.dequeue();
        cities.dequeue();
    }
}

void RouterBuilder::ImportTrucks(Router &router, std::string TRUCK_PATH) {
    Queue<std::string> trucks, cities, weights;
    IO::GetTrucks(&trucks, &cities, &weights, TRUCK_PATH);

    while(!trucks.isEmpty()) {
        std::string truck, city, weight;
        trucks.getFront(truck);
        cities.getFront(city);
        weights.getFront(weight);

        Truck newTruck(truck, weight);
        //router.cities[city]->trucks.enqueue(newTruck);
        router.FindCityByName(city)->trucks.enqueue(newTruck);

        trucks.dequeue();
        cities.dequeue();
        weights.dequeue();
    }
}




