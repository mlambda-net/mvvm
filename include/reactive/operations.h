
#include "observable.h"
#include "observable/replay_subject.h"
#include <functional>
#include <iostream>

namespace reactive {

    template<typename T>
    Box<Subject<T>> ToSubject(T value) {
        auto subject = std::make_shared<Subject<T>>();
        subject->Next(value);

        return subject;
    }

    template<typename T>
    Box<Observable<T>> Range(int start, int end) {
        auto subject = std::make_shared<ReplaySubject<T>>();
        for (int i = start; i <= end; i++) {
            subject->Next(T());
        }

        return subject;
    }

    template<class T>
    std::function<Box<Observable<T>>(Box<Observable<T>>)> Skip(int value) {

        return [value](Box<Observable<T>> obs) -> Box<Observable<T>> {
            int skipped = 0;
            auto subject = std::make_shared<ReplaySubject<T>>();
            auto success = [&skipped, value, &subject](T item) {
                if (skipped++ >= value) {
                    subject->OnNext(item);
                }
            };

            obs->Subscribe(success);

            return subject;
        };
    }

} // namespace reactive