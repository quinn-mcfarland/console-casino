cmake_minimum_required(VERSION 4.3)
project(consolecasino)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_executable(consolecasino main.cpp player.cpp card.cpp CardDeck.cpp)