add_executable(AuroraGame main.cpp)

add_library(modulesLib STATIC)
add_subdirectory(modules)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        modulesLib
)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

#Para usar SFML
find_package(SFML REQUIRED system window graphics network audio)

target_link_libraries(AuroraGame
    PRIVATE
        sfml-system
        sfml-window
        sfml-graphics
        sfml-network
        sfml-audio
)
