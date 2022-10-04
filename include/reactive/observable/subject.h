
#ifndef MVVM_SUBJECT_H
#define MVVM_SUBJECT_H


#include "observable_base.h"
#include <list>

namespace reactive {
    template<typename T>
    class Subject : public ObservableBase<T> {

    public:

        Subject() = default;

        virtual void Next(T value) {
            ObservableBase<T>::ForEach([value](Box<Observer<T>> observer) {
                observer->OnNext(value);
            });
        }

        virtual void Error(std::exception const &e) {
            ObservableBase<T>::ForEach([e](Box<Observer<T>> observer) {
                observer->OnError(e);
            });
        }

        virtual void Complete() {
            ObservableBase<T>::ForEach([](Box<Observer<T>> observer) {
                observer->OnComplete();
            });
        }
    };
} // namespace reactive

#endif //MVVM_SUBJECT_H
