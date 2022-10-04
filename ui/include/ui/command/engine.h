
#ifndef MVVM_ENGINE_H
#define MVVM_ENGINE_H

#include <list>
#include <map>

#include "channel.h"
#include "message.h"

namespace ui {

   class CommandEngine {
     private:
      std::map<std::shared_ptr<Channel>, std::shared_ptr<std::list<Subscription>>> subscriptions;

     public:
      CommandEngine();
      void Subscribe(std::shared_ptr<Channel> channel, const Subscription &handler);
      void Publish(std::shared_ptr<Channel> channel, std::unique_ptr<Message> message);
   };

}  // namespace ui

#endif  // MVVM_ENGINE_H
