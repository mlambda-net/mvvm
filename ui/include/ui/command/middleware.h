
#ifndef MVVM_MIDDLEWARE_H
#define MVVM_MIDDLEWARE_H

#include "message.h"

namespace ui {

   class Middleware {
     protected:
      std::shared_ptr<Middleware> next = nullptr;

     public:
      Middleware() = default;
      virtual ~Middleware() = default;
      virtual void Invoke(std::shared_ptr<Message> message) = 0;
      virtual void Next(std::shared_ptr<Middleware> middleware) = 0;
   };

}  // namespace ui

#endif  // MVVM_MIDDLEWARE_H
