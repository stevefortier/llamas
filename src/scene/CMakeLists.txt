cmake_minimum_required(VERSION 3.18)
project(scene)

set(SOURCE_FILES
    SceneGraph.cpp
    SceneGraph.hpp
    SceneLoader.cpp
    SceneLoader.hpp
    SceneNode.hpp
    SceneTransition.hpp
    )
add_library(scene STATIC ${SOURCE_FILES})
target_link_libraries(scene EnTT::EnTT)

set(TEST_FILES
    SceneGraph.t.cpp
    SceneLoader.t.cpp
    SceneNode.t.cpp
    )

add_tests(test_scene ${TEST_FILES})
target_link_libraries(test_scene scene)