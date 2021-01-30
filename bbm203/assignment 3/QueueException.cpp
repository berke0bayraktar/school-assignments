//
// Created by berke on 8.12.2020.
//

#include "QueueException.h"

QueueException::QueueException(std::string msg) : _msg(msg) {
}

std::string QueueException::Message() {
    return _msg;
}
