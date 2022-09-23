cmake_minimum_required(VERSION 3.1.0)
set( CMAKE_CXX_COMPILER "g++" )
set( CMAKE_CXX_STANDARD 17)
project(Homework1)

add_subdirectory(args)
add_subdirectory(stonks)
add_subdirectory(transactions)
add_subdirectory(main)