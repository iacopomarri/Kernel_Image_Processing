cmake_minimum_required(VERSION 3.5)
project(KernelImageProcessing)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Image.cpp Image.h Color.cpp Color.h KernelImageGUiMain.cpp KernelImageGUiMain.h KernelImageGUiApp.cpp KernelImageGUiApp.h Channels_3.cpp Channels_3.h Channels_4.cpp Channels_4.h Channels_2.cpp Channels_2.h Channel_1.cpp Channel_1.h)
add_executable(KernelImageProcessing ${SOURCE_FILES})

find_package(wxWidgets REQUIRED net core base)
include(${wxWidgets_USE_FILE})


target_link_libraries(KernelImageProcessing ${wxWidgets_LIBRARIES})