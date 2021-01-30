//
// Created by berke on 17.12.2020.
//

#ifndef ASSIGNMENT4_NODE2FREQ_H
#define ASSIGNMENT4_NODE2FREQ_H

#include <list>
#include <string>
#include "BTNode.h"
#include <algorithm>
#include <iostream>

class Node2Freq {
private:
    std::list<std::pair<int,BTNode*>> f2n;
    void insert_if_not_exists(char c);
public:
    void merge();
    int size();
    BTNode* tree();
    explicit Node2Freq(std::string& messageToEncode);
    static void list(BTNode* root, std::string indent, std::string& listing, bool right);
};


#endif //ASSIGNMENT4_NODE2FREQ_H
