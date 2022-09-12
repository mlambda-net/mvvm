project(myapp)

set(MY_EXECUTABLE_SOURCES
        main.cpp
)

add_executable(myapp ${MY_EXECUTABLE_SOURCES})

target_include_directories(myapp PUBLIC ../ui/include)
target_include_directories(myapp PUBLIC ../app/include)


target_link_libraries(myapp PRIVATE ui)
target_link_libraries(myapp PRIVATE app)


