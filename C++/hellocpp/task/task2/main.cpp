//
// Created by mac on 2020/9/18.
//
#include "MyArray.hpp"
#include "Person.hpp"

void test01() {
    MyArray<int> arr1(5);
    MyArray<int> arr2(arr1);
    MyArray<int> arr3(100);
    arr3 = arr1;
}

void test02() {
    MyArray<int> arr1(5);
    for (int i = 0; i < 5; i++) {
        arr1.push_back(i);
    }
    arr1.show_elems();
    arr1.pop_back();
    arr1.show_elems();
}

void printPersonArr(MyArray<Person> &arr) {
    for (int i = 0; i < arr.get_size(); ++i) {
        cout << "name: " << arr[i].name << " age: " << arr[i].age << endl;
    }
}

void test03() {
    MyArray<Person> arr(10);
    Person person1("Tom", 10);
    Person person2("Jerry", 20);
    Person person3("Jony", 30);
    arr.push_back(person1);
    arr.push_back(person2);
    arr.push_back(person3);

    cout << "arr capacity = " << arr.get_capacity() << endl;
    cout << "arr size = " << arr.get_size() << endl;

}

int main() {
//    test01();
//    test02();
    test03();

    return 0;
}

