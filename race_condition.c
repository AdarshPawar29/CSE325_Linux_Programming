/* Program to show the race condition.
Program create two threads: one to increment the value of a shared variable and second to decrement the value of shared 
variable. Both the threads are executed, so the final value of shared variable should be same as its initial value. 
But due to race condition it would not be same. */

#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
void *fun1();
void *fun2();
int shared=1; //shared variable
int main()
{
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
    x=shared;//thread1 reads value of shared variable
    x++;  //thread1 increments its value
    sleep(1);  //thread1 is preempted by thread2
    shared=x; //thread1 updates the value of shared variable
}

void *fun2()
{
    int y;
    y=shared;//thread2 reads value of shared variable
    y--;  //thread2 decrements its value
    sleep(1); //thread2 is preempted by thread1
    shared=y; //thread2 updates the value of shared variable
}

/* the final value of shared variable should have been 1 but it will 
be either 2 or 0 depending upon which thread executes first. This happened
because the two processes were not synchronized. When one thread was modifying 
the value of shared variable the other thread must not have read its value for modification. 
This can be achieved using locks or semaphores */
