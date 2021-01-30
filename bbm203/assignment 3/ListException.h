//
// Created by berke on 8.12.2020.
//

#ifndef ASSIGNMENT3_LISTEXCEPTION_H
#define ASSIGNMENT3_LISTEXCEPTION_H


#include <exception>
#include <string>
class ListException : public std::exception {
private:
    std::string _msg;
public:
    explicit ListException(std::string msg);
    std::string Message();
};


#endif //ASSIGNMENT3_LISTEXCEPTION_H
