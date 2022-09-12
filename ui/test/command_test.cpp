//
// Created by Roy Gonzalez on 24/9/22.
//

#include <gtest/gtest.h>
#include <ui/command/message.h>

#include "../src/command/message/Event.h"
#include "ui/command/engine.h"

TEST(CommandTest, Succes) {
   auto event = std::make_unique<ui::Event>("");
   auto engine = std::make_unique<ui::CommandEngine>();

   // engine->Publish(event);

   ASSERT_TRUE(true);
}