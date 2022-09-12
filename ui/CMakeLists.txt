project(ui)


set(CMAKE_CXX_STANDARD 23)

set(HEADER_LIST
        #Widgets
        include/ui/app.h
        include/ui/widget.h
        include/ui/text.h
        include/ui/window.h
        include/ui/menu.h
        #Font
        include/ui/fonts/material.h
        #Common
        include/ui/common/size.h
        #Command
        include/ui/command/message.h
        include/ui/command/abstract.h
        include/ui/command/engine.h
        include/ui/command/channel.h
        include/ui/command/middleware.h
        )

set(MY_LIBRARY_SOURCES
        src/app.cpp
        #Backend
        src/backend/imgui_impl_sdl.h
        src/backend/imgui_impl_sdl.cpp
        src/backend/imgui_impl_sdlrenderer.h
        src/backend/imgui_impl_sdlrenderer.cpp
        #Library
        src/lib/freetype/imgui_freetype.h
        src/lib/freetype/imgui_freetype.cpp
        src/lib/imgui_config.h
        src/lib/dock/imgui_dock.h
        src/lib/dock/imgui_dock.cpp
        src/lib/spectrum/imgui_spectrum.h
        src/lib/spectrum/imgui_spectrum.cpp
        #Font
        src/fonts/material.cpp
        #Common
        src/common/size.cpp
        #Widgets
        src/widgets/widget.cpp
        src/widgets/text.cpp
        src/widgets/window.cpp
        src/widgets/menu.cpp
        #Command
        src/command/engine.cpp
        src/command/simple_channel.h
        src/command/simple_channel.cpp
        #Middlewares
        src/command/middleware/command.h
        src/command/middleware/lambda.h
        src/command/middleware/lambda.cpp
        src/command/middleware/default.h
        src/command/middleware/default.cpp
        src/command/middleware/empty.h
        src/command/middleware/empty.cpp
        src/command/message/event.h
        src/command/message/event.cpp
        )


SET(TEST_SRC
        test/command_test.cpp
        )


SET(ORIG_FOLDER ${CMAKE_CURRENT_LIST_DIR}/fonts)
set(DEST_FOLDER ${CMAKE_BINARY_DIR}/${PROJECT}/fonts)
add_custom_target(copy_fonts COMMAND ${CMAKE_COMMAND} -E copy_directory ${ORIG_FOLDER} ${DEST_FOLDER})
file(COPY ${ORIG_FOLDER} DESTINATION ${DEST_FOLDER})
add_library(ui ${MY_LIBRARY_SOURCES} ${HEADER_LIST})
add_dependencies(ui copy_fonts)

target_include_directories(ui PUBLIC include)

target_link_libraries(ui PUBLIC imgui::imgui)
target_link_libraries(ui PUBLIC SDL2::SDL2 SDL2::SDL2main SDL2::SDL2-static)
target_link_libraries(ui PRIVATE Boost::boost)
target_link_libraries(ui PRIVATE freetype)

if (APPLE)
    target_link_libraries(ui PRIVATE "-framework OpenGL")
endif ()


enable_testing()

add_executable(ui_test ${TEST_SRC})

target_link_libraries(ui_test PRIVATE GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main)
target_link_libraries(ui_test PRIVATE ui)


source_group(
        TREE "${PROJECT_SOURCE_DIR}/include"
        PREFIX "Header Files"
        FILES ${HEADER_LIST})

install(
        TARGETS ui
        COMPONENT ui.libraries
)

install(
        DIRECTORY ${PROJECT_SOURCE_DIR}/include/
        COMPONENT ui.libraries
        DESTINATION include
)
