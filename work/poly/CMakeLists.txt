add_library(poly poly.h poly.cpp)

add_executable(launch launch.cpp)

target_link_libraries(launch poly)
