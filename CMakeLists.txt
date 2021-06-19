cmake_minimum_required(VERSION 3.18)
project(llamas)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)
include(Externals)
include(Testing)

add_subdirectory(src)
