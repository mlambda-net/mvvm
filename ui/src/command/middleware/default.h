//
// Created by Roy Gonzalez on 19/9/22.
//

#ifndef MVVM_DEFAULT_H
#define MVVM_DEFAULT_H

#include "command.h"

namespace ui {

   class DefaultMiddleware : public CommandMiddleware {
     private:
      std::shared_ptr<CommandMiddleware> next;

     public:
      DefaultMiddleware();
      void Next(std::shared_ptr<CommandMiddleware> middleware) override;
      void Invoke(std::unique_ptr<Message> message) override;
   };
}  // namespace ui

#endif  // MVVM_DEFAULT_H
