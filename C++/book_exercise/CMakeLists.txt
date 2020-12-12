cmake_minimum_required(VERSION 3.10)
project(book_exercise)

set(CMAKE_CXX_STANDARD 11)
# windows下乱码问题
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fexec-charset=GBK")

add_subdirectory(chapter1)
