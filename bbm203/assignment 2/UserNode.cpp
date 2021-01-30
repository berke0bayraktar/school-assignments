//
// Created by berke on 25.11.2020.
//

#include "UserNode.h"

UserNode::UserNode(int id, std::string name) : id(id), name(name), movies() { }
UserNode::UserNode() : id(0), name(std::string()), movies() { }

