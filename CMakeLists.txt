# Specify the minimum version of CMake
cmake_minimum_required(VERSION 3.10)

# Set the project name
project(cpp-socket-chat)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
file(GLOB SOURCES "src/*.cpp")

# Add the header files
file(GLOB HEADERS "src/*.hpp")

# Add the executable
add_executable(cpp-socket-chat ${SOURCES} ${HEADERS})
