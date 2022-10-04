//
// Created by Roy Gonzalez on 4/10/22.
//

#include "dummy.h"

#include <iostream>

Dummy::Dummy() : message("") {
}

Dummy::Dummy(std::string message) : message(message) {
}

std::string Dummy::GetMessage() const {
   return this->message;
}
