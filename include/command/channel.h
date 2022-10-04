
#ifndef MVVM_CHANNEL_H
#define MVVM_CHANNEL_H

#include <command/message.h>
#include <command/middleware.h>

#include <list>
#include <string>

namespace command {
   struct Channel {
      Channel() = default;
      virtual ~Channel() = default;
      virtual void Filter(FilterFn fn) = 0;
      virtual void AddMiddleware(MiddlewareFn middleware) = 0;
      virtual void AddMiddleware(std::unique_ptr<Middleware> middleware) = 0;
      virtual bool IsValidMessage(MessageType message) = 0;
      virtual MiddlewareAction Execute(const Subscription &subscription) = 0;
   };

   using ChannelType = std::shared_ptr<Channel>;
}  // namespace command

#endif  // MVVM_CHANNEL_H
