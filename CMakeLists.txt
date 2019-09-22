cmake_minimum_required(VERSION 3.12)
project(TheString)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)



add_subdirectory(googletest-master/googletest)


add_library(my_string SHARED MyString.cpp MyString.h)

add_executable(TheString main.cpp)
target_link_libraries(TheString  my_string gtest gtest_main)

include_directories(${CMAKE_CURRENT_SOURCE_DIR} googletest-master/googletest/include)