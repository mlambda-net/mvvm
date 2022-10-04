//
// Created by Roy Gonzalez on 10/1/23.
//

#ifndef MVVM_BUTTON_H
#define MVVM_BUTTON_H

#include <ui/widget/widget.h>

namespace ui {

    class Button : public Widget {
        private:
        std::string name;

    public:

        Button();
        Button(const std::string& name);

        ~Button() override = default;

        void Render() override;
    };

} // namespace ui

#endif //MVVM_BUTTON_H
