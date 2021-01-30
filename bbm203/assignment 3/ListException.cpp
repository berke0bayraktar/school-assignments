//
// Created by berke on 8.12.2020.
//

#include "ListException.h"

ListException::ListException(std::string msg) : _msg(msg) {

}

std::string ListException::Message() {
    return _msg;
}
