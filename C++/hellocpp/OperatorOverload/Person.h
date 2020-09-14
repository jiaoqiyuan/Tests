//
// Created by mac on 2020/9/7.
//

#ifndef HELLOCPP_PERSON_H
#define HELLOCPP_PERSON_H

using namespace std;

class Person {
    friend ostream & operator<<(ostream &cout, Person person);
public:
    Person();
    Person(int age);
    ~Person();
    Person operator+(Person &person);

    Person &operator++();
    Person operator++(int);   // int 表示站位参数，用于区分前置或后置递增

    int m_a;
    int m_b;

    Person &operator=(Person &person);
    int *p_age;

    string name;
    int age;
    Person(string name, int age);
    bool operator==(Person &person);

private:
    int number;
};


#endif //HELLOCPP_PERSON_H
