//
// Created by Roy Gonzalez on 9/9/22.
//

#ifndef MVVM_MYAPP_H
#define MVVM_MYAPP_H


#include <ui/app.h>
#include <ui/text.h>
#include <ui/window.h>


class MyApp : public ui::App {
   ui::Text text = ui::Text("Hello World!!!!");
   ui::Window principal = ui::Window("My First App");

  public:
   MyApp(std::string name);
   ~MyApp();
   void Render() override;
};


#endif  // MVVM_MYAPP_H
