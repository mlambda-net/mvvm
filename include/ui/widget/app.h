
//
// Created by Roy Gonzalez on 9/9/22.
//

#ifndef MVVM_APP_H
#define MVVM_APP_H

#include <ui/common/size.h>

namespace ui {

    class App {
    public:
        virtual ~App() = default;

        virtual void ConfigureWeb() = 0;

        virtual void ConfigureDesktop() = 0;

        virtual void ConfigureMobile() = 0;

        virtual void Start() = 0;

        virtual bool Run() = 0;

        virtual Size GetSize() const = 0;

        virtual void Render() = 0;
    };
}  // namespace ui

#endif  // MVVM_APP_H
