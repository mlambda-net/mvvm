//
// Created by Roy Gonzalez on 18/9/22.
//

#include "lambda.h"

#include <utility>

#include "empty.h"

namespace ui {

   LambdaMiddleware::LambdaMiddleware()
       : LambdaMiddleware([](std::unique_ptr<Message>) {
            // this is an empty behavior
         }){};

   LambdaMiddleware::LambdaMiddleware(MiddlewareAction action) {
      this->next = EmptyMiddleware::Instance();
      this->action = std::move(action);
   }

   void LambdaMiddleware::Invoke(std::unique_ptr<Message> message) {
      this->next->Invoke(this->Execute(std::move(message)));
   }

   void LambdaMiddleware::Next(std::shared_ptr<CommandMiddleware> middleware) {
      this->next = middleware;
   }

   std::unique_ptr<Message> LambdaMiddleware::Execute(std::unique_ptr<Message> message) {
      this->action(std::move(message));
      return message;
   }
}  // namespace ui