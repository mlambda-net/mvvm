
//
// Created by Roy Gonzalez on 18/9/22.
//

#ifndef MVVM_SIZE_H
#define MVVM_SIZE_H

namespace ui {
   class Size {
     private:
      int width;
      int height;

     public:
      Size();

      Size(int width, int height);

      int GetWidth() const;

      int GetHeight() const;

      void Resize(int w, int h);
   };
}  // namespace ui

#endif  // MVVM_SIZE_H
