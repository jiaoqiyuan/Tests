//
// Created by mac on 2020/9/11.
//

#include "iostream"

using namespace std;

class Animal {
public:
    virtual void speak();
};

class Cat : public Animal {
public:
    void speak();
};

class Dog: public Animal {
public:
    void speak();
};

void Animal::speak() {
    cout << "Animal speaking." << endl;
}

void Cat::speak() {
    cout << "Cat speaking." << endl;
}

void Dog::speak() {
    cout << "Dog speaking." << endl;
}

void doSpeak(Animal &animal) {
    animal.speak();
}

void test01() {
    Cat cat;
    Dog dog;
    doSpeak(cat);
    doSpeak(dog);
}

int main() {
    test01();
}