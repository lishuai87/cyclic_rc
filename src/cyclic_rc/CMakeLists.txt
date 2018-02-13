cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CYCLIC_SRCS
    include/cyclic_rc/config.h
    include/cyclic_rc/shared_ptr.h
    include/cyclic_rc/details/collector.h
    include/cyclic_rc/details/obj_count.h
    include/cyclic_rc/details/ref_count.h
    impl/collector.cpp
  )

include_directories("include")

add_library(cyclic_rc ${CYCLIC_SRCS})
