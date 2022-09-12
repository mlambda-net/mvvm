//
// Created by Roy Gonzalez on 19/9/22.
//

#include "empty.h"

namespace ui {

   std::shared_ptr<CommandMiddleware> EmptyMiddleware::instance = nullptr;

   void EmptyMiddleware::Invoke(std::unique_ptr<Message> message) {
      // THis shouldn't be called anything
   }

   EmptyMiddleware::EmptyMiddleware() = default;

   std::shared_ptr<CommandMiddleware> EmptyMiddleware::Instance() {
      if (instance == nullptr) {
         EmptyMiddleware empty;
         instance = std::make_shared<EmptyMiddleware>(empty);
      }
      return instance;
   }

   void EmptyMiddleware::Next(std::shared_ptr<CommandMiddleware> middleware) {
      // THis shouldn't be called anything
   }
}  // namespace ui