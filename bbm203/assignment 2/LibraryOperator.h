//
// Created by berke on 26.11.2020.
//

#ifndef ASSIGNMENT2_LIBRARYOPERATOR_H
#define ASSIGNMENT2_LIBRARYOPERATOR_H

#include "LibrarySystem.h"

class LibraryOperator {
public:
    static void ExecuteCommand(LibrarySystem& sys, std::string& method, std::string params[]);
};


#endif //ASSIGNMENT2_LIBRARYOPERATOR_H
