#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char *string = "this is a test string.";
    char *str = strdup(string);
    printf("str = %s\n", str);
    char *first_word = strtok(str, " ");
    char *second_word = strtok(NULL, " ");
    char *third_word = strtok(NULL, " ");
    char *fourth_word = strtok(NULL, " ");
    printf("string = %s\n", string);
    printf("str = %s\n", str);
    printf("first_word = %s\n", first_word);
    printf("second_word = %s\n", second_word);
    printf("third_word = %s\n", third_word);
    printf("fourth_word = %s\n", fourth_word);
    //free(str);
    free(first_word);
    printf("string = %s\n", string);
    printf("str = %s\n", str);
    printf("first_word = %s\n", first_word);
    printf("second_word = %s\n", second_word);
    printf("third_word = %s\n", third_word);
    printf("fourth_word = %s\n", fourth_word);

}
