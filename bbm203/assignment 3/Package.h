//
// Created by berke on 7.12.2020.
//

#ifndef ASSIGNMENT3_PACKAGE_H
#define ASSIGNMENT3_PACKAGE_H

#include <string>

class Package {
private:
    std::string _id;
public:
    Package(std::string id);
    Package();
    virtual std::string Id();
};


#endif //ASSIGNMENT3_PACKAGE_H
