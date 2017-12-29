cmake_minimum_required(VERSION 3.5)
project(KernelImageProcessing)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Image.cpp Image.h KernelImageGUiMain.cpp KernelImageGUiMain.h KernelImageGUiApp.cpp KernelImageGUiApp.h ThreeChannels.cpp ThreeChannels.h FourChannels.cpp FourChannels.h TwoChannels.cpp TwoChannels.h OneChannel.cpp OneChannel.h Color.cpp Color.h Transparent_Color.h Transparent_Color.cpp Effect.cpp Effect.h)
add_executable(KernelImageProcessing ${SOURCE_FILES})

find_package(wxWidgets REQUIRED net core base)
include(${wxWidgets_USE_FILE})


target_link_libraries(KernelImageProcessing ${wxWidgets_LIBRARIES})