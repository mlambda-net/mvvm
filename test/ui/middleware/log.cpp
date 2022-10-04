//
// Created by Roy Gonzalez on 3/10/22.
//

#include "log.h"

namespace mock {
   void Log::Invoke(std::shared_ptr<ui::Message> message) {
      this->next->Invoke(message);
   }
}  // namespace mock