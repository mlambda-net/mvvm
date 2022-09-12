//
// Created by Roy Gonzalez on 9/9/22.
//

#include <imgui.h>
#include <ui/fonts/material.h>
#include <ui/text.h>

#include <boost/format.hpp>
#include <utility>


namespace ui {

   void Text::Render() {
      ImGui::Text(" %s", this->text.c_str());

      ImGui::Text("%s PRINT",
                  this->icons->GetString(ui::MaterialIcon::MD_PRINT).c_str());
   }

   Text::Text(std::string text) { this->text = std::move(text); }

}