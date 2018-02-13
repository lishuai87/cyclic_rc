cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall -fpermissive")

include_directories("cyclic_rc/include")

add_subdirectory(cyclic_rc)
#add_subdirectory(test)
add_subdirectory(test2)
