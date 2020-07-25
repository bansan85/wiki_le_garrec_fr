cmake_minimum_required(VERSION 3.11.0)
project(wiki_le_garrec_fr)
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

add_custom_target(clang_fmt)
file(GLOB_RECURSE allfilescpp "${CMAKE_CURRENT_SOURCE_DIR}/*.c"
     "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
     "${CMAKE_CURRENT_SOURCE_DIR}/*hpp")
foreach(filei ${allfilescpp})
  if(DEFINED ENV{TRAVIS} AND DEFINED ENV{CI})
    add_custom_command(
      TARGET clang_fmt COMMAND bash -c \"! clang-format-10 -style=file ${filei}
                               -output-replacements-xml |grep -q offset\")
  else()
    add_custom_command(TARGET clang_fmt COMMAND clang-format -style=file -i
                                                ${filei})
  endif()
endforeach()

if(DEFINED ENV{TRAVIS} AND DEFINED ENV{CI})
  set(CMAKE_FORMAT_ARGS "--check")
else()
  set(CMAKE_FORMAT_ARGS "-i")
endif()

add_custom_target(cmake_fmt)
file(GLOB_RECURSE allfilescmake "${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.txt")
foreach(filei ${allfilescmake})
  add_custom_command(TARGET cmake_fmt COMMAND cmake-format ${filei}
                                              ${CMAKE_FORMAT_ARGS})
endforeach()
