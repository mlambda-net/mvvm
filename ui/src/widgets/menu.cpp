//
// Created by Roy Gonzalez on 17/9/22.
//

#include "ui/menu.h"

#include <imgui.h>

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>

namespace ui {

   Menu::Menu() : Menu("", ui::MaterialIcon::None) {
   }

   Menu::Menu(const std::string &name) : Menu(name, ui::MaterialIcon::None) {
   }

   Menu::Menu(const std::string &name, ui::MaterialIcon icon) : name(name), icon(icon) {
   }

   Menu::~Menu() = default;

   void Menu::Render() {
      std::stringstream menuName;

      if (this->icon != ui::MaterialIcon::None) {
         menuName << this->icons->GetString(this->icon) << " " << this->name;
      } else {
         menuName << this->name;
      }

      if (ImGui::Begin(menuName.str().c_str())) {
         for_each(this->children.begin(), this->children.end(),
                  [](Menu child) {
                     child.Render();
                  });

         ImGui::EndMenu();
      }
   }

   void Menu::AddMenu(Menu &menu) {
      this->children.push_back(menu);
   }
}  // namespace ui