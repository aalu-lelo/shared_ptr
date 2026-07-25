cmake_minimum_required(VERSION 3.10)
project(MyProject CXX) 

add_executable(shared_ptr.tsk 
    src/shared.cpp
)

target_include_directories(shared_ptr.tsk PRIVATE include)

enable_testing()
add_subdirectory(test)
