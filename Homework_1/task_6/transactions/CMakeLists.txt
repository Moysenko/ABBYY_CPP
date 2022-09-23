cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)

set(DEPENDENCIES Args Stonks)

add_library(Transactions transactions.hpp transactions.cpp)
target_link_libraries(Transactions PUBLIC "${DEPENDENCIES}")
target_include_directories(Transactions PUBLIC "${CMAKE_SOURCE_DIR}")