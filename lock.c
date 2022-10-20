//
// Created by ctracerpp on 2022-10-20.
//
#include <pthread.h>
#include <stdio.h>

int sum = 0;
// 锁
pthread_mutex_t mutex;

void* autoAdd(void* count){
    pthread_mutex_lock(&mutex);
    int loopCount = *((int *)count);
    for (int i = 0; i < loopCount; ++i) {
        sum++;
    }
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main(){
    // 变量初始化
    pthread_mutex_init(&mutex, NULL);
    // 创建线程
    pthread_t thread1,thread2;
    int loopCount = 50000000;
    // char c = 1;
     pthread_create(&thread1, NULL, autoAdd, &loopCount);
     pthread_create(&thread2, NULL, autoAdd, &loopCount);
    // 等待线程结束
     pthread_join(thread1, NULL);
     pthread_join(thread2, NULL);
    // 释放锁
    pthread_mutex_destroy (&mutex);
    printf("excepted %d,sum = %d",2 * loopCount, sum);
    return 0;
}