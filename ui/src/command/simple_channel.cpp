//
// Created by Roy Gonzalez on 18/9/22.
//

#include "simple_channel.h"
#include "middleware/lambda.h"
#include <utility>

namespace ui {

   SimpleChannel::SimpleChannel() : SimpleChannel("") {}

   SimpleChannel::SimpleChannel(const std::string &name) : name(name) {
   }

   bool ui::SimpleChannel::IsValidMessage(std::unique_ptr<Message> message) { return true; }

   void SimpleChannel::AddMiddleware(std::unique_ptr<Middleware> middleware) {
      auto *item = static_cast<CommandMiddleware *>(middleware.get());

      if (item == nullptr) {
         throw std::invalid_argument("The type should be default middleware");
      }

      this->middlewares.push_back(std::unique_ptr<CommandMiddleware>(std::move(item)));
   }

   std::string SimpleChannel::GetID() { return this->name; }

   MiddlewareAction SimpleChannel::Execute(const Subscription &subscription) {
      auto actual = CreateMiddleware(this->middlewares.begin(), this->middlewares.end(), subscription);
      return [&actual](std::unique_ptr<Message> message) {
         actual->Invoke(std::move(message));
      };
   }

   std::shared_ptr<CommandMiddleware> SimpleChannel::CreateMiddleware(std::list<std::shared_ptr<CommandMiddleware>>::iterator first, std::list<std::shared_ptr<CommandMiddleware>>::iterator last, const Subscription &subscription) {
      if (first == last) {
         auto actual = *first;

         auto lambda = std::make_shared<LambdaMiddleware>([actual](std::unique_ptr<Message> message) {
            actual->Invoke(std::move(message));
         });

         actual->Next(lambda);
         return actual;
      }

      auto next = CreateMiddleware(++first, last, subscription);
      auto actual = *first;
      actual->Next(next);
      return actual;
   }

}  // namespace ui