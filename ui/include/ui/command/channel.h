
#ifndef MVVM_CHANNEL_H
#define MVVM_CHANNEL_H

#include <list>
#include <string>

#include "abstract.h"
#include "middleware.h"

namespace ui {
   class Channel {
     public:
      Channel() = default;
      virtual ~Channel() = default;
      virtual std::string GetID() = 0;
      virtual void AddMiddleware(std::function<void(std::shared_ptr<Middleware>, std::shared_ptr<Message>)> middleware) = 0;
      virtual void AddMiddleware(std::unique_ptr<Middleware> middleware) = 0;
      virtual bool IsValidMessage(std::shared_ptr<Message> message) = 0;
      virtual MiddlewareAction Execute(const Subscription &subscription) = 0;
   };
}  // namespace ui

#endif  // MVVM_CHANNEL_H
