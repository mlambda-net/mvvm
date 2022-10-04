//
// Created by Roy Gonzalez on 10/1/23.
//

#ifndef MVVM_LOGIN_H
#define MVVM_LOGIN_H

#include "ui/widget/window.h"
#include "ui/components/button.h"
#include "ui/components/label.h"
#include "ui/components/text.h"



    class Login : ui::Window {
    private:
        std::shared_ptr<ui::Label> userLabel;
        std::shared_ptr<ui::Label> passwordLabel;
        std::shared_ptr<ui::Text> userText;
        std::shared_ptr<ui::Text> passwordText;
        std::shared_ptr<ui::Button> loginButton;
        std::shared_ptr<ui::Button> cancelButton;

    public:
        Login();

        void Load() override;
    };



#endif //MVVM_LOGIN_H
