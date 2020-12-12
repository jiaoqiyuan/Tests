#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

void test_a(){
    double t = 9.0;
    while(abs(t - 9.0/t) > .001) {
        t = (9.0/t + t) / 2.0;
    }
    cout << setprecision(5) << t << endl;
}

// 求前 i 个数字之和
void test_b(){
    int sum = 0;
    for(int i = 1; i < 1000; i++){
        for(int j = 0; j < i; j++) {
            sum++;
        }
    }
    cout << sum << endl;
}

void test_c() {
    int sum = 0;
    for(int i = 1; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            sum++;
        }
    }
    cout << sum << endl;
}

int main() {
    test_a();
    test_b();
    test_c();
}