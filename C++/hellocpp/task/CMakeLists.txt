cmake_minimum_required(VERSION 3.10)
project(hellocpp)

set(CMAKE_CXX_STANDARD 11)
# windows下乱码问题
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fexec-charset=GBK")

add_executable(task1 task1/main.cpp task1/WorkManager.cpp task1/WorkManager.h)
add_executable(task2 task2/main.cpp task2/MyArray.hpp task2/Person.hpp)
