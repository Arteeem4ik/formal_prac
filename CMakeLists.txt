cmake_minimum_required(VERSION 3.7)
project(fromal)

find_package(Threads REQUIRED)
find_package(GTest REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

add_executable(
        fromal
        LongestSubstr.cpp
        LongestSubstr.h
        main.cpp
        tests.cpp
)

target_link_directories(fromal PRIVATE ${GTEST_INCLUDE_DIRS})

target_link_libraries(fromal PRIVATE GTest::GTest Threads::Threads)

target_compile_options(fromal PRIVATE -Wall -Werror)