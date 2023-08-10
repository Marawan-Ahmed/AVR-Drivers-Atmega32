/*This code is written by Marawan Ahmed*/
#include <stdio.h>

void sumsub(float a, float b, float *sum_ptr, float *sub_ptr);
int main(){
	float x1, x2, sum, sub;	
	
	printf("Please enter first number: ");
	scanf("%f", &x1);
	printf("Please enter second number: ");
	scanf("%f", &x2);
	
	sumsub(x1, x2, &sum, &sub);
	
	printf("Sum = %f\n", sum);
	printf("Sub = %f\n", sub);
}

void sumsub(float a, float b, float *sum_ptr, float *sub_ptr){
	*sum_ptr = a + b;
	*sub_ptr = a - b;
}
