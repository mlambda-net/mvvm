
#ifndef MVVM_REPLAY_SUBJECT_H
#define MVVM_REPLAY_SUBJECT_H

#include "observable_base.h"
#include "subject.h"

namespace reactive {

    template<typename T>
    class ReplaySubject : public Subject<T> {
    private:
        std::list<T> buffer;

    public:

        void Next(T value) override {
            this->buffer.push_back(value);
            Subject<T>::Next(value);
        }

        Unique<Unsubscribe> Subscribe(SuccessCallback<T> success, FailureCallback fail, CompleteCallback complete) override {
            auto observer = std::make_shared<Subscriber<T>>(success, fail, complete);
            auto unsubscribe = ObservableBase<T>::Subscribe(observer);
            for (auto values = std::list<T>(this->buffer); auto value: values) {
                observer->OnNext(value);
            }

            return unsubscribe;
        }
    };

} // namespace reactive

#endif //MVVM_REPLAY_SUBJECT_H
