#ifndef MVVM_COMMAND_H
#define MVVM_COMMAND_H

#include <ui/command/middleware.h>

namespace ui {

   class CommandMiddleware : public Middleware {
     public:
      virtual void Next(std::shared_ptr<CommandMiddleware> middleware) = 0;
   };

}  // namespace ui

#endif
