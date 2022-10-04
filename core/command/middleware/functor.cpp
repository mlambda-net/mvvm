//
// Created by Roy Gonzalez on 3/10/22.
//

#include "functor.h"

namespace command {
   FunctorMiddleware::FunctorMiddleware() : FunctorMiddleware([](MiddlewareType middleware, MessageType msg) {
                                            }) {
   }

   FunctorMiddleware::FunctorMiddleware(MiddlewareFn fn) {
      this->fn = fn;
   }

   void FunctorMiddleware::Next(MiddlewareType middleware) {
      this->next = middleware;
   }

   void FunctorMiddleware::Invoke(MessageType message) {
      this->fn(this->next, message);
   }

}  // namespace command