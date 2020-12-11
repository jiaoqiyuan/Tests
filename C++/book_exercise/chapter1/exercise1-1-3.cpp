#include <iostream>

using namespace std;


/* 从命令行获取三个参数，如果三个参数相等打印 equal，否则打印 not equal */
int main(int argc, char * argv[]) {
    if (argc != 4) {
        cout << "Please input 3 args!" << endl;
        return -1;
    }

    if (int(*argv[1]) == int(*argv[2]) && int(*argv[2]) == int(*argv[3])) {
        cout << "equal" << endl;
    } else {
        cout << "not equal" << endl;
    }
}