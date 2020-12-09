#include <stdio.h>
#include <string.h>


/* 判断一个常量字符串数组中是否包含某个字符串 */

const char *const BIG_DATA_SOURCES[2] = {
    "rrc03",
    "route-views3"
};

int if_contains(char *name) {
    int size = sizeof(BIG_DATA_SOURCES) / sizeof(char *);
    printf("size = %d\n", size);
    for(int i = 0; i < size; i++) {
        if(strcmp(name, BIG_DATA_SOURCES[i]) == 0) {
            printf("constains big data source!\n");
            return 1;
        }
    }
    
    return 0;
}

void test_array_init() {
    char array[3] = {50, 60, 70};
    for (int i = 0; i < 3; i++) {
        printf("array[%d] = %c\n", i, array[i]);
    }
}

int main() {
    if_contains("route-views3");
    test_array_init();
    return 0;
}
