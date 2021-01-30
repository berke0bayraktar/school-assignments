//
// Created by berke on 8.12.2020.
//

#include "StackException.h"

std::string StackException::Message() {
    return _msg;
}

StackException::StackException(std::string msg) : _msg(msg) {

}
