project(str_helper)
add_executable(str_helper str_helper.cpp)
add_custom_command(
  TARGET str_helper
  PRE_LINK
  COMMAND make str_helper.cpp.i)

project(macro_and_spaces_internal)
add_executable(macro_and_spaces_internal EXCLUDE_FROM_ALL macro_and_spaces.cpp)
target_compile_options(macro_and_spaces_internal PRIVATE -Wunused-value
                                                         -Wunreachable-code)
add_custom_target(macro_and_spaces ALL COMMAND make macro_and_spaces.cpp.i)
