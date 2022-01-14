cmake_minimum_required(VERSION 3.10)
project(lwbus)

set(CMAKE_CXX_STANDARD 11)

add_library(lwbus
   src/ext/mdns.c
   src/lwbus.cc
   src/discover.cc
)

target_include_directories(lwbus PRIVATE
   src/ext
)

target_include_directories(lwbus PUBLIC
   include
)

add_executable(bus_node
   src/bus_node_test.cc
   )

   target_link_libraries(bus_node lwbus)