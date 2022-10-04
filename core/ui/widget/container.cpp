//
// Created by Roy Gonzalez on 18/9/22.
//

#include <ui/widget/container.h>

#include <ranges>

namespace ui {

    void Container::AddWidget(std::shared_ptr<Widget> w) {
        this->widgets.push_back(w);
    }

    void Container::Render() {
        this->Load();
    }

    void Container::RenderChildren() {
        std::ranges::for_each(this->widgets, [](std::shared_ptr<Widget> widget) {
            widget->Render();
        });
    }

    void Container::Load() {

    }
}