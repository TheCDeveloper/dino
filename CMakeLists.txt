cmake_minimum_required(VERSION 3.16)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


project(dino VERSION 0.1.0 LANGUAGES C)

find_package(SDL3 REQUIRED)


file(GLOB SOURCES CONFIGURE_DEPENDS src/*.c)
add_executable(dino ${SOURCES})
target_link_libraries(dino PRIVATE SDL3::SDL3)
