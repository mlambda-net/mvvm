cmake_minimum_required(VERSION 3.24)

set(CMAKE_TOOLCHAIN_FILE ~/tools/vcpkg/scripts/buildsystems/vcpkg.cmake CACHE STRING "Vcpkg toolchain file")

project(mvvm)

set(Boost_NO_WARN_NEW_VERSIONS 1)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")
set(BUILD_FLAGS ${BUILD_FLAGS} -std=c++20)
set(LINK_FLAGS ${LINK_FLAGS} -stdlib=libc++ -fuse-ld=lld -v)

include(header)
include(groups)
include(fonts)

option(USE_WEB "compile using web" OFF)
option(BUILD_TESTING "include testing" ON)

find_package(imgui CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(Boost  REQUIRED COMPONENTS log CONFIG)
find_package(freetype CONFIG REQUIRED)
find_package(GTest CONFIG REQUIRED)
find_package(matchit CONFIG REQUIRED)

add_subdirectory(app)
add_subdirectory(core)

if (USE_WEB)
    SET("PROJECT" web)
    add_subdirectory(web)
else ()
    SET("PROJECT" cmd)
    add_subdirectory(cmd)
endif ()

if (BUILD_TESTING)
    enable_testing()
    include(GoogleTest)
    add_subdirectory(tests)
endif ()

