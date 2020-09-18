//
// Created by Administrator on 2020/9/16.
//

#ifndef HELLOCPP_CLASS_FUNC_TEMPLATE_H
#define HELLOCPP_CLASS_FUNC_TEMPLATE_H

#include <iostream>
#include <string>

using namespace std;

template <class NameType, class AgeType>
class Person1 {
public:
    Person1(NameType name, AgeType age) {
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



#endif //HELLOCPP_CLASS_FUNC_TEMPLATE_H
