//
// Created by Roy Gonzalez on 10/1/23.
//

#ifndef MVVM_CONSOLE_H
#define MVVM_CONSOLE_H


#include "reactive/observer.h"



template<class T>
class ConsoleObserver: public reactive::Observer<T> {
public:

    ConsoleObserver() = default;

    void OnNext(T value) override {
        std::cout << value << std::endl;
    }

    void Error(const std::exception &e) override {
        std::cout << e.what() << std::endl;
    }

    void OnComplete() override {
        std::cout << "Completed" << std::endl;
    }
};



#endif //MVVM_CONSOLE_H
