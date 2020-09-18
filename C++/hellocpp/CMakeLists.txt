cmake_minimum_required(VERSION 3.14)
project(hellocpp)

set(CMAKE_CXX_STANDARD 11)
# windows下乱码问题
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fexec-charset=GBK")

add_executable(hellocpp main.cpp)
add_executable(person constructor/Person.cpp)
add_executable(phone constructor/Phone.cpp)
add_executable(friend friend/GoodGay.cpp friend/GoodGay.h)
add_executable(operator OperatorOverload/Person.cpp OperatorOverload/Person.h)
add_executable(extend extend/Animal.cpp)
add_executable(task1 task1/WorkManager.cpp task1/WorkManager.h task1/main.cpp)
add_executable(template template/template_test.cpp template/class_template.h template/class_func_template.h)