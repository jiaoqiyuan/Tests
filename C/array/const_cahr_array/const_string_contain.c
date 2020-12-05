#include <stdio.h>
#include <string.h>

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

int main() {
    if_contains("route-views3");
    return 0;
}
