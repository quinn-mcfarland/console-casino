file(GLOB_RECURSE GAME_SOURCES "source/*.cpp")

add_executable(consolecasino ${GAME_SOURCES})

target_link_libraries(consolecasino PRIVATE engine)