# Find all headers in the project include folder
file(GLOB HEADERS CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/include/TestDrivenDevbyExample/*.hpp")

# Make a static library (tradeoff of memory for better performance)
add_library(TDDbyexample STATIC lib.cpp ${HEADERS})

# Add an alias so the target can be used while building
add_library(TDDbyexample::TDDbyexample ALIAS TDDbyexample)

# Set the include directory for builds (tests, examples, etc) and for clients
target_include_directories(TDDbyexample PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)

# Associate the include files with the target, so they will be installed
set_target_properties(TDDbyexample PROPERTIES PUBLIC_HEADER "${HEADERS}")

# Set install targets and destinations
install(TARGETS TDDbyexample
    EXPORT TDDbyexampleTargets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    PUBLIC_HEADER DESTINATION include/TestDrivenDevbyExample)

# Export additional install files (for clients using CMake)
install(EXPORT TDDbyexampleTargets
    NAMESPACE TDDbyexample::
    FILE TDDbyexampleConfig.cmake
    DESTINATION lib/cmake/TDDbyexample)

add_executable(factory.x factory_pattern.cpp)
