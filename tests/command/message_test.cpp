//
// Created by Roy Gonzalez on 4/10/22.
//

#include <gtest/gtest.h>
#include <command/basic-channel.h>
#include <command/engine.h>
#include <command/message.h>
#include <matchit.h>

#include <future>
#include <semaphore>

#include "message/dummy.h"
#include "message/event.h"

TEST(MessageTest, Succes) {
    std::unique_ptr<command::Message> event = std::make_unique<Dummy>("Hello world!");
    auto engine = std::make_shared<command::Engine>();
    auto channel = std::make_shared<command::BasicChannel>();

    std::promise<bool> promise;

    engine->Subscribe(channel, [&](command::MessageType msg) {
        using namespace matchit;
        match(*msg)(
                pattern | as<Dummy>(_) = [msg] {
                    if (auto *dummy = dynamic_cast<const Dummy *>(msg)) {
                        std::cout << dummy->GetMessage() << std::endl;
                    }
                });
        promise.set_value(true);
    });

    engine->Publish(channel, std::move(event));
    auto future = promise.get_future();
    ASSERT_TRUE(future.get());
}

TEST(MessageTest, FilterLogic) {
    auto engine = std::make_shared<command::Engine>();
    auto channel = std::make_shared<command::BasicChannel>();

    std::counting_semaphore<2> semaphore(0);

    channel->Filter([&](command::MessageType message) -> bool {
        semaphore.release();
        using namespace matchit;
        return match(*message)(
                pattern | as<Dummy>(_) = expr(true),
                pattern | _ = expr(false));
    });

    bool eventWasCalled = false;
    bool dummyWasCalled = false;
    engine->Subscribe(channel, [&](command::MessageType msg) {
        using namespace matchit;
        match(*msg)(
                pattern | as<Dummy>(_) = [&] {
                    dummyWasCalled = true;
                },
                pattern | as<Event>(_) = [&] {
                    eventWasCalled = true;
                });
    });

    engine->Publish(channel, std::make_unique<Dummy>("Hello world!"));
    semaphore.acquire();
    engine->Publish(channel, std::make_unique<Event>());
    semaphore.acquire();
    ASSERT_TRUE(dummyWasCalled);
    ASSERT_FALSE(eventWasCalled);
}