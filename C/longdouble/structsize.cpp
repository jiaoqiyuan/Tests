#include <iostream>
using namespace std;
#pragma pack(8)

struct example1
{
    short a;
    long b;
};
struct example2
{
    char c;
    example1 struct1;
    short e;    
};
#pragma pack()
int main(int argc, char* argv[])
{
    example2 struct2;
    cout << sizeof(example1) << endl;
    cout << sizeof(example2) << endl;
    return 0;
}
