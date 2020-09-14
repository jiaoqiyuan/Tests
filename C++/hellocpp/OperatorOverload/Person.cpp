//
// Created by mac on 2020/9/7.
//

#include "iostream"
#include "Person.h"

using namespace std;

/**
 * ================ + overload==================
 */
Person Person::operator+(Person &person) {
    Person temp;
    temp.m_a = m_a + person.m_a;
    temp.m_b = m_b + person.m_b;
    return temp;
}

// + overload
void test01() {
    Person person1;
    Person person2;
    person1.m_a = 1;
    person1.m_b = 2;
    person2.m_a = 3;
    person2.m_b = 4;

    Person person3 = person1 + person2;
    cout << "person3.m_a = " << person3.m_a << endl;
    cout << "person3.m_b = " << person3.m_b << endl;
}

/**
 * ================ << overload==================
 */
ostream &operator<<(ostream &cout, Person person) {
    cout << "m_a = " << person.m_a << " m_b = " << person.m_b << endl;
    cout << "number = " << person.number << endl;
    return cout;
}

// << overload
void test02() {
    Person person;
    person.m_a = 10;
    person.m_b = 10;
    cout << person << "end" << endl;
}

/**
 * ================ ++ overload==================
 */
Person::Person() {
    m_a = 0;
    m_b = 0;
    number = 0;
}

Person &Person::operator++() {
    this->number++;
    return *this;
}

Person Person::operator++(int) {
    Person temp = *this;
    this->number++;
    return temp;
}

void test03() {
    Person person;
    cout << ++(++person) << endl;
    cout << person << endl;

    cout << person++ << endl;
    cout << person << endl;
}

/**
 * ================ = overload==================
 */
Person::Person(int age) {
    this->p_age = new int(age);
}

Person::~Person() {
    if (this->p_age) {
        delete this->p_age;
        this->p_age = NULL;
    }
}

// 参数使用引用是为了防止参数拷贝导致析构函数执行多次，从而多次释放age内存，出现错误。
// 默认拷贝构造函数是浅拷贝，age指针只拷贝值，多次执行析构函数会释放同一块内存多次。
// 返回值使用引用的原因是链式调用需要返回同一个对象，不使用引用的话返回的是拷贝的对象。
Person &Person::operator=(Person &person) {
    // delete mem first
    if (p_age) {
        delete p_age;
        p_age = NULL;
    }
    p_age = new int(*person.p_age);
    return *this;
}

void test04() {
    Person person(18);
    Person person1(20);
    Person person2(30);
    person2 = person1 = person;
    cout << "person age is " << *person.p_age << endl;
    cout << "person1 age is " << *person1.p_age << endl;
    cout << "person2 age is " << *person2.p_age << endl;
}

/**
 * ============ 关系运算符重载 =============
 */
Person::Person(string name, int age) {
    this->name = name;
    this->age = age;
    this->p_age = NULL;
}

bool Person::operator==(Person &person) {
    if (name == person.name && age == person.age) {
        return true;
    }
    return false;
}

void test05() {
    Person person1("Tom", 18);
    Person person2("Jerry", 18);
    if (person1 == person2) {
        cout << "person1 == person2" << endl;
    } else {
        cout << "person1 person2 not equal." << endl;
    }
}

int main() {
//    test01();
//    test02();
//    test03();
//    test04();
    test05();
    return 0;
}