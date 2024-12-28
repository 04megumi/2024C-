cmake_minimum_required(VERSION 3.10)

project(ExecutorTestProject)

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_SOURCE_DIR}/include)

include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

FetchContent_MakeAvailable(googletest)

set(TEST_SOURCES
    ${CMAKE_SOURCE_DIR}/tests/ExecutorTest.cpp
)

add_executable(test_executor ${TEST_SOURCES})

target_link_libraries(test_executor
    GTest::gtest_main
    adas
)

enable_testing()

include(GoogleTest)
gtest_discover_tests(test_executor)