
#ifndef MVVM_SIMPLE_CHANNEL_H
#define MVVM_SIMPLE_CHANNEL_H

#include <ui/command/channel.h>
#include <ui/command/message.h>
#include <ui/command/middleware.h>

#include "middleware/default.h"

namespace ui {

   class SimpleChannel final : public ui::Channel {
      std::string name;
      std::list<std::shared_ptr<Middleware>> middlewares;

     public:
      SimpleChannel();

      explicit SimpleChannel(const std::string &name);

      ~SimpleChannel() override = default;

      std::string GetID() override;

      void AddMiddleware(std::unique_ptr<Middleware> middleware) override;

      void AddMiddleware(std::function<void(std::shared_ptr<Middleware>, std::shared_ptr<Message>)> middleware) override;

      bool IsValidMessage(std::shared_ptr<Message> message) override;

      MiddlewareAction Execute(const Subscription &subscription) override;

      static std::shared_ptr<Middleware> CreateMiddleware(
          std::list<std::shared_ptr<Middleware>>::iterator first,
          std::list<std::shared_ptr<Middleware>>::iterator last,
          const Subscription &subscription);
   };
}  // namespace ui

#endif  // MVVM_SIMPLE_CHANNEL_H
