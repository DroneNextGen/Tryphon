cmake_minimum_required(VERSION 3.0.0)
project(tryphon VERSION 0.1.0)
set(srcdir ${CMAKE_CURRENT_SOURCE_DIR}/src/)
set(pythonbindingsdir ${CMAKE_CURRENT_SOURCE_DIR}/python_bindings/)

include(CTest)
enable_testing()

add_library(tryphon SHARED ${srcdir}/tryphon.c)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

set(LIBRARY_OUTPUT_PATH ${pythonbindingsdir})
