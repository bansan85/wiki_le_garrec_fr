project(linkerweak)
add_executable(linkerweak ClasseA.cpp ClasseB.cpp main.cpp)
target_compile_options(linkerweak PRIVATE -O0)
add_custom_command(
  TARGET linkerweak
  PRE_LINK
  COMMAND nm --demangle
          ${CMAKE_CURRENT_BINARY_DIR}/CMakeFiles/linkerweak.dir/ClasseA.cpp.o)
add_custom_command(
  TARGET linkerweak
  PRE_LINK
  COMMAND nm --demangle
          ${CMAKE_CURRENT_BINARY_DIR}/CMakeFiles/linkerweak.dir/ClasseB.cpp.o)
add_custom_command(
  TARGET linkerweak
  PRE_LINK
  COMMAND nm --demangle
          ${CMAKE_CURRENT_BINARY_DIR}/CMakeFiles/linkerweak.dir/main.cpp.o)
