
#ifndef MVVM_MESSAGE_H
#define MVVM_MESSAGE_H

#include <string>

namespace command {
   class Message {
     public:
      virtual ~Message() = default;
   };

   using MessageType = const Message*;
   using FilterFn = std::function<bool(MessageType)>;
   using Subscription = std::function<void(MessageType)>;
}  // namespace command

#endif  // MVVM_MESSAGE_H
