//
// Created by Roy Gonzalez on 17/9/22.
//

#include "ui/window.h"

#include <imgui.h>
#include <SDL_video.h>

#include <utility>

namespace ui {

   void Window::Render() {
      ImGui::SetNextWindowPos(ImVec2(0.0f, 0.0f), ImGuiCond_FirstUseEver);
      ImGui::SetNextWindowSize(
          ImVec2((float)this->size.GetWidth(), (float)this->size.GetHeight()),
          ImGuiCond_FirstUseEver);
      if (ImGui::Begin(this->name.c_str())) {
      }
      ImGui::End();
   }

   Window::Window(std::string name) { this->name = std::move(name); }

   Window::~Window() {}

   void Window::SetSize(ui::Size size) { this->size = size; }
}