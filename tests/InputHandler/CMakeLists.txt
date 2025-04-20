add_executable(input-handler-test test.cpp)

target_link_libraries(input-handler-test PRIVATE history-cleaner-lib)
target_include_directories(input-handler-test PRIVATE ../../src)

add_test(
    NAME InputHandlerTest
    COMMAND $<TARGET_FILE:input-handler-test> ${CMAKE_CURRENT_SOURCE_DIR}/input_data.txt
)