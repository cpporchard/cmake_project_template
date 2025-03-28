enable_testing()

add_executable(VectorTest vector-t.cpp)
target_link_libraries(VectorTest PRIVATE VectorLib gtest_main)

include(GoogleTest)
gtest_discover_tests(VectorTest)