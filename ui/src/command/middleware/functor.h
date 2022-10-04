//
// Created by Roy Gonzalez on 3/10/22.
//

#ifndef MVVM_FUNCTOR_H
#define MVVM_FUNCTOR_H

#include <ui/command/middleware.h>

namespace ui {

   class FunctorMiddleware : public Middleware {
     private:
      std::function<void(std::shared_ptr<Middleware>, std::shared_ptr<Message>)> fn;

     public:
      FunctorMiddleware();
      FunctorMiddleware(std::function<void(std::shared_ptr<Middleware>, std::shared_ptr<Message>)> fn);
      void Next(std::shared_ptr<Middleware> middleware) override;
      void Invoke(std::shared_ptr<Message> message) override;
   };

}  // namespace ui

#endif  // MVVM_FUNCTOR_H
