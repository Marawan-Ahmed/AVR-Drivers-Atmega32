#include <stdio.h>



int main(){
	int x;
	printf("Please enter number : ");
	scanf("%d", &x);
	
	
	for (int i = 0; i < x; i++){
		for(int j = x-1; j > i; j--){
			printf(" ");
		}
		for(int j = 0; j <= 2*i; j++){
			printf("*");
		}		
		printf("\n");
	} 
}