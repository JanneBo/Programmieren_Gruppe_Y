#include <stdio.h>
#include <stdlib.h>

int main() {

	int *vec = malloc(sizeof(int)*5);
	
	printf("Values of Vec: \n");
	for(int i = 0; i < 5; i++){
		printf("value = %d \n", vec[i]);
		printf("\n");
	}

}
