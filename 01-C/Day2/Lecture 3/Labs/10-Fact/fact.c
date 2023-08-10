#include <stdio.h>


int main(){
	int x;
	printf("Please enter number: ");
	scanf("%d",&x);
	
	int fact = 1;
	
	while (x > 0){
		fact *= x;
		x--;
	}
	printf("Fact = %d", fact);
	
}