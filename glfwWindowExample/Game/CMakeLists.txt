file(GLOB GAME_SRC ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_executable(Liminality liminality.cpp)

# Now apply settings
target_include_directories(Liminality PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/Engine
    ${CMAKE_SOURCE_DIR}/Engine/include
)

target_link_libraries(Liminality PRIVATE Engine glfw3)
