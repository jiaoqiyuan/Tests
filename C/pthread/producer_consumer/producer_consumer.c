#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

/* 需要生产的数量 */
#define Max 5

#define N 3

// 缓冲区数据数量
int count = 0;

pthread_mutex_t the_mutex;

/* 使用信号量 */
pthread_cond_t condc, condp;
int buffer = 0;

/* 生产者 */
void *producer(void *ptr) {
    for (int i = 0; i <= Max; i++) {
        // 使用 mutex 获取锁
        pthread_mutex_lock(&the_mutex);
        printf("Producer get lock\n");
        while(count == N) {
            pthread_cond_wait(&condp, &the_mutex);
        }
        // 往缓冲区放入数据并更新 count
        count++;
        printf("Produce elem done. count = %d\n", count);
        // 唤醒消费者
        if (count == 1) {
            printf("Wake up consumer.\n");
            pthread_cond_signal(&condc);
        }
        // 释放缓冲区
        pthread_mutex_unlock(&the_mutex);
    }
    pthread_exit(0);

}

// 消费者
void *consumer(void *ptr) {
    for (int i = 0; i <= Max; i++) {
        // 使用 mutex 获取锁
        pthread_mutex_lock(&the_mutex);
        printf("Consumer get lock\n");
        while (count == 0) {
            pthread_cond_wait(&condc, &the_mutex);
        }
        // 读取缓冲区数据并更新 count
        count--;
        printf("Get elem, count = %d\n", count);
        // 唤醒生产者
        if (count == N - 1) {
            printf("Wake up producer.\n");
            pthread_cond_signal(&condp);
        }
        // 释放缓冲区
        pthread_mutex_unlock(&the_mutex);
    }
    pthread_exit(0);
}

int main(){
    pthread_t thread_producer, thread_consumer;
    pthread_mutex_init(&the_mutex, NULL);
    // 也可以采用信号量的方式 sem_t semaphore.h
    pthread_cond_init(&condc, NULL);
    pthread_cond_init(&condp, NULL);
    if (pthread_create(&thread_producer, NULL, producer, NULL) != 0) {
        printf("Producer thread create failed.\n");
        return -1;
    }

    if (pthread_create(&thread_consumer, NULL, consumer, NULL) != 0) {
        printf("Consumer thread create failed.\n");
        return -1;
    }

    if (pthread_join(thread_producer, NULL) != 0) {
        printf("Join producer thread failed.\n");
        return -1;
    }
    if (pthread_join(thread_consumer, NULL) != 0) {
        printf("Join consumer thread failed.\n");
        return -1;
    }


    pthread_cond_destroy(&condc);
    pthread_cond_destroy(&condp);
    pthread_mutex_destroy(&the_mutex);
    return 0;
}
