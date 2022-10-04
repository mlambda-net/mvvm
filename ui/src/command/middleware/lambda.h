
//
// Created by Roy Gonzalez on 18/9/22.
//

#ifndef MVVM_LAMBDA_H
#define MVVM_LAMBDA_H

#include <ui/command/abstract.h>
#include <ui/command/message.h>
#include <ui/command/middleware.h>

namespace ui {

   class LambdaMiddleware : public Middleware {
     private:
      MiddlewareAction action;

     public:
      LambdaMiddleware();
      explicit LambdaMiddleware(MiddlewareAction action);
      void Next(std::shared_ptr<Middleware> middleware) override;
      void Invoke(std::shared_ptr<Message> message) override;
      std::shared_ptr<Message> Execute(std::shared_ptr<Message> message);
   };

}  // namespace ui

#endif  // MVVM_LAMBDA_H
