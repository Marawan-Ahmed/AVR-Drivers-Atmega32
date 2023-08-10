#include <stdio.h>

int main(){
	float x[10];
	int i;
	float sum = 0, average = 0;
	
	for (i = 0; i < 10; i++){
		printf("Please enter number %d: ", i+1);
		scanf("%f", &x[i]);
		sum += x[i];
	}

	average = sum / 10.0;
	
	printf("\n");
	printf("Sum = %f\n", sum);
	printf("Average = %f\n", average);
}