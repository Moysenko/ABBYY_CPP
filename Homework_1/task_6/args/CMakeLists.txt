cmake_minimum_required(VERSION 3.8)
add_library(Args args.hpp args.cpp)
target_include_directories(Args PUBLIC "${CMAKE_SOURCE_DIR}")