//
// Created by Roy Gonzalez on 10/1/23.
//

#include "user.h"

User::User(): User("", "") {

}

User::User(std::string name, std::string password): name(name), password(password) {
    //this->Notify()
}
