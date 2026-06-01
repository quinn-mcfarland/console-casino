cmake_minimum_required(VERSION 4.3)
project(
        consolecasino
        VERSION 0.2.1
        LANGUAGES CXX
)

# C++ standard enforcement
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(src/engine)
add_subdirectory(src/game)