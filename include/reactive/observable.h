
#ifndef MVVM_OBSERVABLE_H
#define MVVM_OBSERVABLE_H

#include "observer.h"
#include "global.h"
#include "unsubscribe.h"

namespace  reactive {

    template<typename T>
    struct Observable {

        virtual Unique<Unsubscribe> Subscribe(SuccessCallback<T> success) = 0;

        virtual Unique<Unsubscribe> Subscribe(SuccessCallback<T> success, FailureCallback fail) = 0;

        virtual Unique<Unsubscribe> Subscribe(SuccessCallback<T> success, FailureCallback fail, CompleteCallback complete) = 0;

        virtual Unique<Unsubscribe> Subscribe(Box<Observer<T>> observer) = 0;

        virtual ~Observable() = default;
    };

} // namespace reactive

template <class T>
concept ObservableType = std::is_class_v<Box<reactive::Observable<T>>>;

/*

template <typename T, ObservableType... Args>
inline auto operator | (T& obj, std::invocable<T> auto func){
    return func(std::forward<T>(std::move(obj)));
}

template <ObservableType T, ObservableType... Args>
inline auto operator | (const T& obj, std::invocable<T> auto func){
    return func(std::forward<T>(std::move(obj)));
}
*/
template <ObservableType T, ObservableType... Args>
auto operator >> (T&& obj, std::invocable<T> auto func) {
    return func(std::forward<T>(obj));
}

#endif //MVVM_OBSERVABLE_H
