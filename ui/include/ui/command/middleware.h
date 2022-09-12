
#ifndef MVVM_MIDDLEWARE_H
#define MVVM_MIDDLEWARE_H

#include "message.h"

namespace ui {

   class Middleware {
     public:
      Middleware() = default;
      virtual ~Middleware() = default;
      virtual void Invoke(std::unique_ptr<Message> message) = 0;
   };

}  // namespace ui

#endif  // MVVM_MIDDLEWARE_H
