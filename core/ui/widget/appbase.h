//
// Created by Roy Gonzalez on 10/1/23.
//

#ifndef MVVM_APPBASE_H
#define MVVM_APPBASE_H

#include "ui/widget/window.h"
#include "principal.h"

namespace ui {

    class AppBase {
    private:
        //Principal principal;

    public:
        void AddMenu();

        void AddWindow(std::unique_ptr<Window> window);

        void Show();

    };
}// namespace ui



#endif //MVVM_APPBASE_H
