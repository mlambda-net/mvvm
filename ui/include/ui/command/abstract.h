
#ifndef MVVM_ABSTRACT_H
#define MVVM_ABSTRACT_H

#include <iostream>

#include "message.h"

namespace ui {
   using MiddlewareAction = std::function<void(std::unique_ptr<Message>)>;
   using Subscription = std::function<void(std::unique_ptr<Message>)>;
}  // namespace ui

#endif  // MVVM_ABSTRACT_H
