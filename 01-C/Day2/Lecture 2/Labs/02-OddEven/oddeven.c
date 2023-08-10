#include <stdio.h>


int main(){
	int x;
	printf("Please enter number: ");
	scanf("%d",&x);
	
	if (x%2==0){
		printf("Even");
	}
	else{
		printf("Odd");
	}	
}