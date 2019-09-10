cmake_minimum_required(VERSION 2.8)
cmake_policy (SET CMP0012 NEW)

# enable C++11
set(CMAKE_CXX_STANDARD_11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

project (Cmake)

find_package (OpenCV 3.0.0 REQUIRED)
message (STATUS "OpenCV library status")
message (STATUS "version : ${OpenCV_VERSION}")
message (STATUS "libraries : ${OpenCV_LIBS}")
message (STATUS "include path : ${OpenCV_INCLUDE_DIRS}")


include_directories (${OpenCV_INCLUDE_DIRS})
link_directories (${OpenCV_LIB_DIRS})

add_executable (sample.out main.cpp)
target_link_libraries (sample.out ${OpenCV_LIBS})