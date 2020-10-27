cmake_minimum_required(VERSION 3.10)
project(lab1)

enable_testing()

add_executable(runUnitTests
            ExceptionManager.cpp
            ExceptionManager.h
            Exceptions.h
            IManager.h
            Test_lab1.cpp)

target_link_libraries(runUnitTests gtest gtest_main pthread)
