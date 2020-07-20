add_custom_target(data_for_travis_cpp_preprocessor_folder)
add_custom_command(
  TARGET data_for_travis_cpp_preprocessor_folder
  COMMAND mkdir -p
          "${CMAKE_BINARY_DIR}/wiki_le_garrec_fr_travis/cpp/preprocessor")

add_custom_target(data_for_travis_cpp_preprocessor)
add_dependencies(data_for_travis_cpp_preprocessor
                 data_for_travis_cpp_preprocessor_folder)

add_library(str_helper_internal OBJECT EXCLUDE_FROM_ALL str_helper.cpp)
add_custom_target(str_helper ALL COMMAND make str_helper.cpp.i)
add_custom_command(
  TARGET data_for_travis_cpp_preprocessor
  COMMAND
    cp `echo \"$<TARGET_OBJECTS:str_helper_internal>\" | sed 's/\\.o$$/.i/g'`
    "${CMAKE_BINARY_DIR}/wiki_le_garrec_fr_travis/cpp/preprocessor/str_helper.cpp.i"
)
add_dependencies(data_for_travis_cpp_preprocessor str_helper)

add_library(macro_and_spaces_internal OBJECT EXCLUDE_FROM_ALL
                                             macro_and_spaces.cpp)
target_compile_options(macro_and_spaces_internal PRIVATE -Wno-unused-value
                                                         -Wno-unreachable-code)
add_custom_target(macro_and_spaces ALL COMMAND make macro_and_spaces.cpp.i)
add_custom_command(
  TARGET data_for_travis_cpp_preprocessor
  COMMAND
    cp `echo \"$<TARGET_OBJECTS:macro_and_spaces_internal>\" | sed
    's/\\.o$$/.i/g'`
    "${CMAKE_BINARY_DIR}/wiki_le_garrec_fr_travis/cpp/preprocessor/macro_and_spaces.cpp.i"
)
add_dependencies(data_for_travis_cpp_preprocessor macro_and_spaces)

add_library(bracket_internal OBJECT EXCLUDE_FROM_ALL bracket.cpp)
target_compile_options(bracket_internal
                       PRIVATE -Wno-gnu-zero-variadic-macro-arguments)
add_custom_target(bracket ALL COMMAND make bracket.cpp.i)
add_custom_command(
  TARGET data_for_travis_cpp_preprocessor
  COMMAND
    cp `echo \"$<TARGET_OBJECTS:bracket_internal>\" | sed 's/\\.o$$/.i/g'`
    "${CMAKE_BINARY_DIR}/wiki_le_garrec_fr_travis/cpp/preprocessor/bracket.cpp.i"
)
add_dependencies(data_for_travis_cpp_preprocessor bracket)
