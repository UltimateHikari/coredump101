#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

void segfunc(void)
{
	int *a = NULL;
	int b = *a;
}	

void *thread_routine(void *arg)
{
	printf("oh boy cant wait to segfault");
	segfunc();
}

int main(void)
{
	pthread_t t;
	void *retval;

	if (pthread_create(&t, NULL, thread_routine, NULL) < 0)
		perror("pthread_create");
	
	if (pthread_join(t, &retval) < 0)
		perror("pthread_join");
	
	return 0;
}
