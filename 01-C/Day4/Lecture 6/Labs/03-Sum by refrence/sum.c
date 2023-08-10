/*This code is written by Marawan Ahmed*/
#include <stdio.h>

float sum(float *ptr1, float *ptr2);

int main(){
	float x1,x2;	
	
	printf("Please enter first number: ");
	scanf("%f", &x1);
	printf("Please enter second number: ");
	scanf("%f", &x2);
	
	printf("Sum = %f\n", sum(&x1,&x2));
	
}

float sum(float *ptr1, float *ptr2){
	float a = *ptr1; //equivelant to a = x1
	float b = *ptr2; //equivelant to b = x2
	return a+b;
	
}