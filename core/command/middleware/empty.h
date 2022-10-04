
//
// Created by Roy Gonzalez on 19/9/22.
//

#ifndef MVVM_EMPTY_H
#define MVVM_EMPTY_H

#include <command/middleware.h>

#include <iostream>

namespace command {

   class EmptyMiddleware : public Middleware {
     protected:
      EmptyMiddleware();

     private:
      static MiddlewareType instance;

     public:
      static MiddlewareType Instance();
      void Next(MiddlewareType middleware) override;
      void Invoke(MessageType message) override;
   };

}  // namespace command

#endif  // MVVM_EMPTY_H
