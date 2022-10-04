
//
// Created by Roy Gonzalez on 9/9/22.
//

#ifndef MVVM_MYAPP_H
#define MVVM_MYAPP_H

#include <ui/components/text.h>
#include <ui/widget/window.h>

#include "myapp.h"
#include "ui/widget/application.h"

class MyApp : public ui::Application {

public:
    MyApp(std::string name);

    ~MyApp();

    void Render() override;
};

#endif  // MVVM_MYAPP_H
