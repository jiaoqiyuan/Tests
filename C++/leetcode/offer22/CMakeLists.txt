cmake_minimum_required(VERSION 3.10)
project(hellocpp)

set(CMAKE_CXX_STANDARD 11)
# windows下乱码问题
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fexec-charset=GBK")

add_executable(offer22 offer22.cpp)
add_executable(test leetcode143.cpp)
