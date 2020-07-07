project(str_helper)
add_executable(str_helper str_helper.cpp)
add_custom_command(
  TARGET str_helper
  PRE_LINK
  COMMAND make str_helper.cpp.i)

project(macro_and_spaces_internal)
add_executable(macro_and_spaces_internal EXCLUDE_FROM_ALL macro_and_spaces.cpp)
target_compile_options(macro_and_spaces_internal PRIVATE -Wno-unused-value
                                                         -Wno-unreachable-code)
add_custom_target(macro_and_spaces ALL COMMAND make macro_and_spaces.cpp.i)

project(bracket_internal)
add_executable(bracket_internal EXCLUDE_FROM_ALL bracket.cpp)
target_compile_options(bracket_internal
                       PRIVATE -Wno-gnu-zero-variadic-macro-arguments)
add_custom_target(bracket ALL COMMAND make bracket.cpp.i)
