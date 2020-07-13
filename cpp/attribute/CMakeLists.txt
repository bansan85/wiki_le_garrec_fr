project(pure1_internal)
add_executable(pure1_internal EXCLUDE_FROM_ALL pure1.cpp)
add_custom_target(pure1 ALL COMMAND make pure1.cpp.o)

project(pure2_internal)
add_executable(pure2_internal EXCLUDE_FROM_ALL pure2.cpp)
add_custom_target(pure2 ALL COMMAND make pure2.cpp.o)

project(pure3_internal)
add_executable(pure3_internal EXCLUDE_FROM_ALL pure3.cpp)
add_custom_target(pure3 ALL COMMAND make pure3.cpp.o)

project(pure4_internal)
add_executable(pure4_internal EXCLUDE_FROM_ALL pure4.cpp)
add_custom_target(pure4 ALL COMMAND make pure4.cpp.o)

project(pure5_internal)
add_executable(pure5_internal EXCLUDE_FROM_ALL pure5.cpp)
add_custom_target(pure5 ALL COMMAND make pure5.cpp.o)

project(pure6_internal)
add_executable(pure6_internal EXCLUDE_FROM_ALL pure6.cpp)
add_custom_target(pure6 ALL COMMAND make pure6.cpp.o)
