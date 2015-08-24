#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/times.h>
#include <unistd.h>

void* print1(void* pString)
{
	printf("Før: %s\n", (char*)pString);
	sleep(5);
	//busy_wait_delay(5);
	printf("Etter: %s\n", (char*)pString);
	return 0;
}

void* print2(void* pString)
{
	printf("Før: %s\n", (char*)pString);
	sleep(5);
	//busy_wait_delay(5);
	printf("Etter: %s\n", (char*)pString);
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


void busy_wait_delay(int seconds)
{
	int i, dummy;
    int tps = sysconf(_SC_CLK_TCK);
    clock_t start;
    struct tms exec_time;
    times(&exec_time);
    start = exec_time.tms_utime;
    while( (exec_time.tms_utime - start) < (seconds * tps)) {
    	for(i=0; i<1000; i++) {
    		dummy = i;
    	}
    	times(&exec_time);
    }
}
