#include <stdio.h>
#include <stdlib.h>

int main (){
printf("Hello world! \n");
	int i;
	for(i = 0; i<1000;i++){
		allocate(1000);
	}

	return 0;
}

void allocate(int value) {
     int *ptr = NULL;
     ptr = malloc(100000000000 * sizeof(int));
     if(ptr == NULL){
    	 perror("Error: ");
    	 exit(-1);
     }
     *ptr = value;
     printf("test of allocated memory: %i\n");

}
