
set(CORE_HEADER_LIST
        #Font
        ${PROJECT_SOURCE_DIR}/include/ui/fonts/material.h

        #Common
        ${PROJECT_SOURCE_DIR}/include/ui/common/size.h

        #Command
        ${PROJECT_SOURCE_DIR}/include/command/message.h
        ${PROJECT_SOURCE_DIR}/include/command/engine.h
        ${PROJECT_SOURCE_DIR}/include/command/channel.h
        ${PROJECT_SOURCE_DIR}/include/command/middleware.h
        ${PROJECT_SOURCE_DIR}/include/command/message-queue.h

        #Widgets
        ${PROJECT_SOURCE_DIR}/include/ui/widget/app.h
        ${PROJECT_SOURCE_DIR}/include/ui/widget/widget.h
        ${PROJECT_SOURCE_DIR}/include/ui/widget/window.h
        ${PROJECT_SOURCE_DIR}/include/ui/widget/container.h

        #Components
        ${PROJECT_SOURCE_DIR}/include/ui/components/label.h
        ${PROJECT_SOURCE_DIR}/include/ui/components/button.h
        ${PROJECT_SOURCE_DIR}/include/ui/components/text.h
        ${PROJECT_SOURCE_DIR}/include/ui/components/menu.h

        #Reactive
        ${PROJECT_SOURCE_DIR}/include/reactive/global.h
        ${PROJECT_SOURCE_DIR}/include/reactive/observer.h
        ${PROJECT_SOURCE_DIR}/include/reactive/observable.h
        ${PROJECT_SOURCE_DIR}/include/reactive/operations.h
        ${PROJECT_SOURCE_DIR}/include/reactive/bind.h
        ${PROJECT_SOURCE_DIR}/include/reactive/unsubscribe.h
        ${PROJECT_SOURCE_DIR}/include/reactive/option.h
        ${PROJECT_SOURCE_DIR}/include/reactive/maybe.h
        ${PROJECT_SOURCE_DIR}/include/reactive/future.h
        ${PROJECT_SOURCE_DIR}/include/reactive/observer/subscriber.h
        ${PROJECT_SOURCE_DIR}/include/reactive/observer/unsubscription.h
        ${PROJECT_SOURCE_DIR}/include/reactive/observable/subject.h
        ${PROJECT_SOURCE_DIR}/include/reactive/observable/replay_subject.h
        ${PROJECT_SOURCE_DIR}/include/reactive/observable/observable_base.h
        #Events
        ${PROJECT_SOURCE_DIR}/include/ui/event/listener.h
        )


set(INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include")



