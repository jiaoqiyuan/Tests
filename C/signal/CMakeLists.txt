cmake_minimum_required(VERSION 3.10)
project(test_c)

set(CMAKE_CXX_STANDARD 11)
# windows下乱码问题
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fexec-charset=GBK")

add_executable(signal signal.c)
add_executable(sigtest sigtest.c)
