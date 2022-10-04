
#ifndef MVVM_ENGINE_H
#define MVVM_ENGINE_H

#include <command/channel.h>
#include <command/message.h>

#include <list>
#include <map>

namespace command {

   class Engine {
     private:
      std::map<ChannelType, std::shared_ptr<std::list<Subscription>>> subscriptions;

     public:
      Engine();
      void Subscribe(ChannelType channel, Subscription handler);
      void Publish(ChannelType channel, std::unique_ptr<Message> message);
   };

}  // namespace command

#endif  // MVVM_ENGINE_H
