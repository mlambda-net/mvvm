
#ifndef MVVM_UNSUBSCRIPTION_H
#define MVVM_UNSUBSCRIPTION_H

#include "reactive/unsubscribe.h"
#include <boost/log/trivial.hpp>
#include <functional>

namespace reactive {

    class Unsubscription: public Unsubscribe {
    private:
        std::function<void()> dispose;
        bool disposed = false;

    public:
        explicit Unsubscription(std::function<void()> const &dispose) : dispose(dispose) {
        }

        ~Unsubscription() override {
            try {
                this->Dispose();
            } catch (const std::exception &e) {
                BOOST_LOG_TRIVIAL(fatal) << "Exception releasing the subscription: " << e.what() << std::endl;
            }
        }

        void Dispose() final {
            if (!disposed && this->dispose != nullptr) {
                this->dispose();
            }
            this->disposed = true;
        }

    };

} // namespace reactive

#endif //MVVM_UNSUBSCRIPTION_H
