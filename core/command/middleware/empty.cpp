//
// Created by Roy Gonzalez on 19/9/22.
//

#include "empty.h"

namespace command {

   MiddlewareType EmptyMiddleware::instance = nullptr;

   void EmptyMiddleware::Invoke(MessageType message) {
      // THis shouldn't be called anything
   }

   EmptyMiddleware::EmptyMiddleware() = default;

   MiddlewareType EmptyMiddleware::Instance() {
      if (instance == nullptr) {
         EmptyMiddleware empty;
         instance = std::make_shared<EmptyMiddleware>(empty);
      }
      return instance;
   }

   void EmptyMiddleware::Next(MiddlewareType middleware) {
      // THis shouldn't be called Middleware
   }
}  // namespace command