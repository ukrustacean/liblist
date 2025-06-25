cmake_minimum_required(VERSION 3.31)
project(liblist)

set(CMAKE_CXX_STANDARD 20)

add_library(liblist STATIC liblist.cpp
        NativeCharList.cpp
        NativeCharList.h
        CircularCharList.cpp
        CircularCharList.h)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(liblist_tests
        NativeCharList.cpp
        NativeCharList.h
        NativeCharListTest.cpp
        CircularCharList.cpp
        CircularCharList.h
        CircularCharListTest.cpp)

target_link_libraries(
        liblist_tests
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(liblist_tests)