/*This code is written by Marawan Ahmed*/
#include <stdio.h>

int fact(int n);
int main(){
	int x, y;
	printf("Please enter number: ");
	scanf("%d", &x);
	
	y = fact(x);
	
	printf("fact(%d) = %d", x, y);

}