//
// Created by Roy Gonzalez on 19/9/22.
//

#ifndef MVVM_EMPTY_H
#define MVVM_EMPTY_H

#include <ui/command/middleware.h>

#include <iostream>

namespace ui {

   class EmptyMiddleware : public Middleware {
     protected:
      EmptyMiddleware();

     private:
      static std::shared_ptr<Middleware> instance;

     public:
      static std::shared_ptr<Middleware> Instance();
      void Next(std::shared_ptr<Middleware> middleware) override;
      void Invoke(std::shared_ptr<Message> message) override;
   };

}  // namespace ui

#endif  // MVVM_EMPTY_H
