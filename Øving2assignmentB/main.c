#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/times.h>
#include <unistd.h>

#define MAX_COUNT 2000000
//#define BUF_SIZE 100
static int globalVariable = 0;

void* print1(void* pString)
{
	int localVariable = 0;
	int i;
	for(i = 0; i<MAX_COUNT;i++){
			globalVariable++;
			localVariable++;
			//usleep(10);
			//printf("PRINT1 forløokke: %d\n",globalVariable);
	}
	printf("print1 variables, Global: %d, local: %d\n",globalVariable,localVariable);
	return 0;
}

void* print2(void* pString)
{
	int localVariable = 0;
	int i;
	for(i = 0; i<MAX_COUNT;i++){
			globalVariable++;
			localVariable++;
			//printf("print2 forløokke: %d\n",globalVariable);
	}
	printf("print2 variables, Global: %d, local: %d\n",globalVariable,localVariable);
	return 0;
}
int main(void){
	pthread_t thread1, thread2;

	pthread_create(&thread1,NULL,print1,"TRÅD 1");
	pthread_create(&thread2,NULL,print2,"TRÅD 2");

	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	return 0;
}

