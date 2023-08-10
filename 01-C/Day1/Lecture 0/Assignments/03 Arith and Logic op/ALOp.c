#include <stdio.h>

int main(){
	int x1,x2;
	printf("Please enter number a: ");
	scanf("%d",&x1);
	printf("Please enter number b: ");
	scanf("%d",&x2);
	
	printf("a + b = %d\n", x1+x2);
	printf("a - b = %d\n", x1-x2);
	printf("a & b = %d\n", x1&x2);
	printf("a | b = %d\n", x1|x2);
	printf("a ^ b = %d\n", x1^x2);

}