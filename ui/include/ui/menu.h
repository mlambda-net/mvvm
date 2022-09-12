//
// Created by Roy Gonzalez on 17/9/22.
//

#ifndef MVVM_MENU_H
#define MVVM_MENU_H

#include <list>
#include <string>

#include "ui/fonts/material.h"
#include "widget.h"

namespace ui {

   class Menu : public ui::Widget {
     private:
      std::string name;
      ui::MaterialIcon icon;
      std::function<void()> action;
      std::list<Menu> children;

     public:
      Menu();

      explicit Menu(const std::string& name);

      Menu(const std::string& name, ui::MaterialIcon icon);

      virtual ~Menu();

      void AddMenu(Menu& menu);

      void Render() override;
   };

}  // namespace ui

#endif  // MVVM_MENU_H
