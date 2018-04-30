#define INTER 5
#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
pthread_mutex_t lock;
int circle_points = 0, square_points = 0;

void *fun()
{
		pthread_mutex_lock(&lock);
		double ra_x, ra_y, origin;
		int i;
		srand(time(NULL));
		for ( i = 0; i < (INTER * INTER); i++) {
		ra_x =(double)(rand() % (INTER + 1)) / INTER;
		ra_y =(double)(rand() % (INTER + 1)) / INTER;


		origin = ra_x * ra_x + ra_y * ra_y;

		if (origin <= 1)
			circle_points++;


		square_points++;
		pthread_mutex_unlock(&lock);
	}
}

int main()
{
	double pi;
	int n, interval, i=0;
	pthread_mutex_init(&lock, NULL);
    pthread_t pid;
    printf("Enter number of thread to create\n");
    scanf("%d",&n);
    while(i<n)
    {
	pthread_create(&pid[i],NULL,fun,NULL);
    i++;
    }
    i=0;
	while(i<n)
	{
    	pthread_join(&pid[i],NULL);
        i++;
	}

		pi = (double)(4 * circle_points) / square_points;


	printf("\nFinal value of pi after %lf",pi);
	pthread_mutex_destroy(&lock);

	return 0;
}

