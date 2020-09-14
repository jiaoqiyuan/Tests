#include <iostream>
using namespace std;

void malloc_in_function(char **space) {
    *space = (char *)(malloc(100));
    snprintf(*space, 100, "this is the mem malloced in function.");
}

void test_mem() {
    cout << "Hello, World!" << endl;
    char *space = NULL;
    malloc_in_function(&space);
    printf("space str = %s\n", space);
    if (space) free(space);
}

int main() {
    test_mem();
    return 0;
}
