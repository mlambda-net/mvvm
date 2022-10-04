//
// Created by Roy Gonzalez on 4/10/22.
//

#ifndef MVVM_DUMMY_H
#define MVVM_DUMMY_H

#include <command/message.h>

class Dummy : public command::Message {
  private:
   std::string message;

  public:
   Dummy();
   Dummy(std::string message);
   std::string GetMessage() const;
};

#endif  // MVVM_DUMMY_H
