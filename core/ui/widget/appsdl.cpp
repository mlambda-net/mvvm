//
// Created by Roy Gonzalez on 7/10/22.
//

#include "appsdl.h"

#include <cstdio>
#include <imgui_impl_opengl3.h>
#include <imgui_impl_sdl.h>
#include <ui/fonts/material.h>
#include <utility>

#include "../external/spectrum/imgui_spectrum.h"

#if defined(IMGUI_IMPL_OPENGL_ES2)
#include <SDL2/SDL_opengles2.h>
#else

#include <SDL2/SDL_opengl.h>

#endif

namespace ui {

    bool AppSDL::Run() {
        bool done = false;
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            ImGui_ImplSDL2_ProcessEvent(&event);
            switch (event.type) {
                case SDL_QUIT: {
                    done = true;
                    break;
                }
                case SDL_WINDOWEVENT: {
                    if (event.window.windowID == SDL_GetWindowID(this->window)) {
                        switch (event.window.event) {
                            case SDL_WINDOWEVENT_SIZE_CHANGED: {
                                this->size.Resize(event.window.data1,
                                                  event.window.data2);
                                break;
                            }

                            case SDL_WINDOWEVENT_CLOSE: {
                                event.type = SDL_QUIT;
                                SDL_PushEvent(&event);
                                break;
                            }
                        }
                    }
                    break;
                }
            }
        }

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();

        this->Render();
        ImGui::Render();

        SDL_GL_MakeCurrent(this->window, this->glContext);

        ImGuiIO const &io = ImGui::GetIO();
        glViewport(0, 0, (int) io.DisplaySize.x, (int) io.DisplaySize.y);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        SDL_GL_SwapWindow(this->window);

        return done;
    }

    AppSDL::AppSDL() : AppSDL("") {}

    AppSDL::AppSDL(std::string name) {
        this->name = std::move(name);

        if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_GAMECONTROLLER) !=
            0) {
            printf("Error: %s\n", SDL_GetError());
            throw std::runtime_error("Error initialization video");
        }

        // Create window with graphics context
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
        SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
        SDL_DisplayMode current;
        SDL_GetCurrentDisplayMode(0, &current);
        this->size = ui::Size(current.w, current.h);
    }

    AppSDL::~AppSDL() {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplSDL2_Shutdown();
        ImGui::DestroyContext();
        SDL_GL_DeleteContext(this->glContext);
        SDL_DestroyWindow(this->window);
        SDL_Quit();
    }

    void AppSDL::ConfigureWeb() {
        // For the browser using Emscripten, we are going to use WebGL1 with GL
        // ES2. See the Makefile. for requirement details. It is very likely the
        // generated file won't work in many browsers. Firefox is the only sure
        // bet, but I have successfully run this code on Chrome for Android for
        // example.
        const char *glsl_version = "#version 100";
        // const char* glsl_version = "#version 300 es";
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
                            SDL_GL_CONTEXT_PROFILE_ES);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
        this->version = glsl_version;
    }

    void AppSDL::ConfigureDesktop() {
        // Decide GL+GLSL versions
#if defined(IMGUI_IMPL_OPENGL_ES2)
        printf("OPENGL 1");
        // GL ES 2.0 + GLSL 100
        const char *glsl_version = "#version 100";
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
                            SDL_GL_CONTEXT_PROFILE_ES);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
#elif defined(__APPLE__)
        const char *glsl_version = "#version 150";
        SDL_GL_SetAttribute(
                SDL_GL_CONTEXT_FLAGS,
                SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG);  // Always required on Mac
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
                            SDL_GL_CONTEXT_PROFILE_CORE);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
#else
        // GL 3.0 + GLSL 130
        const char *glsl_version = "#version 130";
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
                            SDL_GL_CONTEXT_PROFILE_CORE);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
#endif

        this->version = glsl_version;
    }

    void AppSDL::ConfigureMobile() { this->version = "none"; }

    void AppSDL::Start() {
        auto window_flags =
                (SDL_WindowFlags) (SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE |
                                   SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_MINIMIZED |
                                   SDL_WINDOW_MAXIMIZED);

        this->window = SDL_CreateWindow(
                this->name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                this->size.GetWidth(), this->size.GetHeight(), window_flags);
        this->glContext = SDL_GL_CreateContext(window);

        SDL_GL_MakeCurrent(window, this->glContext);
        SDL_GL_SetSwapInterval(1);  // Enable vsync

        IMGUI_CHECKVERSION();
        ImGui::CreateContext();

        ImGuiIO &io = ImGui::GetIO();
        (void) io;
        io.IniFilename = nullptr;
        io.Fonts->AddFontFromFileTTF("fonts/Roboto-Regular.ttf", 17.0f);

        auto *material = ui::MaterialFont::GetInstance();
        const ImWchar icons_ranges[] = {(ImWchar) ui::MaterialSize::MIN_MD, (ImWchar) ui::MaterialSize::MAX_16_MD, 0};
        ImFontConfig icons_config;
        icons_config.MergeMode = true;
        icons_config.PixelSnapH = true;
        io.Fonts->AddFontFromFileTTF(
                material->GetFileName(),
                16.0f, &icons_config, icons_ranges);

        io.Fonts->Build();

        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

        ImGui::Spectrum::StyleColorsSpectrum();

        ImGuiStyle *style = &ImGui::GetStyle();
        style->WindowRounding = 5.0f;
        style->FrameRounding = 3.0f;
        style->WindowMenuButtonPosition = ImGuiDir_None;
        style->WindowTitleAlign = ImVec2(0.01f, 0.5f);

        ImGui_ImplSDL2_InitForOpenGL(this->window, this->glContext);
        ImGui_ImplOpenGL3_Init(this->version);
    }

    Size AppSDL::GetSize() const { return this->size; }

}  // namespace ui