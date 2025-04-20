add_library(
  history-cleaner-lib
  InputHandler.cpp
  Config.cpp
)

add_executable(
  history-cleaner
  main.cpp
)

target_link_libraries(history-cleaner PRIVATE history-cleaner-lib)
