#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#include <sys/times.h>
#include <unistd.h>

sem_t semafor;

void* thread(void* num){
	int i;
	sem_wait(&semafor);
	for (i = 0; i < 5; i++){
		printf("Thread %s, i = %d\n",(char*)num, i);
		usleep(100000);
	}
	sem_post(&semafor);
}

int main (){
	pthread_t thread1, thread2, thread3, thread4, thread5;


	sem_init(&semafor, 0, 3);

	pthread_create(&thread1, NULL, thread, "1");
	pthread_create(&thread2, NULL, thread, "2");
	pthread_create(&thread3, NULL, thread, "3");
	pthread_create(&thread4, NULL, thread, "4");
	pthread_create(&thread5, NULL, thread, "5");

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_join(thread3, NULL);
	pthread_join(thread4, NULL);
	pthread_join(thread5, NULL);

	return 0;
}
