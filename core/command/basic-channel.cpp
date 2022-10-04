//
// Created by Roy Gonzalez on 18/9/22.
//

#include "basic-channel.h"

#include <utility>

#include "middleware/empty.h"
#include "middleware/functor.h"
#include "middleware/lambda.h"

namespace command {

   BasicChannel::BasicChannel() : BasicChannel("") {}

   BasicChannel::BasicChannel(const string &name) : name(name),
                                                    filter([](MessageType) {
                                                       return true;
                                                    }) {
   }

   bool BasicChannel::IsValidMessage(MessageType message) {
      return this->filter(message);
   }

   void BasicChannel::AddMiddleware(unique_ptr<Middleware> middleware) {
      this->middlewares.push_back(shared_ptr<Middleware>(std::move(middleware)));
   }

   MiddlewareAction BasicChannel::Execute(const Subscription &subscription) {
      if (this->middlewares.empty()) {
         return subscription;
      }

      auto actual = CreateMiddleware(this->middlewares.begin(), this->middlewares.end(), subscription);
      return [actual](MessageType message) {
         actual->Invoke(message);
      };
   }

   shared_ptr<Middleware> BasicChannel::CreateMiddleware(list<MiddlewareType>::iterator first, list<MiddlewareType>::iterator last, const Subscription &subscription) {
      if (first == last) {
         return make_shared<LambdaMiddleware>(subscription);
      }

      auto actual = *first;
      auto next = CreateMiddleware(++first, last, subscription);
      actual->Next(next);
      return actual;
   }

   void BasicChannel::AddMiddleware(MiddlewareFn middleware) {
      this->middlewares.push_back(make_shared<FunctorMiddleware>(middleware));
   }

   void BasicChannel::Filter(FilterFn fn) {
      this->filter = fn;
   }

}  // namespace command