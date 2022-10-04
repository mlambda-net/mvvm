//
// Created by Roy Gonzalez on 10/1/23.
//

#ifndef MVVM_APPLICATION_H
#define MVVM_APPLICATION_H

#include "appglw.h"
#include "appbase.h"

namespace ui {

class Application : public AppGLW, public AppBase {

    public:
    Application();

    explicit Application(std::string name);
};
} // namespace ui


#endif //MVVM_APPLICATION_H
