cmake_minimum_required(VERSION 3.5.0)
project(cppallprojects)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# To better read travis log.
set(CMAKE_VERBOSE_MAKEFILE ON)
add_subdirectory(template)

if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  add_custom_target(clang_fmt ALL)

  file(GLOB_RECURSE allfilescpp "${CMAKE_CURRENT_SOURCE_DIR}/*.c" "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/*hpp")
  foreach(filei ${allfilescpp})
    add_custom_command(TARGET clang_fmt COMMAND sh ${CMAKE_CURRENT_SOURCE_DIR}/clang-format-check.sh ${filei} DEPENDS ${filei}.stamp)
  endforeach()
endif()