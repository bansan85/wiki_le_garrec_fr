project(str_helper)
add_executable(str_helper str_helper.cpp)
add_custom_command(
  TARGET str_helper
  PRE_LINK
  COMMAND make str_helper.cpp.i)
