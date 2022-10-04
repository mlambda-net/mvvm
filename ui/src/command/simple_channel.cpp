//
// Created by Roy Gonzalez on 18/9/22.
//

#include "simple_channel.h"

#include <utility>

#include "middleware/empty.h"
#include "middleware/functor.h"
#include "middleware/lambda.h"

namespace ui {

   SimpleChannel::SimpleChannel() : SimpleChannel("") {}

   SimpleChannel::SimpleChannel(const std::string &name) : name(name) {
   }

   bool ui::SimpleChannel::IsValidMessage(std::shared_ptr<Message> message) { return true; }

   void SimpleChannel::AddMiddleware(std::unique_ptr<Middleware> middleware) {
      std::shared_ptr<Middleware> item = std::move(middleware);
      this->middlewares.push_back(std::shared_ptr<Middleware>(item));
   }

   std::string SimpleChannel::GetID() { return this->name; }

   MiddlewareAction SimpleChannel::Execute(const Subscription &subscription) {
      if (this->middlewares.empty()) {
         return [subscription](std::shared_ptr<Message> message) {
            subscription(message);
         };
      }

      auto actual = CreateMiddleware(this->middlewares.begin(), this->middlewares.end(), subscription);

      return [actual](std::shared_ptr<Message> message) {
         actual->Invoke(message);
      };
   }

   std::shared_ptr<Middleware> SimpleChannel::CreateMiddleware(
       std::list<std::shared_ptr<Middleware>>::iterator first,
       std::list<std::shared_ptr<Middleware>>::iterator last,
       const Subscription &subscription) {
      if (first == last) {
         return std::make_shared<LambdaMiddleware>(subscription);
      }

      auto actual = *first;
      auto next = CreateMiddleware(++first, last, subscription);
      actual->Next(next);
      return actual;
   }

   void SimpleChannel::AddMiddleware(std::function<void(std::shared_ptr<Middleware>, std::shared_ptr<Message>)> middleware) {
      std::shared_ptr<Middleware> mid = std::make_shared<FunctorMiddleware>(middleware);
      this->middlewares.push_back(mid);
   }

}  // namespace ui