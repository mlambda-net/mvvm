
//
// Created by Roy Gonzalez on 18/9/22.
//

#ifndef MVVM_SIMPLE_CHANNEL_H
#define MVVM_SIMPLE_CHANNEL_H

#include <ui/command/channel.h>
#include <ui/command/message.h>
#include <ui/command/middleware.h>

#include "middleware/default.h"

namespace ui {

   class SimpleChannel final : public ui::Channel {
      std::string name;
      std::list<std::shared_ptr<CommandMiddleware>> middlewares;

     public:
      SimpleChannel();

      explicit SimpleChannel(const std::string &name);

      ~SimpleChannel() override = default;

      std::string GetID() override;

      void AddMiddleware(std::unique_ptr<Middleware> middleware) override;

      bool IsValidMessage(std::unique_ptr<Message> message) override;

      MiddlewareAction Execute(const Subscription &subscription) override;

      static std::shared_ptr<CommandMiddleware> CreateMiddleware(std::list<std::shared_ptr<CommandMiddleware>>::iterator first, std::list<std::shared_ptr<CommandMiddleware>>::iterator last, const Subscription &subscription);
   };
}  // namespace ui

#endif  // MVVM_SIMPLE_CHANNEL_H
