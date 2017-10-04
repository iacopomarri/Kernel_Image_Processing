cmake_minimum_required(VERSION 3.5)
project(KernelImageProcessing)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Image.cpp Image.h Color.cpp Color.h)
add_executable(KernelImageProcessing ${SOURCE_FILES})