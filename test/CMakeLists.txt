find_package(GTest REQUIRED)

add_executable(tests.tsk shared.cpp)

target_include_directories(tests.tsk PRIVATE ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(tests.tsk PRIVATE GTest::gtest_main)

add_test(NAME my_tests COMMAND tests.tsk)
