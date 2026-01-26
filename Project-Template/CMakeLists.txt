cmake_minimum_required(VERSION 3.16)
project(app LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE PROJECT_SOURCES
     CONFIGURE_DEPENDS
     src/*.cpp
     src/*.h
)

add_executable(${PROJECT_NAME}
    ${PROJECT_SOURCES}
    glad/src/glad.c
)

target_include_directories(${PROJECT_NAME} PRIVATE
    src
    headers
    glad/include
)

find_package(glfw3 CONFIG REQUIRED)

target_link_libraries(${PROJECT_NAME}
    glfw
    GL
)
