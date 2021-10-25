cmake_minimum_required(VERSION 3.10)

# Set project name
project(MathLibrary)

include_directories(src/include/utils)
include_directories(src/include/definitions)

add_library(
	matrix-library
	src/MatrixLibrary.cpp
	src/utils/MatrixUtils.cpp
	src/include/definitions/MatrixDefinitions.h
	src/include/utils/MatrixUtils.h
	src/include/MatrixLibrary.h
	)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(matrix src/matrix-test.cpp)

target_link_libraries(matrix PRIVATE matrix-library)
