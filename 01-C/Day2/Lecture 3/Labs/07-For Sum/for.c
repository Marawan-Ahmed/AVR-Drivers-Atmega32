#include <stdio.h>


int main(){
	float sum = 0; 
	float average = 0;
	
	for (int i = 1; i <= 10; i++){
		float temp = 0;
		printf("Enter Number %d: ", i);
		scanf("%f", &temp);
		sum += temp;
	}
	average = sum/10.0;
	
	printf("sum = %f\n", sum);
	printf("average = %f", average);
}