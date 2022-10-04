//
// Created by Roy Gonzalez on 10/1/23.
//

#include "principal.h"

#include <imgui.h>

namespace ui {


    void Principal::Render() {

        auto const *viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowPos( viewport->Pos);
        ImGui::SetNextWindowSize(viewport->Size);

        static ImGuiWindowFlags flags = ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoSavedSettings;

        if (ImGui::Begin(this->name.c_str(), nullptr, flags)) {
            this->RenderChildren();
        }

        ImGui::End();
    }

    Principal::Principal() {
        this->name = "Principal";
    }
} // namespace ui