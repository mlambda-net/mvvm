
#include <myapp.h>

#include <iostream>

#ifdef EMSCRIPTEN
#include <emscripten.h>
#endif

void loop(void *arg) {
   auto *app = static_cast<MyApp *>(arg);
   app->Run();
}

int main() {
   try {
      auto *app = new MyApp("My web APP");
      app->ConfigureWeb();
      app->Start();

#ifdef __EMSCRIPTEN__
      emscripten_set_main_loop_arg(loop, app, 0, true);

#endif

   } catch (std::exception e) {
      std::cout << e.what() << std::endl;
   }

   return 0;
}
