
//
// Created by Roy Gonzalez on 18/9/22.
//

#ifndef MVVM_LAMBDA_H
#define MVVM_LAMBDA_H

#include <ui/command/abstract.h>
#include <ui/command/message.h>
#include <ui/command/middleware.h>

#include "command.h"

namespace ui {

   class LambdaMiddleware : public CommandMiddleware {
     private:
      std::shared_ptr<CommandMiddleware> next;
      MiddlewareAction action;

     public:
      LambdaMiddleware();
      explicit LambdaMiddleware(MiddlewareAction action);
      void Next(std::shared_ptr<CommandMiddleware> middleware) override;
      void Invoke(std::unique_ptr<Message> message) override;
      std::unique_ptr<Message> Execute(std::unique_ptr<Message> message);
   };

}  // namespace ui

#endif  // MVVM_LAMBDA_H
