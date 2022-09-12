//
// Created by Roy Gonzalez on 9/9/22.
//

#ifndef MVVM_WIDGET_H
#define MVVM_WIDGET_H

#include "ui/fonts/material.h"

namespace ui {

   class Widget {
     protected:
      MaterialFont *icons;

     public:
      Widget();
      virtual ~Widget() = default;
      virtual void Render() = 0;
   };

}  // namespace ui

#endif  // MVVM_WIDGET_H
