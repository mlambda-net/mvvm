
project(test)
set(CMAKE_CXX_STANDARD 23)

SET(UI_TEST_SRC
        ui/command_test.cpp
        ui/middleware/log.h
        ui/middleware/log.cpp
        )


set(CMAKE_CXX_STANDARD 23)


enable_testing()

add_executable(test ${UI_TEST_SRC})

target_include_directories(test PUBLIC ../ui/include)
target_include_directories(test PUBLIC ../ui/src)

target_link_libraries(test PRIVATE ui)
target_link_libraries(test PRIVATE GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main)
target_link_libraries(test PRIVATE ui)