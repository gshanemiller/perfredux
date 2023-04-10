cmake_minimum_required(VERSION 3.16)

# ------------

set(SOURCES                                                                                                             
  main.cpp
) 

set(TARGET test1.tsk)
add_executable(${TARGET} ${SOURCES})
target_include_directories(${TARGET} PUBLIC .)
target_compile_definitions(${TARGET} PUBLIC NDEBUG)
