set(UI_SRC_LIST

        #Library
        ${PROJECT_SOURCE_DIR}/ui/external/imgui_config.h
        ${PROJECT_SOURCE_DIR}/ui/external/freetype/imgui_freetype.h
        ${PROJECT_SOURCE_DIR}/ui/external/freetype/imgui_freetype.cpp
        ${PROJECT_SOURCE_DIR}/ui/external/dock/imgui_dock.h
        ${PROJECT_SOURCE_DIR}/ui/external/dock/imgui_dock.cpp
        ${PROJECT_SOURCE_DIR}/ui/external/spectrum/imgui_spectrum.h
        ${PROJECT_SOURCE_DIR}/ui/external/spectrum/imgui_spectrum.cpp

        #Font
        ${PROJECT_SOURCE_DIR}/ui/fonts/material.cpp

        #Common
        ${PROJECT_SOURCE_DIR}/ui/common/size.cpp
        
        #Widgets
        ${PROJECT_SOURCE_DIR}/ui/widget/appglw.h
        ${PROJECT_SOURCE_DIR}/ui/widget/appglw.cpp
        ${PROJECT_SOURCE_DIR}/ui/widget/appbase.h
        ${PROJECT_SOURCE_DIR}/ui/widget/appbase.cpp
        ${PROJECT_SOURCE_DIR}/ui/widget/application.h
        ${PROJECT_SOURCE_DIR}/ui/widget/application.cpp


        ${PROJECT_SOURCE_DIR}/ui/widget/widget.cpp
        ${PROJECT_SOURCE_DIR}/ui/widget/window.cpp
        ${PROJECT_SOURCE_DIR}/ui/widget/principal.h
        ${PROJECT_SOURCE_DIR}/ui/widget/principal.cpp
        ${PROJECT_SOURCE_DIR}/ui/widget/container.cpp

        #components
        ${PROJECT_SOURCE_DIR}/ui/component/label.cpp
        ${PROJECT_SOURCE_DIR}/ui/component/text.cpp
        ${PROJECT_SOURCE_DIR}/ui/component/menu.cpp
        ${PROJECT_SOURCE_DIR}/ui/component/button.cpp

        #events
        ${PROJECT_SOURCE_DIR}/ui/event/resize.h
        ${PROJECT_SOURCE_DIR}/ui/event/resize.cpp
)


