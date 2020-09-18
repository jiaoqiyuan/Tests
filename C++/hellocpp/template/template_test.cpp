//
// Created by Administrator on 2020/9/16.
//
#include "iostream"
#include "class_template.h"
#include "class_func_template.h"

using namespace std;

template <typename T>

void my_swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

void test01() {
    int a = 10, b = 20;
    my_swap<int>(a, b);
    cout << "a = " << a << " b = " << b << endl;
}

// 类模板的用法
void test02() {
    Person<string, int> p1("Tom", 10);
    p1.showPerson();
}

// 类模板与函数模板的区别
void test03() {

}


int main() {
//    test01();
    test02();
    return 0;
}
