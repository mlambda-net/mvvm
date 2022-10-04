//
// Created by Roy Gonzalez on 10/1/23.
//


#include "reactive/observable/subject.h"
#include <ranges>


namespace reactive {
    template<typename T>
    void Subject<T>::Next(T value) {
        printf("next");
    }

    template<typename T>
    void Subject<T>::Error(std::exception const &e) {
        printf("error");
    }

    template<typename T>
    void Subject<T>::Complete() {
        printf("complete");
    }


} // namespace reactive