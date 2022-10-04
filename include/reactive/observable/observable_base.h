
#ifndef MVVM_OBSERVABLE_BASE_H
#define MVVM_OBSERVABLE_BASE_H

#include "reactive/observable.h"
#include "reactive/observer/subscriber.h"
#include "reactive/observer/unsubscription.h"
#include <list>
#include <reactive/global.h>

namespace reactive {

    template<typename T>
    class ObservableBase : public Observable<T> {

    private:
        std::list<Box<Observer<T>>> observers;

    protected:

        void ForEach(std::function<void(Box<Observer<T>>)> fn) {
            std::ranges::for_each(std::list<Box<Observer<T>>>(this->observers), fn);
        }

    public:

        Unique<Unsubscribe> Subscribe(SuccessCallback<T> success) override {
            return this->Subscribe(success, nullptr, nullptr);
        }

        Unique<Unsubscribe> Subscribe(SuccessCallback<T> success, FailureCallback fail) override {
            return this->Subscribe(success, fail, nullptr);
        }

        Unique<Unsubscribe>
        Subscribe(SuccessCallback<T> success, FailureCallback fail, CompleteCallback complete) override {
            return this->Subscribe(std::make_shared<Subscriber<T>>(success, fail, complete));
        }

        Unique<Unsubscribe> Subscribe(Box<Observer<T>> observer) override {
            this->observers.push_back(observer);
            return std::make_unique<Unsubscription>([this, observer]() {
                this->observers.remove(observer);
            });
        }
    };
} // namespace reactive

#endif //MVVM_OBSERVABLE_BASE_H
