//
// Created by berke on 21.12.2020.
//

#ifndef ASSIGNMENT4_IO_H
#define ASSIGNMENT4_IO_H

#include <string>
#include <queue>
#include <fstream>
#include <sstream>
#include "BTNode.h"
#include "Constants.h"

class IO {
private:
    static void serialize(BTNode* root, std::string& str_rep);
    static BTNode* deserialize(std::queue<char>& str_rep);
public:
    static void save_to_file(std::string& message, std::string& PATH);
    static std::string read_from_file(std::string& PATH);
    static void save_tree(BTNode* tree, std::string& TREE_PATH);
    static BTNode* read_tree(std::string& TREE_PATH);
};


#endif //ASSIGNMENT4_IO_H
