#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *print_func(void *arg) {
    int num = *(int*)arg;
    printf("test output. num = %d\n", num);
    sleep(num);
}

int main() {
    for(int i = 0; i < 5; i++) {
        pthread_t *thread = malloc(sizeof(pthread_t));
        pthread_create(thread, NULL, print_func, (void *)&i);

        void *thread_ret = NULL;
        pthread_join(*thread, &thread_ret);
    }
    return 0;
}
