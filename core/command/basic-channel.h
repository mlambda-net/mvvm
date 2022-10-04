
#ifndef MVVM_BASIC_CHANNEL_H
#define MVVM_BASIC_CHANNEL_H

#include <command/channel.h>
#include <command/message.h>
#include <command/middleware.h>

#include "middleware/default.h"

using namespace std;

namespace command {

   class BasicChannel final : public Channel {
      string name;
      list<MiddlewareType> middlewares;
      FilterFn filter;

     public:
      BasicChannel();
      ~BasicChannel() override = default;
      explicit BasicChannel(const string &name);
      void Filter(FilterFn fn) override;
      void AddMiddleware(unique_ptr<Middleware> middleware) override;
      void AddMiddleware(MiddlewareFn middleware) override;
      bool IsValidMessage(MessageType message) override;
      MiddlewareAction Execute(const Subscription &subscription) override;
      static MiddlewareType CreateMiddleware(list<MiddlewareType>::iterator first, list<MiddlewareType>::iterator last, const Subscription &subscription);
   };
}  // namespace command

#endif  // MVVM_BASIC_CHANNEL_H
