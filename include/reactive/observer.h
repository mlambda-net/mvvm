
#ifndef MVVM_OBSERVER_H
#define MVVM_OBSERVER_H

#include <functional>
#include <iostream>

namespace reactive {


    template<typename T>
    struct Observer {
        virtual void OnNext(T value) = 0;

        virtual void OnError(std::exception const &e) const = 0;

        virtual void OnComplete()  = 0;

        virtual ~Observer() = default;
    };
} // namespace reactive

#endif //MVVM_OBSERVER_H
