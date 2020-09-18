//
// Created by Administrator on 2020/9/16.
//

#ifndef HELLOCPP_CLASS_TEMPLATE_H
#define HELLOCPP_CLASS_TEMPLATE_H

#include <string>
#include <iostream>

using namespace std;

template <class NameType, class AgeType>
class Person {
public:
    Person(NameType name, AgeType age) {
        this->name = name;
        this->age = age;
    }

    void showPerson() {
        cout << "name: " << this->name << endl;
        cout << "age: " << this->age << endl;
    }

    NameType name;
    AgeType age;
};


#endif //HELLOCPP_CLASS_TEMPLATE_H
