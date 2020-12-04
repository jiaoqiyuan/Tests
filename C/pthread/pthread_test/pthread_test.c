/* 举例三个线程: 主线程 + create 两个 */
/* 可以直接在 xcode 中执行，如果在linux 上跑编译的时候用下面的makefile, 主要是需要 -lpthread */
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>

void* thread1_main(void *p)
{
    while(1) {
        printf("This is thread 1\n");
        sleep(1);
    }
    return NULL;
}

void* thread2_main(void *p)
{
    while(1) {
        printf("This is thread 2\n");
        sleep(1);
    }
    return NULL;
}

/* 毫秒级 延时 */
void Sleep(int ms)
{
	struct timeval delay;
	delay.tv_sec = 0;
	delay.tv_usec = ms * 1000; // 20 ms
	select(0, NULL, NULL, NULL, &delay);
}

int main()
{
    pthread_t tid1, tid2;
    void *ret1, *ret2;
    pthread_create(&tid1, NULL, thread1_main, NULL);
    pthread_create(&tid2, NULL, thread2_main, NULL);
    while (1) {
        printf("This is thread main\n");
		// 0.5s
        Sleep(1000);
    }
    pthread_join(tid1, &ret1);
    pthread_join(tid2, &ret2);
	
	printf("wait threads finish.\n");

    return 0;
}

