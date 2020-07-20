add_custom_target(data_for_travis_cpp_attribute_folder)
add_custom_command(
  TARGET data_for_travis_cpp_attribute_folder
  COMMAND mkdir -p "${CMAKE_BINARY_DIR}/wiki_le_garrec_fr_travis/cpp/attribute")

add_custom_target(data_for_travis_cpp_attribute)
add_dependencies(data_for_travis_cpp_attribute
                 data_for_travis_cpp_attribute_folder)

add_library(pure1_internal OBJECT EXCLUDE_FROM_ALL pure1.cpp)
add_custom_target(pure1 ALL COMMAND make pure1.o)
add_custom_command(
  TARGET data_for_travis_cpp_attribute
  COMMAND
    objdump -drC --no-show-raw-insn -M intel --dwarf-start=0
    "$<TARGET_OBJECTS:pure1_internal>" >
    "${CMAKE_BINARY_DIR}/wiki_le_garrec_fr_travis/cpp/attribute/pure1.cpp.asm")
add_dependencies(data_for_travis_cpp_attribute pure1)

add_library(pure2_internal OBJECT EXCLUDE_FROM_ALL pure2.cpp)
add_custom_target(pure2 ALL COMMAND make pure2.o)
add_custom_command(
  TARGET data_for_travis_cpp_attribute
  COMMAND
    objdump -drC --no-show-raw-insn -M intel --dwarf-start=0
    "$<TARGET_OBJECTS:pure2_internal>" >
    "${CMAKE_BINARY_DIR}/wiki_le_garrec_fr_travis/cpp/attribute/pure2.cpp.asm")
add_dependencies(data_for_travis_cpp_attribute pure2)

add_library(pure3_internal OBJECT EXCLUDE_FROM_ALL pure3.cpp)
add_custom_target(pure3 ALL COMMAND make pure3.o)
add_custom_command(
  TARGET data_for_travis_cpp_attribute
  COMMAND
    objdump -drC --no-show-raw-insn -M intel --dwarf-start=0
    "$<TARGET_OBJECTS:pure3_internal>" >
    "${CMAKE_BINARY_DIR}/wiki_le_garrec_fr_travis/cpp/attribute/pure3.cpp.asm")
add_dependencies(data_for_travis_cpp_attribute pure3)

add_library(pure4_internal OBJECT EXCLUDE_FROM_ALL pure4.cpp)
add_custom_target(pure4 ALL COMMAND make pure4.o)
add_custom_command(
  TARGET data_for_travis_cpp_attribute
  COMMAND
    objdump -drC --no-show-raw-insn -M intel --dwarf-start=0
    "$<TARGET_OBJECTS:pure4_internal>" >
    "${CMAKE_BINARY_DIR}/wiki_le_garrec_fr_travis/cpp/attribute/pure4.cpp.asm")
add_dependencies(data_for_travis_cpp_attribute pure4)

add_library(pure5_internal OBJECT EXCLUDE_FROM_ALL pure5.cpp)
add_custom_target(pure5 ALL COMMAND make pure5.o)
add_custom_command(
  TARGET data_for_travis_cpp_attribute
  COMMAND
    objdump -drC --no-show-raw-insn -M intel --dwarf-start=0
    "$<TARGET_OBJECTS:pure5_internal>" >
    "${CMAKE_BINARY_DIR}/wiki_le_garrec_fr_travis/cpp/attribute/pure5.cpp.asm")
add_dependencies(data_for_travis_cpp_attribute pure5)

add_library(pure6_internal OBJECT EXCLUDE_FROM_ALL pure6.cpp)
add_custom_target(pure6 ALL COMMAND make pure6.o)
add_custom_command(
  TARGET data_for_travis_cpp_attribute
  COMMAND
    objdump -drC --no-show-raw-insn -M intel --dwarf-start=0
    "$<TARGET_OBJECTS:pure6_internal>" >
    "${CMAKE_BINARY_DIR}/wiki_le_garrec_fr_travis/cpp/attribute/pure6.cpp.asm")
add_dependencies(data_for_travis_cpp_attribute pure6)

add_library(unlikely1_obj OBJECT EXCLUDE_FROM_ALL un-likely1.cpp)
add_custom_target(unlikely1 ALL COMMAND make un-likely1.o)
add_custom_command(
  TARGET data_for_travis_cpp_attribute
  COMMAND
    objdump -drC --no-show-raw-insn -M intel --dwarf-start=0
    "$<TARGET_OBJECTS:unlikely1_obj>" >
    "${CMAKE_BINARY_DIR}/wiki_le_garrec_fr_travis/cpp/attribute/unlikely1.cpp.asm"
)
# TODO: to remove when clang will support it.
target_compile_options(unlikely1_obj PRIVATE -Wno-unknown-attributes)
add_dependencies(data_for_travis_cpp_attribute unlikely1)

add_library(unlikely2_obj OBJECT EXCLUDE_FROM_ALL un-likely2.cpp)
add_custom_target(unlikely2 ALL COMMAND make un-likely2.o)
add_custom_command(
  TARGET data_for_travis_cpp_attribute
  COMMAND
    objdump -drC --no-show-raw-insn -M intel --dwarf-start=0
    "$<TARGET_OBJECTS:unlikely2_obj>" >
    "${CMAKE_BINARY_DIR}/wiki_le_garrec_fr_travis/cpp/attribute/unlikely2.cpp.asm"
)
# TODO: to remove when clang will support it.
target_compile_options(unlikely2_obj PRIVATE -Wno-unknown-attributes)
add_dependencies(data_for_travis_cpp_attribute unlikely2)

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
