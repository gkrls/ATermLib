cmake_minimum_required(VERSION 2.8.11)
project(mCRL2)

enable_testing()

set(MCRL2_MIN_BOOST_VERSION 1.48.0)
set(MCRL2_VERSION 1.0)

find_package(Boost ${MCRL2_MIN_BOOST_VERSION} QUIET REQUIRED)
include_directories(SYSTEM ${Boost_INCLUDE_DIRS})

add_subdirectory(libraries)
add_subdirectory(example)
