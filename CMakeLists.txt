cmake_minimum_required(VERSION 3.13)
project(CaptureIPCamera)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(CaptureIPCamera main.cpp)
target_link_libraries(CaptureIPCamera ${OpenCV_LIBS})