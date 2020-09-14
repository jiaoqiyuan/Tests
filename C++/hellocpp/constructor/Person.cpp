//
// Created by mac on 2020/9/3.
//

#include <iostream>

using namespace std;

class Person {
public:
    Person() {
        cout << "Person 默认构造函数." << endl;
    }

    Person(int age) {
        cout << "Person 有参构造函数." << endl;
        this->age = age;
    }

    Person(const Person &p) {
        cout << "Person 拷贝构造函数." << endl;
        age = p.age;
    }

    ~Person() {
        cout << "Person 析构函数." << endl;
    }

    Person& addAge(int age) {
        this->age += age;
        return *this;
    }

    void showClassName() {
        cout << "this is Person class" << endl;
    }

    void showAge() {
        cout << "age: " << age << endl;
    }

    int age;
};

void test01() {
    Person p1(20);
    Person p2(p1);
}

void doWork(Person p) {
    p.age = 20;
    return;
}

void test02() {
    Person p;
    p.age = 10;
    doWork(p);
    cout << "p.age = " << p.age << endl;
}

Person doWork03() {
    Person p1;
    cout << (int *)&p1 << endl;
    return p1;
}

void test03() {
    Person p = doWork03();
    cout << (int*)&p << endl;
}

void test04() {
    Person p(10);
    cout << "age = " << p.age << endl;
    p.addAge(5).addAge(10);
    cout << "age = " << p.age << endl;
}

void test05() {
    Person *p = NULL;
    p->showAge();
//    p->showClassName();
}

int main() {
//    test01();
//    test02();
//    test03();
//    test04();
    test05();
    return 0;
}