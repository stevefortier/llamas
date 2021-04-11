cmake_minimum_required(VERSION 3.18)
project(llamas)

set(SOURCE_FILES main.cpp)

add_executable(llamas ${SOURCE_FILES})

target_link_libraries(llamas EnTT::EnTT)
