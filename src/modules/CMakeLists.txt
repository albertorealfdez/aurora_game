target_sources(modulesLib PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/game/Game.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/engine2D/Engine2D.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/engine2D/SFMLGraphicEngine.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/states/StateManager.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/states/IntroState.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/input/InputManager.cpp"    
)

# Y donde se encuentran los .h
target_include_directories(modulesLib PUBLIC 
"${CMAKE_CURRENT_SOURCE_DIR}/game/"
"${CMAKE_CURRENT_SOURCE_DIR}/engine2D/"
"${CMAKE_CURRENT_SOURCE_DIR}/states/"
"${CMAKE_CURRENT_SOURCE_DIR}/input/"
)
