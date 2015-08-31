#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
static bool running = 1;
int var1 = 0;
int var2 = 0;

pthread_mutex_t lock;


void* function1(void* num){
	while(running) {
		pthread_mutex_lock(&lock);
		var1 = var1 +1;
		var2 = var1;
		pthread_mutex_unlock(&lock);
	}
}
void* function2(void* num){
	int i;
	for(i=1;i<21;i++){
		printf("Number 1 is %d, number 2 is %d\n",var1,var2);
		usleep(100000);
	}
	running=0;
}






int main (){
	pthread_t thread1, thread2;
	pthread_mutex_init(&lock,NULL);


	pthread_create(&thread1, NULL, function1, "1");
	pthread_create(&thread2, NULL, function2, "2");


	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_mutex_destroy(&lock);

	return 0;
}

