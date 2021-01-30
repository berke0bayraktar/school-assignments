#include <iostream>
#include "IO.h"
#include "Router.h"
#include "RouterBuilder.h"

int main(int argc, char *argv[]) {
    std::string CITY_PATH = argv[1];
    std::string PACKAGE_PATH = argv[2];
    std::string TRUCK_PATH = argv[3];
    std::string MISSION_PATH = argv[4];
    std::string RESULT_PATH = argv[5];

    // IO class for read/write operations
    IO io;
    io.Start(MISSION_PATH);

    // Object that handles packages and trucks between cities
    Router router;

    /* Router is a complex object, it needs initial configuration
     * depending on input files therefore we have a builder class for it*/
    RouterBuilder::Build(router, CITY_PATH, PACKAGE_PATH, TRUCK_PATH);


    // information required for a single mission
    std::string startCity, midwayCity, targetCity;
    int numAddedPackagesStart, numAddedPackagesMidway;
    Queue<int> packagesToRemoveMidway;


    // execute commands one by one
    while(io.GetMission(&startCity, &midwayCity, &targetCity, &numAddedPackagesStart, &numAddedPackagesMidway, &packagesToRemoveMidway)) {
        try {
            router.ExecuteMission(startCity, midwayCity, targetCity, numAddedPackagesStart, numAddedPackagesMidway, &packagesToRemoveMidway);
        }
        catch (StackException& se) {
            std::cout << se.Message();
        }
        catch (QueueException& qe) {
            std::cout << qe.Message();
        }
        catch (ListException& le) {
            std::cout << le.Message();
        }
        catch (std::exception& e) {
            std::cout << e.what();
        }
    }
    io.End(router.Report(), RESULT_PATH);
}
