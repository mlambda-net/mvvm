//
// Created by Roy Gonzalez on 9/9/22.
//

#ifndef MVVM_TEXT_H
#define MVVM_TEXT_H

#include <ui/widget/widget.h>

#include <iostream>

namespace ui {

   class Text : public Widget {
      std::string text;

     public:
      Text() = default;

      virtual ~Text() = default;

      explicit Text(std::string text);

      void Render() override;
   };

}  // namespace ui

#endif  // MVVM_TEXT_H
