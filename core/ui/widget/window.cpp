//
// Created by Roy Gonzalez on 17/9/22.
//

#include <imgui.h>
#include <ui/widget/window.h>
#include <utility>

namespace ui {

    void Window::Render() {

        ImGui::SetNextWindowPos(ImVec2(0.0f, 0.0f), ImGuiCond_FirstUseEver);
        ImGui::SetNextWindowSize(ImVec2((float) this->size.GetWidth(), (float) this->size.GetHeight()),ImGuiCond_FirstUseEver);

        if (ImGui::Begin(this->name.c_str())) {
            this->RenderChildren();
        }

        ImGui::End();
    }

    Window::Window(std::string name) {
        this->name = std::move(name);
    }

    Window::~Window() = default;

    void Window::SetSize(ui::Size _size) {
        this->size = _size;
    }

    void Window::RenderChildren() {
        Container::RenderChildren();
    }


}  // namespace ui