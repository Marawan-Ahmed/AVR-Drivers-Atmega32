#include <stdio.h>

int main(){
	float x1,x2;
	float sum = 0;
	
	while(1){
		printf("Please enter first number: ");
		scanf("%f", &x1);
		printf("Please enter second number: ");
		scanf("%f", &x2);

		sum = x1 + x2;
		printf("Sum = %f\n\n", sum);
	}
	
}