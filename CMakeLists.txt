cmake_minimum_required(VERSION 3.28 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_EXTENSIONS OFF)
set(MSVC true)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(PROJECT_NAME 20MinutesTillSunrise_rl)

project( ${PROJECT_NAME} DESCRIPTION "2D Game made with RayLib")

file(GLOB_RECURSE ALL_FILES "src/*")

add_executable(${PROJECT_NAME} ${ALL_FILES})

include(cmake/CPM.cmake)

CPMAddPackage("gh:raysan5/raylib#5.0")
target_link_libraries(${PROJECT_NAME} PRIVATE
    raylib
)

target_precompile_headers( ${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/src/pch.h )

# /Qspectre
# /fsanitize-address-use-after-return /fsanitize=address
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION ON)
target_compile_options(${PROJECT_NAME} PRIVATE /W4 /Wall /WX /EHa /EHc /options:strict /Ot /sdl /RTC1 /RTCs /RTCu /permissive- /Za /analyze)

add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/src/assets $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets
)
