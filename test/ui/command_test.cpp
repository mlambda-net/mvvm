//
// Created by Roy Gonzalez on 24/9/22.
//

#include <gtest/gtest.h>
#include <ui/command/message.h>

#include <future>

#include "command/message/event.h"
#include "command/simple_channel.h"
#include "ui/command/engine.h"

TEST(CommandTest, Succes) {
   std::unique_ptr<ui::Message> event = std::make_unique<ui::Event>("");
   auto engine = std::make_shared<ui::CommandEngine>();
   auto channel = std::make_shared<ui::SimpleChannel>();

   std::promise<bool> promise;
   engine->Subscribe(channel, [&promise](std::shared_ptr<ui::Message> message) {
      promise.set_value(true);
      ASSERT_TRUE(message != nullptr);
   });

   engine->Publish(channel, std::move(event));
   auto future = promise.get_future();
   ASSERT_TRUE(future.get());
}

TEST(CommandTest, Middleware) {
   std::unique_ptr<ui::Message> event = std::make_unique<ui::Event>("");
   auto engine = std::make_shared<ui::CommandEngine>();
   auto channel = std::make_shared<ui::SimpleChannel>();

   channel->AddMiddleware([](std::shared_ptr<ui::Middleware> middleware, std::shared_ptr<ui::Message> message) {
      std::cout << "enter" << std::endl;
      middleware->Invoke(message);
      std::cout << "exit" << std::endl;
   });

   std::promise<bool> promise;
   engine->Subscribe(channel, [&promise](std::shared_ptr<ui::Message> message) {
      promise.set_value(true);
      ASSERT_TRUE(message != nullptr);
   });

   engine->Publish(channel, std::move(event));
   auto future = promise.get_future();
   ASSERT_TRUE(future.get());

}