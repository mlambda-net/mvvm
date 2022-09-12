//
// Created by Roy Gonzalez on 9/9/22.
//

#ifndef MVVM_APP_H
#define MVVM_APP_H

#include <imgui.h>
#include <SDL2/SDL.h>

#if defined(IMGUI_IMPL_OPENGL_ES2)
#include <SDL2/SDL_opengles2.h>
#else
#include <SDL2/SDL_opengl.h>
#endif

#include <ui/common/size.h>

#include <string>

namespace ui {

   class App {
      std::string name;
      const char *version;
      SDL_GLContext glContext;
      SDL_Window *window;
      ui::Size size;

     public:
      App(std::string name);
      ~App();
      void ConfigureWeb();
      void ConfigureDesktop();
      void ConfigureMobile();
      void Start();
      bool Run();
      ui::Size GetSize() const;
      virtual void Render() = 0;
   };
}  // namespace ui

#endif  // MVVM_APP_H
