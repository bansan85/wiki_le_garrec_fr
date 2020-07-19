cmake_minimum_required(VERSION 3.11.0)
project(cppallprojects)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# To better read travis log.
set(CMAKE_VERBOSE_MAKEFILE ON)

add_custom_target(data_for_travis)

add_subdirectory(attribute)
add_subdirectory(boost)
add_subdirectory(linker)
add_subdirectory(preprocessor)
add_subdirectory(variable)

add_dependencies(data_for_travis data_for_travis_cpp_attribute)
add_dependencies(data_for_travis data_for_travis_cpp_linker)
add_dependencies(data_for_travis data_for_travis_cpp_preprocessor)

if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  add_custom_target(clang_fmt ALL)

  file(GLOB_RECURSE allfilescpp "${CMAKE_CURRENT_SOURCE_DIR}/*.c"
       "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
       "${CMAKE_CURRENT_SOURCE_DIR}/*hpp")
  foreach(filei ${allfilescpp})
    add_custom_command(
      TARGET clang_fmt
      COMMAND sh ${CMAKE_CURRENT_SOURCE_DIR}/clang-format-check.sh ${filei})
  endforeach()

elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  set(ALL_CMAKELISTS_STAMP "")

  file(GLOB_RECURSE allfilescmake "${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.txt")
  foreach(filei ${allfilescmake})
    add_custom_command(
      OUTPUT ${filei}.stamp
      COMMAND sh ${CMAKE_CURRENT_SOURCE_DIR}/cmake-format-check.sh ${filei})
    list(APPEND ALL_CMAKELISTS_STAMP ${filei}.stamp)
  endforeach()

  add_custom_target(cmake_fmt DEPENDS ${ALL_CMAKELISTS_STAMP})
endif()
