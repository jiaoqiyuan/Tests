/**
 * 二元谓词
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class MyCompare {
public:
    bool operator()(int v1, int v2) {
        return v1 > v2;
    }
};

void test01() {
    vector<int> v;
    v.push_back(10);
    v.push_back(40);
    v.push_back(30);
    v.push_back(20);
    v.push_back(50);

    sort(v.begin(), v.end());
    for (auto it = v.begin(); it != v.end(); ++it) {
        cout << *it << " " << endl;
    }

    cout << endl;

    sort(v.begin(), v.end(), MyCompare());
    for (auto it = v.begin(); it != v.end(); ++it) {
        cout << *it << " " << endl;
    }
}

int main() {
    test01();
}
