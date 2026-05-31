# Create game executable
add_executable(consolecasino source/main.cpp)

# Link engine library to game
target_link_libraries(consolecasino PRIVATE game_engine)