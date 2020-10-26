#include <stdio.h>
#include <stdlib.h>


/**
 * 测试指针数组和双指针的使用
 */
void insert_data(char **pa, int n) {
    for (int i = 0; i < n; i++) {
        pa[i] = (char *)malloc(16);
        snprintf(pa[i], 16, "%d", i);
    }
}

int main() {
    int n = 2;
    // char *pa[n];
    char **pa = malloc(n * sizeof(char *));
    insert_data(pa, n);
    for (int i = 0; i < n; i++) {
        printf("pa[%d] is %s.\n", i, pa[i]);
    }
    return 0;
}