#include <iostream>
#include <typeinfo>

using namespace std;

int main() {
    cout << "\"(1 + 2.236) / 2\" = " << (0 + 15) / 2;
    cout << " ========= type is " << typeid((0 + 15) / 2).name() << endl;
    
    cout << "1 + 2 + 3 + 4.0 = " << 1 + 2 + 3 + 4.0;
    cout << " ========= type is " << typeid(1 + 2 + 3 + 4.0).name() << endl;

    cout << "4.1 >= 4 ? " << (4.1 >= 4);
    cout << " ========= type is " << typeid(4.1 >= 4).name() << endl;

    cout << "1 + 2 + \"3\" = " << 1 + 2 + 3 + "3";
    cout << " ========= type is " << typeid(1 + 2 + "3").name() << endl;
}