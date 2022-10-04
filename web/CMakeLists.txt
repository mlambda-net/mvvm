project(web)

add_compile_options(${BUILD_FLAGS})
add_link_options(${LINK_FLAGS})

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIR})
target_include_directories(${PROJECT_NAME} PUBLIC ../app)


set(CMAKE_EXECUTABLE_SUFFIX ".html")
set(FLAGS "-g0")
set(FLAGS "${FLAGS} -sUSE_SDL=2")
set(FLAGS "${FLAGS} -sFULL_ES2=1")
set(FLAGS "${FLAGS} -sWASM=1")
set(FLAGS "${FLAGS} -sASSERTIONS=0")
set(FLAGS "${FLAGS} -sALLOW_MEMORY_GROWTH=1")
set(FLAGS "${FLAGS} -sNO_EXIT_RUNTIME=0")
set(FLAGS "${FLAGS} -sUSE_PTHREADS=0")
set(FLAGS "${FLAGS} -sASYNCIFY")
set(FLAGS "${FLAGS} -sMAX_WEBGL_VERSION=2")
set(FLAGS "${FLAGS} -lembind")
set(FLAGS "${FLAGS} --shell-file=${PROJECT_SOURCE_DIR}/shell_minimal.html")
set(FLAGS "${FLAGS} --preload-file=${PROJECT_BINARY_DIR}/fonts@/fonts")

copy_assets(${PROJECT_NAME})

set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "${FLAGS}")

target_link_libraries(${PROJECT_NAME} PRIVATE core)
target_link_libraries(${PROJECT_NAME} PRIVATE app)



