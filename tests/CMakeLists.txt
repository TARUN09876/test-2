cmake_minimum_required(VERSION 3.16)

# Enable code coverage
option(COVERAGE "Enable code coverage" ON)
find_package(CppUTest REQUIRED)

# Enable coverage flags
if(COVERAGE)
    message("Building with coverage reporting")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --coverage")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
endif()

# Include directories
set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/inc")
include_directories(${SOURCE_DIR} ${INCLUDE_DIR})

# Collect source files
file(GLOB SRC_FILES 
    "${SOURCE_DIR}/user_manager.c"
    "${SOURCE_DIR}/data_processor.c"
)

# Collect test files
file(GLOB TEST_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

# Combine source and test files
set(TEST_SOURCES ${SRC_FILES} ${TEST_FILES})

# Define the test executable
add_executable(memory_leaks_test ${TEST_SOURCES})

# Link with CppUTest
target_link_libraries(memory_leaks_test PRIVATE CppUTest CppUTestExt)

# Set output directory for the test executable
set_target_properties(memory_leaks_test PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/tests
)

# Enable testing
enable_testing()
add_test(NAME memory_leaks_test COMMAND memory_leaks_test)














































