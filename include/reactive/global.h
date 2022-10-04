
#ifndef MVVM_GLOBAL_H
#define MVVM_GLOBAL_H

#include <functional>
#include <iostream>

template <class T>
using Unique = std::unique_ptr<T>;

template <class T>
using Box = std::shared_ptr<T>;

namespace reactive {
    template<typename T>
    using SuccessCallback = std::function<void(T)>;
    using FailureCallback = std::function<void(std::exception)>;
    using CompleteCallback = std::function<void()>;
} // namespace reactive

#endif //MVVM_GLOBAL_H
