add_executable(
  history-cleaner
  main.cpp
)

target_link_libraries(history-cleaner
  PRIVATE re2::re2
)
