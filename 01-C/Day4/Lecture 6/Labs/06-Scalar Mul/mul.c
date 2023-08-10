/*This code is written by Marawan Ahmed*/
#include <stdio.h>
#define SIZE 3

int dot_product (int *ptr_1, int *ptr_2);

int main(){
	int v1[SIZE], v2[SIZE];
	
	for (int i = 0; i < SIZE; i++){
		printf("Please enter number %d in matrix 1: ", i+1);
		scanf("%d", &v1[i]);
	}
	for (int i = 0; i < SIZE; i++){
		printf("Please enter number %d in matrix 2: ", i+1);
		scanf("%d", &v2[i]);
	}
	
	int result = dot_product(v1, v2);
	
	printf("Result = %d\n", result);
}

int dot_product (int *ptr_1, int *ptr_2){
	int result = 0;
	for (int i = 0; i < SIZE; i++){
			result += *(ptr_1 + i) * *(ptr_2 + i);
	}
	return result;
}
