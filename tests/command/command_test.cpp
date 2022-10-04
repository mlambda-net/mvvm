
//
// Created by Roy Gonzalez on 24/9/22.
//

#include <gtest/gtest.h>
#include <command/basic-channel.h>
#include <command/engine.h>
#include <command/message.h>
#include <command/message/event.h>

#include <chrono>
#include <future>

TEST(CommandTest, Succes) {
    std::unique_ptr<command::Message> event = std::make_unique<command::Event>("");
    auto engine = std::make_shared<command::Engine>();
    auto channel = std::make_shared<command::BasicChannel>();

    std::promise<bool> promise;
    engine->Subscribe(channel, [&promise](command::MessageType message) {
        promise.set_value(true);
        ASSERT_TRUE(message != nullptr);
    });

    engine->Publish(channel, std::move(event));
    auto future = promise.get_future();
    ASSERT_TRUE(future.get());
}

TEST(CommandTest, Middleware) {
    std::unique_ptr<command::Message> event = std::make_unique<command::Event>("");
    auto engine = std::make_shared<command::Engine>();
    auto channel = std::make_shared<command::BasicChannel>();

    channel->AddMiddleware([](command::MiddlewareType middleware, command::MessageType message) {
        auto start = std::chrono::high_resolution_clock::now();
        middleware->Invoke(message);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = duration_cast<std::chrono::microseconds>(stop - start);
        std::cout << "duration: " << duration.count() << " µs" << std::endl;
    });

    std::promise<bool> promise;
    engine->Subscribe(channel, [&promise](command::MessageType message) {
        promise.set_value(true);
        ASSERT_TRUE(message != nullptr);
    });

    engine->Publish(channel, std::move(event));
    auto future = promise.get_future();
    ASSERT_TRUE(future.get());
}

TEST(CommandTest, DoubleMiddleware) {
    std::unique_ptr<command::Message> event = std::make_unique<command::Event>("");
    auto engine = std::make_shared<command::Engine>();
    auto channel = std::make_shared<command::BasicChannel>();

    auto middleware_a_called = false;
    channel->AddMiddleware([&middleware_a_called](command::MiddlewareType middleware, command::MessageType message) {
        auto start = std::chrono::high_resolution_clock::now();
        middleware->Invoke(message);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = duration_cast<std::chrono::microseconds>(stop - start);
        std::cout << "duration: " << duration.count() << " µs" << std::endl;
        middleware_a_called = true;
    });

    auto middleware_b_called = false;
    channel->AddMiddleware([&middleware_b_called](command::MiddlewareType middleware, command::MessageType message) {
        std::cout << "enter" << std::endl;
        middleware->Invoke(message);
        std::cout << "exit" << std::endl;
        middleware_b_called = true;
    });

    std::promise<bool> promise;
    engine->Subscribe(channel, [&promise](command::MessageType message) {
        promise.set_value(true);
        ASSERT_TRUE(message != nullptr);
    });

    engine->Publish(channel, std::move(event));
    auto future = promise.get_future();
    ASSERT_TRUE(future.get());
    ASSERT_TRUE(middleware_a_called);
    ASSERT_TRUE(middleware_b_called);
}

TEST(CommandTest, DMDS) {
    std::unique_ptr<command::Message> event = std::make_unique<command::Event>("");
    auto engine = std::make_shared<command::Engine>();
    auto channel = std::make_shared<command::BasicChannel>();

    channel->AddMiddleware([](command::MiddlewareType middleware, command::MessageType message) {
        auto start = std::chrono::high_resolution_clock::now();
        middleware->Invoke(message);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = duration_cast<std::chrono::microseconds>(stop - start);
        std::cout << "duration: " << duration.count() << " µs" << std::endl;
    });

    channel->AddMiddleware([](command::MiddlewareType middleware, command::MessageType message) {
        std::cout << "enter" << std::endl;
        middleware->Invoke(message);
        std::cout << "exit" << std::endl;
    });

    std::promise<bool> promise_a;
    engine->Subscribe(channel, [&promise_a](command::MessageType message) {
        promise_a.set_value(true);
        ASSERT_TRUE(message != nullptr);
    });

    std::promise<bool> promise_b;
    engine->Subscribe(channel, [&promise_b](command::MessageType message) {
        promise_b.set_value(true);
        std::cout << "other subscription" << std::endl;
    });

    engine->Publish(channel, std::move(event));
    auto future_a = promise_a.get_future();
    ASSERT_TRUE(future_a.get());
    auto future_b = promise_b.get_future();
    ASSERT_TRUE(future_b.get());
}