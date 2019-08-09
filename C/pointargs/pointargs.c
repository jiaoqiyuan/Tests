#include <stdio.h>
#include <stdlib.h>

void malloc_handle(char **handle) {
    *handle = (char *)malloc(16);
}

void test_point_args() {
    char *handle = NULL;
    malloc_handle(&handle);
    if (handle == NULL)
    {
        printf("handle is null\n");
    } else
    {
        printf("handle is not null\n");
    }
    //用完记得free
    free(handle);
}

int main(int argc, char *argv[]) {
    test_point_args();
    return 0;
}