//
// Created by Roy Gonzalez on 18/9/22.
//

#include "lambda.h"

#include <utility>

#include "empty.h"

namespace ui {

   LambdaMiddleware::LambdaMiddleware()
       : LambdaMiddleware([](std::shared_ptr<Message>) {
            // this is an empty behavior
         }){};

   LambdaMiddleware::LambdaMiddleware(MiddlewareAction action) {
      this->next = EmptyMiddleware::Instance();
      this->action = std::move(action);
   }

   void LambdaMiddleware::Invoke(std::shared_ptr<Message> message) {
      this->next->Invoke(this->Execute(message));
   }

   void LambdaMiddleware::Next(std::shared_ptr<Middleware> middleware) {
      this->next = middleware;
   }

   std::shared_ptr<Message> LambdaMiddleware::Execute(std::shared_ptr<Message> message) {
      this->action(message);
      return message;
   }
}  // namespace ui