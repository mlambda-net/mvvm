project(app)
set(CMAKE_CXX_STANDARD 23)

set(APP_SRC_LIST
        myapp.h
        myapp.cpp
        view/login.h
        view/login.cpp
        viewmodel/LoginViewModel.cpp
        viewmodel/LoginViewModel.h
        model/user.cpp
        model/user.h
        )

add_compile_options(${BUILD_FLAGS})
add_link_options(${LINK_FLAGS})

add_library(${PROJECT_NAME} ${APP_SRC_LIST})

target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIR})
target_include_directories(${PROJECT_NAME} PUBLIC ../core)

target_link_libraries(${PROJECT_NAME} PUBLIC imgui::imgui)
target_link_libraries(${PROJECT_NAME} INTERFACE glfw)
target_link_libraries(${PROJECT_NAME} PRIVATE core)





