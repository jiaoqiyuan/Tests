//
// Created by mac on 2020/9/3.
//
#include "iostream"
using namespace std;

class Phone {
public:
    Phone(string pName): pName(pName) {
        cout << "make a Phone" << endl;
    }
    string pName;
};

class Person {
public:
    Person(string name, string pName):name(name), phone(pName) {
        cout << "make a Person" << endl;
    }
    string name;
    Phone phone;
};

void test01() {
    Person p("Jony", "Iphone7");
    cout << p.name << " has a " << p.phone.pName << endl;
};

int main() {
    test01();
    return 0;
}