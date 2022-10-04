
//
// Created by Roy Gonzalez on 6/10/22.
//

#ifndef MVVM_MESSAGE_QUEUE_H
#define MVVM_MESSAGE_QUEUE_H

namespace command {

   class MessageQueue {
     public:
      virtual ~MessageQueue() = default;
   };

}  // namespace command

#endif  // MVVM_MESSAGE_QUEUE_H
