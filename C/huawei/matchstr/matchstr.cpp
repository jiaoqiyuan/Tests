#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

int main()
{
    char str1[100] = {0};
    char str2[200] = {0};
    scanf("%s", str1);
    scanf("%s", str2);
    int i;
    for(i = 0; i < strlen(str1); i++) {
        if(strchr(str2, str1[i]) == NULL) {
            printf("false\n");
            break;
        }
    }
    if(i == strlen(str1)) {
        printf("true\n");
    }
    return 0;
}
