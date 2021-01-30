//
// Created by berke on 26.11.2020.
//

#ifndef ASSIGNMENT2_LIBRARYEXCEPTION_H
#define ASSIGNMENT2_LIBRARYEXCEPTION_H

#include <exception>
#include <string>

class LibraryException : public std::exception {
private:
    std::string msg;
public:
    explicit LibraryException(std::string msg) : msg(msg) {}
    std::string Message();
};

#endif //ASSIGNMENT2_LIBRARYEXCEPTION_H
