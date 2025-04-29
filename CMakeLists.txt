cmake_minimum_required(VERSION 3.16)

# Project configuration
project(memory_leaks_project C CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# Default build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# Project-wide options
option(ENABLE_TESTS "Enable building and running tests" OFF)
option(COVERAGE "Enable code coverage" OFF)

# Define paths
set(SOURCE_DIR "${PROJECT_SOURCE_DIR}/src")
set(INCLUDE_DIR "${PROJECT_SOURCE_DIR}/inc")

# Verify that source and header files exist
file(GLOB SOURCES 
    "${SOURCE_DIR}/main.c"
    "${SOURCE_DIR}/user_manager.c"
    "${SOURCE_DIR}/data_processor.c"
)
file(GLOB HEADERS "${INCLUDE_DIR}/*.h")

message("Source files: ${SOURCES}")
message("Header files: ${HEADERS}")

# Check if the source file exists
if(NOT SOURCES)
    message(FATAL_ERROR "Source file 'my_math_function.c' not found in ${SOURCE_DIR}")
endif()


# Create the main executable
add_executable(memory_leaks ${SOURCES})

# Include directories for headers
target_include_directories(memory_leaks PUBLIC ${INCLUDE_DIR})

# Include tests if enabled
if(ENABLE_TESTS)
    message("Tests are enabled. Adding test directory.")
    add_subdirectory(tests)
else()
    message("Tests are disabled. Building only the main application.")
endif()
