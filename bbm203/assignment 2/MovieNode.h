//
// Created by berke on 25.11.2020.
//

#ifndef ASSIGNMENT2_MOVIENODE_H
#define ASSIGNMENT2_MOVIENODE_H

#include <string>

struct MovieNode {
    int id;
    std::string name;
    int year;
    MovieNode* next = nullptr;

    MovieNode(int id, std::string name, int year);
    MovieNode();

};


#endif //ASSIGNMENT2_MOVIENODE_H
