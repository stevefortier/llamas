cmake_minimum_required(VERSION 3.10)
project(llamas)

add_subdirectory(scene)

set(SOURCE_FILES main.cpp)
add_executable(llamas ${SOURCE_FILES})
target_link_libraries(llamas scene)
