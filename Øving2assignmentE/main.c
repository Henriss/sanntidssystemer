#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>


pthread_mutex_t fork1;
pthread_mutex_t fork2;

void* Sokrates(void* num){
	while(1){

		printf("Sokrates is thinking\n");
		pthread_mutex_lock(&fork1); 	// take left fork
		pthread_mutex_lock(&fork2); 	// take right fork
		printf("Sokrates is eating\n");
								// eat
		pthread_mutex_unlock(&fork2); 	// put right fork down
		pthread_mutex_unlock(&fork1); 	// put left fork down
	}
}
void* Aristoteles(void* num){
	while(1){

		printf("Aristoteles is thinking\n");
		pthread_mutex_lock(&fork2);
		pthread_mutex_lock(&fork1); 	// take left fork
		// take right fork
		printf("Aristoteles is eating\n");
								// eat
		pthread_mutex_unlock(&fork2); 	// put right fork down
		pthread_mutex_unlock(&fork1); 	// put left fork down
	}
}






int main (){
	pthread_t thread1, thread2;
	pthread_mutex_init(&fork1, NULL);
	pthread_mutex_init(&fork2, NULL);



	pthread_create(&thread1, NULL, Sokrates, "1");
	pthread_create(&thread2, NULL, Aristoteles, "2");


	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_mutex_destroy(&fork1);
	pthread_mutex_destroy(&fork2);

	return 0;
}
