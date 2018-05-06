# Define the target for the atermpp library

set(SOURCES
  source/aterm_implementation.cpp
  source/aterm_io_binary.cpp
  source/aterm_io_text.cpp
  source/function_symbol.cpp
)

add_library(atermpp ${SOURCES})
target_link_libraries(atermpp utilities)
target_include_directories(atermpp PUBLIC include/)
