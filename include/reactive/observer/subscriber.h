
#ifndef MVVM_SUBSCRIBER_H
#define MVVM_SUBSCRIBER_H

#include "reactive/global.h"

namespace reactive {

    template<typename T>
    class Subscriber : public Observer<T> {

    public:
        Subscriber() = default;

        explicit Subscriber(SuccessCallback<T> success) : Subscriber(success, nullptr, nullptr) {
        }

        Subscriber(SuccessCallback<T> success, FailureCallback const &fail) : Subscriber(success, fail, nullptr) {
        }

        Subscriber(SuccessCallback<T> success, FailureCallback const &fail, CompleteCallback const &complete) :
                successFn(success), failureFn(fail), completeFn(complete) {
        }

        void OnNext(T value) override {
            if (!this->completed && this->successFn != nullptr) {
                this->successFn(value);
            }
        }

        void OnError(std::exception const &e) const override {
            if (!this->completed && failureFn != nullptr) {
                failureFn(e);
            }
        }

        void OnComplete()  override {
            if (!this->completed && completeFn != nullptr) {
                completeFn();
            }
            this->completed = true;
        }

    private:
        SuccessCallback<T> successFn;
        FailureCallback failureFn;
        CompleteCallback completeFn;
        bool completed = false;

    };


} // namespace reactive

#endif //MVVM_SUBSCRIBER_H
