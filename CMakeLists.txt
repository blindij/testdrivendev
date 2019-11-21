
cmake_minimum_required (VERSION 3.4)
project (TDDbyexample
    VERSION 0.1.0
    DESCRIPTION "A C++ project using CMake"
    LANGUAGES CXX
)

# Require C++11 for Catch2
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

# Only build documentation if this is the main project, and not if it is included through add_subdirectory
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    # Docs only available if this is the main project
    find_package(Doxygen QUIET)
    if(Doxygen_FOUND)
        add_subdirectory(docs)
    else()
        message(STATUS "Doxygen not found, not building docs")
    endif()
endif()

# The compiled library code is here
add_subdirectory(src)

# The executable code is here
add_subdirectory(examples)
message(INFO "CMake Project name: ${CMAKE_PROJECT_NAME}, Project name: ${PROJECT_NAME}")
# Testing only available if this is the main project
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
