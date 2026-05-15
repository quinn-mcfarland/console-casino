cmake_minimum_required(VERSION 4.3)

# Set the project meme
project(ConsoleCasino)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add executable
add_executable(consolecasino)

# target sources
target_sources(consolecasino
        PRIVATE
        src/main.cpp
        src/blackjack.cpp
        src/utilities.cpp
        src/fiveCardPoker.cpp
)
