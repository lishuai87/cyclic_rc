cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB sources "*.cpp" "*.h")

add_executable(pytest ${sources})
target_link_libraries(pytest cyclic_rc)
