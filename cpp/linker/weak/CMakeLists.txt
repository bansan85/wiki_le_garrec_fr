add_custom_target(data_for_travis_cpp_linker_weak_folder)
add_custom_command(
  TARGET data_for_travis_cpp_linker_weak_folder
  COMMAND mkdir -p
          "${CMAKE_BINARY_DIR}/wiki_le_garrec_fr_travis/cpp/linker/weak")

add_custom_target(data_for_travis_cpp_linker_weak)
add_dependencies(data_for_travis_cpp_linker_weak
                 data_for_travis_cpp_linker_weak_folder)

add_library(linkerweak_obj OBJECT)
target_compile_options(linkerweak_obj PRIVATE -O0)
set(linkerweak_sources
    "${CMAKE_CURRENT_SOURCE_DIR}/ClasseA.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/ClasseB.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")
target_sources(linkerweak_obj PRIVATE ${linkerweak_sources})

foreach(loop_var IN LISTS linkerweak_sources)
  if(${loop_var} MATCHES ".*Classe.\.cpp")
    get_filename_component(filename_classei ${loop_var} NAME_WE)
    add_custom_command(
      TARGET data_for_travis_cpp_linker_weak
      COMMAND
        nm --demangle `echo \"$<TARGET_OBJECTS:linkerweak_obj>\" | sed
        's/dir.*/dir/g'`/${filename_classei}.cpp.o >
        "${CMAKE_BINARY_DIR}/wiki_le_garrec_fr_travis/cpp/linker/weak/${filename_classei}.cpp.nm"
    )
  endif()
endforeach(loop_var)
add_dependencies(data_for_travis_cpp_linker_weak linkerweak_obj)
