//
// Created by Roy Gonzalez on 10/1/23.
//

#ifndef MVVM_USER_H
#define MVVM_USER_H

namespace ui {

    class User: Observable {

        private:
            std::string name;
            std::string password;


    };

} // ui

#endif //MVVM_USER_H
