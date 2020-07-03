project(templateweak)
add_executable(templateweak ClasseA.cpp ClasseB.cpp main.cpp)
target_compile_options(templateweak PRIVATE -O0)
add_custom_command(
  TARGET templateweak
  PRE_LINK
  COMMAND nm --demangle
          ${CMAKE_CURRENT_BINARY_DIR}/CMakeFiles/templateweak.dir/ClasseA.cpp.o)
add_custom_command(
  TARGET templateweak
  PRE_LINK
  COMMAND nm --demangle
          ${CMAKE_CURRENT_BINARY_DIR}/CMakeFiles/templateweak.dir/ClasseB.cpp.o)
add_custom_command(
  TARGET templateweak
  PRE_LINK
  COMMAND nm --demangle
          ${CMAKE_CURRENT_BINARY_DIR}/CMakeFiles/templateweak.dir/main.cpp.o)
