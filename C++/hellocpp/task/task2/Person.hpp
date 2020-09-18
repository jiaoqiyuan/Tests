//
// Created by mac on 2020/9/18.
//
#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    Person(string name, int age) {
        this->name = name;
        this->age = age;
    }

    Person() {}

public:
    string name;
    int age;
};
