cmake_minimum_required(VERSION 3.26)
project(projeto_itp_sgbd C)

set(CMAKE_C_STANDARD 11)

file(GLOB_RECURSE SOURCES "functions/*.c" "utils/*.c" "tables/*.txt")

add_library(MyLibrary ${SOURCES})
add_executable(main main.c)

target_link_libraries(main MyLibrary)
