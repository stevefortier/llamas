cmake_minimum_required(VERSION 3.18)
project(scene)

set(SOURCE_FILES
	Scene.cpp
	Scene.hpp)
add_library(scene STATIC ${SOURCE_FILES})
target_link_libraries(scene EnTT::EnTT)

set(TEST_FILES
	Scene.t.cpp)
add_executable(test_scene ${TEST_FILES})
target_link_libraries(test_scene scene Catch2::Catch2)
