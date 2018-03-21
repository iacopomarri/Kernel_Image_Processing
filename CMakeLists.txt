cmake_minimum_required(VERSION 3.5)
project(KernelImageProcessing)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(test)

set(SOURCE_FILES main.cpp Image.cpp Image.h KernelImageGUiMain.cpp KernelImageGUiMain.h KernelImageGUiApp.cpp KernelImageGUiApp.h Color.cpp Color.h Transparent_Color.h Transparent_Color.cpp Effect.cpp Effect.h) #test/ImageTest.cpp test/ImageFixture.cpp)
add_executable(KernelImageProcessing ${SOURCE_FILES})
add_library(core ${SOURCE_FILES} ImageBase.h)


target_link_libraries(KernelImageProcessing core)

find_package(wxWidgets REQUIRED net core base)
include(${wxWidgets_USE_FILE})


target_link_libraries(KernelImageProcessing ${wxWidgets_LIBRARIES})