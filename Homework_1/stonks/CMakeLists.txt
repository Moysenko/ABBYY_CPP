cmake_minimum_required(VERSION 3.8)
add_library(Stonks stocks.hpp stocks.cpp)
target_include_directories(Stonks PUBLIC "${CMAKE_SOURCE_DIR}")