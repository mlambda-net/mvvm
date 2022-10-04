
#ifndef MVVM_UNSUBSCRIBE_H
#define MVVM_UNSUBSCRIBE_H

namespace  reactive {
    struct Unsubscribe {
        virtual void Dispose() = 0;

        virtual ~Unsubscribe() = default;
    };
} // namespace reactive

#endif //MVVM_UNSUBSCRIBE_H
