#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h> //It allows a program to control multiple different flows of work that overlap in time.
void * thread_function(void*arg);
char message[]= "Hello World";
int main()
{
	int res;
	pthread_t a_thread;
	void *thread_result;
	res = pthread_create(&a_thread,NULL,thread_function,(void*)message);  //NULL constaint , (void*)messaage argument
	if (res!=0)		
	{
		perror("\n Error: Thread Cannot be created");
		exit(EXIT_FAILURE);
	}
	printf("Waiting foe tread to finish\n");
	res = pthread_join(a_thread,&thread_result);
	if (res!=0)
	{
		perror("Thread Cannot be joind \n");
		exit(EXIT_FAILURE);
	}
	printf("\nThread joind & it returned: %s \n ",(char*)thread_result);
	printf("The message in now %s\n",message);
	exit(EXIT_FAILURE);
}
void *thread_function(void* arg)
{
	printf("thread_function is running. The argument was %s\n",(char*)arg);
	sleep(3);
	strcpy(message,"BYE!");
	pthread_exit("Thank you for the cpu time");
}
//gcc ProgramName -lpthread
//int m = atoi(n)