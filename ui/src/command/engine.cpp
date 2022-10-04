#include <ui/command/engine.h>

#include <thread>

namespace ui {
   CommandEngine::CommandEngine() = default;

   void CommandEngine::Subscribe(std::shared_ptr<Channel> channel, const Subscription& handler) {
      auto subscription = this->subscriptions.find(channel);

      if (subscription == this->subscriptions.end()) {
         auto handlers = this->subscriptions[channel];
         if (handlers == nullptr) {
            handlers = std::make_shared<std::list<Subscription>>();
            this->subscriptions[channel] = handlers;
         }

         auto a = this->subscriptions[channel];
         a->push_back(handler);
      }
   }

   void CommandEngine::Publish(std::shared_ptr<Channel> channel, std::unique_ptr<Message> message) {
      std::shared_ptr<Message> msg = std::move(message);

      auto subscription = this->subscriptions.find(channel);
      if (subscription != this->subscriptions.end() && channel->IsValidMessage(msg)) {
         auto actions = subscription->second;
         std::for_each(
             actions->begin(), actions->end(),
             [channel, &msg](const Subscription& action) {
                MiddlewareAction middleware = channel->Execute(action);
                std::thread process(middleware, msg);
                process.join();
             });
      }
   }
}  // namespace ui
