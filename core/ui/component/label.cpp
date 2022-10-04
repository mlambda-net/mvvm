//
// Created by Roy Gonzalez on 10/1/23.
//



#include <imgui.h>
#include <ui/components/label.h>

namespace ui {
    void ui::Label::Render() {
        ImGui::Text(" %s", this->name.c_str());
    }

    Label::Label(const std::string name): name(name) {
    }
} // namespace ui