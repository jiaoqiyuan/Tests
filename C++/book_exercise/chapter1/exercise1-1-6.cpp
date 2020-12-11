#include <iostream>

using namespace std;

/* 输出结果为后一个数为前两个数之合 */
int main() {
    int f = 0;
    int g = 1;
    for (int i = 0; i <= 15; i++) {
        cout << f << endl;
        f = f + g;
        g = f - g;
    }
}