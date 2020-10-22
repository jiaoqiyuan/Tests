/**
 *  算数仿函数
 * */

#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>

using namespace std;

//negate 一元仿函数 
void test01() {
    negate<int> n;
    cout << n(50) << endl;

    plus<int> plus;
    cout << plus(10, 20) << endl;
    
}

void test02() {
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    for (auto it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    cout << "========" << endl;

    sort(v.begin(), v.end(), greater<int>());
    for (auto it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    cout << "========" << endl;
}


int main() {
    // test01();
    test02();
}