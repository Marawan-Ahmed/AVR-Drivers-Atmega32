#include <stdio.h>

int get_max(int a, int b);

int main(){
	int x1,x2;
	printf("Please enter number 1: ");
	scanf("%d",&x1);
	printf("Please enter number 2: ");
	scanf("%d",&x2);	
	
	printf("Max Number is : %d", get_max(x1,x2));
}	
	
int get_max(int a, int b){
	if (a >= b){
		return a;
	}
	else{
		return b;
	}
}