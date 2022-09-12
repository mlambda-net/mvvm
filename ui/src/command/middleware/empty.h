//
// Created by Roy Gonzalez on 19/9/22.
//

#ifndef MVVM_EMPTY_H
#define MVVM_EMPTY_H

#include "command.h"

namespace ui {

   class EmptyMiddleware : public CommandMiddleware {
     protected:
      EmptyMiddleware();

     private:
      static std::shared_ptr<CommandMiddleware> instance;

     public:
      static std::shared_ptr<CommandMiddleware> Instance();
      void Next(std::shared_ptr<CommandMiddleware> middleware) override;
      void Invoke(std::unique_ptr<Message> message) override;
   };

}  // namespace ui

#endif  // MVVM_EMPTY_H
