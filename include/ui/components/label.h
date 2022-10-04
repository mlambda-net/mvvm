//
// Created by Roy Gonzalez on 10/1/23.
//

#ifndef MVVM_LABEL_H
#define MVVM_LABEL_H

#include "ui/widget/widget.h"

namespace ui {

    class Label : public Widget {
        private:
        std::string name;

    public:

        Label();

        Label(std::string name);

        ~Label() override = default;

        void Render() override;


    };

} // namespace ui

#endif //MVVM_LABEL_H
