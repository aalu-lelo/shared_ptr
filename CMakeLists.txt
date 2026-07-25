cmake_minimum_required(VERSION 3.10)
project(MyProject CXX) 

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(shared_ptr.tsk 
    src/shared.cpp
    src/main.cpp
)

target_include_directories(shared_ptr.tsk PRIVATE include)

enable_testing()
add_subdirectory(test)
