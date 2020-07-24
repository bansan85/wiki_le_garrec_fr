add_custom_target(data_for_travis_cpp_attribute_folder)
add_custom_command(
  TARGET data_for_travis_cpp_attribute_folder
  COMMAND mkdir -p "${CMAKE_BINARY_DIR}/wiki_le_garrec_fr_travis/cpp/attribute")

add_custom_target(data_for_travis_cpp_attribute)
add_dependencies(data_for_travis_cpp_attribute
                 data_for_travis_cpp_attribute_folder)

add_library(pure1_obj OBJECT pure1.cpp)
add_custom_command(
  TARGET data_for_travis_cpp_attribute
  COMMAND
    objdump -drC --no-show-raw-insn -M intel --dwarf-start=0
    "$<TARGET_OBJECTS:pure1_obj>" >
    "${CMAKE_BINARY_DIR}/wiki_le_garrec_fr_travis/cpp/attribute/pure1.cpp.asm")
add_dependencies(data_for_travis_cpp_attribute pure1_obj)

add_library(pure2_obj OBJECT pure2.cpp)
add_custom_command(
  TARGET data_for_travis_cpp_attribute
  COMMAND
    objdump -drC --no-show-raw-insn -M intel --dwarf-start=0
    "$<TARGET_OBJECTS:pure2_obj>" >
    "${CMAKE_BINARY_DIR}/wiki_le_garrec_fr_travis/cpp/attribute/pure2.cpp.asm")
add_dependencies(data_for_travis_cpp_attribute pure2_obj)

add_library(pure3_obj OBJECT pure3.cpp)
add_custom_command(
  TARGET data_for_travis_cpp_attribute
  COMMAND
    objdump -drC --no-show-raw-insn -M intel --dwarf-start=0
    "$<TARGET_OBJECTS:pure3_obj>" >
    "${CMAKE_BINARY_DIR}/wiki_le_garrec_fr_travis/cpp/attribute/pure3.cpp.asm")
add_dependencies(data_for_travis_cpp_attribute pure3_obj)

add_library(pure4_obj OBJECT pure4.cpp)
add_custom_command(
  TARGET data_for_travis_cpp_attribute
  COMMAND
    objdump -drC --no-show-raw-insn -M intel --dwarf-start=0
    "$<TARGET_OBJECTS:pure4_obj>" >
    "${CMAKE_BINARY_DIR}/wiki_le_garrec_fr_travis/cpp/attribute/pure4.cpp.asm")
add_dependencies(data_for_travis_cpp_attribute pure4_obj)

add_library(pure5_obj OBJECT pure5.cpp)
add_custom_command(
  TARGET data_for_travis_cpp_attribute
  COMMAND
    objdump -drC --no-show-raw-insn -M intel --dwarf-start=0
    "$<TARGET_OBJECTS:pure5_obj>" >
    "${CMAKE_BINARY_DIR}/wiki_le_garrec_fr_travis/cpp/attribute/pure5.cpp.asm")
add_dependencies(data_for_travis_cpp_attribute pure5_obj)

add_library(pure6_obj OBJECT pure6.cpp)
add_custom_command(
  TARGET data_for_travis_cpp_attribute
  COMMAND
    objdump -drC --no-show-raw-insn -M intel --dwarf-start=0
    "$<TARGET_OBJECTS:pure6_obj>" >
    "${CMAKE_BINARY_DIR}/wiki_le_garrec_fr_travis/cpp/attribute/pure6.cpp.asm")
add_dependencies(data_for_travis_cpp_attribute pure6_obj)

add_library(unlikely1_obj OBJECT un-likely1.cpp)
add_custom_command(
  TARGET data_for_travis_cpp_attribute
  COMMAND
    objdump -drC --no-show-raw-insn -M intel --dwarf-start=0
    "$<TARGET_OBJECTS:unlikely1_obj>" >
    "${CMAKE_BINARY_DIR}/wiki_le_garrec_fr_travis/cpp/attribute/unlikely1.cpp.asm"
)
# TODO: to remove when clang will support it.
target_compile_options(unlikely1_obj PRIVATE -Wno-unknown-attributes)
add_dependencies(data_for_travis_cpp_attribute unlikely1_obj)

add_library(unlikely2_obj OBJECT un-likely2.cpp)
add_custom_command(
  TARGET data_for_travis_cpp_attribute
  COMMAND
    objdump -drC --no-show-raw-insn -M intel --dwarf-start=0
    "$<TARGET_OBJECTS:unlikely2_obj>" >
    "${CMAKE_BINARY_DIR}/wiki_le_garrec_fr_travis/cpp/attribute/unlikely2.cpp.asm"
)
# TODO: to remove when clang will support it.
target_compile_options(unlikely2_obj PRIVATE -Wno-unknown-attributes)
add_dependencies(data_for_travis_cpp_attribute unlikely2_obj)

add_library(weak1_obj OBJECT weak1.cpp)
add_executable(weak1 $<TARGET_OBJECTS:weak1_obj>)
add_custom_command(
  TARGET data_for_travis_cpp_attribute
  COMMAND
    nm --demangle "$<TARGET_OBJECTS:weak1_obj>" |grep "variable" >
    "${CMAKE_BINARY_DIR}/wiki_le_garrec_fr_travis/cpp/attribute/weak1.cpp.nm")
add_custom_command(
  TARGET data_for_travis_cpp_attribute
  COMMAND "${CMAKE_CURRENT_BINARY_DIR}/weak1" >
          "${CMAKE_BINARY_DIR}/wiki_le_garrec_fr_travis/cpp/attribute/weak1.out"
)
add_dependencies(data_for_travis_cpp_attribute weak1)
