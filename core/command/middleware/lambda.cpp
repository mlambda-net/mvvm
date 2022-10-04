//
// Created by Roy Gonzalez on 18/9/22.
//

#include "lambda.h"

#include "empty.h"

namespace command {

   LambdaMiddleware::LambdaMiddleware()
       : LambdaMiddleware([](MessageType) {
            // this is an empty behavior
         }) {
      // this is an empty behavior
   }

   LambdaMiddleware::LambdaMiddleware(MiddlewareAction action) {
      this->next = EmptyMiddleware::Instance();
      this->action = action;
   }

   void LambdaMiddleware::Invoke(MessageType message) {
      this->next->Invoke(this->Execute(message));
   }

   void LambdaMiddleware::Next(MiddlewareType middleware) {
      this->next = middleware;
   }

   MessageType LambdaMiddleware::Execute(MessageType message) {
      this->action(message);
      return message;
   }
}  // namespace command