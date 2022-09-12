project(web)

set(MY_EXECUTABLE_SOURCES
        main.cpp
        )

add_executable(web ${MY_EXECUTABLE_SOURCES})

target_include_directories(web PUBLIC ../ui/include)
target_include_directories(web PUBLIC ../app/include)


SET(LINK_FLAGS "-g0 -s USE_SDL=2 -s FULL_ES2=1 -s WASM=1 -s ASSERTIONS=0 -s ALLOW_MEMORY_GROWTH=1 -s NO_EXIT_RUNTIME=0 -s USE_PTHREADS=0 -s
ASYNCIFY -s MAX_WEBGL_VERSION=2 -lembind  --shell-file=${PROJECT_SOURCE_DIR}/shell_minimal.html --preload-file=${PROJECT_BINARY_DIR}/fonts@/fonts")

set(CMAKE_EXECUTABLE_SUFFIX ".html")

set_target_properties(web PROPERTIES LINK_FLAGS ${LINK_FLAGS})

target_link_libraries(web PRIVATE ui)
target_link_libraries(web PRIVATE app)


