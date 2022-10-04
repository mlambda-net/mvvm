//
// Created by Roy Gonzalez on 18/9/22.
//

#ifndef MVVM_CONTAINER_H
#define MVVM_CONTAINER_H

#include "widget.h"
#include <iostream>
#include <iterator>
#include <list>

namespace ui {

    class Container  : public ui::Widget {
    private:
        std::list<std::shared_ptr<Widget>> widgets;


    public:
        void AddWidget(std::shared_ptr<Widget> w);
        virtual void Load();
        void Render() override;
        virtual void RenderChildren() ;
    };

}

#endif  // MVVM_CONTAINER_H
