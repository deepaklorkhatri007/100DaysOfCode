cmake_minimum_required (VERSION 2.6)
cmake_policy (SET CMP0012 NEW)
PROJECT(camera)

#Requires OpenCV

FIND_PACKAGE (OpenCV 3.0.0 REQUIRED)
MESSAGE ("OpenCV version : ${OpenCV_VERSION}")

include_directories (${OpenCV_INCLUDE_DIRS})
link_directories (${OpenCV_LIB_DIR})
ADD_EXECUTABLE (sample.out main.cpp)
TARGET_LINK_LIBRARIES(sample.out ${OpenCV_LIBS})