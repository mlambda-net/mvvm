//
// Created by Roy Gonzalez on 19/9/22.
//

#include "default.h"

#include <iostream>

#include "empty.h"
#include "ui/command/middleware.h"

namespace ui {
   void DefaultMiddleware::Next(std::shared_ptr<Middleware> middleware) {
      this->next = middleware;
   }

   void DefaultMiddleware::Invoke(std::shared_ptr<Message> message) {
      this->next->Invoke(std::move(message));
   }

   DefaultMiddleware::DefaultMiddleware() {
      this->next = EmptyMiddleware::Instance();
   }
}  // namespace ui