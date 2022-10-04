//
// Created by Roy Gonzalez on 10/1/23.
//

#include "reactive/observable/lambda_observable.h"
#include "wrapper.h"

namespace reactive {

    template<typename T>
    Disposable<T> LambdaObservable<T>::Subscribe(Success<T> success) {

    }

    template<typename T>
    Disposable<T> LambdaObservable<T>::Subscribe(Success<T> success, Failure fail) {

    }

    template<typename T>
    Disposable<T> LambdaObservable<T>::Subscribe(Success<T> success, Failure fail, Complete complete) {

    }


} // namespace reactive