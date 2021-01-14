#include <iostream>

using namespace std;

struct A {
    int a;
    char b;
    char c;
};


struct B {
    char b;
    int a;
    char c;
};

int main(int argc, char *argv[]) {
    A a;
    B b;
    cout << sizeof(a) << endl;
    cout << sizeof(b) << endl;
}
