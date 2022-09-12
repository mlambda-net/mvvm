project(app)

set(MY_EXECUTABLE_SOURCES
        myapp.cpp
        include/app/myapp.h
)

add_library(app ${MY_EXECUTABLE_SOURCES})

target_include_directories(app PUBLIC ../ui/include)

target_link_libraries(app PRIVATE ui)


