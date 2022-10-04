
#ifndef MVVM_DEFAULT_H
#define MVVM_DEFAULT_H

#include <command/middleware.h>

namespace command {

   class DefaultMiddleware : public Middleware {
     public:
      DefaultMiddleware();
      void Next(MiddlewareType middleware) override;
      void Invoke(MessageType message) override;
   };
}  // namespace command

#endif  // MVVM_DEFAULT_H
