cmake_minimum_required(VERSION 3.0)

project(PRINT)  # Project name

set(CMAKE_CXX_STANDARD 17)

# Include the directory where math.hpp is located
include_directories( includes / utils)

# Source files
set(SOURCE
    # src/try.cpp
    # src/unique_ptr.cpp
    # src/FileSystem.cpp
    # src/threading.cpp
    # src/oop.cpp
    src/task_manager_simulation.cpp
)

# Add executable
add_executable(${PROJECT_NAME} ${SOURCE})