//
// Created by berke on 17.12.2020.
//

#include "Huffman.h"

std::string Huffman::encode(std::string& message, BTNode* huffman_tree) {
    std::string encoding;
    std::map<char, std::string> encodings;

    generate_encoding_from_tree(huffman_tree, encoding, encodings);

    std::string encodedMessage;
    for(char c : message) {
        encodedMessage.append(encodings[c]);
    }
    return encodedMessage;
}

std::string Huffman::decode(std::string &encoded_message, BTNode* huffman_tree) {
    int current_idx = 0;
    std::string decoded_message;
    while (current_idx < encoded_message.size()) {
        char c = read_char_from_encoding_tree(huffman_tree, encoded_message, &current_idx);
        decoded_message.push_back(c);
    }
    return decoded_message;
}


void Huffman::generate_encoding_from_tree(BTNode *root, std::string& encoding, std::map<char, std::string>& encodings) {
    if (root->left == nullptr && root->right == nullptr) { // we are at a leaf node
        encodings.emplace(root->val, encoding);
    }
    if (root->left != nullptr) {
        generate_encoding_from_tree(root->left, encoding.append("0"), encodings);
        encoding.pop_back();
    }
    if (root->right != nullptr) {
        generate_encoding_from_tree(root->right, encoding.append("1"), encodings);
        encoding.pop_back();
    }
}

char Huffman::read_char_from_encoding_tree(BTNode *root, std::string &encoded_message, int* idx) {
    if (root->val != TREE_ROOT_CHAR) { // then we are at a leaf node
        return root->val;
    }

    char direction = encoded_message[*idx];
    *idx = *idx + 1;

    if (direction == '0') { // go left
        return read_char_from_encoding_tree(root->left, encoded_message, idx);
    }
    else { // go right
        return read_char_from_encoding_tree(root->right, encoded_message, idx);
    }
}

std::string Huffman::list(BTNode* huffman_tree) {
    std::string listing, indent;
    Node2Freq::list(huffman_tree, indent, listing, true);
    return listing;
}

BTNode* Huffman::generate_tree(std::string& message) {
    Node2Freq n2f(message);

    while(n2f.size() != 1) {
        n2f.merge();
    }
    return n2f.tree();
}

std::string Huffman::get_huffman_encoding(std::string &c, BTNode *huffman_tree) {
    std::string encoding;
    std::string temp;
    char char_to_search;
    if (c == "' '") {
        char_to_search = ' ';
    }
    else if (c == "\\n") {
        char_to_search = '\n';
    }
    else {
        char_to_search = c.c_str()[0];
    }
    search_tree(char_to_search, huffman_tree, encoding, temp);
    return encoding;
}

void Huffman::search_tree(char &c, BTNode *root, std::string &encoding, std::string& temp) {
    if (root->val != TREE_ROOT_CHAR) { // then we are at a leaf node
        if (root->val == c) {
            encoding = temp;
        }
    }
    if (root->left != nullptr) {
        search_tree(c, root->left, encoding, temp.append("0"));
        temp.pop_back();
    }
    if (root->right != nullptr) {
        search_tree(c, root->right, encoding, temp.append("1"));
        temp.pop_back();
    }
}
