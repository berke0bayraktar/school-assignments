//
// Created by berke on 25.11.2020.
//

#include "MovieNode.h"

MovieNode::MovieNode(int id, std::string name, int year) : id(id), name(name), year(year) { }
MovieNode::MovieNode() : id(0), name(std::string()), year(0) { }