

SET(COMMAND_SRC_LIST
        #Command
        ${PROJECT_SOURCE_DIR}/command/engine.cpp
        ${PROJECT_SOURCE_DIR}/command/basic-channel.h
        ${PROJECT_SOURCE_DIR}/command/basic-channel.cpp
        #Middlewares
        ${PROJECT_SOURCE_DIR}/command/middleware/default.h
        ${PROJECT_SOURCE_DIR}/command/middleware/default.cpp
        ${PROJECT_SOURCE_DIR}/command/middleware/empty.h
        ${PROJECT_SOURCE_DIR}/command/middleware/empty.cpp
        ${PROJECT_SOURCE_DIR}/command/middleware/lambda.h
        ${PROJECT_SOURCE_DIR}/command/middleware/lambda.cpp
        ${PROJECT_SOURCE_DIR}/command/middleware/functor.h
        ${PROJECT_SOURCE_DIR}/command/middleware/functor.cpp
        ${PROJECT_SOURCE_DIR}/command/message/event.h
        ${PROJECT_SOURCE_DIR}/command/message/event.cpp
        ${PROJECT_SOURCE_DIR}/command/message-queue.cpp
        )

