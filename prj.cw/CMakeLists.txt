find_package(OpenCV CONFIG REQUIRED)

add_executable(back back.cpp)
target_link_libraries(opencv_001 PRIVATE opencv_core opencv_imgproc opencv_highgui)
