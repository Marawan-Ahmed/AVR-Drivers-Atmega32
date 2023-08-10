#include <stdio.h>



int main(){
	int max, temp;
	printf("Please enter number 1: ");
	scanf("%d", &max);
	printf("Please enter number 2: ");
	scanf("%d", &temp);
	if(temp > max) max = temp;
 	printf("Please enter number 3: ");
	scanf("%d", &temp);
	if(temp > max) max = temp;
	
	printf("Max Number = %d", max);
}
 		