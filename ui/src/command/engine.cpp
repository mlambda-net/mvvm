#include <ui/command/engine.h>

namespace ui {
   CommandEngine::CommandEngine() = default;

   void CommandEngine::Subscribe(std::shared_ptr<Channel> channel, const Subscription& handler) {
      auto subscription = this->subscriptions.find(channel);
      if (subscription != this->subscriptions.end()) {
         subscription->second.push_back(handler);
      }
   }

   void CommandEngine::Publish(std::shared_ptr<Channel> channel, std::unique_ptr<Message> message) {
      auto subscription = this->subscriptions.find(channel);
      if (subscription != this->subscriptions.end() &&
          channel->IsValidMessage(std::move(message))) {
         auto actions = subscription->second;
         std::for_each(
             actions.begin(), actions.end(),
             [channel, &message](const Subscription& action) {
                MiddlewareAction middleware = channel->Execute(action);
                middleware(std::move(message));
             });
      }
   }
}  // namespace ui
