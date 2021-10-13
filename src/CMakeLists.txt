cmake_minimum_required(VERSION 3.0.0)

set(SOURCES main.cpp)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(Graph ${SOURCES})

target_include_directories(Graph PUBLIC ${MY_INCLUDE_DIR})