# CMake Project Info
cmake_minimum_required(VERSION 4.3)
project(consolecasino)

# Language Standards
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# Output directory for binaries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# External Dependencies

# Source Subdirectories
add_subdirectory(src/engine)
add_subdirectory(src/game)