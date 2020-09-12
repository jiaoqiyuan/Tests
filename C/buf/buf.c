#include <stdio.h>

int main() {
    char *buf = "test.";
    while(*buf != '\0') {
        if (*buf == 0x7e) {
            if (buf[1] == '\0') {
                *buf = '\0';
                break;
            } else
                *buf = ',';
        }
        buf++;
    }
    return 0;
}
