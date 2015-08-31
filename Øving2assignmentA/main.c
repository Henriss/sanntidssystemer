#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#define MAX_COUNT 20
#define BUF_SIZE 100
static int globalVariable = 0;

void main (){
int localVariable = 0;
pid_t pid = fork();
int i;
if(pid == 0){
	printf("Child process: %d\n",pid);
	for(i = 0; i<MAX_COUNT;i++){
		globalVariable++;
		localVariable++;

	}
	printf("Child variables, Global: %d, local: %d\n",globalVariable,localVariable);
	_exit(-1);
} else if(pid >0){
	printf("Parent process: %d\n",pid);
	for(i = 0; i<MAX_COUNT;i++){
		globalVariable++;
		localVariable++;

	}
	printf("Parent variables, Global: %d, local: %d\n",globalVariable,localVariable);
} else {
	printf("Gaffel feil: %d\n",pid);
}
}
