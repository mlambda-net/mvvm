
#ifndef MVVM_MIDDLEWARE_H
#define MVVM_MIDDLEWARE_H

#include <command/message.h>

namespace command {

   class Middleware {
     protected:
      std::shared_ptr<Middleware> next = nullptr;

     public:
      Middleware() = default;
      virtual ~Middleware() = default;
      virtual void Invoke(MessageType message) = 0;
      virtual void Next(std::shared_ptr<Middleware> middleware) = 0;
   };

   using MiddlewareType = std::shared_ptr<Middleware>;
   using MiddlewareFn = std::function<void(MiddlewareType, MessageType)>;
   using MiddlewareAction = std::function<void(MessageType)>;

}  // namespace command

#endif  // MVVM_MIDDLEWARE_H
