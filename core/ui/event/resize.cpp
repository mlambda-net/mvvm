//
// Created by Roy Gonzalez on 9/1/23.
//

#include "resize.h"

namespace ui {
    Resize::Resize(int x, int y) : x(x), y(y) {
    }

    int Resize::GetX() const {
        return this->x;
    }

    int Resize::GetY() const {
        return this->y;
    }
} // namespace ui