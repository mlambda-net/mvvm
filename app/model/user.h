//
// Created by Roy Gonzalez on 10/1/23.
//

#ifndef MVVM_USER_H
#define MVVM_USER_H
#include "reactive/observer.h"
#include <iostream>

class User: reactive::Observer<User> {

private:
    std::string name;
    std::string password;

public:
    User();

    User(std::string name, std::string password);


};


#endif //MVVM_USER_H
