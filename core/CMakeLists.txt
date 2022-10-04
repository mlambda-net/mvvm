project(core)

add_compile_options(${BUILD_FLAGS})
add_link_options(${LINK_FLAGS})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

include(command)
include(ui)
include(reactive)

add_library(${PROJECT_NAME} ${CORE_HEADER_LIST} ${COMMAND_SRC_LIST} ${UI_SRC_LIST} ${RX_SRC_LIST})

target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIR})

target_link_libraries(${PROJECT_NAME} PUBLIC imgui::imgui)
target_link_libraries(${PROJECT_NAME} PUBLIC glfw)
target_link_libraries(${PROJECT_NAME} PUBLIC Boost::boost Boost::log)
target_link_libraries(${PROJECT_NAME} PRIVATE freetype)
target_link_libraries(${PROJECT_NAME} PRIVATE matchit::matchit)

if (APPLE)
    target_link_libraries(${PROJECT_NAME} PRIVATE "-framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo")
endif ()


