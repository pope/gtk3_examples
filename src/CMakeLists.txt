find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})
add_definitions(${GTK3_CFLAGS_OTHER})

# I'm cheating with globbing. If I add a new file, I need to touch the
# CMakeLists.txt file so that cmake updates itself.
file(GLOB sources RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" *.c)
foreach(source ${sources})
  string(REGEX REPLACE "\\.c$" "" exe "${source}")
  add_executable(${exe} ${source})
  target_link_libraries(${exe} ${GTK3_LIBRARIES})
endforeach(source)
