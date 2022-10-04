//
// Created by Roy Gonzalez on 19/9/22.
//

#include "default.h"

#include "empty.h"

namespace command {
   void DefaultMiddleware::Next(MiddlewareType middleware) {
      this->next = middleware;
   }

   void DefaultMiddleware::Invoke(MessageType message) {
      this->next->Invoke(message);
   }

   DefaultMiddleware::DefaultMiddleware() {
      this->next = EmptyMiddleware::Instance();
   }
}  // namespace command