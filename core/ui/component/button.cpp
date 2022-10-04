//
// Created by Roy Gonzalez on 10/1/23.
//


#include <ui/components/button.h>
#include <imgui.h>

namespace ui {
    void ui::Button::Render() {
        if (ImGui::Button(this->name.c_str())) {

        }
    }

    Button::Button(const std::string &name): name(name) {
    }

    Button::Button(): Button("") {
    }
} // namespace ui