//
// Created by Roy Gonzalez on 10/1/23.
//

#include "login.h"



    Login::Login() {
        this->userLabel = std::make_shared<ui::Label>("User");
        this->passwordLabel = std::make_shared<ui::Label>("Password");
        this->userText = std::make_shared<ui::Text>();
        this->passwordText = std::make_shared<ui::Text>();
        this->loginButton = std::make_shared<ui::Button>("Login");
        this->cancelButton = std::make_shared<ui::Button>("Cancel");
    }

    void Login::Load() {
        this->AddWidget(this->userLabel);
        this->AddWidget(this->passwordLabel);
        this->AddWidget(this->userText);
        this->AddWidget(this->passwordText);
        this->AddWidget(this-> loginButton);
        this->AddWidget(this-> cancelButton);
    }
