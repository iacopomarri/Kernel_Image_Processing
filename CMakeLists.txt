cmake_minimum_required(VERSION 3.5)
project(KernelImageProcessing)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Image.cpp Image.h Color.cpp Color.h KernelImageGUiMain.cpp KernelImageGUiMain.h KernelImageGUiApp.cpp KernelImageGUiApp.h)
add_executable(KernelImageProcessing ${SOURCE_FILES})

find_package(wxWidgets REQUIRED net core base)
include(${wxWidgets_USE_FILE})


target_link_libraries(KernelImageProcessing ${wxWidgets_LIBRARIES})