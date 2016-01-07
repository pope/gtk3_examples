project(gtk3-tutorial C)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_C_FLAGS "-Wall -Wextra -Werror ${CMAKE_C_FLAGS}")

add_subdirectory(src)

find_program(CLANG_FORMAT_EXE
  NAMES clang-format clang-format-3.8 clang-format-3.7
  DOC "clang-format executable")
mark_as_advanced(CLANG_FORMAT_EXE)
file(GLOB SOURCES_TO_FORMAT src/*.c)
add_custom_target(format
  COMMAND ${CLANG_FORMAT_EXE} -i -style=Google ${SOURCES_TO_FORMAT}
  COMMENT "Formatting source code")
