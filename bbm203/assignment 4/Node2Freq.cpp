//
// Created by berke on 17.12.2020.
//

#include "Node2Freq.h"

void Node2Freq::merge() {
    auto pair1 = f2n.front();
    int freq1 = pair1.first;
    auto node1 = pair1.second;
    f2n.pop_front();

    auto pair2 = f2n.front();
    int freq2 = pair2.first;
    auto node2 = pair2.second;
    f2n.pop_front();

    auto merge_node = new BTNode;
    merge_node->left = node1;
    merge_node->right = node2;

    f2n.emplace_back(freq1+freq2, merge_node);
    f2n.sort();
}

Node2Freq::Node2Freq(std::string& messageToEncode) {
    for(char c : messageToEncode) {
        insert_if_not_exists(c);
    }
    f2n.sort();
}

void Node2Freq::insert_if_not_exists(char c) {
    // check if it already exists
    for(auto & it : f2n) {
        char curr_char = it.second->val;
        if (c == curr_char) { // already exists
            it.first += 1;
            return;
        }
    }
    f2n.emplace_back(1, new BTNode(c));
}

int Node2Freq::size() {
    return f2n.size();
}

BTNode *Node2Freq::tree() {
    return f2n.begin()->second;
}

void Node2Freq::list(BTNode *root, std::string indent, std::string& listing, bool right) {
    if (root == nullptr) return;

    if (root->val == '\n') {
        listing.append(indent + "+- " + TREE_LIST_NEW_LINE + "\n");
    }
    else if (root->val == TREE_ROOT_CHAR) {
        listing.append(indent + "+- " + TREE_LIST_EMPTY_NODE + "\n");
    }
    else if (root->val == ' ') {
        listing.append(indent + "+- " + TREE_LIST_SPACE + "\n");
    }
    else {
        listing.append(indent + "+- " + root->val + "\n");
    }

    if (right)
        indent.append("  ");
    else
        indent.append("|  ");


    list(root->left, indent, listing, false);
    list(root->right, indent, listing, true);
}
