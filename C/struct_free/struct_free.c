#include <stdio.h>
#include <stdlib.h>

typedef struct value_s {
    int ret;
    char *value;
} value_t;

void generate_value(value_t *value) {
    value->ret = 10;
    value->value = malloc(64);
    snprintf(value->value, 64, "test value.");
    printf("value->value = %s\n", value->value);
}

int main() {
    value_t *value = malloc(sizeof(value_t));
    generate_value(value);
    printf("value = %s\n", value->value);
    char *value_bak = value->value;
    int *ret_p = &value->ret;
    value = NULL;
    free(value);
    printf("value after free = %s\n", value->value);
    free(value_bak);
    printf("value after free bak = %s\n", value->value);
}
