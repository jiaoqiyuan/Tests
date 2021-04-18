cmake_minimum_required(VERSION 3.10)
project(hellocpp)

set(CMAKE_CXX_STANDARD 11)
# windows下乱码问题
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fexec-charset=GBK")

add_executable(ruptime_udp client_udp.c connect.c)
add_executable(ruptimed_udp server_with_execl.c initserver.c set_cloexec.c)
