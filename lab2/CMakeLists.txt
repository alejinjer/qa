cmake_minimum_required(VERSION 3.10)
project(lab2)

enable_testing()

add_executable(runUnitTests
            ExceptionManager.cpp
            ExceptionManager.h
            Exceptions.h
            ConfigLoader.h
            Test_lab2.cpp)

target_link_libraries(runUnitTests gtest gtest_main pthread)
