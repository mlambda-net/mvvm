//
// Created by Roy Gonzalez on 9/9/22.
//

#include "myapp.h"

#include <utility>

MyApp::MyApp(std::string name) : ui::Application(std::move(name)) {

}

void MyApp::Render() {
    this->Show();

}

MyApp::~MyApp() = default;
