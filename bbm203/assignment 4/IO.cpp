//
// Created by berke on 21.12.2020.
//


#include "IO.h"

void IO::serialize(BTNode *root, std::string &str_rep) {
    if (root == nullptr) {
        str_rep.push_back(TREE_NULL_CHAR); // denotes null
        return;
    }
    if (root->val == '\n') {
        str_rep.push_back(TREE_NEW_LINE_CHAR);
    }
    else {
        str_rep.push_back(root->val);
    }
    serialize(root->left, str_rep);
    serialize(root->right, str_rep);
}

BTNode *IO::deserialize(std::queue<char> &str_rep) {
    char c = str_rep.front();
    if (c == TREE_NEW_LINE_CHAR) {
        c = '\n';
    }
    str_rep.pop();

    if (c == TREE_NULL_CHAR) {
        return nullptr;
    }
    auto node = new BTNode(c);
    node->left = deserialize(str_rep);
    node->right = deserialize(str_rep);
    return node;
}

void IO::save_tree(BTNode *tree, std::string &TREE_PATH) {
    std::ofstream tree_file(TREE_PATH);
    std::string str_rep;
    serialize(tree, str_rep);
    tree_file << str_rep;
    tree_file.close();
}

BTNode *IO::read_tree(std::string &TREE_PATH) {
    std::ifstream tree_file(TREE_PATH);
    std::ostringstream str_stream;
    str_stream << tree_file.rdbuf();
    std::string str_rep = str_stream.str();
    tree_file.close();

    std::queue<char> str_rep_q;
    for(char& c : str_rep) {
        str_rep_q.push(c);
    }
    return deserialize(str_rep_q);
}

void IO::save_to_file(std::string &message, std::string &PATH) {
    std::ofstream out_file(PATH);
    out_file << message;
    out_file.close();
}

std::string IO::read_from_file(std::string &PATH) {
    std::ostringstream str_stream;
    std::ifstream in_file(PATH);
    str_stream << in_file.rdbuf();
    std::string str = str_stream.str();
    in_file.close();
    for(char & i : str) {
        i = (char) tolower(i);
    }
    return str;
}
