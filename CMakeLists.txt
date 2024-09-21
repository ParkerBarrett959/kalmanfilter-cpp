# Project Setup
cmake_minimum_required(VERSION 3.22.0)
project(kalmanfilter_cpp VERSION 1.0 LANGUAGES CXX)

# C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# External Dependencies
find_package (Eigen3 3.3 REQUIRED NO_MODULE)
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)

# Set Include Directories
include_directories(include ${EIGEN3_INCLUDE_DIR})

# Get all the Test Source Files
file(GLOB TEST_SOURCES "test/*.cpp")

# Add Executable
add_executable(test-kalmanfilter-cpp ${TEST_SOURCES})
target_link_libraries(test-kalmanfilter-cpp PRIVATE GTest::gtest_main Eigen3::Eigen)