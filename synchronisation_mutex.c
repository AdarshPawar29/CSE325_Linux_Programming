/* Program for process synchronization using locks
Program create two threads: one to increment the value of a shared variable and second to decrement 
the value of shared variable. Both the threads make use of locks so that only one of the threads is executing in 
its critical section */

#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
void *fun1();
void *fun2();
int shared=1; //shared variable
pthread_mutex_t l; //mutex lock
int main()
{
pthread_mutex_init(&l, NULL); //initializing mutex locks
pthread_t thread1, thread2;
pthread_create(&thread1, NULL, fun1, NULL);
pthread_create(&thread2, NULL, fun2, NULL);
pthread_join(thread1, NULL);
pthread_join(thread2,NULL);
printf("Final value of shared is %d\n",shared); //prints the last updated value of shared variable
}

void *fun1()
{
    int x;
    pthread_mutex_lock(&l); //thread1 acquires the lock. Now thread2 will not be able to acquire the lock until it is unlocked by thread1
    x=shared;               //thread1 reads value of shared variable
    x++;                    //thread1 increments its value
    sleep(1);              //thread1 is preempted by thread 2
    shared=x;              //thread1 updates the value of shared variable
    pthread_mutex_unlock(&l);
}

void *fun2()
{
    int y;
    pthread_mutex_lock(&l);
    y=shared;
    y--; 
    sleep(1); 
    shared=y;
    pthread_mutex_unlock(&l);
}

/* the final value of shared variable will be 1. 
When any one of the threads acquires the lock and is making changes to shared variable the other thread 
(even if it preempts the running thread) is not able to acquire the lock and thus not able to read the 
inconsistent value of shared variable. Thus only one of the thread is running in its critical section 
at any given time */
