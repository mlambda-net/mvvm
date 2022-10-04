//
// Created by Roy Gonzalez on 3/10/22.
//

#ifndef MVVM_LOG_H
#define MVVM_LOG_H

#include "ui/command/middleware.h"

namespace mock {

   class Log : public ui::Middleware {
      void Invoke(std::shared_ptr<ui::Message> message) override;
   };

}  // namespace mock

#endif  // MVVM_LOG_H
