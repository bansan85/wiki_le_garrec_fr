add_custom_target(data_for_travis_cpp_preprocessor_folder)
add_custom_command(
  TARGET data_for_travis_cpp_preprocessor_folder
  COMMAND mkdir -p
          "${CMAKE_BINARY_DIR}/wiki_le_garrec_fr_travis/cpp/preprocessor")

add_custom_target(data_for_travis_cpp_preprocessor)
add_dependencies(data_for_travis_cpp_preprocessor
                 data_for_travis_cpp_preprocessor_folder)

add_library(str_helper_obj OBJECT str_helper.cpp)
add_custom_target(
  str_helper_i
  COMMAND ${CMAKE_MAKE_PROGRAM} str_helper.cpp.i
  DEPENDS str_helper_obj)
add_custom_command(
  TARGET data_for_travis_cpp_preprocessor
  COMMAND
    cp `echo \"$<TARGET_OBJECTS:str_helper_obj>\" | sed 's/\\.o$$/.i/g'`
    "${CMAKE_BINARY_DIR}/wiki_le_garrec_fr_travis/cpp/preprocessor/str_helper.cpp.i"
)
add_dependencies(data_for_travis_cpp_preprocessor str_helper_i)

add_library(macro_and_spaces_obj OBJECT macro_and_spaces.cpp)
target_compile_options(macro_and_spaces_obj PRIVATE -Wno-unused-value
                                                    -Wno-unreachable-code)
add_custom_target(
  macro_and_spaces_i
  COMMAND ${CMAKE_MAKE_PROGRAM} macro_and_spaces.cpp.i
  DEPENDS macro_and_spaces_obj)
add_custom_command(
  TARGET data_for_travis_cpp_preprocessor
  COMMAND
    cp `echo \"$<TARGET_OBJECTS:macro_and_spaces_obj>\" | sed 's/\\.o$$/.i/g'`
    "${CMAKE_BINARY_DIR}/wiki_le_garrec_fr_travis/cpp/preprocessor/macro_and_spaces.cpp.i"
)
add_dependencies(data_for_travis_cpp_preprocessor macro_and_spaces_i)

add_library(bracket_obj OBJECT bracket.cpp)
target_compile_options(
  bracket_obj PRIVATE -Wno-gnu-zero-variadic-macro-arguments -Wno-unused-value)
add_custom_target(
  bracket_i
  COMMAND ${CMAKE_MAKE_PROGRAM} bracket.cpp.i
  DEPENDS bracket_obj)
add_custom_command(
  TARGET data_for_travis_cpp_preprocessor
  COMMAND
    cp `echo \"$<TARGET_OBJECTS:bracket_obj>\" | sed 's/\\.o$$/.i/g'`
    "${CMAKE_BINARY_DIR}/wiki_le_garrec_fr_travis/cpp/preprocessor/bracket.cpp.i"
)
add_dependencies(data_for_travis_cpp_preprocessor bracket_i)
