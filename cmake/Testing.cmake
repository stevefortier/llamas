cmake_minimum_required(VERSION 3.10)

include(CTest)

function(add_tests name)
    add_executable(${name}
        ${ARGN}
    )
    target_compile_definitions(${name} PRIVATE -DCATCH_CONFIG_MAIN)
    target_link_libraries(${name} Catch2::Catch2)

    FetchContent_GetProperties(catch2)
    list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/contrib)
    set(PARSE_CATCH_TESTS_ADD_TO_CONFIGURE_DEPENDS ON)
    include(Catch)
    catch_discover_tests(${name})
endfunction()
