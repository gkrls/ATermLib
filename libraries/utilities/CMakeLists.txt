configure_file(include/mcrl2/utilities/toolset_version_const.h.in mcrl2/utilities/toolset_version_const.h)

set(SOURCES
  source/command_line_interface.cpp
  source/logger.cpp
  source/text_utility.cpp
  source/toolset_version.cpp
)

add_library(utilities ${SOURCES})
target_include_directories(utilities PUBLIC include/ ${CMAKE_CURRENT_BINARY_DIR})
