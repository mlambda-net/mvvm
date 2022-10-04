//
// Created by Roy Gonzalez on 19/9/22.
//

#include "empty.h"

namespace ui {

   std::shared_ptr<Middleware> EmptyMiddleware::instance = nullptr;

   void EmptyMiddleware::Invoke(std::shared_ptr<Message> message) {
      // THis shouldn't be called anything
   }

   EmptyMiddleware::EmptyMiddleware() = default;

   std::shared_ptr<Middleware> EmptyMiddleware::Instance() {
      if (instance == nullptr) {
         EmptyMiddleware empty;
         instance = std::make_shared<EmptyMiddleware>(empty);
      }
      return instance;
   }

   void EmptyMiddleware::Next(std::shared_ptr<Middleware> middleware) {
      // THis shouldn't be called Middleware
   }
}  // namespace ui