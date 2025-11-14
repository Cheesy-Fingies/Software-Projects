file(GLOB_RECURSE ENGINE_SRC
    Assets/*.cpp
    Audio/*.cpp
    Core/*.cpp
    Input/*.cpp
    Physics/*.cpp
    Renderer/*.cpp
    Scene/*.cpp
    Utils/*.cpp
)

file(GLOB_RECURSE ENGINE_HEADERS
    Assets/*.h
    Audio/*.h
    Core/*.h
    Input/*.h
    Physics/*.h
    Renderer/*.h
    Scene/*.h
    Utils/*.h
)

add_library(Engine STATIC ${ENGINE_SRC} ${ENGINE_HEADERS})

target_include_directories(Engine PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Core
    ${CMAKE_SOURCE_DIR}/third_party
)

# Link libraries like GLFW and OpenGL
find_package(glfw3 REQUIRED)
target_link_libraries(Engine PUBLIC glfw)

if (WIN32)
    target_link_libraries(Engine PUBLIC opengl32)
endif()

# GLAD source
set(GLAD_SRC ${CMAKE_SOURCE_DIR}/third_party/glad/src/glad.c)

add_library(glad ${GLAD_SRC})
target_include_directories(glad PUBLIC ${CMAKE_SOURCE_DIR}/third_party/glad/include)

# Link GLAD to your engine
target_link_libraries(Engine PUBLIC glad glfw opengl32)
