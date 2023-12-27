cmake_minimum_required(VERSION 3.27)
project(Ascii_Video_Project)

set(CMAKE_CXX_STANDARD 17)
# Find OpenCV package
find_package(OpenCV REQUIRED)

# Include directories
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(Ascii_Video_Project main.cpp)
# Link OpenCV libraries
target_link_libraries(Ascii_Video_Project ${OpenCV_LIBS})