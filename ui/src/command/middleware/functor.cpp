//
// Created by Roy Gonzalez on 3/10/22.
//

#include "functor.h"

namespace ui {
   FunctorMiddleware::FunctorMiddleware() : FunctorMiddleware([](std::shared_ptr<Middleware> middleware, std::shared_ptr<Message> msg) {
                                            }) {
   }

   FunctorMiddleware::FunctorMiddleware(std::function<void(std::shared_ptr<Middleware>, std::shared_ptr<Message>)> fn) {
      this->fn = fn;
   }

   void FunctorMiddleware::Next(std::shared_ptr<Middleware> middleware) {
      this->next = middleware;
   }

   void FunctorMiddleware::Invoke(std::shared_ptr<Message> message) {
      this->fn(this->next, message);
   }

}  // namespace ui