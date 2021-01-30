//
// Created by berke on 8.12.2020.
//

#ifndef ASSIGNMENT3_STACKEXCEPTION_H
#define ASSIGNMENT3_STACKEXCEPTION_H


#include <exception>
#include <string>

class StackException : public std::exception {
private:
    std::string _msg;
public:
    explicit StackException(std::string msg);
    std::string Message();
};


#endif //ASSIGNMENT3_STACKEXCEPTION_H
