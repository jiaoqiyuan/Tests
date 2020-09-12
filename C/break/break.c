#include <stdio.h>
#include <unistd.h>

int main() {

    int i = 0;
    while (1) {
        printf("while...");
        for (i = 0; i < 5; i++) {
            printf("for...");
            if (i == 3 ) break;
        }
    }

    printf("i = %d\n", i);
    return 0;
}
