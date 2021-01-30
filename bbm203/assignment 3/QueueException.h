//
// Created by berke on 8.12.2020.
//

#ifndef ASSIGNMENT3_QUEUEEXCEPTION_H
#define ASSIGNMENT3_QUEUEEXCEPTION_H


#include <string>

class QueueException : public std::exception {
private:
    std::string _msg;
public:
    explicit QueueException(std::string msg);
    std::string Message();
};


#endif //ASSIGNMENT3_QUEUEEXCEPTION_H
