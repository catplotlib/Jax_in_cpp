cmake_minimum_required(VERSION 3.10)
project(MyProject)

# Enable C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories for header files
include_directories(${CMAKE_SOURCE_DIR}/include)

# Find Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Define the test executable
add_executable(my_test
  tests/test_var.cpp
  tests/test_operations.cpp
  src/var.cpp
  src/operations.cpp
)

# Link Google Test and pthread (needed for Google Test)
target_link_libraries(my_test ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)

# Define another executable for the simple_example
add_executable(simple_example
  examples/simple_example.cpp
  src/var.cpp
  src/operations.cpp
)

# Since simple_example doesn't use Google Test, it only needs to be linked with the pthread library if necessary
target_link_libraries(simple_example pthread)
