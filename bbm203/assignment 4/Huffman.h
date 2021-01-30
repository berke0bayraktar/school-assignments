//
// Created by berke on 17.12.2020.
//

#ifndef ASSIGNMENT4_HUFFMAN_H
#define ASSIGNMENT4_HUFFMAN_H

#include "BTNode.h"
#include <map>
#include <vector>
#include <string>
#include "Node2Freq.h"
#include <algorithm>
#include <iostream>
#include <queue>
#include "Constants.h"

class Huffman {
private:
    static void generate_encoding_from_tree(BTNode *root, std::string& encoding, std::map<char, std::string>& encodings);
    static char read_char_from_encoding_tree(BTNode* root, std::string& encoded_message, int* idx);
    static void search_tree(char& c, BTNode* root, std::string& encoding, std::string& temp);
public:
    static std::string encode(std::string& message, BTNode* huffman_tree);
    static std::string decode(std::string& encoded_message, BTNode* huffman_tree);
    static std::string get_huffman_encoding(std::string& c, BTNode* huffman_tree);
    static BTNode* generate_tree(std::string& message);
    static std::string list(BTNode* huffman_tree);
};


#endif //ASSIGNMENT4_HUFFMAN_H
