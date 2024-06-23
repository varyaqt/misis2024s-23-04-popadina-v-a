find_package(Matplot++)
add_executable(timing_q timing_q.cpp)
set_property(TARGET timing_q PROPERTY CXX_STANDARD 20)
target_link_libraries(timing_q stackarr Matplot++::matplot)
install(TARGETS timing_q)

