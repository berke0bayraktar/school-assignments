//
// Created by berke on 17.12.2020.
//

#ifndef ASSIGNMENT4_BTNODE_H
#define ASSIGNMENT4_BTNODE_H

#include "Constants.h"

struct BTNode {
    BTNode* left = nullptr;
    BTNode* right = nullptr;
    char val = TREE_ROOT_CHAR;

    BTNode() = default;
    explicit BTNode(char val) : val(val) {}

    ~BTNode() {
        delete left;
        delete right;
    };
};


#endif //ASSIGNMENT4_BTNODE_H
