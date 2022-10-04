
//
// Created by Roy Gonzalez on 7/10/22.
//

#ifndef MVVM_APPSDL_H
#define MVVM_APPSDL_H

#include <SDL2/SDL.h>
#include <ui/common/size.h>

#include <iostream>

#include "ui/widget/app.h"

namespace ui {
    class AppSDL : private App {
    private:
        std::string name;
        const char *version;
        SDL_GLContext glContext;
        SDL_Window *window;
        Size size;

    public:
        AppSDL();

        explicit AppSDL(std::string name);

        ~AppSDL() override;

        void ConfigureWeb() override;

        void ConfigureDesktop() override;

        void ConfigureMobile() override;

        void Start() override;

        bool Run() override;

        Size GetSize() const override;
    };

}  // namespace ui
#endif  // MVVM_APPSDL_H
