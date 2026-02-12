cmake_minimum_required(VERSION 4.2.3)
project(Excersise)

file(GLOB_RECURSE PROJECT_SOURCES
    CONFIGURE_DEPENDS
    src/*.cpp
    headers/*.hpp
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES} libraries/glad/src/glad.c)

target_include_directories(${PROJECT_NAME} PRIVATE
    src
    headers
    libraries/glad/include
)

find_package(glfw3 CONFIG REQUIRED)

target_link_libraries(${PROJECT_NAME}
    glfw
    GL
)