cmake_minimum_required(VERSION 3.10)

# 1. Name your project
project(minisis LANGUAGES CXX)

# 2. Set C++ standard (C++17 is standard for modern projects)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 3. Recursively find all .cpp files in all subfolders
# This solves your "undefined reference" by finding every source file automatically
file(GLOB_RECURSE SOURCES "src/*.cpp")

# 4. Tell CMake where to find your .h files
# If your headers are in a folder named 'include', change "." to "include"
include_directories(.)

# 5. Create the executable named main.exe
add_executable(main ${SOURCES})

# This tells CMake to output the finished 'main' executable 
# into the directory where this CMakeLists.txt lives (the root).
set_target_properties(main PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}")