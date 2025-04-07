cmake_minimum_required(VERSION 3.20)

project(
  history-cleaner
  VERSION 0.1
  LANGUAGES CXX
)

option(HISTORY_CLEANER_INCLUDE_TESTS "Include test targets in the build" ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

add_subdirectory(src)

if(SVLENS_INCLUDE_TESTS)
  include(CTest)
  add_subdirectory(tests)
endif()
