#include <stdio.h>

void swap(void);
	
int x1,x2;
	
int main(){
	
	printf("Please enter number 1: ");
	scanf("%d",&x1);
	printf("Please enter number 2: ");
	scanf("%d",&x2);	
	
	swap();
	
	printf("Number 1: %d\n", x1);
	printf("Number 2: %d\n", x2);
}

void swap(void){
	int temp = x1;
	x1 = x2;
	x2 = temp;
	return;
}

	
