#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

void thread1_func(void *arg)
{
    sem_t *sem = (sem_t *)arg;
    sem_wait(sem);
    printf("thread1_func \n");

}

void thread2_func(void *arg)
{
    sem_t *sem = (sem_t *)arg;
    printf("thread2_func \n");
    sem_post(sem);
}

int main() {
    printf("sem begin---------->\n");
    //初始化信号量
    sem_t sem,sem1;
    sem_init(&sem, 0, 0);
    //创建一个线程
    pthread_t thread1;
    pthread_create(&thread1, NULL, thread1_func, &sem);
    //创建一个线程
    pthread_t thread2;
    pthread_create(&thread2, NULL, thread2_func, &sem);
    //等待线程结束
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("sem end<----------\n");
    return 0;
}
// output:
//  sem begin---------->
//  thread2_func
//  thread1_func
//  sem end<----------

