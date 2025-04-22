cmake_minimum_required(VERSION 3.0)

project(PRINT)  # Project name

set(CMAKE_CXX_STANDARD 17)

# Include the directory where math.hpp is located
include_directories( includes / utils)

# Source files
set(SOURCE
    # src/unique_ptr.cpp
)

# Add executable
add_executable(${PROJECT_NAME} ${SOURCE})
