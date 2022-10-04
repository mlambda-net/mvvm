
#include <command/message.h>

#ifndef MVVM_EVENT_H
#define MVVM_EVENT_H

namespace command {

   class Event : public Message {
     private:
      std::string name;

     public:
      explicit Event(const std::string &name);
   };

}  // namespace command

#endif  // MVVM_EVENT_H
