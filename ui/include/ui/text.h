//
// Created by Roy Gonzalez on 9/9/22.
//

#ifndef MVVM_TEXT_H
#define MVVM_TEXT_H

#include <iostream>

#include "widget.h"

namespace ui {

   class Text : public ui::Widget {
      std::string text;

     public:
      Text() = default;

      virtual ~Text() = default;

      explicit Text(std::string text);

      void Render() override;
   };

}  // namespace ui

#endif  // MVVM_TEXT_H
