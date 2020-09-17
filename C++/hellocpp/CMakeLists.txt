cmake_minimum_required(VERSION 3.14)
project(hellocpp)

set(CMAKE_CXX_STANDARD 11)

add_executable(hellocpp main.cpp)
add_executable(person constructor/Person.cpp)
add_executable(phone constructor/Phone.cpp)
add_executable(friend friend/GoodGay.cpp friend/GoodGay.h)
add_executable(operator OperatorOverload/Person.cpp OperatorOverload/Person.h)
add_executable(extend extend/Animal.cpp)
