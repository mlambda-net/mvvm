project(myapp)
set(CMAKE_CXX_STANDARD 20)


add_compile_options(${BUILD_FLAGS})
add_link_options(${LINK_FLAGS})

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIR})
target_include_directories(${PROJECT_NAME} PUBLIC ../app)

target_link_libraries(${PROJECT_NAME} PRIVATE app)

copy_assets(cmd)



