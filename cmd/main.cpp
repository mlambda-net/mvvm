
#include <iostream>
#include <app/myapp.h>


int main() {


    try {

        auto app = new MyApp("My App");
        app->ConfigureDesktop();
        app->Start();
        auto done = false;
        while (!done) {
            done = app->Run();
        }
    } catch (std::exception e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
