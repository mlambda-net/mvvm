//
// Created by Roy Gonzalez on 18/9/22.
//

#include <ui/common/size.h>

ui::Size::Size() : Size(0, 0) {}

ui::Size::Size(int width, int height) : width(width), height(height) {
}

int ui::Size::GetWidth() const { return this->width; }

int ui::Size::GetHeight() const { return this->height; }

void ui::Size::Resize(int w, int h) {
   this->width = w;
   this->height = h;
}
