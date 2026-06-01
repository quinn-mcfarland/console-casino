file(GLOB_RECURSE ENGINE_SOURCES "source/*.cpp")

add_library(engine STATIC ${ENGINE_SOURCES})

target_include_directories(engine
        PUBLIC include/
        PRIVATE source/
)