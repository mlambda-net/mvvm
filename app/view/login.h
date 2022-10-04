//
// Created by Roy Gonzalez on 10/1/23.
//

#ifndef MVVM_LOGIN_H
#define MVVM_LOGIN_H

#include "ui/widget/window.h"

namespace ui {

    class Login : Window {



    public:
        ~Login() override;

        void Render() override;

        void RenderChildren() override;

    };

} // namespace ui

#endif //MVVM_LOGIN_H
