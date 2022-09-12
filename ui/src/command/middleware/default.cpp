//
// Created by Roy Gonzalez on 19/9/22.
//

#include "default.h"

#include "empty.h"

namespace ui {
   void DefaultMiddleware::Next(std::shared_ptr<CommandMiddleware> middleware) {
      this->next = middleware;
   }

   void DefaultMiddleware::Invoke(std::unique_ptr<Message> message) {
      this->next->Invoke(std::move(message));
   }

   DefaultMiddleware::DefaultMiddleware() {
      this->next = EmptyMiddleware::Instance();
   }
}  // namespace ui