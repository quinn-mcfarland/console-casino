cmake_minimum_required(VERSION 4.1)
project(console_casino)

set(CMAKE_CXX_STANDARD 20)

add_executable(console_casino main.cpp utilities.cpp blackjack.cpp fiveCardPoker.cpp)
