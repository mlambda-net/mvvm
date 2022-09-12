//
// Created by Roy Gonzalez on 17/9/22.
//

#ifndef MVVM_WINDOW_H
#define MVVM_WINDOW_H

#include <string>

#include "ui/common/size.h"
#include "widget.h"

namespace ui {

   class Window final : public ui::Widget {
     private:
      ui::Size size;
      std::string name;

     public:
      Window() = default;
      explicit Window(std::string name);
      ~Window() override;
      void Render() override;
      void SetSize(ui::Size size);
   };
}  // namespace ui

#endif  // MVVM_WINDOW_H
