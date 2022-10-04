//
// Created by Roy Gonzalez on 6/1/23.
//

#include "appglw.h"
#include "../external/spectrum/imgui_spectrum.h"


#include <GLFW/glfw3.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <ui/fonts/material.h>

static void glfw_error_callback(int error, const char* description)
{
    fprintf(stderr, "Glfw OnError %d: %s\n", error, description);
}

ui::AppGLW::~AppGLW() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();
}

ui::AppGLW::AppGLW() {
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit()) {
        printf("Bad initialization");
    }

}

ui::AppGLW::AppGLW(std::string name)  {
    this->name = name;
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit()) {
        printf("Bad initialization");
    }
}

void ui::AppGLW::ConfigureWeb() {
}

void ui::AppGLW::ConfigureMobile() {
}

void ui::AppGLW::ConfigureDesktop() {
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // Required on Mac
}

void ui::AppGLW::Start() {

    const char *glsl_version = "#version 150";

    this->window = glfwCreateWindow(1280, 720, this->name.c_str(), nullptr, nullptr);
    if (this->window == nullptr) {
        printf("Failed to create");
    }

    glfwMakeContextCurrent(this->window);
    glfwSwapInterval(1); // Enable vsync

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    (void) io;
    ImGui::StyleColorsDark();

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


    ImGui_ImplGlfw_InitForOpenGL(this->window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);
}


bool ui::AppGLW::Run() {

    while (!glfwWindowShouldClose(this->window))
    {
        // Poll and handle events (inputs, window resize, etc.)
        // You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
        // - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application, or clear/overwrite your copy of the mouse data.
        // - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application, or clear/overwrite your copy of the keyboard data.
        // Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
        glfwPollEvents();

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        this->Render();
        ImGui::Render();

        int display_w;
        int display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);

        glViewport(0, 0, display_w, display_h);

        //glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);

        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwSwapBuffers(this->window);
    }

    return true;
}

ui::Size ui::AppGLW::GetSize() const {
    return ui::Size();
}

