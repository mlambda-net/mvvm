//
// Created by Roy Gonzalez on 3/10/22.
//

#ifndef MVVM_FUNCTOR_H
#define MVVM_FUNCTOR_H

#include <command/middleware.h>

namespace command {

   class FunctorMiddleware : public Middleware {
     private:
      MiddlewareFn fn;

     public:
      FunctorMiddleware();
      FunctorMiddleware(MiddlewareFn fn);
      void Next(MiddlewareType middleware) override;
      void Invoke(MessageType message) override;
   };

}  // namespace command

#endif  // MVVM_FUNCTOR_H
