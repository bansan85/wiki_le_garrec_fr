add_subdirectory(weak)

add_custom_target(data_for_travis_cpp_linker)
add_dependencies(data_for_travis_cpp_linker data_for_travis_cpp_linker_weak)
