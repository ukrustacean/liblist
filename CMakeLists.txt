cmake_minimum_required(VERSION 3.31)
project(liblist)

set(CMAKE_CXX_STANDARD 20)

add_library(liblist STATIC liblist.cpp
        NativeCharList.cpp
        NativeCharList.h
        CircularCharList.cpp
        CircularCharList.h)

include(GoogleTest)

add_executable(liblist_tests
        NativeCharList.cpp
        NativeCharList.h
        NativeCharListTest.cpp
        CircularCharList.cpp
        CircularCharList.h
        CircularCharListTest.cpp)

gtest_add_tests(TARGET liblist_tests)