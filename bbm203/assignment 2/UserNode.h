//
// Created by berke on 25.11.2020.
//

#ifndef ASSIGNMENT2_USERNODE_H
#define ASSIGNMENT2_USERNODE_H

#include <string>
#include "SinglyCircularLinkedList.h"

struct UserNode {
    int id;
    std::string name;
    UserNode* next = nullptr;
    UserNode* prev = nullptr;
    SinglyCircularLinkedList movies;
    UserNode(int id, std::string name);
    UserNode();
};

#endif //ASSIGNMENT2_USERNODE_H
