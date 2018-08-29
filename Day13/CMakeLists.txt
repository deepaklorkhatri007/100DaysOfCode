cmake_minimum_required(VERSION 2.6)
cmake_policy (SET CMP0012 NEW)

PROJECT (datatypes)

# OpenCV
find_package(OpenCV 3.0.0 REQUIRED)
message ("OpenCV Version : ${OpenCV_VERSION}")

include_directories(${OpenCV_INCLUDE_DIRS})
link_directories (${OpenCV_LIB_DIRS})
add_executable(sample.out main.cpp)
target_link_libraries(sample.out ${OpenCV_LIBS})

