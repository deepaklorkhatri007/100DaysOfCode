cmake_minimum_required (VERSION 2.8)
cmake_policy (SET CMP0012 NEW)

project (Gamma)

find_package (OpenCV 3.0.0 REQUIRED)
message ("OpenCV VERSION : ${OpenCV_VERSION}")

include_directories (${OpenCV_INCLUDE_DIRS})
link_directories (${OpenCV_LIB_DIRS})

add_executable (sample.out main.cpp)
target_link_libraries (sample.out ${OpenCV_LIBS})