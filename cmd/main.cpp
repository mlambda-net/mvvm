
#include <iostream>

#include "myapp.h"

int main() {
   try {
      std::unique_ptr<MyApp> app = std::make_unique<MyApp>("My App");
      app->ConfigureDesktop();
      app->Start();
      auto done = false;
      while (!done) {
         done = app->Run();
      }
   } catch (std::exception *e) {
      std::cout << e->what() << std::endl;
   }
   return 0;
}
