#include <stdio.h>

int main(char argc, char *argv[]) {
    int n = 5;
    char ary[n];
    for (int i = 0; i < n; i++){
        ary[i] = i;
    }
    for (int i = 0; i < n; i++){
        printf("ary = %d\n", ary[i]);
    }
    return 0;
}
