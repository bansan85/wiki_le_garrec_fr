project(boostexecutor)

find_package(Boost)
if(NOT Boost_FOUND)
  message(FATAL_ERROR "Failed to found boost. Executor not generated.")
endif()

find_package(Threads REQUIRED)

add_executable(boostexecutor executor.cpp main.cpp)
target_include_directories(boostexecutor SYSTEM PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(boostexecutor Threads::Threads)
