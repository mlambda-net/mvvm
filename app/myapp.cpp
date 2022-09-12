//
// Created by Roy Gonzalez on 9/9/22.
//

#include "include/app/myapp.h"

#include <utility>

MyApp::MyApp(std::string name) : ui::App(std::move(name)) {
   this->principal.SetSize(ui::Size(200, 200));
}

void MyApp::Render() {
   bool show = true;
   this->text.Render();
   this->principal.Render();
   ImGui::ShowDemoWindow(&show);
}

MyApp::~MyApp() = default;
