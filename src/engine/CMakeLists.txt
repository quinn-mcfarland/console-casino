# Engine Target
add_library(game_engine STATIC)

# Source targets
target_sources(game_engine PRIVATE
    source/player.cpp
)

target_include_directories(game_engine
    PUBLIC include/
    PRIVATE source/
)

target_link_libraries(game_engine PRIVATE)