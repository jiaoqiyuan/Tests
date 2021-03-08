#include "apue.h"
#include <pwd.h>

static void my_alarm(int signo) {
    struct passwd *rootptr;
    printf("in signal handler!\n");
    if ((rootptr = getpwnam("root")) == NULL) {
        printf("getpwnam(root) error!\n");
    }
    alarm(1);
}

int main(void) {
    struct passwd *ptr;

    signal(SIGALRM, my_alarm);
    alarm(1);
    for ( ; ; ) {
        if ((ptr = getpwnam("jqy")) == NULL) {
            printf("getpwnam error \n");
        }
        if (strcmp(ptr->pw_name, "jqy") != 0) {
            printf("return value corrupted!, pw_name = %s\n", ptr->pw_name);
        }
    }
}