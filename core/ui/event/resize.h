//
// Created by Roy Gonzalez on 9/1/23.
//

#ifndef MVVM_RESIZE_H
#define MVVM_RESIZE_H

#include "command/message.h"

namespace ui {

    class Resize : public command::Message {

    private:
        int x;
        int y;

    public:
        Resize(int x, int y);

        int GetX() const;

        int GetY() const;

    };

} // namespace ui

#endif //MVVM_RESIZE_H
