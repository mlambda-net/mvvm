cmake_minimum_required(VERSION 3.24)
project(mvvm)

set(Boost_NO_WARN_NEW_VERSIONS 1)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_TOOLCHAIN_FILE ${HOME}/tools/vcpkg/scripts/buildsystems/vcpkg.cmake CACHE STRING "Vcpkg toolchain file")

option(USE_WEB "compile using web" OFF)

find_package(imgui CONFIG REQUIRED)
find_package(SDL2 CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(Boost 1.80 COMPONENTS REQUIRED)
find_package(freetype CONFIG REQUIRED)
find_package(GTest CONFIG REQUIRED)


if (USE_WEB)
    SET("PROJECT" web)
    add_subdirectory(web)
else ()
    SET("PROJECT" cmd)
    add_subdirectory(cmd)
endif ()


add_subdirectory(ui)
add_subdirectory(app)


