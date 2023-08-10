#include <stdio.h>

int main(){
	int x[10];
	int y;
	
	for (int i = 0; i < 10; i++){
		printf("Please enter number %d: ", i+1);
		scanf("%d", &x[i]);
	}
	
	printf("Please enter number to search: ");
	scanf("%d", &y);
	
	int found = 0;
	int i;
	
	for (i = 0; i < 10; i++){
		if (x[i] == y){
			found = 1;
			break;
		}
	}
	
	if (found){
		printf("Value exist at number %d", i+1);
	} 
	else{
		printf("Not found");
	}
}