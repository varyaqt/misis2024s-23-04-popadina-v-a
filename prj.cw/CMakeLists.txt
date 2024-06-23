cmake_minimum_required(VERSION 3.10)

project(prj.cw)

find_package(OpenCV CONFIG REQUIRED)

add_executable(prj.cw back.cpp)

target_link_libraries(prj.cw PRIVATE OpenCV)
