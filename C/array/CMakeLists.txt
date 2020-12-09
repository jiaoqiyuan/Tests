cmake_minimum_required(VERSION 3.10)
project(test_c)

set(CMAKE_CXX_STANDARD 11)
# windows下乱码问题
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fexec-charset=GBK")

add_subdirectory(dynamic_array)
add_subdirectory(const_char_array)
add_subdirectory(out_of_array_index)
add_subdirectory(pointer_array)
