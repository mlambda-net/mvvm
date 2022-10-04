//
// Created by Roy Gonzalez on 6/1/23.
//

#ifndef MVVM_APPGLW_H
#define MVVM_APPGLW_H

#include <GLFW/glfw3.h>
#include <iostream>

#include "ui/widget/app.h"

namespace ui {

    class AppGLW : private App {

    private:
        std::string name;
        GLFWwindow *window;

    public:
        AppGLW();

        explicit AppGLW(std::string name);

        ~AppGLW() override;

        void ConfigureWeb() override;

        void ConfigureDesktop() override;

        void ConfigureMobile() override;

        void Start() override;

        bool Run() override;

        Size GetSize() const override;
    };



} // namespace ui
#endif //MVVM_APPGLW_H
