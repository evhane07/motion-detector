cmake_minimum_required(VERSION 3.10)
project(motion_detector)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(motion_detector motion_detector.cpp)
target_link_libraries(motion_detector ${OpenCV_LIBS})