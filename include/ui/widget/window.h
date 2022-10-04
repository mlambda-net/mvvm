//
// Created by Roy Gonzalez on 17/9/22.
//
#ifndef MVVM_WINDOW_H
#define MVVM_WINDOW_H

#include <string>

#include "ui/common/size.h"
#include "container.h"
#include "widget.h"

namespace ui {

    class Window : public ui::Container {
    protected:
        ui::Size size;
        std::string name;

    public:
        Window() = default;

        explicit Window(std::string name);

        ~Window() ;

        void Render() override;

        void RenderChildren() override;

        void SetSize(ui::Size size);
    };

}  // namespace ui

#endif  // MVVM_WINDOW_H


