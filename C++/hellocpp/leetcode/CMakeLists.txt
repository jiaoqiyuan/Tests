cmake_minimum_required(VERSION 3.10)
project(hellocpp)

set(CMAKE_CXX_STANDARD 11)
# windows下乱码问题
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fexec-charset=GBK")

add_executable(leetcode main.cpp ListNode.h
    1290/leetcode1290.cpp
    1290/leetcode1290.h
    offer22/offer22.cpp
    offer18/offer18.cpp
    isPalindrome/IsPalindrome.cpp
)
