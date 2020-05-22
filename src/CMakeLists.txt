set(pythonbindingsdir ${CMAKE_CURRENT_SOURCE_DIR}/../python_bindings/)

add_library(tryphon SHARED tryphon.c tryphon.h)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

set(LIBRARY_OUTPUT_PATH ${pythonbindingsdir})
