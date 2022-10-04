project(tests)

add_compile_options(${BUILD_FLAGS})
add_link_options(${LINK_FLAGS})

set(CMAKE_CXX_STANDARD 20)
SET(TEST_SRC_LIST
        command/command_test.cpp
        command/message/dummy.h
        command/message/dummy.cpp
        command/message_test.cpp
        command/message/event.cpp
        command/message/event.h
        reactive/observer/console.h

        reactive/observable_test.cpp
        )


add_executable(${PROJECT_NAME} ${TEST_SRC_LIST})

target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIR})
target_include_directories(${PROJECT_NAME} PUBLIC ../core)

target_link_libraries(${PROJECT_NAME} PRIVATE core)
target_link_libraries(${PROJECT_NAME} PRIVATE GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main)
target_link_libraries(${PROJECT_NAME} PRIVATE matchit::matchit)

gtest_discover_tests(${PROJECT_NAME})
