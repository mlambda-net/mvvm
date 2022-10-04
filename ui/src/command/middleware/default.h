
#ifndef MVVM_DEFAULT_H
#define MVVM_DEFAULT_H

#include <ui/command/middleware.h>

namespace ui {

   class DefaultMiddleware : public Middleware {
     public:
      DefaultMiddleware();
      void Next(std::shared_ptr<Middleware> middleware) override;
      void Invoke(std::shared_ptr<Message> message) override;
   };
}  // namespace ui

#endif  // MVVM_DEFAULT_H
