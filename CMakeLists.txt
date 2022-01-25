cmake_minimum_required(VERSION 3.10)
project(lwbus)

set(CMAKE_CXX_STANDARD 17)

find_package(Boost REQUIRED COMPONENTS
   system
)

add_library(lwbus
   src/ext/mdns.c
   src/ServiceAdvertiser.cpp
   src/ServiceLookup.cpp
)

target_link_libraries(lwbus
   Boost::system
)

target_include_directories(lwbus PRIVATE
   src/ext
)

target_include_directories(lwbus PUBLIC
   include
)

add_executable(lwbus_test
   src/lwbus_test.cpp
)

target_link_libraries(lwbus_test
   lwbus
)
