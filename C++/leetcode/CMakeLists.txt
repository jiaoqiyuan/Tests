cmake_minimum_required(VERSION 3.10)
project(hellocpp)

set(CMAKE_CXX_STANDARD 11)
# windows下乱码问题
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fexec-charset=GBK")

add_subdirectory(1290)
add_subdirectory(2)
add_subdirectory(offer18)
add_subdirectory(offer22)
add_subdirectory(isPalindrome)
