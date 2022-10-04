
//
// Created by Roy Gonzalez on 18/9/22.
//

#ifndef MVVM_LAMBDA_H
#define MVVM_LAMBDA_H

#include <command/message.h>
#include <command/middleware.h>

namespace command {

   class LambdaMiddleware : public Middleware {
     private:
      MiddlewareAction action;

     public:
      LambdaMiddleware();
      explicit LambdaMiddleware(MiddlewareAction action);
      void Next(MiddlewareType middleware) override;
      void Invoke(MessageType message) override;
      MessageType Execute(MessageType message);
   };

}  // namespace command

#endif  // MVVM_LAMBDA_H
