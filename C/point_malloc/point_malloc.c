#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test_malloc(void **arg) {
    char *tmp = (char *)arg;
    char **str = (char **)arg;
    *str = malloc(100);
    snprintf(*str, 100, "test str.");
    printf("arg in fun is %s\n", *str);
}

int main(){
    char *str = NULL;
    test_malloc((void **)&str);
    printf("str out of fun is %s\n", str);
    free(str);
    printf("str out of fun is %s\n", str);
    free(str);
    free(str);
    free(str);
    free(str);
    return 0;
}
