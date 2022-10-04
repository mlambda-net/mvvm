#include <command/engine.h>

#include <thread>

namespace command {
   Engine::Engine() = default;

   void Engine::Subscribe(ChannelType channel, Subscription handler) {
      auto subscription = this->subscriptions.find(channel);

      if (subscription == this->subscriptions.end()) {
         auto handlers = this->subscriptions[channel];
         if (handlers == nullptr) {
            handlers = std::make_shared<std::list<Subscription>>();
            this->subscriptions[channel] = handlers;
         }
      }
      auto a = this->subscriptions[channel];
      a->push_back(handler);
   }

   void Engine::Publish(ChannelType channel, std::unique_ptr<Message> message) {
      MessageType msg = message.get();

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
}  // namespace command
